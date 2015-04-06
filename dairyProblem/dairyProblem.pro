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
    dataReader/cvrpdata.cpp \
    dataReader/cvrpdemand.cpp \
    dataReader/cvrpfile.cpp \
    dataReader/cvrpfilereader.cpp \
    dataReader/vrp2dcoordinate.cpp \
    dataReader/vrptokens.cpp

HEADERS  += \
    dataReader/cvrpdata.h \
    dataReader/cvrpdemand.h \
    dataReader/cvrpfile.h \
    dataReader/cvrpfilereader.h \
    dataReader/IDataReader.h \
    dataReader/vrp2dcoordinate.h \
    dataReader/vrptokens.h
