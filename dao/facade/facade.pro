QT -= core
TEMPLATE = lib

INCLUDEPATH += ${ROOT_SYNOPSIS}
DESTDIR = ${ROOT_SYNOPSIS}/out/
LIBS += -L${ROOT_SYNOPSIS}/out/


LIBS += \
    -lsynopsisbase \
    -lsynopsisdao \
    -lsynopsisdaopostgres  \

TARGET = synopsisdaofacade

HEADERS += \
    ids_drivers.h \
    dao_class_factory.h

SOURCES += \
    ids_drivers.cpp \
    dao_class_factory.cpp
