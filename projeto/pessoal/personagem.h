#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <objeto.h>

class Personagem : public Objeto
{
public:
    double anguloGiroCabeca = -70;
    int sentidoGiro;
public:
    Personagem();
    Personagem( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // PERSONAGEM_H
