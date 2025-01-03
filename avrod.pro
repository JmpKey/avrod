QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clearroutewin.cpp \
    controlwin.cpp \
    customsqltablemodel.cpp \
    euserwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    parsemodule.cpp \
    reportwin.cpp \
    reservwindow.cpp \
    ruserwindow.cpp

HEADERS += \
    clearroutewin.h \
    controlwin.h \
    customsqltablemodel.h \
    euserwindow.h \
    mainwindow.h \
    parsemodule.h \
    reportwin.h \
    reservwindow.h \
    ruserwindow.h

FORMS += \
    clearroutewin.ui \
    controlwin.ui \
    euserwindow.ui \
    mainwindow.ui \
    reportwin.ui \
    reservwindow.ui \
    ruserwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
