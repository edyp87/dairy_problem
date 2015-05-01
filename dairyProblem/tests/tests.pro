include(../defaults.pri)
QT       -= gui

TARGET = ut
CONFIG   += console warn_off
CONFIG   -= app_bundle
DEFINES += QT_NO_DEBUG QT_NO_WARNING_OUTPUT QT_NO_DEBUG_OUTPUT
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lgtest -lgmock -pthread
LIBS += -L../src -ldairyProblem

SOURCES += main.cpp \
    NearestNeighbourHeuristicUT.cpp \
    MatrixUT.cpp \
    CvrpFileReaderUT.cpp \
    PolarCoordinatesMatrixConverterUT.cpp

HEADERS += \
    Mocks/CvrpFileMock.h
