QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assets_inspect.cpp \
    confirmbox.cpp \
    db_connection.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    manager_mainwindow.cpp \
    manager_view.cpp \
    okbox.cpp \
    textreplacerdelegate.cpp \
    user_view.cpp

HEADERS += \
    assets_inspect.h \
    confirmbox.h \
    db_connection.h \
    login.h \
    mainwindow.h \
    manager_mainwindow.h \
    manager_view.h \
    okbox.h \
    textreplacerdelegate.h \
    user_view.h

FORMS += \
    assets_inspect.ui \
    confirmbox.ui \
    manager_view.ui \
    user_view.ui \
    login.ui \
    mainwindow.ui \
    manager_mainwindow.ui \
    okbox.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sources.qrc
