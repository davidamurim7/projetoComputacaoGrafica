#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include <gui.h>
#include <vector>

#include <objeto.h>
#include <personagem.h>
#include <casa.h>
#include <predio.h>
#include <predio2.h>
#include <carro.h>
#include <carro2.h>
#include <arvore.h>
#include <arvore2.h>
#include <lobo.h>
#include <catavento.h>
#include <grama.h>
#include <muro.h>
#include <portao.h>
#include <pista.h>
#include <aviao.h>
#include <helicoptero.h>

vector<Objeto*> objetos;
int posSelecionado = -1;
bool incluirObjeto = false;

vector<Camera*> cameras;
vector<Camera*> camerasV;
vector<Camera*> camerasO;
vector<Camera*> camerasP;
int posCam = -1;
int posCamV = 0;
int posCamO = -1;
int posCamP = -1;


vector<GLfloat*> lightXYZ;
int posLightXYZ = 0;

//-------------------sombra-------------------
bool drawShadow = false;
bool pontual = true;
vector<GLfloat*> planos;
//-------------------sombra-------------------

bool viewports = false;
bool scissored = false;

void cenario(){

    GUI::setLight(0,0,5,0,true,false,false,false,pontual);
    GUI::drawOrigin(1);

    GUI::setColor(0.941176471,0.901960784,0.549019608);
    GUI::drawFloor(20,20);

    if(drawShadow)
    {
        //-------------------back-------------------
        glPushMatrix();
            glTranslated(0,7,-17);
            glRotatef(45, 1, 0, 0);
            GUI::drawFloor(70,20);
        glPopMatrix();

        //-------------------front-------------------
        glPushMatrix();
            glTranslated(0,10,10);
            glRotatef(-90, 1, 0, 0);
            GUI::drawFloor(70,20);
        glPopMatrix();

        //-------------------left-------------------
        glPushMatrix();
            glTranslated(17,7,0);
            glRotated(45, 0, 0, 1);
            GUI::drawFloor(20,70);
        glPopMatrix();

        //-------------------right-------------------
        glPushMatrix();
            glTranslated(-10,10,0);
            glRotatef(-90, 0, 0, 1);
            GUI::drawFloor(20,70);
        glPopMatrix();
        //----------------

    }


    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            glPushName(i+1);
                objetos[i]->desenha();
            glPopName();
        glPopMatrix();
    }

    //-------------------sombra-------------------
    float lightPos[4] = {0+glutGUI::lx,5+glutGUI::ly,0+glutGUI::lz,(float)pontual};
    glDisable(GL_LIGHTING);
    glColor4d(0,0,0,1);
    for(int i = 0; i < planos.size(); i++) {
        glPushMatrix();
                GLfloat sombra[4][4];
                GUI::shadowMatrix(sombra,planos[i],lightPos);
                glMultTransposeMatrixf( (GLfloat*)sombra );

                if (drawShadow) {
                    bool aux = glutGUI::draw_eixos;
                    glutGUI::draw_eixos = false;
                    for (int i = 0; i < objetos.size(); ++i) {
                        glPushMatrix();
                            if(objetos[i]->sombra)
                                objetos[i]->desenha();
                        glPopMatrix();
                    }
                    glutGUI::draw_eixos = aux;
                }
        glPopMatrix();
    }
    glEnable(GL_LIGHTING);
    //-------------------sombra-------------------
}

//-------------------viewPorts------------------

