#-------------------------------------------------
#
# Project created by QtCreator 2019-10-21T23:08:10
#
#-------------------------------------------------

QT       -= gui

TARGET = untitled
TEMPLATE = lib

DEFINES += UNTITLED_LIBRARY

SOURCES += test_lib.cpp

HEADERS += test_lib.h\
        untitled_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
