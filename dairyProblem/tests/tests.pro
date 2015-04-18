include(../defaults.pri)
QT       -= gui

TARGET = ut
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lgtest -lgmock -pthread
LIBS += -L../src -ldairyProblem

SOURCES += main.cpp \
    NearestNeighbourHeuristicUT.cpp \
    MatrixUT.cpp
