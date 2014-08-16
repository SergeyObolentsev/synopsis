QT -= core gui
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}
DESTDIR = ${ROOT_SYNOPSIS}/out/
LIBS += -L${ROOT_SYNOPSIS}/out/

LIBS += \
    -lsynopsisbase \
    -lsynopsisdao \
    -lpq

TARGET = synopsisdaopostgres

HEADERS += \
    inc/connection_postgr.h \
    inc/dataaccessor_postgr.h

SOURCES += \
    cpp/connection_postgr.cpp \
    cpp/dataaccessor_postgr.cpp
