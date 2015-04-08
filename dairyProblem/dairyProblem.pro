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
    dataReader/CvrpDemand.cpp \
    dataReader/CvrpFile.cpp \
    dataReader/CvrpFilereader.cpp \
    dataReader/Vrp2dCoordinate.cpp \
    dataReader/VrpTokens.cpp \
    dataCoverter/DistanceMatrixConverter.cpp \
    dataReader/CvrpRawData.cpp \
    dataCoverter/CvrpDistanceMatrixData.cpp \
    algorithms/NearestNeighbourHeuristic.cpp

HEADERS  += \
    dataReader/IDataReader.h \
    dataReader/CvrpDemand.h \
    dataReader/CvrpFile.h \
    dataReader/CvrpFilereader.h \
    dataReader/Vrp2dCoordinate.h \
    dataReader/VrpTokens.h \
    dataCoverter/IDataCoverter.h \
    dataCoverter/ICvrpGraphData.h \
    dataCoverter/DistanceMatrixConverter.h \
    dataReader/CvrpRawData.h \
    dataCoverter/CvrpDistanceMatrixData.h \
    utilities/Matrix.h \
    algorithms/NearestNeighbourHeuristic.h
