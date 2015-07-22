QT -= core gui
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}
DESTDIR = ${ROOT_SYNOPSIS}/out/

TARGET = synopsisbase

HEADERS += \
inc/column.h \
inc/field.h \
inc/variant.h \
inc/defines.h \
inc/stl_helper_map.h

SOURCES += \
cpp/variant.cpp

OTHER_FILES += \
    ../install.sh


