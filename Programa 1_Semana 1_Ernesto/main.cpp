#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

float negro[]={0,0,0},blanco[]={1,1,1},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};


void inicio ()
{
    glMatrixMode(GL_PROJECTION);
    int a=18;
    gluOrtho2D(-a,a,-a,a);
}

void cuadrado(float x, float y, float lado, float *color)
{
    glColor3fv(color);
    //glLineWidth(s);
    //glPointSize(s);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x,y+lado);
    glVertex2f(x+lado,y+lado);
    glVertex2f(x+lado,y);
    glEnd();
}

void display(void)
{
glClearColor(0,0,0,0);// color de fondo de ventana
glClear(GL_COLOR_BUFFER_BIT);

cuadrado(-8,-8,5,cyan);
cuadrado(0,0,5,rojo);
cuadrado(8,8,5,naranja);



 glutSwapBuffers();
 // glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // Inicializar la ventana de Opengl
    glutInitWindowPosition(0,0); //posicion de la ventana
    glutInitWindowSize(800,600); //tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH); //Especifica el tipo de modo de visualizacion al crear una ventana (Activa el buffer de colores de tipo RGB)

    glutCreateWindow("Primer programa"); //Nombre que se le da a la ventana
    glutDisplayFunc(display); //nombre de la funcion
    inicio();

    //glClearColor(1,0,0,0);  //opcional: color de la venta (Negro)
    glutMainLoop(); //Hace que aperezca la ventana
    return EXIT_SUCCESS; // Puedes colocar tambien return 0

}
