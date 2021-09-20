#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

enum TIPO {NENHUM, ARVORE, ARVORE2, PREDIO, PREDIO2, GRAMA, MURO, PORTAO, PISTA, CASA, CARRO, PERSONAGEM, CARRO2, CATAVENTO, LOBO, AVIAO, HELICOPTERO};

class Objeto
{
public:
    Vetor3D t = Vetor3D(0,0,0);
    Vetor3D a = Vetor3D(0,0,0);
    Vetor3D s = Vetor3D(1,1,1);

    bool selecionado = false;
    bool origem = false;
    bool sombra = true;
    TIPO tipo = NENHUM;

public:
    Objeto();
    virtual ~Objeto();
    virtual void desenha();
    void cubo();
};

#endif // OBJETO_H
