QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gestion_de_ciclo.cpp \
    info.cpp \
    opciones_extras.cpp \
    resultado.cpp \
    dateselectiondialog.cpp \
    inicio.cpp \
    main.cpp \
    mainwindow.cpp \
    quiz_quedar_embarazada.cpp \
    usuario.cpp

HEADERS += \
    gestion_de_ciclo.h \
    info.h \
    opciones_extras.h \
    resultado.h \
    dateselectiondialog.h \
    inicio.h \
    mainwindow.h \
    quiz_quedar_embarazada.h \
    usuario.h

FORMS += \
    gestion_de_ciclo.ui \
    info.ui \
    opciones_extras.ui \
    resultado.ui\
    dateselectiondialog.ui \
    inicio.ui \
    mainwindow.ui \
    quiz_quedar_embarazada.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Imagenes/Higiene.jpg \
    Imagenes/imagen1.jpg
