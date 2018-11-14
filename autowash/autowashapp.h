// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-
/**
 * Файл содержит заголовок класса, представляющего приложение esvp
 * Ответственен за создание главного окна, хранение осовных объектов
 *
**/

#ifndef AUTOWASHAPP_H
#define AUTOWASHAPP_H

#include <QApplication>

namespace awash {
	class MainWindow;
	class Settings;

	class AutoWashApp :public QApplication {
		Q_OBJECT
	public:


		AutoWashApp(int argc, char **argv);
		virtual ~AutoWashApp();

		int exec();



		static AutoWashApp * getApp();

		//    QRunnbale * initializationResourcesProcess();


	private:
		AutoWashApp(const AutoWashApp &);
		AutoWashApp & operator = (const AutoWashApp &);

		MainWindow * mainWindow;
		Settings * settings;


		void setupLogger();
		int argC;
		const char * argV;


		bool resourceInitialization();

		static AutoWashApp * app;

		int run();

	private:

	};

};

#endif
