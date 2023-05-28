QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinhashdialog.cpp \
    addinlistdialog.cpp \
    addintreedialog.cpp \
    clientsWindow.cpp \
    clientsobj.cpp \
    clientstree.cpp \
    infosimWindow.cpp \
    infosimobj.cpp \
    issueorrefundsimWindow.cpp \
    issueorrefundsimobj.cpp \
    main.cpp \
    menu.cpp \
    myhashtable.cpp \
    mylist.cpp \
    mylistnode.cpp \
    searchengine.cpp

HEADERS += \
    addinhashdialog.h \
    addinlistdialog.h \
    infosimobj.h \
    issueorrefundsimobj.h \
    myexception.h \
    addintreedialog.h \
    clientsWindow.h \
    clientsobj.h \
    clientstree.h \
    infosimWindow.h \
    issueorrefundsimWindow.h \
    menu.h \
    myhashtable.h \
    mylist.h \
    mylistnode.h \
    searchengine.h

FORMS += \
    addinhashdialog.ui \
    addinlistdialog.ui \
    addintreedialog.ui \
    clientsWindow.ui \
    infosimWindow.ui \
    issueorrefundsimWindow.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
