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

			QDir tmp1(qApp->applicationDirPath() + "/../lib/");

			QDir tmp2(qApp->applicationDirPath() + "/../share/");

			stringsToReplace.push_back(make_pair("${LIBDIR}", tmp1.absolutePath()));
			stringsToReplace.push_back(make_pair("${SHAREDIR}", tmp2.absolutePath()));
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

namespace awash {


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

		listeningSettings.host = qsettings.value("listening/host", "").toString();
		listeningSettings.port = qsettings.value("listening/port", 1202).toInt();
		listeningSettings.cob_id = qsettings.value("listening/cob_id", 1).toInt();

        qmlSettings.qmlFile = qsettings.value("qml/qml_file", "${SHAREDIR}" +QString("/") + QString(PROJECT_NAME) + QString("/qml/main.qml")).toString();
        qmlSettings.qmlDebug = qsettings.value("qml/qml_debug", QVariant(false)).toBool();
        qmlSettings.demoMode = qsettings.value("qml/demo_mode", QVariant(false)).toBool();
        qmlSettings.speedometerAnimation = qsettings.value("qml/speedometer_animation", QVariant(true)).toBool();
        qmlSettings.animationTime = qsettings.value("qml/animation_time", 500).toInt();
        qmlSettings.animationSteps = qsettings.value("qml/animation_steps", 5).toInt();

        codeSysSettings.gvlFile = qsettings.value("codesys/gvl_file", "${SHAREDIR}" +QString("/") + QString(PROJECT_NAME) + QString("/gvl/NVL2UI.gvl")).toString();

        videoSettings.activeCleanVideo = qsettings.value("video/active_clean_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.coldWaterVideo = qsettings.value("video/coldwater_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.foamVideo = qsettings.value("video/foam_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.helpVideo = qsettings.value("video/help_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.hotWaterVideo = qsettings.value("video/hotwater_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.osmoseVideo = qsettings.value("video/osmose_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.pauseVideo = qsettings.value("video/pause_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.printVideo = qsettings.value("video/print_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.shampooVideo = qsettings.value("video/shampoo_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.waxVideo = qsettings.value("video/wax_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();
        videoSettings.idleVideo = qsettings.value("video/idle_btn", "/usr/share/" + QString(PROJECT_NAME) + QString("/video/Idle.mp4") ).toString();



        #ifdef DEVELOP_FLAGS
            qmlSettings.realQmlFile = processSpecialDirs(DEVELOP_QML_PATH);
            codeSysSettings.realGvlFile = processSpecialDirs(DEVELOP_GVL_PATH);
        #else
            qmlSettings.realQmlFile = processSpecialDirs(qmlSettings.qmlFile);
            codeSysSettings.realGvlFile = processSpecialDirs(codeSysSettings.gvlFile);
        #endif



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

		qsettings->setValue("listening/host", listeningSettings.host);
		qsettings->setValue("listening/port", listeningSettings.port);
		qsettings->setValue("listening/cob_id", listeningSettings.cob_id);



		qsettings->setValue("qml/qml_file",  qmlSettings.qmlFile );
		qsettings->setValue("qml/qml_debug", qmlSettings.qmlDebug);
        qsettings->setValue("qml/demo_mode", qmlSettings.demoMode);
        qsettings->setValue("qml/speedometer_animation", qmlSettings.speedometerAnimation);

        qsettings->setValue("qml/animation_time", qmlSettings.animationTime);
        qsettings->setValue("qml/animation_steps", qmlSettings.animationSteps);

		qsettings->setValue("codesys/gvl_file", codeSysSettings.gvlFile);




		qsettings->setValue("video/active_clean_btn",  videoSettings.activeCleanVideo);
		qsettings->setValue("video/coldwater_btn", videoSettings.coldWaterVideo);
        qsettings->setValue("video/foam_btn", videoSettings.foamVideo);
        qsettings->setValue("video/help_btn", videoSettings.helpVideo);
		qsettings->setValue("video/hotwater_btn",  videoSettings.hotWaterVideo );
		qsettings->setValue("video/osmose_btn", videoSettings.osmoseVideo );
        qsettings->setValue("video/pause_btn", videoSettings.pauseVideo );
        qsettings->setValue("video/print_btn", videoSettings.printVideo);
        qsettings->setValue("video/shampoo_btn", videoSettings.shampooVideo );
        qsettings->setValue("video/wax_btn", videoSettings.waxVideo);
        qsettings->setValue("video/idle_btn", videoSettings.idleVideo);

	};


};
