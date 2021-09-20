#include "muro.h"

Muro::Muro()
{
    tipo = MURO;
    model = new Model3DS("../3ds/muro.3ds");
}

Muro::~Muro()
{
    delete model;
}

Muro::Muro( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = MURO;
    model = new Model3DS("../3ds/muro.3ds");
}

void Muro::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(1,0,0.3);
            glRotatef(-90,1,0,0);
            glRotatef(73,0,0,1);
            glScalef(0.2,0.2,0.2);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.7,-0.4,0.4,0.8,0.5,0);
            }
         glPopMatrix();
    glPopMatrix();
}
