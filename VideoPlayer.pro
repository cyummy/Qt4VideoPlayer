#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T17:18:32
#
#-------------------------------------------------

QT       += core gui
QT       += phonon

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    videolistdialog.cpp \
    videoplayerdialog.cpp \
    qtclickablelabel.cpp \
    myinputpanel.cpp \
    myinputpanelcontext.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    videolistdialog.h \
    videoplayerdialog.h \
    qtclickablelabel.h \
    myinputpanel.h \
    myinputpanelcontext.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    videolistdialog.ui \
    videoplayerdialog.ui \
    myinputpanelform.ui
