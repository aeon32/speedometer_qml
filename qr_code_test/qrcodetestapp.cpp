// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "qrcodetestapp.h"




#include <libeom/logger/logger.h>
#include <libeom/stringutils/stringutils.h>



#include <locale>
#include "localconfig.h"
#include "mainwindow.h"

namespace qrcodetest{

namespace {


const char * PROGNAME = PROJECT_NAME;

};

/*****************************************************************************
**      Реализация QRCodeTestApp
**
******************************************************************************/

QRCodeTestApp::QRCodeTestApp(int argc, char **argv):QApplication(argc, argv), argC(argc), argV(argV), mainWindow(NULL)  {

    app = this;



    setQuitOnLastWindowClosed(false);


};


QRCodeTestApp::~QRCodeTestApp() {

    //settings->saveSettings();



    if (mainWindow)
        delete mainWindow;



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
	mainWindow = new MainWindow();
	mainWindow->show();

	int res = QApplication::exec();
	return res;


};




};





