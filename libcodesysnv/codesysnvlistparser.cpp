
#include "codesysnvlistparser.h"

#include <libiec61131parser/runtime/antlr4-runtime.h>
#include <libiec61131parser/IEC61131Lexer.h>
#include <libiec61131parser/IEC61131Parser.h>


#include <QDataStream>
#include <QStringList>

#include <QtXml>
#include <QStack>

#include <iostream>
#include <libeom/logger/logger.h>



namespace {

//класс-парсер xml в старом формате
class GVLXmlContentHandler: public QXmlDefaultHandler {
public:

    //тип текущей точки
    enum POINT_TYPE {
        ROOT, GVL, DECLARATIONS, DECLARATIONS_CDATA, NOT_SUPPORTED_TAG
    };



    QStack<POINT_TYPE> pointStack;

    QString errorS;
    QString localError;

    QString nvListSection;


    GVLXmlContentHandler () {

    };

    virtual bool startDocument () {
        pointStack.push_back(ROOT);
        return true;
    };

    virtual bool endDocument () {
        return true;
    };


    bool processGVL ( const QXmlAttributes & atts) {
        if (pointStack.back()!= ROOT) {
            localError = "Tag GVL not after root";
            return false;
        };
        pointStack.push_back(GVL);
        return true;
    };

    bool processDeclarations () {
        if (pointStack.back()!= GVL  && pointStack.back()!=NOT_SUPPORTED_TAG) {
            localError = "Tag Declarations not after GVL";
            return false;
        };
        if (pointStack.back()== GVL )
            pointStack.push_back(DECLARATIONS);
        else
            pointStack.push_back(NOT_SUPPORTED_TAG);

        return true;
    };

   virtual bool	startCDATA() {
      if (pointStack.back() == DECLARATIONS) {
        pointStack.push_back(DECLARATIONS_CDATA);
      };
      return true;

   };

   virtual bool	endCDATA() {
      if (pointStack.back() == DECLARATIONS_CDATA) {
        pointStack.pop();
      };
      return true;

   };

   virtual bool characters(const QString & characters) {
       if (pointStack.back() == DECLARATIONS_CDATA)
            nvListSection = characters;
       return true;
   };







    virtual bool startElement ( const QString & namespaceURI, const QString & localName, const QString & qName, const QXmlAttributes & atts ) {
        if (localName == "GVL") {
            return processGVL(atts);
        } else if (localName =="Declarations" ) {
            return processDeclarations();
        } else {
            pointStack.push_back(NOT_SUPPORTED_TAG);
            return true;
        };
        return true;

    };

    virtual bool endElement ( const QString & namespaceURI, const QString & localName, const QString & qName ) {
        pointStack.pop_back();
        return true;
    };


    virtual bool fatalError ( const QXmlParseException & exception ) {
        errorS = (localError.isEmpty() ? exception.message() : localError) +" at " + QString::number(exception.lineNumber());
        return false;
    };

    virtual bool error ( const QXmlParseException & exception ) {
        errorS = (localError.isEmpty() ? exception.message() : localError) +" at " + QString::number(exception.lineNumber());
        return false;
    };

    virtual QString errorString() {
        return errorS.isNull() ? QXmlDefaultHandler::errorString() : errorS;
    };




};



class GVLXMLReader:public QXmlSimpleReader {
public:
    GVLXmlContentHandler contentHandler;

    /*!<vectorToSave - вектор, в который будут сохранены строки с объектами */
    GVLXMLReader():QXmlSimpleReader() {
        setContentHandler(&contentHandler);
        setErrorHandler(&contentHandler);
        setLexicalHandler(&contentHandler);

    };


    //Функция для финализации в случае ошибки/исключения.
    void finalizeOnError() {

    };
};


};


CodeSysNvListParser::CodeSysNvListParser(const QString & fileName) throw (ECodeSysNvListParserException) {
    std::string nvListSectionList = loadFile(fileName);
    parse(nvListSectionList);

};







std::string CodeSysNvListParser::loadFile(const QString & fileName) throw(ECodeSysNvListParserException) {
    EOM_LOG_INFO<<"Loading document from "<<fileName <<eom::endl;



    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        EOM_LOG_ERROR<<"Cannot open file " << fileName << " for reading " <<eom::endl;

    };

    QXmlInputSource xmlInputSource(&file);

    GVLXMLReader xmlReader;
    bool res = xmlReader.parse(&xmlInputSource, false);



    if (!res) {
        xmlReader.finalizeOnError();//Обязательно освобождаем динамические ресурсы!
        EOM_LOG_ERROR<<"Error parsing " << fileName << "." << xmlReader.contentHandler.errorString()<<eom::endl;

        throw ECodeSysNvListParserException("Ошибка загрузки", QString("Ошибка разбора файла ") + fileName);

    } else {

    };

    //QTextCodec * codec = QTextCodec::codecForName("CP1251");
    //QByteArray convertedString = codec->fromUnicode(xmlReader.contentHandler.nvListSection);
    //QByteArray convertedString = xmlReader.contentHandler.nvListSection.toLatin1();

    return xmlReader.contentHandler.nvListSection.toStdString();

};



void  CodeSysNvListParser::parse(const std::string & nvList) throw(ECodeSysNvListParserException) {
    EOM_LOG_DEBUG_HERE << "Parsing nvList .."<<eom::endl;
	antlr4::ANTLRInputStream input(nvList);
	IEC61131Lexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    tokens.fill();
    IEC61131Parser parser(&tokens);
    parser.setBuildParseTree(true);

    IEC61131Parser::Var_block_globalContext* globalContext = parser.var_block_global();
    if (globalContext) {

        for( IEC61131Parser::Variable_declarationContext * variable : globalContext->variables) {
            for (antlr4::Token * name : variable->names) {
                EOM_LOG_DEBUG<<"Variable "<<name->getText()<<" type "<<variable->type->getText()<<eom::endl;
                Variable tmpVar = {QString(name->getText().c_str()).simplified(), QString(variable->type->getText().c_str()).simplified() };
                variableList.push_back(tmpVar);
            };

        };


    };



};

CodeSysNvListParser::VariableList CodeSysNvListParser::getVariableList() const {
    return variableList;
};


ECodeSysNvListParserException::ECodeSysNvListParserException(const QString & message, const QString & subMessage) {

};

ECodeSysNvListParserException::ECodeSysNvListParserException(const QString & message) {

};
ECodeSysNvListParserException::ECodeSysNvListParserException() {

};