//visao de duas cameras (duas viewports), viewport auxiliar sobrepondo a principal
void viewPorts() {
    float width = glutGUI::width;
    float height = glutGUI::height;

    //viewport principal
    glViewport(0, 0, width, height);
        glLoadIdentity();
        gluLookAt(glutGUI::cam->e.x,glutGUI::cam->e.y,glutGUI::cam->e.z, glutGUI::cam->c.x,glutGUI::cam->c.y,glutGUI::cam->c.z, glutGUI::cam->u.x,glutGUI::cam->u.y,glutGUI::cam->u.z);
            cenario();

    //viewport auxiliar sobrepondo a principal
    if (!scissored) {
        //misturando com a principal
        glViewport(0, 3*height/4, width/4, height/4);
    } else {
        //recortando/substituindo o pedaço
        GUI::glScissoredViewport(0, 3*height/4, width/4, height/4);
    }
        glLoadIdentity();
        Vetor3D eye = Vetor3D(camerasV[posCamV]->e.x, camerasV[posCamV]->e.y, camerasV[posCamV]->e.z);
        Vetor3D center = Vetor3D(camerasV[posCamV]->c.x, camerasV[posCamV]->c.y, camerasV[posCamV]->c.z);
        Vetor3D up = Vetor3D(camerasV[posCamV]->u.x, camerasV[posCamV]->u.y, camerasV[posCamV]->u.z);
        gluLookAt(eye.x,eye.y,eye.z, center.x,center.y,center.z, up.x, up.y, up.z);
            cenario();
}
//-------------------viewPorts------------------


void desenha() {

    GUI::displayInit();

    if (!viewports) {
        cenario();
    } else {
        viewPorts();
    }


    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }


    GUI::displayEnd();
}

void salvar(){
    ofstream arq("../cenarioSalvo.txt");
    arq.clear();
    arq << objetos.size() << "\n";
    for (int i = 0; i < objetos.size();i++) {
        arq << objetos[i]->tipo << "\n";
        arq << objetos[i]->t.x << "\n";
        arq << objetos[i]->t.y << "\n";
        arq << objetos[i]->t.z << "\n";
        arq << objetos[i]->a.x << "\n";
        arq << objetos[i]->a.y << "\n";
        arq << objetos[i]->a.z << "\n";
        arq << objetos[i]->s.x << "\n";
        arq << objetos[i]->s.y << "\n";
        arq << objetos[i]->s.z << "\n";
    }
}

void carregar(string arquivo){
    ifstream arq(arquivo);
    string linha;
    getline(arq,linha);
    int n_obj = std::stoi (linha);
    int tipo;
    double tx, ty, tz, ax, ay, az, sx, sy, sz;
    for( int i = 0; i < n_obj; i++ ){
      getline(arq,linha);
      tipo = std::stoi (linha);
      getline(arq,linha);
      tx = std::stof(linha);
      getline(arq,linha);
      ty = std::stof(linha);
      getline(arq,linha);
      tz = std::stof(linha);
      getline(arq,linha);
      ax = std::stof(linha);
      getline(arq,linha);
      ay = std::stof(linha);
      getline(arq,linha);
      az = std::stof(linha);
      getline(arq,linha);
      sx = std::stof(linha);
      getline(arq,linha);
      sy = std::stof(linha);
      getline(arq,linha);
      sz = std::stof(linha);
      Vetor3D tn = Vetor3D(tx,ty,tz);
      Vetor3D an = Vetor3D(ax,ay,az);
      Vetor3D sn = Vetor3D(sx,sy,sz);
      if( tipo == ARVORE ){
        objetos.push_back(new Arvore(tn, an, sn));
      }else if( tipo == ARVORE2 ){
        objetos.push_back(new Arvore2(tn, an, sn));
      }else if( tipo == PREDIO ){
        objetos.push_back(new Predio(tn, an, sn));
      }else if( tipo == PREDIO2 ){
          objetos.push_back(new Predio2(tn, an, sn));
      }else if( tipo == GRAMA ){
         objetos.push_back(new Grama(tn, an, sn));
      }else if( tipo == MURO ){
         objetos.push_back(new Muro(tn, an, sn));
      }else if( tipo == PORTAO ){
          objetos.push_back(new Portao(tn, an, sn));
      }else if( tipo == PISTA ){
          objetos.push_back(new Pista(tn, an, sn));
      }else if( tipo == CASA ){
          objetos.push_back(new Casa(tn, an, sn));
      }else if( tipo == CARRO ){
          objetos.push_back(new Carro(tn, an, sn));
      }else if( tipo == PERSONAGEM ){
          objetos.push_back(new Personagem(tn, an, sn));
      }else if( tipo == CARRO2 ){
          objetos.push_back(new Carro2(tn, an, sn));
      }else if( tipo == CATAVENTO ){
          objetos.push_back(new Catavento(tn, an, sn));
      }else if( tipo == LOBO ){
          objetos.push_back(new Lobo(tn, an, sn));
      }else if( tipo == AVIAO ){
          objetos.push_back(new Aviao(tn, an, sn));
      }else if( tipo == HELICOPTERO ){
          objetos.push_back(new Helicoptero(tn, an, sn));
      }

    }
}

