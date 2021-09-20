#ifndef LOBO_H
#define LOBO_H

#include <objeto.h>

class Lobo : public Objeto
{
public:
    Model3DS* model;
public:
    Lobo();
    ~Lobo();
    Lobo( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // LOBO_H
