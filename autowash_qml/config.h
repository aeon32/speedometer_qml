// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

/**
 * Разные константы
 *
**/
#ifndef C3CONFIG_H
#define C3CONFIG_H

namespace awash {

static const char * CONF_FILE_NAME = "${HOME}/.autowash/autowash.conf";  //путь к файлу конфигу
static const char * DEFAULT_LOG_FILE_NAME = "${HOME}/.autowash/log.txt";  //путь к логу по дефолту

#ifdef _MSC_BUILD
static const char * DEVELOP_QML_PATH = "${BINDIR}/qml/main.qml";  //путь к qml при разработке
static const char * DEVELOP_GVL_PATH = "${BINDIR}/gvl/NVL2UI.gvl";  //путь к qml при разработке
#else
static const char * DEVELOP_QML_PATH = "${BINDIR}/../../autowash_qml/qml/main.qml";  //путь к qml при разработке
static const char * DEVELOP_GVL_PATH = "${BINDIR}/../../autowash_qml/gvl/NVL2UI.gvl";  //путь к qml при разработке
#endif

static const char * DEFAULT_QML_PATH = "${SHAREDIR}/${PROJECTNAME}/qml/main.qml";
static const char * DEFAULT_GVL_PATH = "${SHAREDIR}/${PROJECTNAME}/qml/NVL2UI.gvl";

};


#endif
