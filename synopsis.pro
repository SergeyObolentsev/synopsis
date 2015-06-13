TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS  = \
    base \
    dao \
    dao/drivers/postgres \
    dao/facade \
    test
