#ifndef CARRO2_H
#define CARRO2_H

#include <objeto.h>

class Carro2 : public Objeto
{
public:
    Model3DS* model;
public:
    Carro2();
    ~Carro2();
    Carro2( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // CARRO2_H
