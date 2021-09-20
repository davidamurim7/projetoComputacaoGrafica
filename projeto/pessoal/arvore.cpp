#include "arvore.h"

Arvore::Arvore()
{
    tipo = ARVORE;
    model = new Model3DS("../3ds/palm2.3DS");
}

Arvore::~Arvore()
{
    delete model;
}

Arvore::Arvore( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = ARVORE;
    model = new Model3DS("../3ds/palm2.3DS");
}

void Arvore::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.025,0.025,0.025);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-1,0,1,1,3.5,-1);
            }
         glPopMatrix();
    glPopMatrix();
}
