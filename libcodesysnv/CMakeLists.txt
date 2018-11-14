# -*- coding:utf-8 -*-
# -*- кодировка:utf-8 -*-

SET (SUBPROJECT codesysnv)
PROJECT (${SUBPROJECT})



FIND_PACKAGE(Qt5Core)

IF (NOT Qt5Core_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 core not found" )
ENDIF (NOT Qt5Core_FOUND)

FIND_PACKAGE(Qt5Network)

IF (NOT Qt5Network_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 network not found" )
ENDIF (NOT Qt5Network_FOUND)


FIND_PACKAGE(Qt5Xml)

IF (NOT Qt5Xml_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 xml not found" )
ENDIF (NOT Qt5Xml_FOUND)


FIND_PACKAGE(Boost COMPONENTS locale )  
IF (NOT Boost_FOUND)
  MESSAGE(FATAL_ERROR "Boost not found" )
ENDIF (NOT Boost_FOUND)



SET(MOC_HEADERS
    qcodesysnv.h
   
)
SET (HEADERS 
    codesysnvlistparser.h

)

SET (SOURCES
    qcodesysnv.cpp
    codesysnvlistparser.cpp
)



SET (GENERATED_SOURCES 
    ${BUILDINFO_H} ${BUILDINFO_CPP}
)

QT5_WRAP_CPP(MOC_SOURCES ${MOC_HEADERS})

SOURCE_GROUP ("Header Files" FILES ${HEADERS})
SOURCE_GROUP ("Source Files" FILES ${SOURCES})
SOURCE_GROUP ("Generated Files" FILES ${MOC_SOURCES})

IF (develop_flags)
    ADD_DEFINITIONS(-DDEVELOP_FLAGS=1)
ENDIF(develop_flags)

ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB)


ADD_LIBRARY(${SUBPROJECT} STATIC  ${HEADERS} ${SOURCES}  ${MOC_HEADERS}  ${MOC_SOURCES} )

TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT}  PUBLIC  ${FULL_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT}  PUBLIC ${FULL_SOURCE_DIR}/libiec61131parser/runtime)

TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT}  PUBLIC  ${Boost_INCLUDE_DIRS} )


IF (USE_QT)                                                                                                         
  Qt5_USE_MODULES(${SUBPROJECT} Core Network Xml)
  TARGET_COMPILE_DEFINITIONS(${SUBPROJECT} PUBLIC -DUSE_QT4=1)
                 
ENDIF (USE_QT)

IF (WIN32)
	#INCLUDE(GenerateExportHeader) 
	#GENERATE_EXPORT_HEADER(${SUBPROJECT})

ENDIF(WIN32)


