#!/bin/bash

export QT_LOGGING_RULES=*.debug=true
export QT_LOGGING_RULES=qt.multimedia.*=true 
#export  GST_DEBUG=3
#export  GST_DEBUG_DUMP_DOT_DIR=$PWD

./bin/autowash_qml