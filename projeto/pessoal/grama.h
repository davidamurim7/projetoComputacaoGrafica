#ifndef GRAMA_H
#define GRAMA_H

#include <objeto.h>

class Grama : public Objeto
{
public:
    Model3DS* model;
public:
    Grama();
    ~Grama();
    Grama( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};


#endif // GRAMA_H
