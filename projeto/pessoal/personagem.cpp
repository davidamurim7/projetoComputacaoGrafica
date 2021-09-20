#include "personagem.h"

Personagem::Personagem()
{
    tipo = PERSONAGEM;
}

Personagem::Personagem( Vetor3D t, Vetor3D a, Vetor3D s )
{
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = PERSONAGEM;
}

void Personagem::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        glScalef(0.5,0.5,0.5);
        glRotatef(0,1,0,0);
        glTranslatef(0,0,0);
        glScalef(1,1,1);

        //cabeça
        glPushMatrix();

        if( sentidoGiro == 1){
            anguloGiroCabeca += 5;
            if(anguloGiroCabeca >= 60){
                sentidoGiro = -1;
            }
        }else{
            anguloGiroCabeca -= 5;
            if(anguloGiroCabeca <= -60){
                sentidoGiro = 1;
            }
        }

        glRotatef(anguloGiroCabeca,0,1,0);
        GUI::setColor(0,1,0);
        GUI::drawSphere(0,2.9,0,0.3);
        GUI::setColor(0,0,0);
        GUI::drawSphere(0.15,3,0.2,0.07);
        GUI::drawSphere(-0.15,3,0.2,0.07);
        GUI::drawSphere(0,2.85,0.3,0.07);
        glPopMatrix();

        //tronco
        glPushMatrix();
            GUI::setColor(1,0,0);
            GUI::drawSphere(0,1.5,0,0.3);
            GUI::setColor(0.9,0.5,0.3);
            GUI::drawBox(-0.3,1.5,-0.2, 0.3,1.8,0.2,false);
            GUI::drawBox(-0.5,1.8,-0.2, 0.5,2.1,0.2,false);
            GUI::drawBox(-0.7,2.1,-0.2, 0.7,2.4,0.2,false);
            GUI::drawBox(-0.2,2.4,-0.2, 0.2,2.6,0.2,false);

        glPopMatrix();

        GUI::setColor(0,0,1);
        //pernas direita
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.4,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0,1.6,0.15);
                glVertex3f(0,1.6,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0.2,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.4,0,0.15);
                glVertex3f(0.2,0,0.15);
                glVertex3f(0,1.6,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0,1.6,-0.15);
            glEnd();
        glPopMatrix();




        //pernas esquerda
        glRotatef(180,0,1,0);
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.4,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0,1.6,0.15);
                glVertex3f(0,1.6,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0.2,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.4,0,0.15);
                glVertex3f(0.2,0,0.15);
                glVertex3f(0,1.6,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0,1.6,-0.15);
            glEnd();
        glPopMatrix();

        //braço direito
        glTranslatef(0.5,0.8,0);
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.4,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0,1.6,0.15);
                glVertex3f(0,1.6,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0.2,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.4,0,0.15);
                glVertex3f(0.2,0,0.15);
                glVertex3f(0,1.6,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0,1.6,-0.15);
            glEnd();
        glPopMatrix();

        //braço direito
        glRotatef(180,0,1,0);
        glTranslatef(1,0,0);
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.4,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0,1.6,0.15);
                glVertex3f(0,1.6,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0.2,0,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0.2,2,0.15);
                glVertex3f(0.4,0,0.15);
                glVertex3f(0.2,0,0.15);
                glVertex3f(0,1.6,0.15);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(0.2,2,-0.15);
                glVertex3f(0.4,0,-0.15);
                glVertex3f(0.2,0,-0.15);
                glVertex3f(0,1.6,-0.15);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-1.5,-0.8,0.6,0.5,2.6,-0.6);
            }
        glPopMatrix();

    glPopMatrix();
}
