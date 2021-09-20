#include "casa.h"

Casa::Casa()
{
    tipo = CASA;
}

Casa::Casa( Vetor3D t, Vetor3D a, Vetor3D s )
{
    this->t = t;
    this->a = a;
    this->s = s;
    tipo = CASA;
}

void Casa::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(-1,0,-1.5);

            GUI::setColor(0.5,0,0);


            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(1,1,1);
                glVertex3f(1,1,2);
                glVertex3f(1.8,0.53,2);
                glVertex3f(1.8,0.53,1);
            glEnd();



            glBegin(GL_POLYGON);
                glNormal3f(0,1,0);
                glVertex3f(0.2,0.53,1);
                glVertex3f(0.2,0.53,2);
                glVertex3f(1,1,2);
                glVertex3f(1,1,1);
            glEnd();

            GUI::setColor(1,1,1);


            GUI::drawBox(0.5,0,1,1.5,0.7,2,false);

            GUI::setColor(0.5,0,0);

            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(0.6,0,2.001);
                glVertex3f(0.8,0,2.001);
                glVertex3f(0.8,0.4,2.001);
                glVertex3f(0.6,0.4,2.001);
            glEnd();

            glBegin(GL_POLYGON);
                glNormal3f(0,0,-1);
                glVertex3f(1.1,0.2,2.001);
                glVertex3f(1.3,0.2,2.001);
                glVertex3f(1.3,0.4,2.001);
                glVertex3f(1.1,0.4,2.001);
            glEnd();

            GUI::setColor(1,1,1);

            glBegin(GL_TRIANGLES);
                glNormal3f(0,0,1);
                glVertex3f(1.5,0.7,2);
                glVertex3f(1,1,2);
                glVertex3f(0.5,0.7,2);

            glEnd();

            glBegin(GL_TRIANGLES);
                glNormal3f(0,0,-1);
                glVertex3f(0.5,0.7,1);
                glVertex3f(1,1,1);
                glVertex3f(1.5,0.7,1);

            glEnd();

            GUI::drawBox(1.3,0,1.3,1.4,1.1,1.5,false);

            GUI::setColor(0,0,0,1);
            glBegin(GL_LINES);
                glVertex3f(0.6,0,1.4);
                glVertex3f(0.6,1.1,1.4);

            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0.4,1.1,1.35);
                glVertex3f(0.8,1,1.45);

            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0.4,1,1.5);
                glVertex3f(0.5,1.1,1.3);

            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0.5,1,1.5);
                glVertex3f(0.6,1.1,1.3);

            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0.6,1,1.5);
                glVertex3f(0.7,1.1,1.3);

            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0.7,1,1.5);
                glVertex3f(0.8,1.1,1.3);

            glEnd();

        glPopMatrix();
        glPushMatrix();
            if( selecionado ){
                GUI::setColor(0,1,0,0.5);
                GUI::drawBox(-0.85,0,0.85,0.85,1.2,-0.85);
            }
        glPopMatrix();

    glPopMatrix();




}
