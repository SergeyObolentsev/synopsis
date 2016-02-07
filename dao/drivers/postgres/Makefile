#############################################################################
# Makefile for building: libsynopsisdaopostgres.so.1.0.0
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       =
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I../../../../../Qt5.0.0/5.0.0/gcc_64/mkspecs/linux-g++-64 -I. -I${ROOT_SYNOPSIS}
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/home/qaz/Qt5.0.0/5.0.0/gcc_64 -shared -Wl,-soname,libsynopsisdaopostgres.so.1
LIBS          = $(SUBLIBS) -L${ROOT_SYNOPSIS}/out/ -lsynopsisbase -lsynopsisdao -lpq -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         =
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = cpp/connection_postgr.cpp \
		cpp/dataaccessor_postgr.cpp 
OBJECTS       = connection_postgr.o \
		dataaccessor_postgr.o
DIST          =
QMAKE_TARGET  = synopsisdaopostgres
DESTDIR       = ${ROOT_SYNOPSIS}/out/
TARGET        = libsynopsisdaopostgres.so.1.0.0
TARGETA       = ${ROOT_SYNOPSIS}/out/libsynopsisdaopostgres.a
TARGETD       = libsynopsisdaopostgres.so.1.0.0
TARGET0       = libsynopsisdaopostgres.so
TARGET1       = libsynopsisdaopostgres.so.1
TARGET2       = libsynopsisdaopostgres.so.1.0


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: ${ROOT_SYNOPSIS}/out/$(TARGET)

${ROOT_SYNOPSIS}/out/$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@test -d ${ROOT_SYNOPSIS}/out/ || $(MKDIR) ${ROOT_SYNOPSIS}/out/ 
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET)
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET0)
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET1)
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET2)
	-$(MOVE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) ${ROOT_SYNOPSIS}/out/



staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP) 
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)


dist: 
	@test -d .tmp/synopsisdaopostgres1.0.0 || $(MKDIR) .tmp/synopsisdaopostgres1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/synopsisdaopostgres1.0.0/ && (cd `dirname .tmp/synopsisdaopostgres1.0.0` && $(TAR) synopsisdaopostgres1.0.0.tar synopsisdaopostgres1.0.0 && $(COMPRESS) synopsisdaopostgres1.0.0.tar) && $(MOVE) `dirname .tmp/synopsisdaopostgres1.0.0`/synopsisdaopostgres1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/synopsisdaopostgres1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET) 
	-$(DEL_FILE) ${ROOT_SYNOPSIS}/out/$(TARGET0) ${ROOT_SYNOPSIS}/out/$(TARGET1) ${ROOT_SYNOPSIS}/out/$(TARGET2) $(TARGETA)
	-$(DEL_FILE) Makefile


check: first

compiler_clean: 

####### Compile

connection_postgr.o: cpp/connection_postgr.cpp inc/connection_postgr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o connection_postgr.o cpp/connection_postgr.cpp

dataaccessor_postgr.o: cpp/dataaccessor_postgr.cpp inc/dataaccessor_postgr.h \
		inc/connection_postgr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataaccessor_postgr.o cpp/dataaccessor_postgr.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

