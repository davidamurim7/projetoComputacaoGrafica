#ifndef AVIAO_H
#define AVIAO_H

#include <objeto.h>

class Aviao : public Objeto
{
public:
    Model3DS* model;
    double anguloGiro = 0;
    double altura = 0;
    double largura = 0;
public:
    Aviao();
    ~Aviao();
    Aviao( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // AVIAO_H
