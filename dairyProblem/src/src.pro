include(../defaults.pri)

TEMPLATE = lib

TARGET = dairyProblem

QT += core gui

QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    dataReader/CvrpDemand.cpp \
    dataReader/CvrpFile.cpp \
    dataReader/CvrpFilereader.cpp \
    dataReader/Vrp2dCoordinate.cpp \
    dataReader/VrpTokens.cpp \
    dataReader/CvrpRawData.cpp \
    dataConverter/DistanceMatrixConverter.cpp \
    dataConverter/CvrpDistanceMatrixData.cpp \
    algorithms/NearestNeighbourHeuristic.cpp

HEADERS  += \
    dataReader/IDataReader.h \
    dataReader/CvrpDemand.h \
    dataReader/CvrpFile.h \
    dataReader/CvrpFilereader.h \
    dataReader/Vrp2dCoordinate.h \
    dataReader/VrpTokens.h \
    dataReader/CvrpRawData.h \
    dataConverter/IDataCoverter.h \
    dataConverter/ICvrpGraphData.h \
    dataConverter/DistanceMatrixConverter.h \
    dataConverter/CvrpDistanceMatrixData.h \
    utilities/Matrix.h \
    algorithms/NearestNeighbourHeuristic.h
