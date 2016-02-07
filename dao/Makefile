#############################################################################
# Makefile for building: libsynopsisdao.so.1.0.0
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       =
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I${ROOT_SYNOPSIS}
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/home/qaz/Qt5.0.0/5.0.0/gcc_64 -shared -Wl,-soname,libsynopsisdao.so.1
LIBS          = $(SUBLIBS) -L../out -lsynopsisbase -lpthread 
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

SOURCES       = cpp/dataaccessorutils.cpp 
OBJECTS       = dataaccessorutils.o
DIST          =
QMAKE_TARGET  = synopsisdao
DESTDIR       = ../out/
TARGET        = libsynopsisdao.so.1.0.0
TARGETA       = ../out/libsynopsisdao.a
TARGETD       = libsynopsisdao.so.1.0.0
TARGET0       = libsynopsisdao.so
TARGET1       = libsynopsisdao.so.1
TARGET2       = libsynopsisdao.so.1.0


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

all: ../out/$(TARGET)

../out/$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@test -d ../out/ || $(MKDIR) ../out/ 
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) ../out/$(TARGET)
	-$(DEL_FILE) ../out/$(TARGET0)
	-$(DEL_FILE) ../out/$(TARGET1)
	-$(DEL_FILE) ../out/$(TARGET2)
	-$(MOVE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) ../out/



staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP) 
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)

dist: 
	@test -d .tmp/synopsisdao1.0.0 || $(MKDIR) .tmp/synopsisdao1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/synopsisdao1.0.0/ && (cd `dirname .tmp/synopsisdao1.0.0` && $(TAR) synopsisdao1.0.0.tar synopsisdao1.0.0 && $(COMPRESS) synopsisdao1.0.0.tar) && $(MOVE) `dirname .tmp/synopsisdao1.0.0`/synopsisdao1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/synopsisdao1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) ../out/$(TARGET) 
	-$(DEL_FILE) ../out/$(TARGET0) ../out/$(TARGET1) ../out/$(TARGET2) $(TARGETA)
	-$(DEL_FILE) Makefile


check: first

compiler_clean: 

####### Compile

dataaccessorutils.o: cpp/dataaccessorutils.cpp inc/dataaccessorutils.h \
		inc/daocommon.h \
		inc/row.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataaccessorutils.o cpp/dataaccessorutils.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

