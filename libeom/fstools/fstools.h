// -*- coding:utf-8 -*-
// -*- кодировка:utf-8 -*-

/****************************************************************************************************
**                  Модуль содержит вспомогательные функции для работы с файловой системы
**
****************************************************************************************************/
#ifndef EFSTOOLS_H
#define EFSTOOLS_H

#include "../exceptions/ebaseexception.h"



namespace eom {

/**\class EFSException
 *  Класс исключительной ситуации при работе с файловой системой
 *
**/

class EFSException: public EBaseException {

public:
    EFSException(const QString & message, const QString & subMessage);
    EFSException(const QString & message);

};




};//eom


#endif
