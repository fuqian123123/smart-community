#-------------------------------------------------
#
# Project created by QtCreator 2019-01-16T17:50:48
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smart-community
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    sqlmanager.cpp \
    base_add_widget.cpp \
    base_manage_widget.cpp \
    login_dialog.cpp \
    manager_form.cpp \
    manager_renyuan_add_widget.cpp \
    manager_renyuan_manage_widget.cpp

HEADERS  += \
    sqlmanager.h \
    base_add_widget.h \
    base_manage_widget.h \
    login_dialog.h \
    manager_form.h \
    manager_renyuan_add_widget.h \
    manager_renyuan_manage_widget.h

FORMS    += \
    logindialog.ui
