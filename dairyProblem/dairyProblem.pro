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
    cvrpfile.cpp \
    cvrpdata.cpp \
    vrp2dcoordinate.cpp \
    vrptokens.cpp \
    cvrpdemand.cpp \
    cvrpfilereader.cpp

HEADERS  += \
    cvrpfile.h \
    cvrpdata.h \
    vrp2dcoordinate.h \
    vrptokens.h \
    cvrpdemand.h \
    cvrpfilereader.h
