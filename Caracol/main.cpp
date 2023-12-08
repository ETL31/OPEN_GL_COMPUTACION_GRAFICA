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
void antenas ()
{
    glBegin(GL_LINE_STRIP);
    glVertex2d(-5.44,4.75);
    glVertex2d(-4.89,3.44);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2d(-3.61,4.75);
    glVertex2d(-3.8,3.68);
    glEnd();

     glBegin(GL_LINE_STRIP);
    glVertex2d(7.53,-3.69);
    glVertex2d(2.99,-4.49);
    glEnd();

}





void display1(void)
{
    glClearColor (1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers

 glLineWidth(5);
//Caracol

circulo(3,3,1.5,black,1,2*M_PI,0);
circulo(3,3,3,black,1,2*M_PI,0);
circulo(3,3,5.5,black,1,2*M_PI,0);
circulo(-4,2,1.7,black,1,3*M_PI/2,M_PI/7);
circulo(-5.5,5.5,0.75,black,1,2*M_PI,0);
circulo(-3.5,5.5,0.75,black,1,2*M_PI,0);
antenas();
circulo(3,3,7.5,black,1,3*M_PI/2,8*M_PI/7.18);
circulo(-4,2.5,0.25,black,2,2*M_PI,0);
circulo(-5.5,2,0.65,black,1,2*M_PI,3*M_PI/2);
circulo(7.5,-2,1.7,black,1,13*M_PI/25,-M_PI/2);


















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
