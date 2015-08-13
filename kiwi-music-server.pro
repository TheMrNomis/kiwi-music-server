#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T17:21:45
#
#-------------------------------------------------

QT       += core \
            multimedia \
            sql

QT       -= gui

TARGET = kiwi-music-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Commander.cpp \
    BDD.cpp \
    Parameters.cpp

HEADERS += \
    Commander.h \
    BDD.h \
    Parameters.h

DISTFILES +=
