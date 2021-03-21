// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "qrcodetestapp.h"




#include <libeom/logger/logger.h>
#include <libeom/stringutils/stringutils.h>
#include <libqtquickauxitems/qtquickqrcode.h>

#include "settings/settings.h"

#include <locale>
#include "localconfig.h"




namespace qrcodetest{

namespace {


const char * PROGNAME = PROJECT_NAME;

};

/*****************************************************************************
**      Реализация QRCodeTestApp
**
******************************************************************************/

QRCodeTestApp::QRCodeTestApp(int argc, char **argv):QApplication(argc, argv), argC(argc), argV(argV), engine(NULL)  {

    app = this;



    settings = new Settings(argc, argv);

    setQuitOnLastWindowClosed(false);


};


QRCodeTestApp::~QRCodeTestApp() {

    if (engine)
        delete engine;


    delete settings;




};

void QRCodeTestApp::setupLogger() {



};

int QRCodeTestApp::exec() {

    setupLogger();

    int res = 0;

    if (!resourceInitialization()) {
        return -1;

    };


    return run();

};


QRCodeTestApp * QRCodeTestApp::getApp() {
    return app;

};





QRCodeTestApp * QRCodeTestApp::app = 0;



bool QRCodeTestApp::resourceInitialization() {
    return true;

};

int QRCodeTestApp::run() {


    qmlRegisterType<QtQuickQRCode> ("QtQuickQRCode",1,0,"QtQuickQRCode");

    engine = new QQmlApplicationEngine(settings->qmlSettings.realQmlFile, this);
    if (engine->rootObjects().isEmpty())
        return -1;

    qmlRoot = engine->rootObjects().first();
    if (!qmlRoot)
        return -1;



	int res = QApplication::exec();
	return res;


};




};





