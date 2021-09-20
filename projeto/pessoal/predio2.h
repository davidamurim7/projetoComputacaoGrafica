#ifndef PREDIO2_H
#define PREDIO2_H

#include <objeto.h>

class Predio2 : public Objeto
{
public:
    Model3DS* model;
public:
    Predio2();
    ~Predio2();
    Predio2( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // PREDIO2_H
