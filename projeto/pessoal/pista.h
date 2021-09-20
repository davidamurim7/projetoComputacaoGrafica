#ifndef PISTA_H
#define PISTA_H


#include <objeto.h>

class Pista : public Objeto
{
public:
    Model3DS* model;
public:
    Pista();
    ~Pista();
    Pista( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};



#endif // PISTA_H
