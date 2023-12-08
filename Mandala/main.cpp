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
float red[] = {1,0,0}, green[]={0,0.504,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={0.93,0.54,0.44}, orange[]={1,0.5,0};




void circulo(float x,float y ,float r ,float *color, int mod,float Theta1,float Theta2)
{
    glColor3fv(color);
    switch (mod)
    {
        case 1 : glBegin(GL_LINE_STRIP); break;
        case 2 : glBegin(GL_POLYGON);
                 glVertex2f(x,y);
        ; break;
    }

    for (float i = Theta1;i >= Theta2; i = i -0.01)
    {
        glVertex2f(r*cos(i)+x,r*sin(i)+y);
    }
    glEnd();


}
void estrella(float x,float y, float r , float *color)

{
glBegin(GL_LINE_STRIP);
glVertex2d(x,y);
glVertex2d(x+r,y+r);
glVertex2d(x+2*r,y);
glVertex2d(x+3.5*r,y);
glVertex2d(x+3.5*r+0.1,y-1.5*r);
glVertex2d(x+5*r,y-2*r);
glVertex2d(x+4.5*r,y-4*r);
glVertex2d(x+5*r,y-5.2*r);
glVertex2d(x+3.5*r+0.1,y-5.5*r);
glVertex2d(x+3.5*r,y-7*r);
glVertex2d(x+2*r,y-6.5*r);
glVertex2d(x+r,y-8*r);
glVertex2d(x,y-6.5*r);
glVertex2d(x-r,y-7*r);
glVertex2d(x-2*r,y-5.5*r);
glVertex2d(x-3*r,y-5.2*r);
glVertex2d(x-2.5*r,y-4*r);
glVertex2d(x-3*r,y-2*r);
glVertex2d(x-2*r,y-1.5*r);
glVertex2d(x-1.5*r,y+r*0.5);
glVertex2d(x,y);
glEnd();
}

void display1(void)
{
    glClearColor (1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers

 glLineWidth(3);
//Mandala
circulo(0,0,6,black,1,2*M_PI,0);
circulo(0,0,2.5,black,1,2*M_PI,0);
circulo(0,0,1.75,black,1,2*M_PI,0);
circulo(0,0,0.25,black,1,M_PI,0);
circulo(0.25,0,0.5,black,1,2*M_PI,M_PI);
circulo(0,0,0.75,black,1,M_PI,0);
circulo(0.25,0,1,black,1,2*M_PI,M_PI);
circulo(0,0,1.25,black,1,M_PI,0);
circulo(0.25,0,1.5,black,1,2*M_PI,M_PI);
estrella(-1,3,1,black);
estrella(-1,3.5,1.2,black);



    glutSwapBuffers();//limpia la consola,
    //glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(450,450); //tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   // glutCreateWindow("Circunferencia"); //nombre de la ventana


    glutInitWindowPosition(1,1); //posicion de la ventana
    glutCreateWindow("Circunferencia");
    glutDisplayFunc(display1);


    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-15,15,-15,15);


    glutMainLoop(); //que aparesca la consola


    return EXIT_SUCCESS;
}
