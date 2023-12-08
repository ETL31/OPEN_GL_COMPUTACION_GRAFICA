#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
#include <stdlib.h>
#define M_PI 3.1415



float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1}, verdeoscuro[]={0.4,0.6,0.1},celeste[]={0.4,0.8,1}, amarillo1[]={1,1,0.2};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};


void pantalla()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-12,12,-12,12);

}

void circulo (float x, float y, float r, int patron, float *color, float p, float l )
{
    glColor3fv(color);
    glPointSize(p);
    glLineWidth(l);

    switch(patron)
    {
    case 1:
        glBegin(GL_POINTS);break;
    case 2:
        glBegin(GL_LINES);break;
    case 3:
        glBegin(GL_LINE_LOOP);break;

    case 4:
        glBegin(GL_POLYGON); break;
    }
        for (float Theta=0 ; Theta< 2*M_PI ; Theta = Theta + 0.1)
        {
            glVertex2f(r*cos(Theta)+x,r*sin(Theta)+y);
        }
        glEnd();
}

void linea (float x, float y, float w, float z, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(w,z);

    glEnd();

}

void cuadrado(float x, float y, float z, float a, float b, float c, float d, float e, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glVertex2f(d,e);

    glEnd();
}

void display(void)
{
glClearColor(1,1,1,0);//color de la ventana negro
glClear(GL_COLOR_BUFFER_BIT);


        cuadrado(-10.89364,12.49052,-9.30195,12.95035,11.63764,-7.81239,9.72761,-14.42675,celeste,3);
        cuadrado(-15.24426,-7.45868,7.39313,12.66738,8.87871,11.4294,-11.24735,-12.41061,amarillo1,3);

        circulo(0.82,2.01,1.42,4,rojo,2,2);
        circulo(0.66,0.19,0.87,4,cyan,2,2);
        circulo(-1.22,3.13,1.15,4,verde,2,2);
        circulo(-2.8,2.19,0.87,4,cyan,2,2);
        circulo(-3.28,4.45,1.29,4,rojo,2,2);
        circulo(-0.28,4.11,0.57,4,gris,2,2);
        circulo(0.72,4.75,0.84,4,verdeoscuro,2,2);
        circulo(-2.7,0.35,1.24,4,blanco,2,2);
        circulo(1.12,-0.31,0.59,4,negro,2,2);
        circulo(2.76,-2.23,0.5,4,amarillo1,2,2);
        circulo(-0.7,-2.93,0.87,4,negro,2,2);
        circulo(-1.44,0.43,1.75,4,verde,2,2);
        circulo(-1.1,1.65,7.08,3,verdeoscuro,2,15);
        circulo(-6.54,2.05,1,4,naranja,2,2);
        circulo(-6.54,2.05,0.74,4,rojo,2,2);
        circulo(-6.08,0.67,0.77,4,naranja,2,2);
        circulo(-4.98,-2.83,0.36,4,cyan,2,2);
        circulo(-2.84,-2.31,0.44,4,cyan,2,2);

        circulo(0.82,2.01,1.42,3,negro,2,2);
        circulo(0.66,0.19,0.87,3,negro,2,2);
        circulo(-1.22,3.13,1.15,3,negro,2,2);
        circulo(-2.8,2.19,0.87,3,negro,2,2);
        circulo(-3.28,4.45,1.29,3,negro,2,2);
        circulo(-0.28,4.11,0.57,3,negro,2,2);
        circulo(0.72,4.75,0.84,3,negro,2,2);
        circulo(-2.7,0.35,1.24,3,negro,2,2);
        circulo(1.12,-0.31,0.59,3,negro,2,2);
        circulo(2.76,-2.23,0.5,3,negro,2,2);
        circulo(-0.7,-2.93,0.87,3,negro,2,2);
        circulo(-1.44,0.43,1.75,3,negro,2,2);
        circulo(-6.54,2.05,1,3,negro,2,2);
        circulo(-6.54,2.05,0.74,3,negro,2,2);
        circulo(-6.08,0.67,0.77,3,negro,2,2);
        circulo(-4.98,-2.83,0.36,3,negro,2,2);
        circulo(-2.84,-2.31,0.44,3,negro,2,2);


        linea(1.76,6.85,-3.5,-4.23,negro,2);
        linea(-1.14,7.13,-6.74,-1.49,negro,2);
        linea(-6.98,0.33,0.78,-3.53,negro,2);
        linea(-7.8,2.15,3.74,-0.63,negro,2);
        linea(-3.94,7.19,3.42,0.21,negro,2);
        linea(-5.48,4.93,4.08,4.39,negro,2);
        linea(2.32,4.93,1.88,-2.59,negro,2);
        linea(-1.58,-2.87,1,-2.43,negro,2);
        linea(-1.26,-3.6,1.44,-3.03,negro,2);
        linea(-1.53,-3.21,1.32,-2.71,negro,2);
        linea(-3.88,-2.27,-2.42,-4.73,negro,2);
        linea(-4.38,-3.49,-2.14,-3.53,negro,2);
        linea(-5.12,2.19,-5.48,0.99,negro,2);
        linea(-4.76,5.43,-4.76,4.39,negro,2);
        linea(-5.16,5.49,-5.16,4.45,negro,2);
        linea(-6.48,4.49,3.64,-1.21,negro,2);
        linea(-12,12,12,12,negro,25);
        linea(12,12,12,-12,negro,25);
        linea(12,-12,-12,-12,negro,25);
        linea(-12,-12,-12,12,negro,25);

 glutSwapBuffers();
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);              //Sirve para inicializar mi ventana de opengl
    glutInitWindowPosition(0,0);        //parte la ventana en 4 partes y en (0,0) esta en el centro,posicion de mi ventana
    glutInitWindowSize(600,600);        //tamaño de mi ventana tamaño normal (600,600)
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);           //tipo de modo de visualizacion de la ventana

    glutCreateWindow("Semana 5");        //Colocar el nombre que se le da a la ventana
    glutDisplayFunc(display);                   //nombre de la función
    pantalla();
                            //glClearColor(1,1,1,1);//color de la ventana negro
    glutMainLoop();             //hace que aparezca la ventana
    return EXIT_SUCCESS;            //tambien se puede usar el return
}
