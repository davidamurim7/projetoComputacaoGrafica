#ifndef MURO_H
#define MURO_H

#include <objeto.h>

class Muro : public Objeto
{
public:
    Model3DS* model;
public:
    Muro();
    ~Muro();
    Muro( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // MURO_H
