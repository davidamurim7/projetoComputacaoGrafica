#include "aviao.h"

Aviao::Aviao()
{
    tipo = AVIAO;
    model = new Model3DS("../3ds/aviao2.3DS");
}

Aviao::~Aviao()
{
    delete model;
}

Aviao::Aviao( Vetor3D t, Vetor3D a, Vetor3D s ){
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = AVIAO;
    model = new Model3DS("../3ds/aviao2.3DS");
}

void Aviao::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();

            anguloGiro += 20;
            if(anguloGiro >= 360){
                anguloGiro = 0;
                altura = 0;
                largura = 0;
            }

            if(anguloGiro <= 180){
                altura += 0.7;
            }else{
                altura -= 0.7;
            }

            if(anguloGiro <= 90 || anguloGiro >= 270){
                largura += 0.7;
            }else{
                largura -= 0.7;
            }

            glTranslatef(-0.3,altura,largura);
            glRotatef(-anguloGiro,1,0,0);
            glRotatef(90,0,1,0);
            glRotatef(-90,1,0,0);
            glScalef(0.00001,0.00001,0.00001);
            model->draw();
        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                if(anguloGiro <= 90 || anguloGiro >= 270){
                     GUI::drawBox(-1.9,-1.5+altura,1.6+largura,1.95,2+altura,-1.85+largura);
                }else{
                     GUI::drawBox(-1.9,-1.5+altura,1.6+largura,1.95,1.2+altura,-1.85+largura);
                }

            }
        glPopMatrix();
    glPopMatrix();
}