void onOffOrigem(){

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
    }

}

void removerSelecionado(){
    if(posSelecionado >= 0 and posSelecionado < objetos.size()){
        delete objetos[posSelecionado];
        objetos.erase(objetos.begin()+posSelecionado);
    }
}

void removerUltimo(){
    if(objetos.size() > 0 ){
        delete objetos[objetos.size()-1];
        objetos.pop_back();
    }
}

void selecionarIndo(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado++;
    posSelecionado = posSelecionado%objetos.size();
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}

void selecionarVoltando(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado--;
    if (posSelecionado < 0) {
        posSelecionado = objetos.size()-1;
    }
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}

void naoSelecionar(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado= -1;
    glutGUI::trans_obj = false;
}

void removeTudo(){
    for (int i = 0; i < objetos.size(); ++i) {
        delete objetos[i];
    }
    objetos.clear();
}

void teclado(unsigned char key, int x, int y) {

    GUI::keyInit(key,x,y);

    switch (key) {

        case 't':
            glutGUI::trans_obj = !glutGUI::trans_obj;
            break;
        case 'l':
            glutGUI::trans_luz = !glutGUI::trans_luz;
            break;
        case 'L':
            posLightXYZ++;
            posLightXYZ %= lightXYZ.size();
            glutGUI::lx = lightXYZ[posLightXYZ][0];
            glutGUI::ly = lightXYZ[posLightXYZ][1];
            glutGUI::lz = lightXYZ[posLightXYZ][2];
            break;
        case '.':
            selecionarIndo();
            break;
        case ',':
            selecionarVoltando();
            break;
        case ';':
            naoSelecionar();
            break;
        case 'O':
            incluirObjeto = !incluirObjeto;
            break;
        case 'W':
            onOffOrigem();
            break;
        case 'r':
            removerSelecionado();
            break;
        case 'R':
            removerUltimo();
            break;
        case 'S':
            salvar();
            break;
        case 'P':
            removeTudo();
            carregar("../cenarioPadrao.txt");
            break;
        case 'Q':
            removeTudo();
            carregar("../cenarioSalvo.txt");
            break;
        case 'H':
            drawShadow = !drawShadow;
            break;
        case 'J':
            pontual = !pontual;
            break;
        case 'V':
            viewports = !viewports;
            break;
        case '<':
            scissored = !scissored;
            break;
        case 'u':
            if(posSelecionado >= 0 and posSelecionado < objetos.size())
            {
                objetos[posSelecionado]->sombra = !objetos[posSelecionado]->sombra;
            }
            break;
        case '=':
            glutGUI::projection = 1;
            posCamO++;
            if (posCamO >= camerasO.size()) {
                posCamO = 0;
            }
            glutGUI::cam = new CameraDistante(camerasO[posCamO]->e, camerasO[posCamO]->c, camerasO[posCamO]->u);
            break;

        case '-':
            glutGUI::projection = 0;
            posCamP++;
            if (posCamP >= camerasP.size()) {
                posCamP = 0;
            }
            glutGUI::cam = new CameraDistante(camerasP[posCamP]->e, camerasP[posCamP]->c, camerasP[posCamP]->u);
            break;

        case '/':
            posCam++;
            if (posCam >= cameras.size()) {
                posCam = 0;
            }
            glutGUI::cam = new CameraDistante(cameras[posCam]->e, cameras[posCam]->c, cameras[posCam]->u);
            break;

        case '|':
            posCamV++;
            if (posCamV >= camerasV.size()) {
                posCamV = 0;
            }
            break;

        //----------projeção
        case 'b':
            glutGUI::anglePerspective++;
            break;
        case 'n':
            glutGUI::anglePerspective--;
            break;
        case 'v':
            glutGUI::anglePerspective = 30;
            break;
        case 'e':
            glutGUI::obliquaX++;
            break;
        case 'd':
            glutGUI::obliquaX--;
            break;
        case '[':
            glutGUI::obliquaY++;
            break;
        case ']':
            glutGUI::obliquaY--;
            break;
        case 'D':
            glutGUI::obliquaX = 45;
            glutGUI::obliquaY = -45;
            break;
        case 'G':
            glutGUI::obliquaX = 90;
            glutGUI::obliquaY = -90;
            break;


        case '"':
            if (incluirObjeto) {
                objetos.push_back( new Arvore() );
            }
            break;
        case '!':
            if (incluirObjeto) {
                objetos.push_back( new Arvore2() );
            }
            break;
        case '@':
            if (incluirObjeto) {
                objetos.push_back( new Predio() );
            }
            break;
        case '#':
            if (incluirObjeto) {
                objetos.push_back( new Predio2() );
            }
            break;
        case '$':
            if (incluirObjeto) {
                objetos.push_back( new Grama() );
            }
            break;
        case '%':
            if (incluirObjeto) {
                objetos.push_back( new Muro() );
            }
            break;
        case '&':
            if (incluirObjeto) {
                objetos.push_back( new Portao() );
            }
            break;
        case '*':
            if (incluirObjeto) {
                objetos.push_back( new Pista() );
            }
            break;
        case '(':
            if (incluirObjeto) {
                objetos.push_back( new Casa() );
            }
            break;

        case ')':
            if (incluirObjeto) {
                objetos.push_back( new Carro() );
            }
            break;

        case '_':
            if (incluirObjeto) {
                objetos.push_back( new Personagem() );
            }
            break;

        case '+':
            if (incluirObjeto) {
                objetos.push_back( new Carro2() );
            }
            break;

        case '{':
            if (incluirObjeto) {
                objetos.push_back( new Catavento() );
            }
            break;

        case '}':
            if (incluirObjeto) {
                objetos.push_back( new Lobo() );
            }
            break;

        case '?':
            if (incluirObjeto) {
                objetos.push_back( new Aviao() );
            }
            break;

        case '>':
            if (incluirObjeto) {
                objetos.push_back( new Helicoptero() );
            }
            break;
    }
}

