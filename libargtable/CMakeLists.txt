# for now, install in subdirectory of source directory by default
SET (SUBPROJECT argtable)
PROJECT (${SUBPROJECT})


ADD_DEFINITIONS(-DHAVE_STDLIB_H -DSTDC_HEADERS -DHAVE_STRING_H)


ADD_LIBRARY( ${SUBPROJECT}  STATIC arg_dbl.c arg_end.c arg_file.c arg_int.c arg_lit.c arg_rem.c arg_str.c argtable2.c argtable2.h getopt.c getopt.h getopt1.c )

