#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<cmath>
#endif
#include <stdlib.h>
#define M_PI 3.141516


float white[]={1,1,1};
float black[]={0,0,0};
float negro[]={0,0,0},blanco[]={1,1,1},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};




void Circunferencia(float x0, float y0,float r, float theta1,float theta2, float *Color,int mod)
{
 glColor3fv(Color);
  switch (mod)
  {
      case 1: glBegin(GL_POINTS); break;
      case 2: glBegin(GL_LINES); break;
      case 3: glBegin(GL_LINE_LOOP); break;
      case 4: glBegin(GL_LINE_STRIP); break;
      case 5: glBegin(GL_POLYGON); break;


  }
    glVertex2f(x0,y0);
    for(float i=theta1;i>=theta2;i=i-0.01 )
    {
        glVertex2f(r*cos(i)+x0,r*sin(i)+y0);
    }
    glEnd();
}


void circulos (float x,float y,int r, float *Color,int patron)
{
 glColor3fv(Color);
 switch (patron)
 {
     case 1: glBegin(GL_LINE_LOOP); break;
     case 2: glBegin(GL_POLYGON); break;


 }
 for (float i=0;i<2*M_PI;i=i+0.001)
 {
  glVertex2f(r*cos(i)+x,r*sin(i)+y);
 }
glEnd();
}






void display1(void)
{
    glClearColor (0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers
    //Circunferencia(0,4,1.5,M_PI_2,-M_PI_2,verde,GL_POINT) ;
    glLineWidth(7);
    circulos(0,0,8.18,blanco,2);
    Circunferencia(0,0,8.18,M_PI/2,-M_PI/2,rojo,5);
    circulos(0,4,4.15,blanco,2);




    glutSwapBuffers();//limpia la consola,


}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(500,500); //tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(1,1); //posicion de la ventana
    glutCreateWindow("Npetalos");
    glutDisplayFunc(display1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-12,12,-12,12);


    glutMainLoop(); //que aparesca la consola
    return EXIT_SUCCESS;
}
