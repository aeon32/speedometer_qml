// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-
/**
 * Файл содержит заголовок класса, представляющего приложение esvp
 * Ответственен за создание главного окна, хранение осовных объектов
 *
**/

#ifndef AUTOWASHQMLAPP_H
#define AUTOWASHQMLAPP_H

#include <QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QTimer>
#include <QElapsedTimer>



class QCodesysNVSocket;
class QCodesysNVTelegram;

namespace awash {
	class Settings;

	class AutoWashQmlApp :public QApplication {
		Q_OBJECT
	public:


		AutoWashQmlApp(int argc, char **argv);
		virtual ~AutoWashQmlApp();

		int exec();



		static AutoWashQmlApp * getApp();

		//    QRunnbale * initializationResourcesProcess();


	private:
		AutoWashQmlApp(const AutoWashQmlApp &);
		AutoWashQmlApp & operator = (const AutoWashQmlApp &);

		QQmlApplicationEngine * engine;
		Settings * settings;

		//socket and telegrams
		QCodesysNVSocket *socket;
		QCodesysNVTelegram *receivableTelegram;

		void setupLogger();
		int argC;
		const char * argV;
		QObject * qmlRoot;

		int oldButtonActive;


		unsigned int testMoneyIndexValue;
		unsigned int lastPostCounterFund;

		double animationPostCounterFund;
		double postCounterFundAnimationStep;



        QStringList netVariableNames;


		bool resourceInitialization();

		static AutoWashQmlApp * app;

		int run();

		void setPostMode(unsigned int mode);

		void setScreen (unsigned int screen);

		void setQMLDebugFlag(bool debugFlag);

		void setNewPostCounterFund(unsigned int newPostCounterFund);

		QTimer testTimer;
		QTimer timeOutTimer;

		QElapsedTimer animationElapsedTimer;
		QTimer animationTimer;

	private slots:
		void on_codesysTelegramReceived(QString IP, unsigned int port, unsigned int bytes, unsigned int cobid);
		void on_dataAvailable();

        void on_animationTimerTimeout();

		void on_testTimerTimeout();

		void on_initializationError();

		void on_timeOutTimerTimeout();
	};

};

#endif
