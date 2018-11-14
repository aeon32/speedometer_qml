// -*- coding:utf-8 -*-
// -*- кодировка:utf-8 -*-

#include "stringutils.h"
#include "../localconfig.h"
#include <memory>
#include <QTextCodec>
namespace c3map {

namespace {

const char * OSPO_CODECNAME=OSPO_CHARSET;

QTextCodec *  ospoCodec = NULL;

};

std::string toOSPOCoding(const char * str) {
    if (!ospoCodec)
        ospoCodec = QTextCodec::codecForName(OSPO_CODECNAME);
    return  std::string((const char *) (ospoCodec->fromUnicode(QString(str))));

};

std::string toOSPOCoding(const QString & str) {
  if (!ospoCodec)
        ospoCodec = QTextCodec::codecForName(OSPO_CODECNAME);
  return  std::string((const char *) (ospoCodec->fromUnicode(str)));

};


QString fromOSPOCoding(const char * str) {
    if (!ospoCodec)
        ospoCodec = QTextCodec::codecForName(OSPO_CODECNAME);
    return ospoCodec->toUnicode(str);


};

QString fromOSPOCoding(const std::string & str) {
  if (!ospoCodec)
        ospoCodec = QTextCodec::codecForName(OSPO_CODECNAME);
    return ospoCodec->toUnicode(str.c_str());

};


}; //namespace c3map


