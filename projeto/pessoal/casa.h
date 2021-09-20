#ifndef CASA_H
#define CASA_H

#include <objeto.h>

class Casa : public Objeto
{
public:
    Casa();
    Casa( Vetor3D t, Vetor3D a, Vetor3D s );
    void desenha();
};

#endif // CASA_H
