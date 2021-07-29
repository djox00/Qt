#-------------------------------------------------
#
# Project created by QtCreator 2021-07-03T12:49:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Finalni
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    proizvodjac.cpp \
    potrosac.cpp

HEADERS  += dialog.h \
    proizvodjac.h \
    potrosac.h \
    common.h \
    consts.h

FORMS    += dialog.ui

RESOURCES +=
