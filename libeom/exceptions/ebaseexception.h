// -*- coding:utf-8 -*-
// -*- ���������:utf-8 -*-

/****************************************************************************************************
**                  ������ �������� ������� ����� ����������
**
****************************************************************************************************/
#ifndef EEXCEPTION_H
#define EEXCEPTION_H

#include <QString>
#include <exception>

/**\class EBaseException
 *  ������� ����� �������������� ��������
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
