QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game_window.cpp \
    specifications_player.cpp \
    src/create_parameters.cpp \
    src/creature/player.cpp \
    src/creature/creature.cpp \
    src/window/character_creation_menu.cpp \
    configuration.cpp \  #---
    src/window/loading.cpp \
    src/window/main.cpp \
    src/window/settings.cpp \
    src/window/main_menu.cpp \
    src/widget_info.cpp

HEADERS += \
    game_window.h \
    include/create_parameters.h \
    include/creature/creature.h \
    include/window/character_creation_menu.h \
    configuration.h \  #---
    include/window/main_menu.h \
    include/window/settings.h \
    include/window/loading.h \
    include/creature/player.h \
    include/widget_info.h \
    specifications_player.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icon_window.qrc \
    pixmap.qrc
