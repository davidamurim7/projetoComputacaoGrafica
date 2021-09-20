#include "pista.h"

Pista::Pista()
{
    tipo = PISTA;
    model = new Model3DS("../3ds/pista.3ds");
}

Pista::~Pista()
{
    delete model;
}

Pista::Pista( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = PISTA;
    model = new Model3DS("../3ds/pista.3ds");
}

void Pista::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glRotatef(5,0,0,1);
            glTranslatef(-0.3,-0.5,-0.13);
            glScalef(0.007,0.007,0.007);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-3.5,0,4.1,3.75,0.03,-3.75);
            }
         glPopMatrix();
    glPopMatrix();
}
