#include "portao.h"

Portao::Portao()
{
    tipo = PORTAO;
    model = new Model3DS("../3ds/portao.3DS");
}

Portao::~Portao()
{
    delete model;
}

Portao::Portao( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = PORTAO;
    model = new Model3DS("../3ds/portao.3DS");
}

void Portao::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            GUI::setColor(0,1,0);
            glRotatef(-90,1,0,0);
            glScalef(0.002,0.002,0.002);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.85,0,0.2,0.85,2.25,-0.2);
            }
         glPopMatrix();
    glPopMatrix();
}
