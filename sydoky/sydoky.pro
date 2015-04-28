#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T21:42:18
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sydoky
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gen.cpp \
    counter.cpp \
    polewidget.cpp

HEADERS  += mainwindow.h \
    gen.h \
    counter.h \
    polewidget.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    red.png
