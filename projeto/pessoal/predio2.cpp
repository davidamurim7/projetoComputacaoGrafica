#include "predio2.h"

Predio2::Predio2()
{
    tipo = PREDIO2;
    model = new Model3DS("../3ds/apartamento1.3DS");
}

Predio2::~Predio2()
{
    delete model;
}

Predio2::Predio2( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = PREDIO2;
    model = new Model3DS("../3ds/apartamento1.3DS");
}

void Predio2::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90, 1, 0, 0);
            glRotatef(-180, 0, 0, 1);
            glScalef(0.5, 0.5, 0.5);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-2.2,0,1.5,2.2,3.2,-1.5);
            }
         glPopMatrix();
    glPopMatrix();
}
