#ifndef ARVORE2_H
#define ARVORE2_H

#include <objeto.h>

class Arvore2 : public Objeto
{
public:
    Model3DS* model;
public:
    Arvore2();
    ~Arvore2();
    Arvore2( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // ARVORE2_H
