include(../defaults.pri)

TEMPLATE = app
CONFIG   += app_bundle
TARGET = dairyProblem

QT += core gui

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp

LIBS += -L../src -ldairyProblem
