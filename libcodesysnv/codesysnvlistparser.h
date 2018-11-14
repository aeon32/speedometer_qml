
#ifndef CODESYSNVLISTPARSER_H
#define CODESYSNVLISTPARSER_H

//parser for codesys .gvl export file

#include <QString>
#include <libeom/exceptions/ebaseexception.h>
#include <string>
#include <vector>

class ECodeSysNvListParserException: public eom::EBaseException {
    public:
        ECodeSysNvListParserException(const QString & message, const QString & subMessage);
        ECodeSysNvListParserException(const QString & message);
        ECodeSysNvListParserException();

};


class CodeSysNvListParser {
public:
    struct Variable {
        QString name;
        QString type;
    };

    typedef std::vector<Variable> VariableList;

public:
    CodeSysNvListParser(const QString & fileName) throw (ECodeSysNvListParserException);

    VariableList getVariableList() const;
private:
    VariableList variableList;

    std::string loadFile(const QString & fileName) throw (ECodeSysNvListParserException);
    void parse(const std::string & nvList) throw (ECodeSysNvListParserException);


};

#endif // QCODESYSNV_H
