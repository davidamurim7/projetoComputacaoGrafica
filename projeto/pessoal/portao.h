#ifndef PORTAO_H
#define PORTAO_H

#include <objeto.h>

class Portao : public Objeto
{
public:
    Model3DS* model;
public:
    Portao();
    ~Portao();
    Portao( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // PORTAO_H
