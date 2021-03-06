#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/JVBotServer
# Generated by qmake (2.01a) (Qt 4.8.4) on: Wed Aug 27 22:26:00 2014
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/lib/i386-linux-gnu/qt4/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Inbproject -I../../Qt5.0.2/5.0.2/gcc/include -I/opt/ros/indigo/include -I../../Qt5.0.2/5.0.2/gcc/include/QtCore -I. -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/i386-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
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

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = JVANN.cpp \
		JVAlgorithm.cpp \
		JVAlgorithmBinarize.cpp \
		JVAlgorithmBlobs.cpp \
		JVAlgorithmGrayscale.cpp \
		JVAlgorithmResize.cpp \
		JVBot.cpp \
		JVBotDemo.cpp \
		JVBotManager.cpp \
		JVBotServer.cpp \
		JVBotServerUI.cpp \
		JVDataDetected.cpp \
		JVImage.cpp \
		JVImageManager.cpp \
		JVImageProcessor.cpp \
		JVImageScanner.cpp \
		JVInputGenerator.cpp \
		JVInputGeneratorHOG.cpp \
		JVRenderArea.cpp \
		JVScreenCapturer.cpp \
		JVTrainer.cpp \
		JVTrainerCombination.cpp \
		JVTrainingSetData.cpp \
		JVTrainingSetGenerator.cpp \
		main.cpp moc_JVBot.cpp \
		moc_JVBotDemo.cpp \
		moc_JVBotManager.cpp \
		moc_JVBotServer.cpp \
		moc_JVBotServerUI.cpp \
		moc_JVRenderArea.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/JVANN.o \
		build/Debug/GNU-Linux-x86/JVAlgorithm.o \
		build/Debug/GNU-Linux-x86/JVAlgorithmBinarize.o \
		build/Debug/GNU-Linux-x86/JVAlgorithmBlobs.o \
		build/Debug/GNU-Linux-x86/JVAlgorithmGrayscale.o \
		build/Debug/GNU-Linux-x86/JVAlgorithmResize.o \
		build/Debug/GNU-Linux-x86/JVBot.o \
		build/Debug/GNU-Linux-x86/JVBotDemo.o \
		build/Debug/GNU-Linux-x86/JVBotManager.o \
		build/Debug/GNU-Linux-x86/JVBotServer.o \
		build/Debug/GNU-Linux-x86/JVBotServerUI.o \
		build/Debug/GNU-Linux-x86/JVDataDetected.o \
		build/Debug/GNU-Linux-x86/JVImage.o \
		build/Debug/GNU-Linux-x86/JVImageManager.o \
		build/Debug/GNU-Linux-x86/JVImageProcessor.o \
		build/Debug/GNU-Linux-x86/JVImageScanner.o \
		build/Debug/GNU-Linux-x86/JVInputGenerator.o \
		build/Debug/GNU-Linux-x86/JVInputGeneratorHOG.o \
		build/Debug/GNU-Linux-x86/JVRenderArea.o \
		build/Debug/GNU-Linux-x86/JVScreenCapturer.o \
		build/Debug/GNU-Linux-x86/JVTrainer.o \
		build/Debug/GNU-Linux-x86/JVTrainerCombination.o \
		build/Debug/GNU-Linux-x86/JVTrainingSetData.o \
		build/Debug/GNU-Linux-x86/JVTrainingSetGenerator.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/moc_JVBot.o \
		build/Debug/GNU-Linux-x86/moc_JVBotDemo.o \
		build/Debug/GNU-Linux-x86/moc_JVBotManager.o \
		build/Debug/GNU-Linux-x86/moc_JVBotServer.o \
		build/Debug/GNU-Linux-x86/moc_JVBotServerUI.o \
		build/Debug/GNU-Linux-x86/moc_JVRenderArea.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = JVBotServer
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/JVBotServer

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

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_JVBotServerUI.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux-x86/JVBotServer1.0.0 || $(MKDIR) build/Debug/GNU-Linux-x86/JVBotServer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux-x86/JVBotServer1.0.0/ && $(COPY_FILE) --parents JVANN.h JVAlgorithm.h JVAlgorithmBinarize.h JVAlgorithmBlobs.h JVAlgorithmGrayscale.h JVAlgorithmResize.h JVBot.h JVBotDemo.h JVBotManager.h JVBotServer.h JVBotServerUI.h JVDataDetected.h JVImage.h JVImageManager.h JVImageProcessor.h JVImageScanner.h JVInputGenerator.h JVInputGeneratorHOG.h JVRenderArea.h JVScreenCapturer.h JVTrainer.h JVTrainerCombination.h JVTrainingSetData.h JVTrainingSetGenerator.h build/Debug/GNU-Linux-x86/JVBotServer1.0.0/ && $(COPY_FILE) --parents JVANN.cpp JVAlgorithm.cpp JVAlgorithmBinarize.cpp JVAlgorithmBlobs.cpp JVAlgorithmGrayscale.cpp JVAlgorithmResize.cpp JVBot.cpp JVBotDemo.cpp JVBotManager.cpp JVBotServer.cpp JVBotServerUI.cpp JVDataDetected.cpp JVImage.cpp JVImageManager.cpp JVImageProcessor.cpp JVImageScanner.cpp JVInputGenerator.cpp JVInputGeneratorHOG.cpp JVRenderArea.cpp JVScreenCapturer.cpp JVTrainer.cpp JVTrainerCombination.cpp JVTrainingSetData.cpp JVTrainingSetGenerator.cpp main.cpp build/Debug/GNU-Linux-x86/JVBotServer1.0.0/ && $(COPY_FILE) --parents JVBotServerUI.ui build/Debug/GNU-Linux-x86/JVBotServer1.0.0/ && (cd `dirname build/Debug/GNU-Linux-x86/JVBotServer1.0.0` && $(TAR) JVBotServer1.0.0.tar JVBotServer1.0.0 && $(COMPRESS) JVBotServer1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux-x86/JVBotServer1.0.0`/JVBotServer1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux-x86/JVBotServer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_JVBot.cpp moc_JVBotDemo.cpp moc_JVBotManager.cpp moc_JVBotServer.cpp moc_JVBotServerUI.cpp moc_JVRenderArea.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_JVBot.cpp moc_JVBotDemo.cpp moc_JVBotManager.cpp moc_JVBotServer.cpp moc_JVBotServerUI.cpp moc_JVRenderArea.cpp
moc_JVBot.cpp: JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBot.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVBot.h -o moc_JVBot.cpp

moc_JVBotDemo.cpp: JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBotDemo.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVBotDemo.h -o moc_JVBotDemo.cpp

moc_JVBotManager.cpp: JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBotManager.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVBotManager.h -o moc_JVBotManager.cpp

moc_JVBotServer.cpp: JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBotServer.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVBotServer.h -o moc_JVBotServer.cpp

moc_JVBotServerUI.cpp: ui_JVBotServerUI.h \
		JVRenderArea.h \
		JVDataDetected.h \
		JVBotServerUI.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVBotServerUI.h -o moc_JVBotServerUI.cpp

moc_JVRenderArea.cpp: JVRenderArea.h
	/usr/lib/i386-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) JVRenderArea.h -o moc_JVRenderArea.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_JVBotServerUI.h
compiler_uic_clean:
	-$(DEL_FILE) ui_JVBotServerUI.h
ui_JVBotServerUI.h: JVBotServerUI.ui
	/usr/lib/i386-linux-gnu/qt4/bin/uic JVBotServerUI.ui -o ui_JVBotServerUI.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/JVANN.o: JVANN.cpp JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVInputGeneratorHOG.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVANN.o JVANN.cpp

build/Debug/GNU-Linux-x86/JVAlgorithm.o: JVAlgorithm.cpp JVAlgorithm.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVAlgorithm.o JVAlgorithm.cpp

build/Debug/GNU-Linux-x86/JVAlgorithmBinarize.o: JVAlgorithmBinarize.cpp JVAlgorithmBinarize.h \
		JVAlgorithm.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVAlgorithmBinarize.o JVAlgorithmBinarize.cpp

build/Debug/GNU-Linux-x86/JVAlgorithmBlobs.o: JVAlgorithmBlobs.cpp JVAlgorithmBlobs.h \
		JVAlgorithm.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVAlgorithmBlobs.o JVAlgorithmBlobs.cpp

build/Debug/GNU-Linux-x86/JVAlgorithmGrayscale.o: JVAlgorithmGrayscale.cpp JVAlgorithmGrayscale.h \
		JVAlgorithm.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVAlgorithmGrayscale.o JVAlgorithmGrayscale.cpp

build/Debug/GNU-Linux-x86/JVAlgorithmResize.o: JVAlgorithmResize.cpp JVAlgorithmResize.h \
		JVAlgorithm.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVAlgorithmResize.o JVAlgorithmResize.cpp

build/Debug/GNU-Linux-x86/JVBot.o: JVBot.cpp JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVTrainingSetGenerator.h \
		JVScreenCapturer.h \
		JVBotServer.h \
		JVBotManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVBot.o JVBot.cpp

build/Debug/GNU-Linux-x86/JVBotDemo.o: JVBotDemo.cpp JVBotDemo.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVBotDemo.o JVBotDemo.cpp

build/Debug/GNU-Linux-x86/JVBotManager.o: JVBotManager.cpp JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBotDemo.h \
		JVBotServer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVBotManager.o JVBotManager.cpp

build/Debug/GNU-Linux-x86/JVBotServer.o: JVBotServer.cpp JVBotServer.h \
		JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVScreenCapturer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVBotServer.o JVBotServer.cpp

build/Debug/GNU-Linux-x86/JVBotServerUI.o: JVBotServerUI.cpp JVBotServer.h \
		JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h \
		JVDataDetected.h \
		JVBotServerUI.h \
		ui_JVBotServerUI.h \
		JVRenderArea.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVBotServerUI.o JVBotServerUI.cpp

build/Debug/GNU-Linux-x86/JVDataDetected.o: JVDataDetected.cpp JVDataDetected.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVDataDetected.o JVDataDetected.cpp

build/Debug/GNU-Linux-x86/JVImage.o: JVImage.cpp JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVImage.o JVImage.cpp

build/Debug/GNU-Linux-x86/JVImageManager.o: JVImageManager.cpp JVImageManager.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVImageManager.o JVImageManager.cpp

build/Debug/GNU-Linux-x86/JVImageProcessor.o: JVImageProcessor.cpp JVImageProcessor.h \
		JVImage.h \
		JVAlgorithm.h \
		JVAlgorithmBinarize.h \
		JVAlgorithmGrayscale.h \
		JVAlgorithmBlobs.h \
		JVAlgorithmResize.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVImageProcessor.o JVImageProcessor.cpp

build/Debug/GNU-Linux-x86/JVImageScanner.o: JVImageScanner.cpp JVImageScanner.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVImageScanner.o JVImageScanner.cpp

build/Debug/GNU-Linux-x86/JVInputGenerator.o: JVInputGenerator.cpp JVInputGenerator.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVInputGenerator.o JVInputGenerator.cpp

build/Debug/GNU-Linux-x86/JVInputGeneratorHOG.o: JVInputGeneratorHOG.cpp JVInputGeneratorHOG.h \
		JVInputGenerator.h \
		JVImage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVInputGeneratorHOG.o JVInputGeneratorHOG.cpp

build/Debug/GNU-Linux-x86/JVRenderArea.o: JVRenderArea.cpp JVRenderArea.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVRenderArea.o JVRenderArea.cpp

build/Debug/GNU-Linux-x86/JVScreenCapturer.o: JVScreenCapturer.cpp JVScreenCapturer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVScreenCapturer.o JVScreenCapturer.cpp

build/Debug/GNU-Linux-x86/JVTrainer.o: JVTrainer.cpp JVTrainer.h \
		JVTrainerCombination.h \
		JVBotServer.h \
		JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVDataDetected.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVTrainer.o JVTrainer.cpp

build/Debug/GNU-Linux-x86/JVTrainerCombination.o: JVTrainerCombination.cpp JVTrainerCombination.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVTrainerCombination.o JVTrainerCombination.cpp

build/Debug/GNU-Linux-x86/JVTrainingSetData.o: JVTrainingSetData.cpp JVTrainingSetData.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVTrainingSetData.o JVTrainingSetData.cpp

build/Debug/GNU-Linux-x86/JVTrainingSetGenerator.o: JVTrainingSetGenerator.cpp JVTrainingSetGenerator.h \
		JVTrainingSetData.h \
		JVImageScanner.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/JVTrainingSetGenerator.o JVTrainingSetGenerator.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp JVBotServerUI.h \
		ui_JVBotServerUI.h \
		JVRenderArea.h \
		JVDataDetected.h \
		JVBotServer.h \
		JVBotManager.h \
		JVBot.h \
		JVANN.h \
		JVInputGenerator.h \
		JVImage.h \
		JVImageManager.h \
		JVImageProcessor.h \
		JVAlgorithm.h \
		JVTrainingSetData.h \
		JVTrainer.h \
		JVTrainerCombination.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/moc_JVBot.o: moc_JVBot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVBot.o moc_JVBot.cpp

build/Debug/GNU-Linux-x86/moc_JVBotDemo.o: moc_JVBotDemo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVBotDemo.o moc_JVBotDemo.cpp

build/Debug/GNU-Linux-x86/moc_JVBotManager.o: moc_JVBotManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVBotManager.o moc_JVBotManager.cpp

build/Debug/GNU-Linux-x86/moc_JVBotServer.o: moc_JVBotServer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVBotServer.o moc_JVBotServer.cpp

build/Debug/GNU-Linux-x86/moc_JVBotServerUI.o: moc_JVBotServerUI.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVBotServerUI.o moc_JVBotServerUI.cpp

build/Debug/GNU-Linux-x86/moc_JVRenderArea.o: moc_JVRenderArea.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_JVRenderArea.o moc_JVRenderArea.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

