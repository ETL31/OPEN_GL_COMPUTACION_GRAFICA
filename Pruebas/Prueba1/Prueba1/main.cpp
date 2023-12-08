
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

using namespace std;
void Cubo();
void Tamano(int anch,int alto);
void tiempo(int param);

int valor=1;
GLfloat rotar=30.0f;

void tiempo(int param)
{
    glutPostRedisplay();
    glutTimerFunc(valor,tiempo,0);
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void Cubo(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //borra toda la pantalla

    glPushMatrix();

    glRotatef(rotar,2.0f,1.0f,1.0f); //rotacion

    glBegin(GL_LINE_LOOP);

    glColor3f(1.0,0.0,1.0);

    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,5.0);

    glColor3f(1.0,0.0,0.0);

    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,5.0,0.0);

    glColor3f(0.0,1.0,1.0);

    glVertex3f(0.0,0.0,0.0);
    glVertex3f(5.0,0.0,0.0);

    glColor3f(0.0,1.0,1.0);

    glVertex3f(0.0,0.0,5.0);
    glVertex3f(5.0,0.0,5.0);

    glColor3f(1.0,0.0,1.0);

    glVertex3f(0.0,5.0,0.0);
    glVertex3f(0.0,5.0,5.0);

    glColor3f(0.0,1.0,1.0);

    glVertex3f(0.0,0.0,5.0);
    glVertex3f(5.0,0.0,5.0);

    glColor3f(0.0,1.0,1.0);

    glVertex3f(0.0,5.0,5.0);
    glVertex3f(5.0,5.0,5.0);

    glColor3f(1.0,0.0,1.0);

    glVertex3f(5.0,5.0,5.0);
    glVertex3f(5.0,5.0,0.0);

    glColor3f(1.0,0.0,0.0);

    glVertex3f(5.0,0.0,5.0);
    glVertex3f(5.0,5.0,5.0);

    glColor3f(1.0,0.0,0.0);

    glVertex3f(0.0,5.0,5.0);
    glVertex3f(0.0,0.0,5.0);

    glColor3f(1.0,0.0,0.0);

    glVertex3f(5.0,0.0,0.0);
    glVertex3f(5.0,5.0,0.0);

    glColor3f(0.0,1.0,1.0);

    glVertex3f(0.0,5.0,0.0);
    glVertex3f(5.0,5.0,0.0);

    glColor3f(1.0,0.0,1.0);

    glVertex3f(5.0,0.0,0.0);
    glVertex3f(5.0,0.0,5.0);

    glEnd();

    glPopMatrix();
    glutSwapBuffers();

    rotar+=0.4;

}

void Tamano(int anch,int alto)
{   if(alto==0) alto=1;
    float razon=1.0*anch/alto;
    glMatrixMode(GL_PROJECTION); //Activa la proyeccion
    glLoadIdentity();    //Genera la imagen
    glViewport(0, 0, anch, alto);
    gluPerspective(50.0,razon,1,1000); //Acomoda el tamaño
    glMatrixMode(GL_MODELVIEW); //Activa la nueva imagen
    glLoadIdentity(); //Genera la imagen
    gluLookAt(16.0,12.0,20.0, //la camara
              0.0,0.0,0.0, //donde obsera la camara
              0.0,1.0,0.0); //eje principal
}

int main(int argc, char** argv)//argumentos
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Cubo");
    init();
    glutDisplayFunc(Cubo);
    glutReshapeFunc(Tamano);
    glutTimerFunc(valor,tiempo,0);
    glutMainLoop();
    return 0;
}
