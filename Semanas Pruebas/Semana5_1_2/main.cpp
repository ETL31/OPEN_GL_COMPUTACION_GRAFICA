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




void display1(void)
{
    glClearColor (0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers


glBegin(GL_LINE_LOOP);
glVertex2d(-5,6);
for (float Theta=M_PI/4; Theta>-M_PI/4;Theta=Theta-0.1)
{   glColor3d(0,1,1);
    glVertex2d(2*cos(Theta)-5,2*sin(Theta)+6);
}
glEnd();




    glutSwapBuffers();//limpia la consola,
    //glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(350,350); //tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   // glutCreateWindow("Circunferencia"); //nombre de la ventana


    glutInitWindowPosition(1,1); //posicion de la ventana
    glutCreateWindow("Circunferencia");
    glutDisplayFunc(display1);


    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);


    glutMainLoop(); //que aparesca la consola


    return EXIT_SUCCESS;
}
