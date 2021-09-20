#include "carro2.h"

Carro2::Carro2()
{
    model = new Model3DS("../3ds/carro2.3DS");
}

Carro2::~Carro2()
{
    delete model;
}

Carro2::Carro2( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = CARRO2;
    model = new Model3DS("../3ds/carro2.3DS");
}

void Carro2::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glTranslatef(0,0,0);
            glScalef(0.00001,0.00001,0.00001);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.3,0,0.7,0.3,0.6,-0.7);
            }
        glPopMatrix();
    glPopMatrix();
}
