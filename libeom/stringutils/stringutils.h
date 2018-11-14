// -*- coding:utf-8 -*-
// -*- кодировка:utf-8 -*-

/****************************************************************************************************
**                  Модуль содержит вспомогательные функции для работы со строками
**
****************************************************************************************************/
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <QString>



namespace c3map {

/**
 * Функция преобразования строки в дефолтную ОСПОШную кодировку
**/
std::string toOSPOCoding(const char * str);
std::string toOSPOCoding(const QString & str);


/**
 * Обратное преобразование
**/
QString fromOSPOCoding(const char * str);
QString fromOSPOCoding(const std::string & str);

};


#endif
