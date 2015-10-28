#-------------------------------------------------
#
# Project created by QtCreator 2015-10-20T16:04:25
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Household
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    data.cpp \
    household.cpp \
    transaction.cpp

HEADERS  += mainwindow.h \
    login.h \
    data.h \
    idata.h \
    household.h \
    transaction.h

FORMS    += mainwindow.ui \
    login.ui

DISTFILES += \
    HouseholdDB
