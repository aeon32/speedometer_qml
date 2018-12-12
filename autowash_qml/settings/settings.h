// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

/*****************************************************************************
**                CSettings. Хранилище для настроек программы
*****************************************************************************/

#ifndef CSETTINGS_H
#define CSETTINGS_H


#include <QString>
#include <QVariant>
#include <QObject>
#include <QVariantMap>
#include <QSettings>


namespace awash {

class Settings {

public:
    enum RunMode {          //режим работы приложения
        ARGS_PARSE_ERROR,    //произошла ошибка при разборе аргументов командной строки
        ARGS_WORK,          //штатный режим работы
        ARGS_SHOW_VERSION,  //показать версию программы
        ARGS_SHOW_RELEASE,  //показать версию релиза
		ARGS_SHOW_HELP,    //показать помощь
        ARGS_TEST          //тестирование
    };
private:
    RunMode runMode;
public:
	struct LoggerSettings {
		QString fileLogName;
		QString realFileLogName;
		QString prefix;
		int logLevel;
		int fileLogLevel;
	} loggerSettings;

	struct ListeningSettings {
		QString host;
		unsigned int port;
		unsigned int cob_id;

	} listeningSettings;

	struct QMLSettings {
        QString qmlFile;
        QString realQmlFile;
        bool qmlDebug;
        bool demoMode;
        bool speedometerAnimation;
        unsigned int animationTime;
        unsigned int animationSteps;
	} qmlSettings;

    struct CodeSysSettings {
        QString gvlFile;
        QString realGvlFile;
    } codeSysSettings;

    struct VideoSettings {
        QString activeCleanVideo;
        QString foamVideo;
        QString shampooVideo;
        QString coldWaterVideo;
        QString hotWaterVideo;
        QString waxVideo;
        QString osmoseVideo;
        QString pauseVideo;
        QString printVideo;
        QString helpVideo;
        QString idleVideo;

    } videoSettings;

    //Функция возвращает режим работы программы (по результам парсинга командной строки)
    inline RunMode getRunMode() const {return runMode; } ;
    //Функция возвращает командострочную справку
    QString getHelpMessage() const;
    //Функция возвращает строку об ошибке
    QString getErrorMessage() const;


    virtual ~Settings();


    //функция возвращает дефолтный экземпляр настроек
    static Settings * getInstance();


private:
    QString helpMessage;
    QString errorMessage;

    QString iniFileName;

    QString parseCommandString(int argc, const char * const * argv, const QString & defaultConfFile);

	void load();

	void save(QSettings * qsettings);
public:
    Settings(int argc, const char * const *argv);
};


};

#endif
