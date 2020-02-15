TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CSckFactoryImpl.cpp \
    HwEncDes.cpp \
    MainOP.cpp

HEADERS += \
    CSocketProtocol.h \
    CSckFactoryImpl.h \
    CEncDesProtocol.h \
    HwEncDes.h \
    MainOP.h
