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
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_POLYGON); break;


    }


    glVertex2f(x,y);
    for (float i = Theta1;i >= Theta2; i = i -0.01)
    {
        glVertex2f(r*cos(i)+x,r*sin(i)+y);

    }
    glEnd();


}

void cuadrado (float x , float y, float lado,int mod ,float *C)
{
glColor3fv(C);
switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_QUADS); break;


    }
glVertex2f(x, y);
glVertex2f(x + lado, y);
glVertex2f(x+lado, y - lado );
glVertex2f(x, y-lado );

glEnd();

}

void rombo (float x , float y, float lado,int mod ,float *C)
{
glColor3fv(C);
switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_QUADS); break;


    }
glVertex2f(x, y);
glVertex2f(x +lado, y-lado);
glVertex2f(x, y - 2*lado );
glVertex2f(x-lado, y-lado );

glEnd();

}

void cuadrilatero(float x, float y , float a,float b, float c, float d,float e,float f,float *C,int mod)
{

    glColor3fv(C);
switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_QUADS); break;


    }
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glEnd();

}

void triangulo (float x, float y , float a,float b, float c, float d,float *C,int mod)
{

    glColor3fv(C);
switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_TRIANGLES); break;


    }
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glEnd();

}


void display1(void)
{
    glClearColor (1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers

 glLineWidth(4);
//CORAZON
    circulo(-8.5,10.5,2,pink,1,3*M_PI/4,-M_PI/4);
    circulo(-8.5,10.5,2,green,2,3*M_PI/4,-M_PI/4);
    circulo(-8.5,10.5,2,pink,1,M_PI/4,0);

    circulo(-11.5,10.5,2,pink,1,5*M_PI/4,M_PI/4);
    circulo(-11.5,10.5,2,green,2,5*M_PI/4,M_PI/4);
    circulo(-11.5,10.5,2,pink,1,5*M_PI/4,3*M_PI/4);
    rombo(-10,11.82,2.85,2,green);
    rombo(-10,11.82,1.40,2,green);
    rombo(-10,11.82,2.85,1,pink);
    rombo(-10,11.82,1.40,1,pink);
    cuadrilatero(-11.5,10.5,-10,9.02,-10,6.12,-11.45,7.57,pink,1);

//Figura arriba medio
    cuadrado(-2,12,2,2,green);
    cuadrado(-2,12,2,1,pink);
    circulo(-1,12,2,green,2,3*M_PI/4,M_PI/4);
    circulo(-1,12,2,pink,1,3*M_PI/4,M_PI/4);
    circulo(-2,8,2,green,2,M_PI,M_PI/2);
    circulo(-2,8,2,pink,1,M_PI,M_PI/2);
    circulo(0,8,2,green,2,M_PI/2,0);
    circulo(0,8,2,pink,1,M_PI/2,0);
    cuadrilatero(-4,8,2,8,0,6,-2,6,green,2);
    cuadrilatero(-4,8,2,8,0,6,-2,6,pink,1);
    cuadrilatero(-2,10,0,10,0,6,-2,8,green,2);
    cuadrilatero(-2,10,0,10,0,6,-2,8,pink,1);
    circulo(0,6,2,green,2,M_PI/4,0);
    circulo(0,6,2,pink,1,M_PI/4,0);
    circulo(-2,6,2,green,2,M_PI,3*M_PI/4);
    circulo(-2,6,2,pink,1,M_PI,3*M_PI/4);


  // Figura arriba derecha

  cuadrado(6,8,2,2,green);
  cuadrado(6,8,2,1,pink);
  circulo(6,8,2,green,2,3*M_PI/2,M_PI);
  circulo(6,8,2,pink,1,3*M_PI/2,M_PI);
  circulo(6,8,2,green,2,M_PI,M_PI/2);
  circulo(6,8,2,pink,1,M_PI,M_PI/2);
  circulo(8,8,2, green,2,0,-M_PI/4);
  circulo(8,8,2,pink,1,0,-M_PI/4);
  circulo(8,8,2,green,2,7*M_PI/4,3*M_PI/2);
  circulo(8,8,2,pink,1,7*M_PI/4,3*M_PI/2);
  cuadrilatero(6,10,8,10,10,8,6,8,green,2);
  cuadrilatero(6,10,8,10,10,8,6,8,pink,1);
  cuadrilatero(8.60,12.40,10,10.94,10,8,8.67,9.32,green,2);
  cuadrilatero(8.60,12.40,10,10.94,10,8,8.67,9.32,pink,1);
  circulo(10,10.94,2,green,2,3*M_PI/4,M_PI/4);
  circulo(10,10.94,2,pink,1,3*M_PI/4,M_PI/4);
  triangulo(11.40,12.40,12.8,10.94,10,10.94,green,2);
  triangulo(11.40,12.40,12.8,10.94,10,10.94,pink,1);

  // figura del medio a la izquierda

  circulo(-10,0,2,green,2,7*M_PI/4,5*M_PI/4);
  circulo(-10,0,2,pink,1,7*M_PI/4,5*M_PI/4);
  cuadrilatero(-10,2,-8,0,-8,-2,-10,0,green,2);
  cuadrilatero(-10,2,-8,0,-8,-2,-10,0,pink,1);
  triangulo(-10,2,-10,0,-12,0,green,2);
  triangulo(-10,2,-10,0,-12,0,pink,1);
  cuadrado(-8,0,2,2,green);
  cuadrado(-8,0,2,1,pink);
  circulo(-8,-2,2,green,2,7*M_PI/4,5*M_PI/4);
  circulo(-8,-2,2,pink,1,7*M_PI/4,5*M_PI/4);
  circulo(-8,-2,2,green,2,0,-M_PI/4);
  circulo(-8,-2,2,pink,1,0,-M_PI/4);
  circulo(-12,-2,2,green,2,7*M_PI/4,5*M_PI/4);
  circulo(-12,-2,2,pink,1,7*M_PI/4,5*M_PI/4);
  circulo(-12,-2,2,green,2,5*M_PI/4,M_PI);
  circulo(-12,-2,2,pink,1,5*M_PI/4,M_PI);
  cuadrilatero(-14,0,-10,0,-12,-2,-14,-2,green,2);
  cuadrilatero(-14,0,-10,0,-12,-2,-14,-2,pink,1);

  //figura medio medio

  circulo(-1,0,2,green,2,3*M_PI/4,M_PI/4);
  circulo(-1,0,2,pink,1,3*M_PI/4,M_PI/4);
  cuadrilatero(0.40,1.42,2,0,0.42,-1.40,-1,0,green,2);
  cuadrilatero(0.40,1.42,2,0,0.42,-1.40,-1,0,pink,1);
  triangulo(1.77,2.81,2,0,0.4,1.42,green,2);
  triangulo(1.77,2.81,2,0,0.4,1.42,pink,1);
  circulo(0.42,-1.40,2,green,2,3*M_PI/2,5*M_PI/4);
  circulo(0.42,-1.40,2,pink,1,3*M_PI/2,5*M_PI/4);
  circulo(0.42,-1.40,2,green,2,0,-M_PI/2);
  circulo(0.42,-1.40,2,pink,1,0,-M_PI/2);
  circulo(-2.4,-1.42,2,green,2,7*M_PI/4,3*M_PI/2);
  circulo(-2.4,-1.42,2,pink,1,7*M_PI/4,3*M_PI/2);
  circulo(-2.4,-1.42,2,green,2,3*M_PI/2,M_PI);
  circulo(-2.4,-1.42,2,pink,1,3*M_PI/2,M_PI);
  cuadrilatero(-2.35,1.47,0.42,-1.4,-0.97,-2.82,-2.4,-1.42,green,2);
  cuadrilatero(-2.35,1.47,0.42,-1.4,-0.97,-2.82,-2.4,-1.42,pink,1);
  cuadrilatero(-3.66,2.82,-2.35,1.47,-2.4,-1.42,-3.8,0,green,2);
  cuadrilatero(-3.66,2.82,-2.35,1.47,-2.4,-1.42,-3.8,0,pink,1);


//figura medio derecha

rombo(9,2,3,2,green);
rombo(9,2,3,1,pink);
rombo(9,2,1.5,1,pink);
circulo(6,-1,2,green,2,3*M_PI/4,M_PI/4);
circulo(6,-1,2,pink,1,3*M_PI/4,M_PI/4);
circulo(12,-1,2,green,2,3*M_PI/4,M_PI/4);
circulo(12,-1,2,pink,1,3*M_PI/4,M_PI/4);
cuadrilatero(10.43,0.41,12,-1,9,-4,9,-1,pink,1);
circulo(10.43,-2.65,2,green,2,7*M_PI/4,5*M_PI/4);
circulo(10.43,-2.65,2,pink,1,7*M_PI/4,5*M_PI/4);
circulo(7.64,-2.65,2,green,2,7*M_PI/4,5*M_PI/4);
circulo(7.64,-2.65,2,pink,1,7*M_PI/4,5*M_PI/4);
circulo(7.64,-2.65,2,green,2,7*M_PI/4,3*M_PI/2);
circulo(7.64,-2.65,2,pink,1,7*M_PI/4,3*M_PI/2);
triangulo(10.43,0.41,10.43,-2.65,12,-1,pink,1);

//figura abajo izquierda

circulo(-10,-12,2,green,2,2*M_PI,0);
circulo(-10,-12,2,pink,1,M_PI/4,-M_PI/4);
circulo(-10,-12,2,pink,1,7*M_PI/4,5*M_PI/4);
circulo(-10,-12,2,pink,1,5*M_PI/4,3*M_PI/4);
cuadrilatero(-10,-9.22,-8.57,-10.59,-10,-12,-11.41,-10.59,green,2);
cuadrilatero(-10,-9.22,-8.57,-10.59,-10,-12,-11.41,-10.59,pink,1);
circulo(-10,-9.2,2,green,2,0,-M_PI/4);
circulo(-10,-9.2,2,pink,1,0,-M_PI/4);
circulo(-10,-9.2,2,green,2,5*M_PI/4,M_PI);
circulo(-10,-9.2,2,pink,1,5*M_PI/4,M_PI);
cuadrilatero(-12,-5.2,-10,-7.2,-10,-9.2,-12,-9.2,green,2);
cuadrilatero(-12,-5.2,-10,-7.2,-10,-9.2,-12,-9.2,pink,1);
cuadrilatero(-10,-7.2,-8,-5.2,-8,-9.2,-10,-9.2,green,2);
cuadrilatero(-10,-7.2,-8,-5.2,-8,-9.2,-10,-9.2,pink,1);
triangulo(-10,-9.2,-8,-7,-8,-9.2,pink,1);

//figura abajo medio

cuadrado(-2.4,-12,2,2,green);
cuadrado(-2.4,-12,2,1,pink);
circulo(-2.4,-14,2,green,2,M_PI,M_PI/2);
circulo(-2.4,-14,2,pink,1,M_PI,M_PI/2);
circulo(-0.4,-14,2,green,2,M_PI/2,0);
circulo(-0.4,-14,2,pink,1,M_PI/2,0);
circulo(-0.4,-14,2,pink,1,M_PI/4,0);
circulo(1.6,-10,2,green,2,M_PI/2,0);
circulo(1.6,-10,2,pink,1,M_PI/2,0);
cuadrilatero(-2.4,-10,1.6,-10,-0.4,-12,-2.4,-12,green,2);
cuadrilatero(-2.4,-10,1.6,-10,-0.4,-12,-2.4,-12,pink,1);
circulo(-4.4,-10,2,green,2,M_PI,M_PI/2);
circulo(-4.4,-10,2,pink,1,M_PI,M_PI/2);
cuadrilatero(-4.4,-8,-2.4,-10,-2.4,-12,-4.4,-10,green,2);
cuadrilatero(-4.4,-8,-2.4,-10,-2.4,-12,-4.4,-10,pink,1);
triangulo(-0.4,-10,1.6,-8,1.6,-10,green,2);
triangulo(-0.4,-10,1.6,-8,1.6,-10,pink,1);

//figura abajo derecha

circulo(9,-9,2,green,2,5*M_PI/4,3*M_PI/4);
circulo(9,-9,2,pink,1,5*M_PI/4,3*M_PI/4);
circulo(9,-9,2,green,2,M_PI/4,-M_PI/4);
circulo(9,-9,2,pink,1,M_PI/4,-M_PI/4);
circulo(9,-9,2,pink,1,0,-M_PI/4);
cuadrilatero(9.02,-6.11,10.4,-7.57,9,-9,7.57,-7.59,green,2);
cuadrilatero(9.02,-6.11,10.4,-7.57,9,-9,7.57,-7.59,pink,1);
circulo(10.42,-12.4,2,green,2,7*M_PI/4,5*M_PI/4);
circulo(10.42,-12.4,2,pink,1,7*M_PI/4,5*M_PI/4);
cuadrilatero(9,-9,10.42,-10.40,10.42,-12.4,7.59,-10.4,green,2);
cuadrilatero(9,-9,10.42,-10.40,10.42,-12.4,7.59,-10.4,pink,1);
triangulo(8.78,-11.25,10.42,-12.4,8.95,-13.76,green,2);
triangulo(8.78,-11.25,10.42,-12.4,8.95,-13.76,pink,1);

circulo(7.55,-12.42,2,green,2,7*M_PI/4,5*M_PI/4);
circulo(7.55,-12.42,2,pink,1,7*M_PI/4,5*M_PI/4);
cuadrilatero(7.59,-10.42,8.78,-11.25,8.95,-13.76,7.55,-12.42,green,2);
cuadrilatero(7.59,-10.42,8.78,-11.25,8.95,-13.76,7.55,-12.42,pink,1);
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
