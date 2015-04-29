#-------------------------------------------------
#
# Project created by QtCreator 2015-02-22T21:42:18
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sydoky
TEMPLATE = app
RC_FILE = myicon.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    gen.cpp \
    counter.cpp \
    polewidget.cpp

HEADERS  += mainwindow.h \
    gen.h \
    counter.h \
    polewidget.h

FORMS    +=

OTHER_FILES += \
    myicon.ico \
    myicon.rc \
    setup.exe \
    release.rar \
    описание.doc
