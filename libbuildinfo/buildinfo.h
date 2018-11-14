// -*- coding:cp1251 -*-
// -*- кодировка:cp1251 -*-
#ifndef BUILD_OPTIONS_H
#define BUILD_OPTIONS_H

namespace build_options {

enum OptionType {
    PROJECT_VERSION,     //версия
    PROJECT_RELEASE,     //релиз
    PROJECT_BUILD_TYPE,  //тип сборки
    BUILD_TIME,   //время сборки программы
    REVISION,     //ревизия
    ALL           //все опции
};
const char * getBuildParamValue(OptionType optionType);



};//namespace
#endif
