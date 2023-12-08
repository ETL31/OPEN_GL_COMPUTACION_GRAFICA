#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#define M_PI 3.1411516
#include <cmath>

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};



void display(void)
{
    glClearColor (0.1,0.2,0.2,0);
    glPointSize(3);
    glLineWidth(2);
    glBegin(GL_POINTS);

    for (float i=0 ; i< 2*M_PI ; i = i+ 0.1)
{

    glVertex2d(2*cos(i)-6,2*sin(i)+5);
}
    glEnd();


glBegin(GL_LINES);
for (float i=0; i<2*M_PI;i=i+0.01)
{   glColor3d(0,0,1);

    glVertex2f(2*cos(i)-1.5,2*sin(i)+5);
}
glEnd();



glBegin(GL_LINE_STRIP);
for (float i=0; i<2*M_PI;i=i+0.01)
{     glColor3d(1,1,1);

    glVertex2f(2*cos(i)+3,2*sin(i)+5);
}
glEnd();


glBegin(GL_LINE_LOOP);
for (float i=0; i<2*M_PI;i=i+0.01)
{   glColor3d(0.0,1,0.41);

    glVertex2f(2*cos(i)-3.5,2*sin(i));
}
glEnd();



glBegin(GL_POLYGON);
for (float i=0; i<2*M_PI;i=i+0.01)
{    glColor3d(1,1,1);
    glVertex2f(2*cos(i)+1,2*sin(i));
}
glEnd();


    glutSwapBuffers();//limpia la consola,
    //glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(600,600); //tamaño de la ventana
    glutInitWindowPosition(10,10); //posicion de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Circunferencia: "); //nombre de la ventana
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);

    glutMainLoop(); //que aparesca la consola

    return EXIT_SUCCESS;
}
