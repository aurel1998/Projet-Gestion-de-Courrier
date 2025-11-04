#-------------------------------------------------
#
# Project created by QtCreator 2018-08-30T08:39:32
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = procorex
TEMPLATE = app


SOURCES += main.cpp\
        corex.cpp \
    accueil.cpp \
    section_courriers.cpp \
    documentez_vous.cpp \
    parametre.cpp \
    formulaire_type.cpp \
    recherche_de_courriers.cpp \
    reglages_courriers.cpp \
    changer_mot_de_passe.cpp \
    enregistrement.cpp \
    ajouter_un_agent.cpp \
    infogeneralutilisateurs.cpp \
    archives.cpp \
    agent.cpp \
    rechercher_un_agent.cpp

HEADERS  += corex.h \
    accueil.h \
    section_courriers.h \
    documentez_vous.h \
    parametre.h \
    formulaire_type.h \
    recherche_de_courriers.h \
    reglages_courriers.h \
    changer_mot_de_passe.h \
    connexion_bdd.h \
    enregistrement.h \
    ajouter_un_agent.h \
    infogeneralutilisateurs.h \
    archives.h \
    agent.h \
    rechercher_un_agent.h

FORMS    += corex.ui \
    accueil.ui \
    section_courriers.ui \
    documentez_vous.ui \
    parametre.ui \
    formulaire_type.ui \
    recherche_de_courriers.ui \
    reglages_courriers.ui \
    changer_mot_de_passe.ui \
    enregistrement.ui \
    ajouter_un_agent.ui \
    infogeneralutilisateurs.ui \
    archives.ui \
    agent.ui \
    rechercher_un_agent.ui

DISTFILES += \
    ../images de corex/IMAGES COREX/images28.jpg \
    ../images de corex/IMAGES/actu.png

RESOURCES += \
    rssources.qrc
