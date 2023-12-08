#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include <stdlib.h>
#define M_PI 3.1415

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

void inicio ()
{
    glMatrixMode(GL_PROJECTION);
    int a=9;
    gluOrtho2D(-a,a,-a,a);
}

void circulo(float x,float y ,float r , int m, float theta1,float theta2,float *color)
{
    glColor3fv(color);
    switch (m)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_POLYGON);   break;
    }

    glVertex2f(x,y);
    for (float i = theta1; i>= theta2; i = i -0.01)
    {
        glVertex2f(r*cos(i)+x,r*sin(i)+y);
    }
    glEnd();
}
void lineas (float x, float y, float *color, float l)
{
    glColor3fv(color);
    glLineWidth(l);
    glBegin(GL_LINES);
    glVertex2d(x,0);
    glVertex2d(-x,0);
    glVertex2d(0,y);
    glVertex2d(0,-y);
    glEnd();

}


void display(void){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    circulo(0,0,5.5,2,2*M_PI,0,blanco);

    lineas(-5.5,-5.5,negro,10);
    circulo(0,0,5,2,2*M_PI,0,negro);

    circulo(0,-1,5,2,3*M_PI/4,M_PI/4,verde);
    circulo(0,1,5,2,7*M_PI/4,5*M_PI/4,verde);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutInitWindowPosition(10,10);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutCreateWindow("Omnitrix"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);


    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
