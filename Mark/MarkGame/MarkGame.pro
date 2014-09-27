#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T15:08:41
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MarkGame
TEMPLATE = app


SOURCES += main.cpp\
        markgame.cpp \
    mainwindow.cpp \
    menu.cpp

HEADERS  += markgame.h \
    score.h \
    MovableGraphicsPixmapItem.h \
    MarkgamePrivate.h \
    mainwindow.h \
    menu.h

RESOURCES += \
    markgame.qrc

OTHER_FILES +=
