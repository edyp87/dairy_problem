#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T12:59:01
#
#-------------------------------------------------

TEMPLATE = subdirs

SUBDIRS = \
    src \
    app \
    data \
    tests


OTHER_FILES += \
    defaults.pri

app.depends = src
tests.depends = src
