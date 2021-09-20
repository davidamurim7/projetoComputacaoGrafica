#include "helicoptero.h"

Helicoptero::Helicoptero()
{
    tipo = HELICOPTERO;
    model = new Model3DS("../3ds/helicoptero.3DS");
}

Helicoptero::~Helicoptero()
{
    delete model;
}

Helicoptero::Helicoptero( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = HELICOPTERO;
    model = new Model3DS("../3ds/helicoptero.3DS");
}

void Helicoptero::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
//            glScalef(1,1,1.2);
            glTranslatef(0,0.9,-0.5);
            glRotatef(180,0,1,0);
            glRotatef(-90,1,0,0);
            glScalef(0.01,0.01,0.01);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-1.7,0,2.2,1.7,1.2,-1.8);
            }
        glPopMatrix();
    glPopMatrix();
}
