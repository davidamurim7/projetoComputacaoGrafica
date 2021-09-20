#ifndef CATAVENTO_H
#define CATAVENTO_H

#include <objeto.h>

class Catavento : public Objeto
{
public:
    Model3DS* model;
public:
    Catavento();
    ~Catavento();
    Catavento( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // CERCADO_H
