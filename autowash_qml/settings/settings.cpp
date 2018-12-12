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

        qmlSettings.qmlFile = qsettings.value("qml/qml_file", "${MEDIADIR}" + QString("/qml/main.qml")).toString();
        qmlSettings.qmlDebug = qsettings.value("qml/qml_debug", QVariant(false)).toBool();
        qmlSettings.demoMode = qsettings.value("qml/demo_mode", QVariant(false)).toBool();
        qmlSettings.speedometerAnimation = qsettings.value("qml/speedometer_animation", QVariant(true)).toBool();
        qmlSettings.animationTime = qsettings.value("qml/animation_time", 500).toInt();
        qmlSettings.animationSteps = qsettings.value("qml/animation_steps", 5).toInt();

        codeSysSettings.gvlFile = qsettings.value("codesys/gvl_file", "${MEDIADIR}"+ QString("/gvl/NVL2UI.gvl")).toString();

        videoSettings.activeCleanVideo = qsettings.value("video/active_clean_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.coldWaterVideo = qsettings.value("video/coldwater_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.foamVideo = qsettings.value("video/foam_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.helpVideo = qsettings.value("video/help_btn",  "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.hotWaterVideo = qsettings.value("video/hotwater_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.osmoseVideo = qsettings.value("video/osmose_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.pauseVideo = qsettings.value("video/pause_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.printVideo = qsettings.value("video/print_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.shampooVideo = qsettings.value("video/shampoo_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.waxVideo = qsettings.value("video/wax_btn", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();
        videoSettings.idleVideo = qsettings.value("video/idle", "${MEDIADIR}" + QString("/video/Idle.mp4") ).toString();

        qmlSettings.realQmlFile = processSpecialDirs(qmlSettings.qmlFile);
        codeSysSettings.realGvlFile = processSpecialDirs(codeSysSettings.gvlFile);

        videoSettings.realActiveCleanVideo = processSpecialDirs( videoSettings.activeCleanVideo);
        videoSettings.realFoamVideo = processSpecialDirs( videoSettings.foamVideo);
        videoSettings.realShampooVideo = processSpecialDirs( videoSettings.shampooVideo );
        videoSettings.realColdWaterVideo = processSpecialDirs( videoSettings.coldWaterVideo);
        videoSettings.realHotWaterVideo = processSpecialDirs( videoSettings.hotWaterVideo);
        videoSettings.realWaxVideo = processSpecialDirs( videoSettings.waxVideo);
        videoSettings.realOsmoseVideo = processSpecialDirs( videoSettings.osmoseVideo);
        videoSettings.realPauseVideo = processSpecialDirs( videoSettings.pauseVideo);
        videoSettings.realPrintVideo = processSpecialDirs( videoSettings.printVideo);
        videoSettings.realHelpVideo = processSpecialDirs( videoSettings.helpVideo);
        videoSettings.realIdleVideo = processSpecialDirs( videoSettings.idleVideo);



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
        qsettings->setValue("video/idle", videoSettings.idleVideo);

	};


};
