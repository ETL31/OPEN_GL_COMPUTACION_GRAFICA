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

void triangulo(float x, float y, float a, float b, float c, float d, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_TRIANGLES);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);


    glEnd();

}

void cuadrilatero(float x, float y, float a, float b, float c, float d, float e, float f, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);

    glEnd();

}

void cuadrilaterostrip(float x, float y, float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_QUAD_STRIP);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glVertex2f(g,h);
    glVertex2f(j,k);

    glEnd();

}

void poligon(float x, float y, float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glVertex2f(g,h);
    glVertex2f(j,k);

    glEnd();

}

void borde(float x, float y, float a, float b, float c, float d, float e, float f, float g, float h, float j, float k, float *color, float s)
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


void display (void)
{
    glClearColor(1,1,1,1); //opcional:color de la venta (negro)
    glClear(GL_COLOR_BUFFER_BIT);

    //*******Pintado

    triangulo(-5.73,0.23,-1.96,1.81,4.02,0.86,cyan,3);
    triangulo(-5.68,-0.55,-5.73,0.23,-5.42,0.1,azul,3);
    cuadrilatero(-5.73,0.23,-5.42,0.1,-4.38,0.17,-3.91,0.34,azul,3);
    triangulo(-4.38,0.17,-3.91,0.34,-3.83,-0.88,azul,3);

    cuadrilaterostrip(0.44,-0.85,-0.05,-0.86,0.99,0.13,-0.07,0.61,2.39,0.16,4.02,0.86,azul,3);
    cuadrilaterostrip(2.39,0.16,4.02,0.86,2.97,-0.72,4.02,0.66,3.9,-0.68,4.02,0.66,azul,3);

    //Coloar parte trasera

    cuadrilatero(3.9,-0.68,4.02,0.66,6.04,0.68,5.82,-0.53,verde,3);


    //Color Puertas

    cuadrilatero(-3.91,0.34,-3.83,-0.88,-2.04,-0.85,-2.04,0.47,amarillo,3);
    cuadrilatero(-2.04,-0.85,-2.04,0.47,-0.07,0.61,-0.05,-0.86,amarillo,3);

    //Color ventanas
    triangulo(-4.8,0.52,-3.26,1.18,-3.48,0.67,gris,3);
    poligon(-3.15,1.21,-3.32,0.68,-0.03,0.92,0.05,1.39,-1.98,1.68,-3.15,1.21,gris,3);

    //Color Capote
    poligon(-1.96,1.81,4.02,0.86,6.06,0.88,2.27,1.48,-0.12,1.78,-1.96,1.81,verde,3);

    //Color ruedas
    poligon(-5.6,-0.74,-5.22,-0.25,-4.56,-0.22,-4.17,-0.58,-4.01,-0.92,-4.08,-1.58,rosa,3);
    poligon(-4.08,-1.58,-4.4,-1.89,-5.24,-1.88,-5.63,-1.29,-5.6,-0.74,-5.6,-0.74,rosa,3);

    poligon(0.76,-1.53,0.83,-0.85,1.23,-0.37,2.09,-0.35,2.52,-0.8,2.7,-1.5,rosa,3);
    poligon(2.7,-1.5,2.29,-2.15,1.23,-2.2,0.76,-1.53,0.76,-1.53,0.76,-1.53,rosa,3);

    poligon(3.21,-1.43,3.22,-1.65,3.5,-1.96,4.2,-2.0,4.68,-1.74,4.68,-1.37,rosa,3);
    triangulo(4.68,-1.74,4.68,-1.37,4.87,-1.3,rosa,3);

    cuadrilatero(-2.83,-1.43,-2.59,-1.67,-1.98,-1.68,-1.73,-1.46,rosa,3);


    //Color luces traseras
    cuadrilatero(4.02,0.86,4.02,0.66,6.04,0.68,6.06,0.88,rojo,3);

    //Color de bordes inferiores

    cuadrilaterostrip(-5.68,-0.55,-5.68,-0.55,-5.36,-0.04,-5.42,0.1,-4.5,0.0,-4.38,0.17,negro,3);
    cuadrilaterostrip(-4.5,0.0,-4.38,0.17,-3.75,-1.4,-3.66,-1.19,0.76,-1.53,0.53,-1.22,negro,3);
    cuadrilaterostrip(0.76,-1.53,0.53,-1.22,0.61,-0.83,0.44,-0.85,1.01,-0.07,0.99,0.13,negro,3);
    cuadrilaterostrip(1.01,-0.07,0.99,0.13,2.15,-0.05,2.39,0.16,2.61,-0.74,2.97,-0.72,negro,3);

    cuadrilatero(2.97,-0.72,2.96,-0.89,3.9,-0.79,3.9,-0.68,negro,3);
    cuadrilatero(3.9,-0.79,3.9,-0.68,5.63,-0.54,5.63,-0.67,negro,3);

    cuadrilaterostrip(2.72,-0.91,3.9,-0.79,2.91,-1.44,3.97,-1.07,4.68,-1.37,5.85,-0.91,gris,3);
    cuadrilatero(3.97,-1.07,5.85,-0.91,5.89,-0.67,3.97,-0.78,gris,3);

    cuadrilaterostrip(-3.83,-0.88,-3.66,-1.19,-2.04,-0.85,-1.89,-1.18,-0.05,-0.86,0.09,-1.21,gris,3);
    cuadrilatero(-0.05,-0.86,0.09,-1.21,0.53,-1.22,0.44,-0.85,gris,3);

    //Color Puerta de gasolina

    cuadrilatero(2.39,0.16,2.61,-0.18,2.94,-0.18,2.93,0.18,amarillo,3);


    //******Bordes

    //superficie

    borde(-3.15,1.21,-3.32,0.68,-3.32,0.68,-0.03,0.92,-0.03,0.92,0.05,1.39,negro,3);
    borde(0.05,1.39,-1.98,1.68,-1.98,1.68,-3.15,1.21,-3.15,1.21,-3.15,1.21,negro,3);
    borde(-5.68,-0.55,-5.36,-0.04,-4.5,0.0,-4.17,-0.58,-4.01,-0.92,-3.75,-1.4,negro,3);
    borde(-3.75,-1.4,0.76,-1.53,0.61,-0.83,1.01,-0.07,2.15,-0.05,2.61,-0.74,negro,3);
    borde(2.61,-0.74,2.97,-0.72,2.96,-0.89,2.72,-0.91,2.91,-1.44,4.68,-1.37,negro,3);
    borde(5.85,-0.91,5.89,-0.67,5.63,-0.67,5.63,-0.54,5.63,-0.67,3.97,-0.78,negro,3);
    borde(3.9,-0.68,3.9,-0.79,3.97,-0.78,3.97,-1.07,2.91,-1.44,3.97,-1.07,negro,3);
    borde(2.96,-0.89,3.9,-0.79,3.97,-0.78,3.97,-1.07,2.91,-1.44,4.68,-1.37,negro,3);
    borde(4.68,-1.37,5.85,-0.91,3.97,-1.07,3.97,-0.78,5.63,-0.67,5.63,-0.54,negro,3);
    borde(3.9,-0.68,4.02,0.86,4.02,0.86,4.02,0.86,4.02,0.86,4.02,0.86,negro,3);
    borde(-3.91,0.34,-3.83,-0.88,-2.04,-0.85,-2.04,0.47,-3.91,0.34,-2.04,0.47,negro,3);
    borde(0.44,-0.85,-0.05,-0.86,-2.04,-0.85,-2.05,0.47,-0.07,0.61,-0.05,-0.86,negro,3);

    //Para poner gasolina

    borde(2.39,0.16,2.61,-0.18,2.94,-0.18,2.93,0.18,2.39,0.16,2.39,0.16,negro,3);


    //Ruedas

    borde(-5.6,-0.74,-5.22,-0.25,-4.56,-0.22,-4.17,-0.58,-4.01,-0.92,-4.08,-1.58,negro,3);
    borde(-4.08,-1.58,-4.4,-1.89,-5.24,-1.88,-5.63,-1.29,-5.6,-0.74,-5.6,-0.74,negro,3);

    borde(0.76,-1.53,0.83,-0.85,1.23,-0.37,2.09,-0.35,2.52,-0.8,2.7,-1.5,negro,3);
    borde(2.7,-1.5,2.29,-2.15,1.23,-2.2,0.76,-1.53,0.76,-1.53,0.76,-1.53,negro,3);

    borde(-2.83,-1.43,-2.59,-1.67,-1.98,-1.68,-1.73,-1.46,-1.73,-1.46,-1.73,-1.46,negro,3);

    borde(3.21,-1.43,3.22,-1.65,3.5,-1.96,4.2,-2.0,4.68,-1.74,4.87,-1.3,negro,3);



    //Contorno

    borde(-5.73,0.23,-1.96,1.81,-1.96,1.81,4.02,0.86,4.02,0.86,-5.73,0.23,negro,3);
    borde(-4.8,0.52,-3.26,1.18,-3.26,1.18,-3.48,0.67,-3.48,0.67,-4.8,0.52,negro,3);
    borde(-5.73,0.23,-5.68,-0.55,-5.68,-0.55,-5.42,0.1,-5.42,0.1,-4.38,0.17,negro,3);
    borde(-4.38,0.17,-3.83,-0.88,-3.83,-0.88,-3.66,-1.19,-3.66,-1.19,-1.89,-1.18,negro,3);
    borde(-1.89,-1.18,0.09,-1.21,0.09,-1.21,0.53,-1.22,0.53,-1.22,0.44,-0.85,negro,3);
    borde(0.44,-0.85,0.99,0.13,0.99,0.13,2.39,0.16,2.39,0.16,2.97,-0.72,negro,3);
    borde(2.97,-0.72,3.9,-0.68,3.9,-0.68,5.82,-0.53,5.82,-0.53,6.04,0.68,negro,3);
    borde(6.04,0.68,6.06,0.88,6.06,0.88,4.02,0.86,4.02,0.86,4.02,0.66,negro,3);
    borde(4.02,0.66,6.04,0.68,6.04,0.68,6.06,0.88,6.06,0.88,2.27,1.48,negro,3);
    borde(2.27,1.48,-0.12,1.78,-0.12,1.78,-1.96,1.81,-1.96,1.81,-5.73,0.23,negro,3);

    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana
    glutInitWindowPosition(0,0);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tama�o de la ventana
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutCreateWindow("Carro"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);
    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
