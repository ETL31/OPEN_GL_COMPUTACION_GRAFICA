#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

void inicio ()
{
    glMatrixMode(GL_PROJECTION);
    int a=7;
    gluOrtho2D(-a,a,-a,a);
}

void poligono(float x, float y, float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glVertex2f(g,h);
    glVertex2f(j,k);

    glEnd();

}

void Pintado(float x, float y, float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glVertex2f(g,h);
    glVertex2f(j,k);

    glEnd();
}


void display (void)
{
    glClearColor(1,1,1,1); //opcional:color de la venta (negro)
    glClear(GL_COLOR_BUFFER_BIT);

    //CABEZA

    poligono(-2.61,-0.21,-2.72,1.12,-2.61,1.65,-2.5,2.38,-2.31,2.62,-2.0,3.0,negro,2);
    poligono(-2.0,3.0,-2.32,3.66,-2.95,4.27,-1.5,4.0,-1.13,3.6,0.0,3.5,negro,2);
    poligono(0.0,3.5,1.12,3.61,1.5,4.0,2.94,4.26,2.36,3.66,2.0,3.0,negro,2);
    poligono(2.0,3.0,2.32,2.6,2.48,2.39,2.62,1.66,2.71,1.11,2.59,-0.18,negro,2);
    poligono(0.0,0.0,-0.88,0.67,-1.09,-0.06,-0.88,0.67,-2.61,-0.21,-1.56,0.78,negro,2);
    poligono(-1.56,0.78,-0.88,0.67,-1.56,0.78,-2.17,1.43,-2.72,1.12,-2.61,1.65,negro,2);
    poligono(-2.61,1.65,-2.17,1.43,-2.04,2.42,-2.5,2.38,-2.31,2.62,-2.04,2.42,negro,2);
    poligono(-2.04,2.42,-2.31,2.62,-1.27,3.0,0.0,3.5,1.24,2.99,2.32,2.6,negro,2);
    poligono(2.32,2.6,2.0,2.5,2.18,1.45,1.55,0.79,0.87,0.69,0.0,0.0,negro,2);
    poligono(0.0,0.5,-0.2,1.1,-1.28,1.21,-1.69,1.61,-1.83,2.38,-1.64,2.31,negro,2);
    poligono(-1.64,2.31,-1.48,2.27,-1.13,2.15,-0.84,2.07,-0.57,1.98,0.0,2.5,negro,2);
    poligono(0.0,2.5,0.57,1.97,1.46,2.26,1.68,2.34,1.84,2.39,1.67,1.61,negro,2);
    poligono(1.67,1.61,1.28,1.2,0.21,1.11,0.0,0.5,0.21,1.11,0.21,1.11,negro,2);
    poligono(-1.64,2.31,-1.5,1.7,-1.15,1.4,-0.61,1.38,-0.39,1.8,0.01,1.57,negro,2);
    poligono(0.01,1.57,0.41,1.82,0.62,1.4,1.15,1.39,1.5,1.69,1.68,2.34,negro,2);
    poligono(0.21,1.11,0.41,1.82,0.01,1.57,-0.39,1.8,-0.57,1.98,-0.67,1.52,negro,2);
    poligono(-0.67,1.52,-0.9,1.52,-1.31,1.72,-1.48,2.27,-1.13,2.15,-1.19,1.91,negro,2);
    poligono(-1.19,1.91,-1.06,1.81,-0.88,1.81,-0.84,2.07,-0.57,1.98,-0.39,1.8,negro,2);
    poligono(-0.39,1.8,-0.2,1.1,0.0,0.5,0.21,1.11,0.41,1.82,0.57,1.97,negro,2);
    poligono(0.57,1.97,0.67,1.55,0.92,1.53,1.31,1.75,1.46,2.26,1.13,2.15,negro,2);
    poligono(1.12,2.15,1.19,1.94,1.06,1.82,0.9,1.82,0.86,2.04,1.13,2.15,negro,2);
    poligono(-1.13,3.6,-1.27,3.0,-1.5,4.0,-2.32,3.66,-2.0,3.0,-1.27,3.0,negro,2);
    poligono(1.12,3.61,1.24,2.99,1.5,4.0,2.36,3.66,2.0,3.0,1.24,2.99,negro,3);
    poligono(-1.27,3.0,-0.57,1.98,0.0,2.5,0.57,1.97,1.24,2.99,0.0,2.5,negro,2);
    poligono(-1.83,2.38,-2.04,2.42,-2.31,2.62,-1.27,3.0,0.0,2.5,0.0,2.5,negro,2);
    poligono(1.84,2.39,2.0,2.5,2.18,1.45,2.18,1.45,2.18,1.45,2.18,1.45,negro,2);
    poligono(2.71,1.11,2.18,1.45,1.67,1.61,1.28,1.2,1.55,0.79,2.59,-0.18,negro,2);
    poligono(0.21,1.11,0.87,0.69,1.55,0.79,2.59,-0.18,0.87,0.69,1.11,-0.07,negro,2);
    poligono(-0.2,1.1,-0.88,0.67,-1.56,0.78,-1.28,1.21,-1.69,1.61,-2.17,1.43,negro,2);


    //CUERPO

    poligono(3.69,-3.2,2.59,-0.18,1.11,-0.07,0.0,0.0,-1.09,-0.06,-2.61,-0.21,negro,2);
    poligono(-2.61,-0.21,-3.68,-3.19,-2.42,-3.83,0.02,-5.64,2.46,-3.76,3.69,-3.2,negro,2);
    poligono(0.02,-5.64,1.0,-3.16,2.46,-3.76,2.9,-2.76,3.69,-3.2,2.9,-2.76,negro,2);
    poligono(2.9,-2.76,2.59,-0.18,1.57,-1.46,1.57,-1.46,0.0,0.0,-1.58,-1.46,negro,2);
    poligono(-1.58,-1.46,-1.09,-0.06,-1.58,-1.46,-2.61,-0.21,-2.88,-2.77,-3.68,-3.19,negro,2);
    poligono(-1.58,-1.46,-2.88,-2.77,-2.42,-3.83,-1.02,-3.16,0.02,-5.64,1.0,-3.16,negro,2);
    poligono(1.0,-3.16,0.03,-2.71,-1.02,-3.16,-2.42,-3.83,-1.3,-2.43,-2.88,-2.77,negro,2);
    poligono(1.0,-3.16,1.3,-2.43,0.03,-2.71,-1.3,-2.43,-1.02,-3.16,-1.3,-2.43,negro,2);
    poligono(-1.3,-2.43,0.0,0.0,1.3,-2.43,2.46,-3.76,2.9,-2.76,1.3,-2.43,negro,3);
    poligono(2.9,-2.76,1.57,-1.46,1.11,-0.07,0.0,0.0,0.0,0.0,0.0,0.0,negro,2);



    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana
    glutInitWindowPosition(0,0);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutCreateWindow("Rosa"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);
    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
