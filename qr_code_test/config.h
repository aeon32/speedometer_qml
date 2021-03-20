// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

/**
 * Разные константы
 *
**/
#ifndef CONFIG_H
#define CONFIG_H

namespace qrcodetest {

static const char * CONF_FILE_NAME = "${HOME}/.qrcodetest/autowash.conf";  //путь к файлу конфигу
static const char * DEFAULT_LOG_FILE_NAME = "${HOME}/.qrcodetest/log.txt";  //путь к логу по дефолту

#ifdef _MSC_BUILD
static const char * DEVELOP_QML_PATH = "${BINDIR}/qml/main.qml";  //путь к qml при разработке
#else
static const char * DEVELOP_QML_PATH = "${BINDIR}/../../qr_code_test/qml/main.qml";  //путь к qml при разработке
#endif

static const char * DEFAULT_QML_PATH = "${SHAREDIR}/${PROJECTNAME}/qml/main.qml";
static const char * DEFAULT_GVL_PATH = "${SHAREDIR}/${PROJECTNAME}/qml/NVL2UI.gvl";

};


#endif
