#-------------------------------------------------
#
# Project created by QtCreator 2020-03-28T10:08:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fkword
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += TIXML_USE_STL


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
        $$PWD/src/3rd/tinyxml \
        $$PWD/src/base \
        $$PWD/src/cmn \
        $$PWD/src/dbgc \
        $$PWD/src/youdao \
        $$PWD/src/fknow \

LIBS += \
#    -L$$PWD/lib/ -logdf -lcoin -lcrypt



#---------------------------------------------------
#
# Code for mainwindow
#
#---------------------------------------------------
FORMS += \
        mainwindow.ui

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \

HEADERS += \
        src/mainwindow.h \
        src/main.h


#---------------------------------------------------
#
# Code for src/3rd/tinyxml
#
#---------------------------------------------------
SOURCES += \
        src/3rd/tinyxml/tinystr.cpp \
        src/3rd/tinyxml/tinyxml.cpp \
        src/3rd/tinyxml/tinyxmlerror.cpp \
        src/3rd/tinyxml/tinyxmlparser.cpp \
        src/3rd/tinyxml/xmltest.cpp \


HEADERS += \
        src/3rd/tinyxml/tinystr.h \
        src/3rd/tinyxml/tinyxml.h \


#---------------------------------------------------
#
# Code for src/base
#
#---------------------------------------------------
SOURCES += \
        src/base/StyleMgr.cpp \
        src/base/WdGrpMgr.cpp \
        src/base/WordAttr.cpp \
        src/base/WordGroup.cpp \


HEADERS += \
        src/base/cppdbg11.cpp \
        src/base/StyleMgr.h \
        src/base/types.h \
        src/base/WdGrpMgr.h \
        src/base/WordAttr.h \
        src/base/WordGroup.h \


#---------------------------------------------------
#
# Code for src/cmn
#
#---------------------------------------------------
SOURCES += \
        src/cmn/cmnutil.cpp \
        src/cmn/dbapi.cpp \
        src/cmn/DbMgr.cpp \
        src/cmn/fdb.cpp \
        src/cmn/ftool.cpp \
        src/cmn/Thread.cpp \


HEADERS += \
        src/cmn/cmnutil.h \
        src/cmn/dbapi.h \
        src/cmn/DbMgr.h \
        src/cmn/fdb.h \
        src/cmn/ftool.h \
        src/cmn/Thread.h \

#---------------------------------------------------
#
# Code for src/dbgc
#
#---------------------------------------------------
SOURCES += \
#        src/dbgc/dbgc.cpp \
        src/dbgc/DbgComm.cpp \
        src/dbgc/DbgServer.cpp \
        src/dbgc/Trace.cpp \


HEADERS += \
        src/dbgc/DbgComm.h \
        src/dbgc/DbgServer.h \
        src/dbgc/Trace.h \


#---------------------------------------------------
#
# Code for src/youdao
#
#---------------------------------------------------
SOURCES += \
        src/youdao/Youdao.cpp \


HEADERS += \
        src/youdao/Youdao.h \



#---------------------------------------------------
#
# Code for frogknow wordbook, src/fknow
#
#---------------------------------------------------
SOURCES += \
        src/fknow/FKWordBook.cpp \
        src/fknow/FKWordConf.cpp \
        src/fknow/NetWord.cpp \
        src/fknow/WordLearn.cpp \


HEADERS += \
        src/fknow/FKWordBook.h \
        src/fknow/FKWordConf.h \
        src/fknow/NetWord.h \
        src/fknow/WordLean.h \































