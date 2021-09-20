#include "predio.h"

Predio::Predio()
{
    tipo = PREDIO;
    model = new Model3DS("../3ds/predio.3DS");
}

Predio::~Predio()
{
    delete model;
}

Predio::Predio( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = PREDIO;
    model = new Model3DS("../3ds/predio.3DS");
}

void Predio::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.0005,0.0005,0.0005);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.53,0,0.25,2.1,1.4,-0.45);
            }
         glPopMatrix();
    glPopMatrix();
}
