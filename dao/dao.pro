QT -= core gui
TARGET = synopsisdao
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}

HEADERS += \
    inc/row.h \
    inc/idataaccessor.h \
    inc/dataaccessorbase.h \
    inc/dataaccessorutils.h

DESTDIR = ../out

LIBS += -L../out
LIBS += -lsynopsisbase

SOURCES += \
    cpp/dataaccessorutils.cpp \
    cpp/dataaccessorbase.cpp

