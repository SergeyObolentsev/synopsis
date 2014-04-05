QT       -= core gui
TARGET = synopsisdao
TEMPLATE = lib

HEADERS += \
    inc/row.h


INCLUDEPATH = ${ROOT_SYNOPSIS}

DESTDIR = ../out

LIBS += -L../out
LIBS += -lsynopsisbase

