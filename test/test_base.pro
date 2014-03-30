#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T10:52:17
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_test_basetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


INCLUDEPATH = ../../

SOURCES += tst_test_basetest.cpp \
    test_variant.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    test_variant.h

LIBS += -L/home/qaz/work/synopsys2/synopsis/build-base-Desktop-Debug
LIBS += -lsynopsisdao
