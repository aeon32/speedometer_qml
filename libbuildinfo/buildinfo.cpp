#include "buildinfo.h"

#include "info.h"
#include "config.h"

namespace build_options {


const char * getBuildParamValue(OptionType optionType) {
    switch(optionType) {

        case PROJECT_VERSION:    return projectVersion; break;
        case PROJECT_RELEASE:    return projectRelease; break;
        case PROJECT_BUILD_TYPE: return projectBuildType; break;

        case BUILD_TIME: return buildTime; break;
        case REVISION: return revision; break;
        case ALL:
        break;
    }
    return 0;
};//getBuildParamValue
};//namespace
