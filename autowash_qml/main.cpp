// -*- coding:utf8 -*-
// -*- ���������:utf8 -*-


#include <locale>
#include "localconfig.h"

#include <QTextCodec>
#include <locale.h>
#include "autowashqmlapp.h"

int main(int argc, char **argv) {
	::setlocale(LC_ALL, PROJECT_WORKING_LOCALE);
	//QTextCodec::setCodecForTr(QTextCodec::codecForName(PROJECT_WORKING_CHARSET));
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName(PROJECT_WORKING_CHARSET));


	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("KOI8-R"));

	//������� ���������. ������ � ��������� ����������
	return(awash::AutoWashQmlApp(argc, argv).exec());
}
