#-------------------------------------------------
#
# Project created by QtCreator 2019-08-26T10:13:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DepartmentMangagement
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

CONFIG += c++11

SOURCES += \
        datatype.cpp \
        dialog_definejob.cpp \
        dialog_deletedepart.cpp \
        dialog_failalert.cpp \
        dialog_insertdepart.cpp \
        dialog_insertdepartnew.cpp \
        dialog_insertstaff.cpp \
        dialog_searchjob.cpp \
        dialog_showdepart.cpp \
        dialog_showstaff.cpp \
        dialog_successalert.cpp \
        form_showdepart.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        alert.h \
        datatype.h \
        dialog_definejob.h \
        dialog_deletedepart.h \
        dialog_failalert.h \
        dialog_insertdepart.h \
        dialog_insertdepartnew.h \
        dialog_insertstaff.h \
        dialog_searchjob.h \
        dialog_showdepart.h \
        dialog_showstaff.h \
        dialog_successalert.h \
        form_showdepart.h \
        mainwindow.h

FORMS += \
        dialog_definejob.ui \
        dialog_deletedepart.ui \
        dialog_failalert.ui \
        dialog_insertdepart.ui \
        dialog_insertdepartnew.ui \
        dialog_insertstaff.ui \
        dialog_searchjob.ui \
        dialog_showdepart.ui \
        dialog_showstaff.ui \
        dialog_successalert.ui \
        form_showdepart.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    C:/Users/HP/Pictures/IconImage/icon2.png

RC_FILE += icon2.rc

