#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T10:52:17
#
#-------------------------------------------------

QT -= gui
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}
DESTDIR = ${ROOT_SYNOPSIS}/out/
LIBS += -L${ROOT_SYNOPSIS}/out/

LIBS += \
    -lsynopsisbase \
    -lsynopsisdao \
    -lsynopsisdaopostgres \
    -lsynopsisdaofacade

QT       += testlib

TARGET = tst_test_basetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_test_basetest.cpp \
    test_variant.cpp \
    test_row.cpp \
    test_dataaccessutils.cpp \
    test_daopostgres.cpp \
    test_facade.cpp


HEADERS += \
    test_variant.h \
    test_row.h \
    qtmeta.h \
    test_dataaccessutils.h \
    test_daopostgres.h \
    test_facade.h

