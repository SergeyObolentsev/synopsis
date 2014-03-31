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

SOURCES += \
    tst_test_basetest.cpp \
    test_variant.cpp


HEADERS += \
    test_variant.h

OUT_PWD = ../out

LIBS += -L$$PWD/../base/out
LIBS += -lsynopsisdao
