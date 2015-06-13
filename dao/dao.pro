QT -= core gui
TARGET = synopsisdao
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}

DESTDIR = ../out

LIBS += -L../out
LIBS += -lsynopsisbase

HEADERS += \
    inc/row.h \
    inc/idataaccessor.h \
    inc/dataaccessorutils.h \
    inc/iconnection.h \
    inc/daocommon.h

SOURCES += \
    cpp/dataaccessorutils.cpp \
    cpp/dataaccessorbase.cpp
