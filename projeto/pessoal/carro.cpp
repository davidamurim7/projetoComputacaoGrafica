#include "carro.h"

Carro::Carro()
{
    tipo = CARRO;
    model = new Model3DS("../3ds/cartest.3DS");
}

Carro::~Carro()
{
    delete model;
}

Carro::Carro( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = CARRO;
    model = new Model3DS("../3ds/cartest.3DS");
}

void Carro::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glScalef(1,1,1.2);
            glRotatef(-90,1,0,0);
            glTranslatef(0,0,0);
            glScalef(0.001,0.001,0.001);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.5,0,1.3,0.5,0.8,-1.3);
            }
        glPopMatrix();
    glPopMatrix();
}
