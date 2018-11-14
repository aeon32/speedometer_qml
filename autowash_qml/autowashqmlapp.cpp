// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "autowashqmlapp.h"

#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include <QtQuick/qquickitem.h>
#include <QMessageBox>

#include "settings/settings.h"


#include <libeom/logger/logger.h>
#include <libeom/stringutils/stringutils.h>
#include <libcodesysnv/qcodesysnv.h>
#include <libcodesysnv/codesysnvlistparser.h>

#include <initializer_list>


#include <locale>
#include "localconfig.h"

#ifdef WIN32
#include <Windows.h>
#endif
namespace awash
{

namespace
{


const char * PROGNAME = PROJECT_NAME;

const int ANIMATION_TIME = 500;
const int ANIMATION_STEPS = 10;

};

/*****************************************************************************
**      Реализация AutoWashQmlApp
**
******************************************************************************/

AutoWashQmlApp::AutoWashQmlApp(int argc, char **argv):QApplication(argc, argv), argC(argc), argV(argV),
    engine(nullptr),  receivableTelegram(nullptr), socket(nullptr), testTimer(this), testMode(0), timeOutTimer(this), oldButtonActive(-1),
    lastPostCounterFund(0), animationPostCounterFund(0)
{

    app = this;


    settings = new Settings(argc, argv);

    connect(&testTimer, SIGNAL(timeout()), this, SLOT(on_testTimerTimeout()));
    connect(&timeOutTimer, SIGNAL(timeout()), this, SLOT(on_timeOutTimerTimeout()));

    connect(&animationTimer, SIGNAL(timeout()), this, SLOT(on_animationTimerTimeout()));

    timeOutTimer.setSingleShot(true);


};


AutoWashQmlApp::~AutoWashQmlApp()
{

    //settings->saveSettings();



    if (engine)
        delete engine;
    if (receivableTelegram)
        delete receivableTelegram;
    if (socket)
        delete socket;


    delete settings;


};

void AutoWashQmlApp::setupLogger()
{
    eom::LoggerStream::setFileLogLevel(settings->loggerSettings.realFileLogName, eom::LoggerStream::fromSettings(settings->loggerSettings.fileLogLevel));
    eom::LoggerStream::setLogLevel(eom::LoggerStream::fromSettings(settings->loggerSettings.logLevel));
    eom::LoggerStream::setLogPrefix(settings->loggerSettings.prefix);
    //eom::LoggerStream::setCStringEncoding("UTF-8");

};

int AutoWashQmlApp::exec()
{

    setupLogger();

    int res = 0;
    switch (settings->getRunMode())
    {
    case Settings::ARGS_SHOW_HELP:
        std::wcout<<settings->getHelpMessage().toStdWString()<<std::endl;
        break;
    case Settings::ARGS_PARSE_ERROR:
        std::wcerr<<settings->getErrorMessage().toStdWString()<<std::endl;
        res = -1;
        break;


    };

    if (settings->getRunMode() != Settings::ARGS_WORK &&
            settings->getRunMode()!= Settings::ARGS_TEST )
    {
        return res;
    };


    if (!resourceInitialization())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Ошибка инициализации");
        return -1;

    };


    return run();

};


void AutoWashQmlApp::on_initializationError()
{
    //QMessageBox::warning(nullptr, "Ошибка", "Ошибка инициализации");

};

AutoWashQmlApp * AutoWashQmlApp::getApp()
{
    return app;

};





AutoWashQmlApp * AutoWashQmlApp::app = 0;



