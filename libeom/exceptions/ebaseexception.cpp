// -*- coding:koi8-r -*-
// -*- кодировка:koi8-r -*-

#include "ebaseexception.h"

namespace eom {



EBaseException::EBaseException()  {

};

EBaseException::EBaseException(const QString & message, const QString & subMessage):message(message), subMessage(subMessage) {



};

EBaseException::EBaseException(const QString & message) :message(message) {

};


EBaseException::~EBaseException() throw () {


};

QString EBaseException::getMessage() const {
    return message;
};

QString EBaseException::getSubMessage() const {
    return subMessage;
};


const char * EBaseException::what() const throw() {
    QString whatString = message + ":" + subMessage;
    return whatString.toStdString().c_str();
};







}; //namespace eom
