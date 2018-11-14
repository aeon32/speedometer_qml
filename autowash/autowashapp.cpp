// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-

#include "autowashapp.h"




#include <libeom/logger/logger.h>
#include <libeom/stringutils/stringutils.h>



#include <locale>
#include "localconfig.h"
#include "mainwindow.h"

namespace awash{

namespace {


const char * PROGNAME = PROJECT_NAME;

};

/*****************************************************************************
**      Реализация AutoWashApp
**
******************************************************************************/

AutoWashApp::AutoWashApp(int argc, char **argv):QApplication(argc, argv), argC(argc), argV(argV), mainWindow(NULL)  {

    app = this;



    setQuitOnLastWindowClosed(false);


};


AutoWashApp::~AutoWashApp() {

    //settings->saveSettings();



    if (mainWindow)
        delete mainWindow;



};

void AutoWashApp::setupLogger() {



};

int AutoWashApp::exec() {

    setupLogger();

    int res = 0;
    
    if (!resourceInitialization()) {
        return -1;

    };


    return run();

};


AutoWashApp * AutoWashApp::getApp() {
    return app;

};





AutoWashApp * AutoWashApp::app = 0;



bool AutoWashApp::resourceInitialization() {
    return true;

};

int AutoWashApp::run() {
	mainWindow = new MainWindow();
	mainWindow->show();

	int res = QApplication::exec();
	return res;


};




};





