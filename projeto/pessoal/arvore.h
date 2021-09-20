#ifndef ARVORE_H
#define ARVORE_H

#include <objeto.h>

class Arvore : public Objeto
{
public:
    Model3DS* model;
public:
    Arvore();
    ~Arvore();
    Arvore( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};


#endif // ARVORE_H


