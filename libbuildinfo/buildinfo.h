// -*- coding:cp1251 -*-
// -*- ���������:cp1251 -*-
#ifndef BUILD_OPTIONS_H
#define BUILD_OPTIONS_H

namespace build_options {

enum OptionType {
    PROJECT_VERSION,     //������
    PROJECT_RELEASE,     //�����
    PROJECT_BUILD_TYPE,  //��� ������
    BUILD_TIME,   //����� ������ ���������
    REVISION,     //�������
    ALL           //��� �����
};
const char * getBuildParamValue(OptionType optionType);



};//namespace
#endif
