// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-
/**
 * Файл содержит заголовок класса, представляющего приложение esvp
 * Ответственен за создание главного окна, хранение осовных объектов
 *
**/

#ifndef QRCodeTestApp_H
#define QRCodeTestApp_H

#include <QApplication>
#include <QtQml/QQmlApplicationEngine>

namespace qrcodetest {
	class MainWindow;
	class Settings;

	class QRCodeTestApp :public QApplication {
		Q_OBJECT
	public:


		QRCodeTestApp(int argc, char **argv);
		virtual ~QRCodeTestApp();

		int exec();



		static QRCodeTestApp * getApp();

		//    QRunnbale * initializationResourcesProcess();


	private:
		QRCodeTestApp(const QRCodeTestApp &);
		QRCodeTestApp & operator = (const QRCodeTestApp &);

		Settings * settings;

		QQmlApplicationEngine * engine;
		QObject * qmlRoot;


		void setupLogger();
		int argC;
		const char * argV;


		bool resourceInitialization();

		static QRCodeTestApp * app;

		int run();

	private:

	};

};

#endif
