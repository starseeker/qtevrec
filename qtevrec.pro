# -------------------------------------------------
# Project created by QtCreator 2011-02-24T13:07:33
# -------------------------------------------------
TARGET = qtevrec
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    canvaswidget.cpp \
    eventserialization.cpp \
    qinputeventrecorder.cpp \
    naiveserialization.cpp \
    eventserialization2.cpp
HEADERS += mainwindow.h \
    canvaswidget.h \
    eventserialization.h \
    qinputeventrecorder.h
FORMS += mainwindow.ui
LIBS += -lboost_serialization
