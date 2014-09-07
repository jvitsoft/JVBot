# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = JVBotClient
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += JVAreaSelector.cpp JVBotClient.cpp JVBotClientUI.cpp JVRenderArea.cpp JVViewer.cpp main.cpp
HEADERS += JVAreaSelector.h JVBotClient.h JVBotClientUI.h JVRenderArea.h JVViewer.h
FORMS += JVBotClientUI.ui JVViewer.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += . /opt/ros/indigo/include /home/vrs/Qt5.0.2/5.0.2/gcc/include /home/vrs/Qt5.0.2/5.0.2/gcc/include/QtCore 
LIBS += 
