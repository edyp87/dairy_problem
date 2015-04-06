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
    dataCoverter/cvrpdata.cpp \
    dataCoverter/cvrpdemand.cpp \
    dataCoverter/cvrpfile.cpp \
    dataCoverter/cvrpfilereader.cpp \
    dataCoverter/vrp2dcoordinate.cpp \
    dataCoverter/vrptokens.cpp

HEADERS  += \
    dataCoverter/cvrpdata.h \
    dataCoverter/cvrpdemand.h \
    dataCoverter/cvrpfile.h \
    dataCoverter/cvrpfilereader.h \
    dataCoverter/IDataReader.h \
    dataCoverter/vrp2dcoordinate.h \
    dataCoverter/vrptokens.h
