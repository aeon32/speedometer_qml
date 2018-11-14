// -*- coding:koi8-r -*-
// -*- кодировка:koi8-r -*-

#include "fstools.h"
#include <QDir>
#include <QString>
#include "../logger/logger.h"
namespace eom {


EFSException::EFSException(const QString & message, const QString & subMessage):EBaseException (message, subMessage) {

};



EFSException::EFSException(const QString & message):EBaseException(message) {

};



}; //namespace eom
