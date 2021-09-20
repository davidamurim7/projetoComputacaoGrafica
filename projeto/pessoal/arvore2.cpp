#include "arvore2.h"

Arvore2::Arvore2()
{
    tipo = ARVORE2;
    model = new Model3DS("../3ds/pinhei.3DS");
}

Arvore2::~Arvore2()
{
    delete model;
}


Arvore2::Arvore2( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = ARVORE2;
    model = new Model3DS("../3ds/pinhei.3DS");
}

void Arvore2::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,0,1.8);
            glRotatef(-90,1,0,0);
            glScalef(0.002,0.002,0.002);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-1.3,0,1.3,1.3,3.5,-1.3);
            }
         glPopMatrix();
    glPopMatrix();
}
