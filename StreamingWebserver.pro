QT = core network

CONFIG += c++14
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS QT_DISABLE_DEPRECATED_BEFORE=0x060000

HEADERS += streamingwebserver.h

SOURCES += main.cpp \
           streamingwebserver.cpp

OTHER_FILES += .dockerignore \
               Dockerfile

include(QtWebserver/QtWebserver.pri)
