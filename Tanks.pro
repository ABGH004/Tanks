QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bricks.cpp \
    Bullet.cpp \
    Dialog.cpp \
    Forest.cpp \
    GridScene.cpp \
    Map.cpp \
    MovableBox.cpp \
    MovableBricks.cpp \
    MovableForest.cpp \
    NewMap.cpp \
    NewTank.cpp \
    Tank.cpp \
    View.cpp \
    main.cpp \
    mainwindow.cpp \
    myBox.cpp

HEADERS += \
    Bricks.h \
    Bullet.h \
    Dialog.h \
    Forest.h \
    GridScene.h \
    Map.h \
    MovableBox.h \
    MovableBricks.h \
    MovableForest.h \
    NewMap.h \
    NewTank.h \
    Tank.h \
    View.h \
    mainwindow.h \
    myBox.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

RC_ICONS = icon.ico
FORMS += \
    Dialog.ui \
    NewTank.ui \
    mainwindow.ui
