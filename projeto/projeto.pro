TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/arvore.cpp \
    pessoal/arvore2.cpp \
    pessoal/aviao.cpp \
    pessoal/carro2.cpp \
    pessoal/casa.cpp \
    pessoal/catavento.cpp \
    pessoal/grama.cpp \
    pessoal/helicoptero.cpp \
    pessoal/lobo.cpp \
    pessoal/muro.cpp \
    pessoal/personagem.cpp \
    pessoal/objeto.cpp \
    pessoal/carro.cpp \
    pessoal/pista.cpp \
    pessoal/portao.cpp \
    pessoal/predio.cpp \
    pessoal/predio2.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/arvore.h \
    pessoal/arvore2.h \
    pessoal/aviao.h \
    pessoal/carro2.h \
    pessoal/casa.h \
    pessoal/catavento.h \
    pessoal/grama.h \
    pessoal/helicoptero.h \
    pessoal/lobo.h \
    pessoal/muro.h \
    pessoal/personagem.h \
    pessoal/objeto.h \
    pessoal/carro.h \
    pessoal/pista.h \
    pessoal/portao.h \
    pessoal/predio.h \
    pessoal/predio2.h
