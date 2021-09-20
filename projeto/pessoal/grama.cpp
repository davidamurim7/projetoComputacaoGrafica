#include "grama.h"

Grama::Grama()
{
    tipo = GRAMA;
    model = new Model3DS("../3ds/gramado.3DS");
    sombra = false;
}

Grama::~Grama()
{
    delete model;
}

Grama::Grama( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = GRAMA;
    model = new Model3DS("../3ds/gramado.3DS");
    sombra = false;
}

void Grama::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0.7,4,0);
            glScalef(0.05,0.05,0.05);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-1.75,0,0.3,1.75,4.7,-0.3);
            }
         glPopMatrix();
    glPopMatrix();
}
