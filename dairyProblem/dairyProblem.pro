#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T12:59:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dairyProblem
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    vrpfilereader.cpp \
    cvrpfile.cpp \
    cvrpdata.cpp \
    vrp2dcoordinate.cpp \
    vrpdemand.cpp \
    vrptokens.cpp

HEADERS  += \
    vrpfilereader.h \
    cvrpfile.h \
    cvrpdata.h \
    vrp2dcoordinate.h \
    vrpdemand.h \
    vrptokens.h
