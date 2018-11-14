

FUNCTION(GET_HELP_MESSAGE _out)

SET (${_out}
"Usage:
  cmake -DINFO_H_IN=<input_config_file>  -DHG_EXECUTABLE=<optional path to hg for revision info determination> -DHG_ENCONDING=<encoding for hg> -P BuildTimeConfigModule.cmake

"

PARENT_SCOPE
)

ENDFUNCTION()





FUNCTION (BUILD_TIME_CONFIG_MODULE_MAIN)


IF (NOT INFO_H_IN)
  MESSAGE("Attribute INFO_H_IN doesnt set")
  GET_HELP_MESSAGE(OUT1)
  MESSAGE(${OUT1})
  MESSAGE(FATAL_ERROR "exiting")
 ENDIF(NOT INFO_H_IN)

GET_FILENAME_COMPONENT(INFO_H_IN_DIR "${INFO_H_IN}" DIRECTORY )

SET (buildTime )
STRING (TIMESTAMP buildTime "%d-%m-%Y %H:%M" )
SET (revision "undefined")

IF (HG_EXECUTABLE)
 IF (NOT HG_ENCODING)
	SET (HG_ENCODING cp1251)
 ENDIF(NOT HG_ENCODING)
 
 EXECUTE_PROCESS (COMMAND ${HG_EXECUTABLE} log -l3 --follow --encoding=${HG_ENCODING} --template "changeset {rev}:{node|short}\\\\\nuser:  {author}    date:{date|date}      summary:{desc|firstline}\\\\\n\\\\\n"  WORKING_DIRECTORY "${INFO_H_IN_DIR}" TIMEOUT 10 OUTPUT_VARIABLE revision_aux RESULT_VARIABLE result  ERROR_VARIABLE error )
 
 IF (result EQUAL 0 AND revision_aux)
  SET(revision ${revision_aux})
  #STRING  (MAKE_C_IDENTIFIER  ${revision_aux} revision)
 ENDIF (result EQUAL 0 AND revision_aux)
  
ENDIF(HG_EXECUTABLE)


CONFIGURE_FILE(${INFO_H_IN}  ${INFO_H_IN_DIR}/info.h ESCAPE_QUOTES)


ENDFUNCTION(BUILD_TIME_CONFIG_MODULE_MAIN)

BUILD_TIME_CONFIG_MODULE_MAIN ()

