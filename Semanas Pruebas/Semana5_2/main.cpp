#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<cmath>
#endif
#include <stdlib.h>
#define M_PI 3.141516


float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};

void Inicio()
{
    glMatrixMode(GL_PROJECTION);
     gluOrtho2D(-3,3,-3,3);
}


void display1(void)
{
    glClearColor (0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers

    glLineWidth(3);

    //CARDIOIDE
    glBegin(GL_POLYGON);
    glVertex2f(-2,2);
    for (float i=0;i<2*M_PI;i=i+0.0001)
    {
        glColor3f(0,1,0);
        glVertex2f(((0.5)*(1-cos(i))*cos(i))-2,(0.5)*(1-cos(i))*sin(i)+2);

    }
    glEnd();

    //CARACOL
    glBegin(GL_POLYGON);
    glVertex2f(2,1);
    for (float i=0;i<2*M_PI;i=i+0.0001)
    {
        glColor3f(0,1,1);
        glVertex2f(((0.5)*(1+2*sin(i))*cos(i))+2,((0.5)*(1+2*sin(i))*sin(i))+1);

    }
    glEnd();

    //ROSA_PAR
     glBegin(GL_POLYGON);
     glVertex2f(0,0);
    for (float i=0;i<2*M_PI;i=i+0.00001)
    {
        glColor3f(1,0.5,0);
        glVertex2f(((sin(2*i))*cos(i)),((sin(2*i))*sin(i)));

    }
    glEnd();

    // ROSA_IMPAR
    glBegin(GL_POLYGON);
    glVertex2f(-2,-1.5);
    for (float i=0;i<2*M_PI;i=i+0.01)
    {
        glColor3f(0,0,1);
        glVertex2f(((cos(3*i))*cos(i))-2,((cos(3*i))*sin(i))-1.5);

    }
    glEnd();

    //LAMNDISCATA
    glBegin(GL_POLYGON);
    glVertex2f(2,-1.5);

    for (float i=0;i<=2*M_PI;i=i+0.00001)
    {
        glColor3f(1,0,0);
        glVertex2f((0.9*(sqrt((sin(2*i)))*cos(i))+2),(0.9*(sqrt((sin(2*i)))*sin(i)))-1.5);

    }
    glEnd();





    glutSwapBuffers();//limpia la consola,
    //glFlush();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(500,500); //tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   // glutCreateWindow("Circunferencia"); //nombre de la ventana


    glutInitWindowPosition(1,1); //posicion de la ventana
    glutCreateWindow("Figuras Parametricas: ");
    glutDisplayFunc(display1);
    Inicio();


    //glMatrixMode(GL_PROJECTION);
   // gluOrtho2D(-10,10,-10,10);


    glutMainLoop(); //que aparesca la consola


    return EXIT_SUCCESS;
}
