lessThan(QT_MAJOR_VERSION, 5): error(This project requires Qt 5 or later)

QT += core gui widgets quick

TARGET = widgetsandqml

SOURCES += main.cpp mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
