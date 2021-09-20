#include "lobo.h"

Lobo::Lobo()
{
    tipo = LOBO;
    model = new Model3DS("../3ds/lobo.3ds");
}

Lobo::~Lobo()
{
    delete model;
}

Lobo::Lobo( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = LOBO;
    model = new Model3DS("../3ds/lobo.3ds");
}

void Lobo::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            GUI::setColor(0,1,0);
            glRotatef(-90,1,0,0);
            glScalef(0.2,0.2,0.2);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.3,0,0.8,0.3,0.9,-1);
            }
         glPopMatrix();
    glPopMatrix();
}
