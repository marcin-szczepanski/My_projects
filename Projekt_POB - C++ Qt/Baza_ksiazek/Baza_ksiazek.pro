#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T10:36:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Baza_ksiazek
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ksiazka.cpp \
    papierowa.cpp \
    ebook.cpp \
    audiobook.cpp \
    tabela.cpp

HEADERS  += mainwindow.h \
    ksiazka.h \
    papierowa.h \
    ebook.h \
    audiobook.h \
    tabela.h

FORMS    += mainwindow.ui
