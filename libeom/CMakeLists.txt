# -*- coding:utf-8 -*-
# -*- кодировка:utf-8 -*-

SET (SUBPROJECT eom)
PROJECT (${SUBPROJECT})




FIND_PACKAGE(Qt5Core)

IF (NOT Qt5Core_FOUND)
  MESSAGE(FATAL_ERROR "Qt4 not found" )
ENDIF (NOT Qt5Core_FOUND)


SET (HEADERS
    exceptions/ebaseexception.h
    logger/logger.h
    fstools/fstools.h
    stringutils/stringutils.h
    iterators/javastyleiterator.h

)

SET (SOURCES
    exceptions/ebaseexception.cpp
    logger/logger_qt4.cpp
    fstools/fstools.cpp
)



SET (GENERATED_SOURCES 
    ${BUILDINFO_H} ${BUILDINFO_CPP}
)


SOURCE_GROUP ("Header Files" FILES ${HEADERS})
SOURCE_GROUP ("Source Files" FILES ${SOURCES})
SOURCE_GROUP ("Generated Files" FILES ${MOC_SOURCES})


ADD_LIBRARY(${SUBPROJECT}  ${HEADERS} ${SOURCES}   )

IF (USE_QT)                                                                                                         
	Qt5_USE_MODULES(${SUBPROJECT} Core)
  TARGET_COMPILE_DEFINITIONS(${SUBPROJECT} PUBLIC -DUSE_QT4=1)
                 
ENDIF (USE_QT)

IF (WIN32)
	#INCLUDE(GenerateExportHeader) 
	#GENERATE_EXPORT_HEADER(${SUBPROJECT})

ENDIF(WIN32)