//picking
int picking( GLint cursorX, GLint cursorY, int w, int h ) {
    int BUFSIZE = 512;
    GLuint selectBuf[512];

    GUI::pickingInit(cursorX,cursorY,w,h,selectBuf,BUFSIZE);

//de acordo com a implementacao original da funcao display
    //lembrar de nao inicializar a matriz de projecao, para nao ignorar a gluPickMatrix
//    GUI::displayInit();
    desenha();
    //só precisa desenhar o que for selecionavel
//    desenhaPontosDeControle();
//fim-de acordo com a implementacao original da funcao display

    //retornando o name do objeto (ponto de controle) mais proximo da camera (z minimo! *[matrizes de normalizacao da projecao])
    return GUI::pickingClosestName(selectBuf,BUFSIZE);
}
//-------------------picking------------------

void mouse(int button, int state, int x, int y) {

    GUI::mouseButtonInit(button,state,x,y);

    // if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {
        // when the button is pressed
        if (state == GLUT_DOWN) {
            //picking
            int pick = picking( x, y, 5, 5 );
            if (pick != 0) {
                if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
                    objetos[posSelecionado]->selecionado = false;
                }
                posSelecionado = pick-1;
                objetos[posSelecionado]->selecionado = true;
                glutGUI::lbpressed = false;
            }
        }
    }
}


