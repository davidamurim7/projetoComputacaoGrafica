#ifndef CARRO_H
#define CARRO_H

#include <objeto.h>

class Carro : public Objeto
{
public:
    Model3DS* model;
public:
    Carro();
    ~Carro();
    Carro( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // CARRO_H