bool AutoWashQmlApp::resourceInitialization()
{
    CodeSysNvListParser::VariableList gvlVariableList;
    try
    {
        CodeSysNvListParser parser(settings->codeSysSettings.realGvlFile);
        gvlVariableList = parser.getVariableList();

    }
    catch (ECodeSysNvListParserException & exc)
    {
        return false;
    };

    QStringList variableTypes;
    for (CodeSysNvListParser::Variable & var : gvlVariableList)
    {
        //EOM_LOG_ERROR << var.name << eom::endl;
        variableTypes.append(var.type);
        netVariableNames.append(var.name);

    };


    receivableTelegram = new QCodesysNVTelegram(0);
    connect(receivableTelegram, SIGNAL(updated()), this, SLOT(on_dataAvailable()));
    receivableTelegram->setCobId(settings->listeningSettings.cob_id);
    receivableTelegram->setVariableTypes(variableTypes);




    QHostAddress address;
    if (!settings->listeningSettings.host.isEmpty())
    {
        address = QHostAddress(settings->listeningSettings.host);
        if (address.isNull())
        {
            EOM_LOG_ERROR << " Invalid host address value " << settings->listeningSettings.host;
            return false;
        }
    }
    else
    {
        address = QHostAddress::Any;

    };

    quint16 port = settings->listeningSettings.port;


    socket = new QCodesysNVSocket(address, port);
    //connect(socket, SIGNAL(udpPackageReceived(QString, uint, uint)), this, SLOT(UDPreceived(QString, unsigned int, unsigned int)));
    connect(socket, SIGNAL(codesysTelegramReceived(QString, uint, uint, uint)), this, SLOT(on_codesysTelegramReceived(QString, unsigned int, unsigned int, unsigned int)));

    socket->addTelegram(receivableTelegram);

    return true;

};

void AutoWashQmlApp::on_codesysTelegramReceived(QString IP, unsigned int port, unsigned int bytes, unsigned int cobid)
{
    //EOM_LOG_DEBUG << "Diagram received from ip " << IP << " port " << port << " bytes " << bytes << " cobid " << cobid << eom::endl;

};

void AutoWashQmlApp::setNewPostCounterFund(unsigned int newPostCounterFund)
{
    if (newPostCounterFund >=0 && newPostCounterFund != lastPostCounterFund)
    {

        postCounterFundAnimationStep = newPostCounterFund -   animationPostCounterFund;
        postCounterFundAnimationStep = postCounterFundAnimationStep / ANIMATION_TIME;


        lastPostCounterFund = newPostCounterFund;



        animationElapsedTimer.restart();
        animationTimer.start(ANIMATION_TIME / ANIMATION_STEPS);

    };
};

void AutoWashQmlApp::on_animationTimerTimeout()
{
    animationPostCounterFund += postCounterFundAnimationStep * animationElapsedTimer.elapsed();
    int animationPostCounterFundInt = (int) animationPostCounterFund + 0.5;

    if (animationPostCounterFundInt < 0)
        animationPostCounterFundInt = 0;

    if (animationPostCounterFundInt >= lastPostCounterFund)
    {

        animationPostCounterFundInt = lastPostCounterFund;
        animationPostCounterFund = lastPostCounterFund;
        animationTimer.stop();
    };

        QVariantMap variantMap;

        variantMap.insert(QString("postCounterFund"), QVariant(animationPostCounterFundInt));

        QVariant returnedValue;
        QMetaObject::invokeMethod(qmlRoot, "setVariables",
                                  Q_RETURN_ARG(QVariant, returnedValue),
                                  Q_ARG(QVariant, QJsonObject::fromVariantMap(variantMap))
                                 );

}

