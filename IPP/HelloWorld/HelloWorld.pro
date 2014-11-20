#-------------------------------------------------
#
# Project created by QtCreator 2014-11-15T20:06:11
#
#-------------------------------------------------

QT       += core

QT       -= gui



TARGET = HelloWorld
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp




HEADERS += \
    ../../../../../../"Program Files (x86)"/Intel/"Composer XE 2015"/ipp/include/ippcore.h


unix|win32: LIBS += -L$$PWD/../../../../../../"Program Files (x86)"/Intel/"Composer XE 2015"/ipp/lib/ia32/ -lippcore

INCLUDEPATH += $$PWD/../../../../../../Program Files (x86)/Intel/Composer XE 2015/ipp/include
DEPENDPATH += $$PWD/../../../../../../Program Files (x86)/Intel/Composer XE 2015/ipp/include
