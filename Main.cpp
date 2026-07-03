#include "Temporizador.hpp"
#include "Circulo.hpp"
#include "Utilities.hpp"
#include "Estado.hpp"

#ifdef __linux__
#include <GL/glut.h>
#endif

GLfloat AspectRatio;
Temporizador temp_animate = Temporizador();
double deltaT_acumulado = 0;
/*Ponto p1 = Ponto(-25.0f, -25.0f);
Ponto p2 = Ponto(25.0f, -25.0f);
Ponto p3 = Ponto(25.0f, 25.0f);
Ponto p4 = Ponto(-25.0f, 25.0f);
Circulo circ = Circulo(Ponto(0.0f,0.0f), 10.0);*/
Estado estado;
Estado prox;

void init(){
    estado = Estado(leArq("stops.txt", 550u));
    cout << "arquivo lido" << endl;

    glClearColor(0.5f, 0.5f, 1.0f, 1.0f); // Fundo neutro escuro para nao contaminar paredes/teto

    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    //glEnable (GL_CULL_FACE );
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    //glShadeModel(GL_FLAT);
    //glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

    //ModoDeExibicao
    if (true) // Faces Preenchidas??
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void desenhaCirculo(Circulo c){
    glColor3f(0.75f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(c.posicao().x, c.posicao().y);
    double angulo = 0.0;
    for(int i = 0; i <= 40; i++){
        angulo = 2.0f * M_PI * i/40;
        glVertex2d(c.posicao().x + c.raio() * cos(angulo),
                   c.posicao().y + c.raio() * sin(angulo));
    }
    glEnd();
}

void desenhaEstado(Estado est){
    glColor3f(0.75f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    for(int i = 0; i < est.vec->size()-1; i++){
        glVertex2d((*est.vec)[i].x, (*est.vec)[i].y);
        glVertex2d((*est.vec)[i+1].x, (*est.vec)[i+1].y);
    }
    glVertex2d((*est.vec)[est.vec->size()-1].x, (*est.vec)[est.vec->size()-1].y);
    glVertex2d((*est.vec)[0].x, (*est.vec)[0].y);
    glEnd();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// cores chapadas, sem iluminacao
    glDisable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //cout << "a desenhar estado" << endl;
    desenhaEstado(estado);
    //cout << estado.dist << endl;
    //cout << "estado desenhado" << endl;
    prox = estado.geraUmMelhor();
    estado = prox;

    //for(Ponto p: *paradas){
        //desenhaCirculo(Circulo(p, 0.125));
    //}
    //desenhaCirculo(circ);

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h){

	// Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Define a area a ser ocupada pela area OpenGL dentro da Janela
    glViewport(0, 0, w, h);
    // Define os limites logicos da area OpenGL dentro da Janela
    glOrtho(-54.0, 53.0, -54.0, 53.0, 0.0, 10.0); // Projecao paralela Orthografica

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void animate(){
    double dt;
    dt = temp_animate.getDeltaT();
    deltaT_acumulado += dt;

    if(deltaT_acumulado > 1.0/30.0){//fps 30
        deltaT_acumulado = 0;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(775,775);
    glutCreateWindow("Algoritmos geneticos");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutIdleFunc(animate);
    glutMainLoop();
}