int main()
{
    cout << "Hello World!" << endl;

    GLfloat light_a[3] = {0,0,0};
    lightXYZ.push_back(light_a);
    GLfloat light_b[3] = {6,-3,0};
    lightXYZ.push_back(light_b);
    GLfloat light_c[3] = {-6,-3,0};
    lightXYZ.push_back(light_c);
    GLfloat light_d[3] = {0,-3,6};
    lightXYZ.push_back(light_d);
    GLfloat light_e[3] = {0,-3,-6};
    lightXYZ.push_back(light_e);
    GLfloat light_f[3] = {6,-3,-6};
    lightXYZ.push_back(light_f);
    GLfloat light_g[3] = {6,-3,6};
    lightXYZ.push_back(light_g);
    GLfloat light_h[3] = {-6,-3,-6};
    lightXYZ.push_back(light_h);
    GLfloat light_i[3] = {-6,-3,6};
    lightXYZ.push_back(light_i);
    GLfloat light_j[3] = {0,4,6};
    lightXYZ.push_back(light_j);

    cameras.push_back(new CameraDistante(0,8,20, 0,1,0, 0,1,0));
    cameras.push_back(new CameraDistante(0,1,1,  0,3,-1, 0,1,0)); //obliqua
    cameras.push_back(new CameraDistante(0,9.5,30, 0,3,0, 0,1,0));
    cameras.push_back(new CameraDistante(6,50,0, 6,0,0, 0,0,-1));
    cameras.push_back(new CameraJogo(0.337119, 9.72637, 7.82033, 0.404669, 8.47037, -2.16229, 0,1,0));
    cameras.push_back(new CameraJogo(0,1.5,0, 0,1,-2, 0,1,0));
    cameras.push_back(new CameraDistante(-1,2,0, 2.5,1.5,1, 0,1,0));
    cameras.push_back(new CameraDistante(2,1,5, -5.5,1,6.5 ,0,1,0));
    cameras.push_back(new CameraDistante(1.5,1.5,2, 5.5,1,5, 0,1,0));

    camerasV.push_back(new CameraDistante(0,9.5,30, 0,3,0, 0,1,0));
    camerasV.push_back(new CameraDistante(Vetor3D(0, 1, 5), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasV.push_back(new CameraDistante(Vetor3D(0, 10, 0), Vetor3D(0,0,0), Vetor3D(0, 0, -1)));
    camerasV.push_back(new CameraDistante(Vetor3D(5, 1, 0), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasV.push_back(new CameraJogo(0.337119, 9.72637, 7.82033, 0.404669, 8.47037, -2.16229, 0,1,0));

    //clássicas ortogonais
    camerasO.push_back(new CameraDistante(Vetor3D(0, 0, 10), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(0, 10, 0), Vetor3D(0,0,0), Vetor3D(0, 0, -1)));
    camerasO.push_back(new CameraDistante(Vetor3D(10, 0, 0), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5.34611, 5.07777, 4.61756), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5.34611, 2.07777, 4.61756), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));
    camerasO.push_back(new CameraDistante(Vetor3D(5.34611, 2.07777, 2.61756), Vetor3D(0.7, 1.3, 0), Vetor3D(0, 1, 0)));

    //pontos de fuga perspectiva
    camerasP.push_back(new CameraDistante(Vetor3D(0, 0, 10), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasP.push_back(new CameraDistante(Vetor3D(5, 0, 5), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));
    camerasP.push_back(new CameraDistante(Vetor3D(4, 2, 7), Vetor3D(0,0,0), Vetor3D(0, 1, 0)));


    //-------------------sombra-------------------
    GLfloat plano_d[4] = {0,1,0,-0.01};
    planos.push_back(plano_d);
    GLfloat plano_b[4] = {0,1,1,9.99};
    planos.push_back(plano_b);
    GLfloat plano_f[4] = {0,0,-1,9.99};
    planos.push_back(plano_f);
    GLfloat plano_l[4] = {-1,1,0,9.99};
    planos.push_back(plano_l);
    GLfloat plano_r[4] = {1,0,0,9.99};
    planos.push_back(plano_r);
    //-------------------sombra-------------------


    carregar("../cenarioSalvo.txt");

    GUI gui = GUI(800,600,desenha,teclado,mouse);

}