void AutoWashQmlApp::on_dataAvailable()
{

    QStringList dataStrings;
    receivableTelegram->dataToStringList(dataStrings);

    auto dataTypes = receivableTelegram->readVariableTypes();
    auto dataTypesIt = dataTypes.begin();
    QStringList::iterator netVariableNamesIt = netVariableNames.begin();

    QVariantMap variantMap;


    for (QStringList::iterator dataIt = dataStrings.begin();
            dataIt != dataStrings.end() && dataTypesIt != dataTypes.end() && netVariableNamesIt != netVariableNames.end();
            ++dataIt,++dataTypesIt, ++netVariableNamesIt)
    {
        QVariant data = QCodesysNVType::convertToVariant(*dataIt, *dataTypesIt);

        if (*netVariableNamesIt == "postCounterFund" )
        {
            setNewPostCounterFund(data.toUInt());
        } else
        {
           variantMap.insert((*netVariableNamesIt), data);
        };

    };

    /*
    QVariantMap::const_iterator buttonActiveIt = variantMap.find(QString("buttonActive"));
    if (buttonActiveIt != variantMap.cend()  && buttonActiveIt.value().toInt() != oldButtonActive) {
    	oldButtonActive = buttonActiveIt.value().toInt();
    	int amountReceived =  variantMap["amountReceived"].toInt();

    	quint16 lockTop = variantMap["lockTop"].toInt();
    	quint16 lockMid = variantMap["lockMid"].toInt();

    	unsigned int codeSysTime = lockTop;
    	codeSysTime = (codeSysTime << 16) + lockMid;
    	unsigned int localTime = 0;
    	#ifdef WIN32
    		localTime = GetTickCount();
    	#endif

    	QTime time = QTime::currentTime();
    	EOM_LOG_DEBUG_HERE << " new button pressed " << oldButtonActive << " localtime " <<localTime <<" codesysTime "<<codeSysTime<<" diff "<<(localTime- codeSysTime)<< eom::endl;


    };

    */

    QVariant returnedValue;
    QMetaObject::invokeMethod(qmlRoot, "setVariables",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, QJsonObject::fromVariantMap(variantMap))
                             );

    timeOutTimer.start();

    /*
    QString moneyString = dataStrings[0];
    QString modeString = dataStrings[1];

    bool ok;
    unsigned int dMoney = moneyString.toUInt(&ok);
    if (ok)
    	setMoneyValue(dMoney);

    unsigned int dMode = modeString.toUInt(&ok);
    if (ok)
    	setWorkingMode(dMode);
    */
};

void AutoWashQmlApp::setQMLDebugFlag(bool debugFlag)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(qmlRoot, "setQmlDebug",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, debugFlag)
                             );


};


int AutoWashQmlApp::run()
{
    QFontDatabase::addApplicationFont(":/fonts/DejaVuSans.ttf");
    setFont(QFont("DejaVu Sans"));

    engine = new QQmlApplicationEngine(settings->qmlSettings.realQmlFile, this);
    if (engine->rootObjects().isEmpty())
        return -1;

    qmlRoot = engine->rootObjects().first();
    if (!qmlRoot)
        return -1;


    setPostMode(0);
    setQMLDebugFlag(settings->qmlSettings.qmlDebug);


    testTimer.setInterval(1000);
    //testTimer.start();

    timeOutTimer.setInterval(4000);
    timeOutTimer.start();

    int res = QApplication::exec();
    return res;


};

void AutoWashQmlApp::setPostMode(unsigned int mode)
{
    QVariantMap variantMap;

    variantMap.insert(QString("postMode"), mode);


    QVariant returnedValue;
    QMetaObject::invokeMethod(qmlRoot, "setVariables",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, QJsonObject::fromVariantMap(variantMap))
                             );

}



void AutoWashQmlApp::on_testTimerTimeout()
{
    const int TEST_VALUES_N = 5;

    const int TEST_VALUES [TEST_VALUES_N] = {0, 50, 100, 150, 200};


    /*

    QVariantMap variantMap;

    for (QStringList::iterator netVariableNamesIt = netVariableNames.begin(); netVariableNamesIt != netVariableNames.end(); ++netVariableNamesIt)
    {
        if (*netVariableNamesIt == "postMode")
        {
            variantMap.insert((*netVariableNamesIt), QVariant(TEST_VALUES[testMode]));
        }
        else
        {
            variantMap.insert((*netVariableNamesIt), QVariant(0));
        };


    };


    QVariant returnedValue;
    QMetaObject::invokeMethod(qmlRoot, "setVariables",
                              Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, QJsonObject::fromVariantMap(variantMap))
                             );
    */

    testMode++;
    if (testMode == TEST_VALUES_N)
        testMode = 0;

    setNewPostCounterFund(TEST_VALUES[testMode]);


};

void AutoWashQmlApp::on_timeOutTimerTimeout()
{
    const int STOP_MODE = 1000;
    setPostMode(1000);

};


};





