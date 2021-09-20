#ifndef PREDIO_H
#define PREDIO_H

#include <objeto.h>

class Predio : public Objeto
{
public:
    Model3DS* model;
public:
    Predio();
    ~Predio();
    Predio( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // PREDIO_H
