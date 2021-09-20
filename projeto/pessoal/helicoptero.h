#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include <objeto.h>

class Helicoptero : public Objeto
{
public:
    Model3DS* model;
public:
    Helicoptero();
    ~Helicoptero();
    Helicoptero( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // HELICOPTERO_H
