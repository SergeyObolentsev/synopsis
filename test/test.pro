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


INCLUDEPATH = ${ROOT_SYNOPSIS}

SOURCES += \
    tst_test_basetest.cpp \
    test_variant.cpp \
    test_row.cpp


HEADERS += \
    test_variant.h \
    test_row.h \
    qtmeta.h

DESTDIR = ../out

LIBS += -L../out
LIBS += \
    -lsynopsisbase \
    -lsynopsisdao
