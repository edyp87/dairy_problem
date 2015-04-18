QT       -= gui

TARGET = tst_untitledtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lgtest -lgmock -pthread

SOURCES += main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
