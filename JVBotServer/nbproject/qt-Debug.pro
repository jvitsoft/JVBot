# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = JVBotServer
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += JVANN.cpp JVAlgorithm.cpp JVAlgorithmBinarize.cpp JVAlgorithmBlobs.cpp JVAlgorithmGrayscale.cpp JVAlgorithmResize.cpp JVBot.cpp JVBotDemo.cpp JVBotManager.cpp JVBotServer.cpp JVBotServerUI.cpp JVDataDetected.cpp JVImage.cpp JVImageManager.cpp JVImageProcessor.cpp JVImageScanner.cpp JVInputGenerator.cpp JVInputGeneratorHOG.cpp JVRenderArea.cpp JVScreenCapturer.cpp JVTrainer.cpp JVTrainerCombination.cpp JVTrainingSetData.cpp JVTrainingSetGenerator.cpp main.cpp
HEADERS += JVANN.h JVAlgorithm.h JVAlgorithmBinarize.h JVAlgorithmBlobs.h JVAlgorithmGrayscale.h JVAlgorithmResize.h JVBot.h JVBotDemo.h JVBotManager.h JVBotServer.h JVBotServerUI.h JVDataDetected.h JVImage.h JVImageManager.h JVImageProcessor.h JVImageScanner.h JVInputGenerator.h JVInputGeneratorHOG.h JVRenderArea.h JVScreenCapturer.h JVTrainer.h JVTrainerCombination.h JVTrainingSetData.h JVTrainingSetGenerator.h
FORMS += JVBotServerUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += . /home/vrs/Qt5.0.2/5.0.2/gcc/include /opt/ros/indigo/include /home/vrs/Qt5.0.2/5.0.2/gcc/include/QtCore 
LIBS += 
