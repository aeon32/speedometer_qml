// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "settings.h"


#include <memory>
#include <QVector>
#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QStack>
#include <strstream>


#include <libeom/logger/logger.h>



#include "../localconfig.h"
#include "../config.h"

namespace {

	const char * convertFromWChar(const wchar_t * text) {
		return reinterpret_cast<const char *> (text);
	};


	using namespace std;
	//Кэш из специальных значений папок
	struct SpecialDirsCache {
		typedef QVector< pair<QString, QString> > PairStrings;

		PairStrings stringsToReplace;
		SpecialDirsCache() {
			stringsToReplace.push_back(make_pair("${HOME}", QDir::homePath()));
			stringsToReplace.push_back(make_pair("${BINDIR}", qApp->applicationDirPath()));


            QDir libDir(qApp->applicationDirPath() + "/../lib/");
			QDir shareDir(qApp->applicationDirPath() + "/../share/");

            #ifdef DEVELOP_FLAGS
                QDir mediaDir(qApp->applicationDirPath() + "/../../" + PROJECT_NAME);

            #else
                QDir mediaDir(qApp->applicationDirPath() + "/../share/" + PROJECT_NAME);

            #endif





			stringsToReplace.push_back(make_pair("${LIBDIR}", libDir.absolutePath()));
			stringsToReplace.push_back(make_pair("${SHAREDIR}", shareDir.absolutePath()));
			stringsToReplace.push_back(make_pair("${MEDIADIR}", mediaDir.absolutePath()));
			stringsToReplace.push_back(make_pair("${PROJECTNAME}",PROJECT_NAME));

		};
	};



	auto_ptr<SpecialDirsCache> pSpecialDirsCache;


	/**************************************************************************************
	**               Реализация processSpecialDirs
	**
	**************************************************************************************/
	QString processSpecialDirs(const QString & originalValue) {
		using namespace std;
		if (!pSpecialDirsCache.get()) {
			pSpecialDirsCache.reset(new SpecialDirsCache());
		};

		QString aux2 = originalValue;

		SpecialDirsCache::PairStrings::iterator it = pSpecialDirsCache->stringsToReplace.begin();
		for (; it != pSpecialDirsCache->stringsToReplace.end(); ++it) {
			aux2.replace(it->first, it->second);
		};

		return aux2;
	};


};


//единственный экземпляр настроек

namespace qrcodetest {


	Settings::Settings(int argC, const char * const *argv) :runMode(Settings::ARGS_WORK) {
		iniFileName = parseCommandString(argC, argv, QString(CONF_FILE_NAME));

		load();

	};

	Settings::~Settings() {
		QSettings qsettings(iniFileName, QSettings::IniFormat);
		save(&qsettings);

	};



	QString Settings::parseCommandString(int argC, const char * const * argV, const QString & defaultConfFile) {
		return processSpecialDirs(defaultConfFile);
	};

	QString Settings::getHelpMessage() const {
		return helpMessage;
	};


	QString Settings::getErrorMessage() const {
		return errorMessage;
	};

	void Settings::load() {
		QSettings qsettings(iniFileName, QSettings::IniFormat);
		loggerSettings.fileLogName = qsettings.value("logging/log_filename", DEFAULT_LOG_FILE_NAME).toString();
		loggerSettings.logLevel = qsettings.value("logging/log_level", 1).toInt();
		loggerSettings.fileLogLevel = qsettings.value("logging/file_log_level", 1).toInt();
		loggerSettings.prefix = qsettings.value("logging/prefix", "").toString();
		loggerSettings.realFileLogName = processSpecialDirs(loggerSettings.fileLogName);



        qmlSettings.qmlFile = qsettings.value("qml/qml_file", "${MEDIADIR}" + QString("/qml/main.qml")).toString();
        qmlSettings.qmlDebug = qsettings.value("qml/qml_debug", QVariant(false)).toBool();
        qmlSettings.demoMode = qsettings.value("qml/demo_mode", QVariant(false)).toBool();



        qmlSettings.realQmlFile = processSpecialDirs(qmlSettings.qmlFile);



		if (!QFile(iniFileName).exists() || qsettings.status() == QSettings::FormatError) {
			save(&qsettings);
		};
     };

	void Settings::save(QSettings * qsettings) {
		qsettings->clear();

		qsettings->setValue("logging/log_filename", loggerSettings.fileLogName);
		qsettings->setValue("logging/log_level", loggerSettings.logLevel);
		qsettings->setValue("logging/file_log_level", loggerSettings.fileLogLevel);
		qsettings->setValue("logging/prefix", loggerSettings.prefix);


		qsettings->setValue("qml/qml_file",  qmlSettings.qmlFile );
		qsettings->setValue("qml/qml_debug", qmlSettings.qmlDebug);
        qsettings->setValue("qml/demo_mode", qmlSettings.demoMode);



	};


};
