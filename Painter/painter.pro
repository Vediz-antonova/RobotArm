QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduinocommunicator.cpp \
    circle.cpp \
    figure.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    rhombus.cpp \
    square.cpp \
    triangle.cpp

HEADERS += \
    arduinocommunicator.h \
    circle.h \
    figure.h \
    line.h \
    mainwindow.h \
    rectangle.h \
    rhombus.h \
    square.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
