#-------------------------------------------------
#
# Project created by QtCreator 2018-08-11T16:10:55
#
#-------------------------------------------------

QT     += core
QT     -= gui
CONFIG += console
CONFIG -= app_bundle

LIBS += -lpthread libwsock32 libws2_32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Soft
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        USER\main.cpp \
        USER\mainwindow.cpp \
        TRADE\trade.cpp \
        DATA\data.cpp \
        STOCK\stock.cpp \
        WEB\web.cpp \
        KEYBOARD\keyboard.cpp \
        MOUSE\mouse.cpp \
        WINAPI\winapi.cpp

HEADERS += \
        USER\mainwindow.h \
        TRADE\trade.h \
        DATA\data.h \
        STOCK\stock.h \
        WEB\web.h \
        KEYBOARD\keyboard.h \
        MOUSE\mouse.h \
        WINAPI\winapi.h

FORMS += \
        USER\mainwindow.ui
