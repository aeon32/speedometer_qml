SET (SUBPROJECT qr_code_test)
PROJECT (${SUBPROJECT})

IF (NOT PROJECT_WORKING_CHARSET)
 SET (PROJECT_WORKING_CHARSET "UTF8")
ENDIF(NOT PROJECT_WORKING_CHARSET)

CONFIGURE_FILE(localconfig.h.in "${${SUBPROJECT}_SOURCE_DIR}/localconfig.h" ESCAPE_QUOTES)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(MOC_HEADERS
   qrcodetestapp.h
   
)

SET (HEADERS
   localconfig.h
   settings/settings.h
   config.h

) 


SET (SOURCES
   qrcodetestapp.cpp
   main.cpp
   settings/settings.cpp

)



FIND_PACKAGE(Qt5Widgets)

IF (NOT Qt5Widgets_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 not found" )
ENDIF (NOT Qt5Widgets_FOUND)


FIND_PACKAGE(Qt5Network)

IF (NOT Qt5Network_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 not found" )
ENDIF (NOT Qt5Network_FOUND)

FIND_PACKAGE(Qt5Qml)

IF (NOT Qt5Qml_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 qml not found" )
ENDIF (NOT Qt5Qml_FOUND)

FIND_PACKAGE(Qt5Quick)

IF (NOT Qt5Quick_FOUND)
  MESSAGE(FATAL_ERROR "Qt5 not found" )
ENDIF (NOT Qt5Quick_FOUND)



SET (UI_SOURCES)


QT5_WRAP_CPP(MOC_SOURCES ${MOC_HEADERS})


SOURCE_GROUP ("Header Files" FILES ${HEADERS} ${MOC_HEADERS})
SOURCE_GROUP ("Source Files" FILES ${SOURCES})
SOURCE_GROUP ("Generated Files" FILES ${MOC_SOURCES} ${UI_SOURCES})




ADD_EXECUTABLE(${SUBPROJECT}  ${UI_HEADERS} ${HEADERS} ${MOC_HEADERS} ${SOURCES} ${MOC_SOURCES}  ${UI_SOURCES}   ${GENERATED_SOURCES}  )
TARGET_LINK_LIBRARIES (${SUBPROJECT}  eom qtquickauxitems)

Qt5_USE_MODULES(${SUBPROJECT} Widgets Network Qml Gui Quick)


TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT}  PUBLIC -DUSE_QT4=1 ${FULL_SOURCE_DIR})

TARGET_COMPILE_DEFINITIONS (${SUBPROJECT}  PUBLIC -DUSE_QT4=1)
TARGET_COMPILE_DEFINITIONS (${SUBPROJECT} PUBLIC -DUSE_QT4=1)

IF (develop_flags)
  TARGET_COMPILE_DEFINITIONS(${SUBPROJECT} PUBLIC -DDEVELOP_FLAGS=1)
ENDIF(develop_flags)

INSTALL(TARGETS ${SUBPROJECT} RUNTIME DESTINATION bin)





