CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(qipv4editplugin)
TEMPLATE    = lib

HEADERS     = qipv4editplugin.h
SOURCES     = qipv4editplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(qipv4edit.pri)
