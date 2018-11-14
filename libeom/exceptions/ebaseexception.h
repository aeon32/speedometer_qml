// -*- coding:utf-8 -*-
// -*- кодировка:utf-8 -*-

/****************************************************************************************************
**                  Модуль содержит базовые класс исключений
**
****************************************************************************************************/
#ifndef EEXCEPTION_H
#define EEXCEPTION_H

#include <QString>
#include <exception>

/**\class EBaseException
 *  Базовый класс исключительной ситуации
 *
**/
namespace eom {
class EBaseExceptionPrivate;
class EBaseException: public std::exception {
private:
    QString message;
    QString subMessage;
public:
    EBaseException(const QString & message, const QString & subMessage);
    EBaseException(const QString & message);
    EBaseException();
    virtual ~EBaseException() throw();

    QString getMessage() const ;
    QString getSubMessage()  const;

    virtual const char * what()  const throw();
};



};//eom


#endif
