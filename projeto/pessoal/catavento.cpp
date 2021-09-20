#include "catavento.h"

Catavento::Catavento()
{
    tipo = CATAVENTO;
    model = new Model3DS("../3ds/catavento.3DS");
}

Catavento::~Catavento()
{
    delete model;
}

Catavento::Catavento( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = CATAVENTO;
    model = new Model3DS("../3ds/catavento.3DS");
}

void Catavento::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            GUI::setColor(0,1,0);
            glTranslatef(0,3,0);
            glRotatef(-90,1,0,0);
            glScalef(0.005,0.005,0.005);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.7,0,0.5,0.7,3.6,-1.5);
            }
         glPopMatrix();
    glPopMatrix();
}
