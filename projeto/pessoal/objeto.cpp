#include "objeto.h"

Objeto::Objeto()
{

}

Objeto::~Objeto()
{

}

void Objeto::desenha()
{
    glTranslatef(t.x,t.y,t.z);
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);
    glScalef(s.x,s.y,s.z);

    if( origem ){
        GUI::drawOrigin(2);
    }
}

void Objeto::cubo()
{
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, 0, -1);
        glVertex3f(0, 0, -1);
        glVertex3f(0, 1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 0, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(-1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, -1);
        glVertex3f(0, 0, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(1, 0, 0);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 0, 0);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, -1);
        glVertex3f(0, 1, -1);
    glEnd();

    glBegin(GL_QUADS);
        glNormal3f(0, -1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -1);
        glVertex3f(1, 0, -1);
        glVertex3f(1, 0, 0);
    glEnd();
}
