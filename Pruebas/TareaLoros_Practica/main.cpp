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
    gluOrtho2D(-8.5,8.5,-8.5,7);
}

void ojos (float x, float y, float r,float theta1, float theta2, int n, float *color, float l)
{
    glColor3fv(color);
    glLineWidth(l);

    switch(n)
    {
    case 1:
        glBegin(GL_LINES);break;
    case 2:
        glBegin(GL_LINE_STRIP);break;
    case 3:
        glBegin(GL_LINE_LOOP);break;

    case 4:
        glBegin(GL_POLYGON); break;
    }

    for (float T=theta1 ; T<theta2 ; T=T+0.01)
        {
            glVertex2f(r*cos(T)+x,r*sin(T)+y);
        }

    glEnd();
}

void circulos (float x, float y, float r,float theta1, float theta2, int n, float *color, float l)
{
    glColor3fv(color);
    glLineWidth(l);

    switch(n)
    {
    case 1:
        glBegin(GL_LINES);break;
    case 2:
        glBegin(GL_LINE_STRIP);break;
    case 3:
        glBegin(GL_LINE_LOOP);break;

    case 4:
        glBegin(GL_POLYGON); break;
    }

    glVertex2f(x,y);
    for (float T=theta1 ; T<theta2 ; T=T+0.01)
        {
            glVertex2f(r*cos(T)+x,r*sin(T)+y);
        }

    glEnd();
}

void rectangulo(float x,float y, float lado1, float lado2, int n, float *color, float l)
{
    glColor3fv(color);
    glLineWidth(l);

    switch(n)
    {
    case 1:
        glBegin(GL_LINES);break;
    case 2:
        glBegin(GL_LINE_STRIP);break;
    case 3:
        glBegin(GL_LINE_LOOP);break;
    case 4:
        glBegin(GL_POLYGON); break;
    }

    glVertex2f(x,y);
    glVertex2f(x+lado1,y);
    glVertex2f(x+lado1,y+lado2);
    glVertex2f(x,y+lado2);

    glEnd();
}


void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    //CUADRO EXT

    rectangulo(-7.69,-7.6,15.42,13.79,4,verde,4);
    rectangulo(-7.69,-7.6,15.42,13.79,3,negro,4);

    //LORO 1

    circulos(-3.41,-0.66,6.9,0,M_PI/2,4,azul,3);
    circulos(-3.41,1.92,4.27,M_PI/2,M_PI,4,amarillo,3);
    circulos(-5.05,1.93,2.61,M_PI,3*M_PI/2,4,rojo,3);
    circulos(-5.05,0.93,1.58,3*M_PI/2,2*M_PI,4,amarillo,3);
    circulos(-4.4,0.94,1,0,M_PI/2,4,azul,3);
    circulos(-4.41,1.31,0.61,M_PI/2,M_PI,4,amarillo,3);
    rectangulo(-5.06,0.93,0.65,0.37,4,rojo,3);

    circulos(-3.41,-0.66,6.9,0,M_PI/2,3,negro,3);
    circulos(-3.41,1.92,4.27,M_PI/2,M_PI,3,negro,3);
    circulos(-5.05,1.93,2.61,M_PI,3*M_PI/2,3,negro,3);
    circulos(-5.06,0.93,1.58,3*M_PI/2,2*M_PI,3,negro,3);
    circulos(-4.4,0.94,0.99,0,M_PI/2,3,negro,3);
    circulos(-4.41,1.31,0.61,M_PI/2,M_PI,3,negro,3);
    rectangulo(-5.06,0.93,0.65,0.37,3,negro,3);

    //LORO 2

    circulos(-7.68,-4.94,4.28,0,M_PI/2,4,amarillo,3);
    circulos(-6.0,-4.94,2.64,3*M_PI/2,2*M_PI,4,azul,3);
    circulos(-6.02,-5.96,1.64,M_PI,3*M_PI/2,4,rojo,3);
    circulos(-6.67,-5.95,1.01,M_PI/2,M_PI,4,amarillo,3);
    circulos(-6.66,-5.55,0.61,0,M_PI/2,4,rojo,3);
    rectangulo(-6.67,-5.95,0.65,0.37,4,amarillo,3);


    circulos(-7.68,-4.94,4.28,0,M_PI/2,3,negro,3);
    circulos(-6.0,-4.94,2.61,3*M_PI/2,2*M_PI,3,negro,3);
    circulos(-6.02,-5.96,1.64,M_PI,3*M_PI/2,3,negro,3);
    circulos(-6.67,-5.95,1.01,M_PI/2,M_PI,3,negro,3);
    circulos(-6.66,-5.55,0.61,0,M_PI/2,3,negro,3);
    rectangulo(-6.67,-5.95,0.65,0.37,3,negro,3);

    //LORO 3

    circulos(3.48,-7.59,6.91,M_PI/2,M_PI,4,rojo,3);
    circulos(3.49,-4.94,4.26,0,M_PI/2,4,amarillo,3);
    circulos(5.15,-4.94,2.58,3*M_PI/2,2*M_PI,4,azul,3);
    circulos(5.14,-5.94,1.64,M_PI,3*M_PI/2,4,rojo,3);
    circulos(4.46,-5.94,0.97,M_PI/2,M_PI,4,amarillo,3);
    circulos(4.46,-5.57,0.63,0,M_PI/2,4,rojo,3);
    rectangulo(4.46,-5.94,0.68,0.37,4,amarillo,3);

    circulos(3.48,-7.59,6.91,M_PI/2,M_PI,3,negro,3);
    circulos(3.49,-4.94,4.26,0,M_PI/2,3,negro,3);
    circulos(5.15,-4.94,2.58,3*M_PI/2,2*M_PI,3,negro,3);
    circulos(5.14,-5.94,1.64,M_PI,3*M_PI/2,3,negro,3);
    circulos(4.46,-5.94,0.97,M_PI/2,M_PI,3,negro,3);
    circulos(4.46,-5.57,0.63,0,M_PI/2,3,negro,3);
    rectangulo(4.46,-5.94,0.68,0.37,3,negro,3);

    //LORO 4

    circulos(7.74,1.95,4.22,M_PI/2,M_PI,4,amarillo,3);
    circulos(6.14,1.94,2.61,M_PI,3*M_PI/2,4,rojo,3);
    circulos(6.14,0.93,1.61,3*M_PI/2,2*M_PI,4,amarillo,3);
    circulos(6.75,0.94,0.99,0,M_PI/2,4,azul,3);
    circulos(6.74,1.32,0.6,M_PI/2,M_PI,4,amarillo,3);
    rectangulo(6.13,0.93,0.61,0.38,4,rojo,3);

    circulos(7.74,1.95,4.22,M_PI/2,M_PI,3,negro,3);
    circulos(6.14,1.94,2.61,M_PI,3*M_PI/2,3,negro,3);
    circulos(6.14,0.93,1.61,3*M_PI/2,2*M_PI,3,negro,3);
    circulos(6.75,0.94,0.99,0,M_PI/2,3,negro,3);
    circulos(6.74,1.32,0.6,M_PI/2,M_PI,3,negro,3);
    rectangulo(6.14,0.93,0.6,0.38,3,negro,3);

    //OJOS

    ojos(-2.1,3.31,sqrt(0.14),0,2*M_PI,4,blanco,4);
    ojos(-2.1,3.31,sqrt(0.14),0,2*M_PI,3,negro,4);
    ojos(-2.1,3.31,sqrt(0.02),0,2*M_PI,4,negro,4);

    ojos(-5.15,-4.14,sqrt(0.07),0,2*M_PI,4,blanco,3);
    ojos(-5.15,-4.14,sqrt(0.07),0,2*M_PI,3,negro,3);
    ojos(-5.15,-4.14,sqrt(0.01),0,2*M_PI,4,negro,3);

    ojos(2.17,-3.57,sqrt(0.14),0,2*M_PI,4,blanco,4);
    ojos(2.17,-3.57,sqrt(0.14),0,2*M_PI,3,negro,4);
    ojos(2.17,-3.57,sqrt(0.02),0,2*M_PI,4,negro,4);

    ojos(5.26,2.81,sqrt(0.07),0,2*M_PI,4,blanco,3);
    ojos(5.26,2.81,sqrt(0.07),0,2*M_PI,3,negro,3);
    ojos(5.26,2.81,sqrt(0.01),0,2*M_PI,4,negro,3);


    // CUADRO

    rectangulo(-7.69,-7.6,4.27,6.93,3,negro,4);
    rectangulo(-7.69,-0.65,4.28,6.88,3,negro,4);
    rectangulo(-3.41,-7.59,6.89,6.93,3,negro,4);
    rectangulo(-3.41,-0.66,6.89,6.91,3,negro,4);
    rectangulo(3.47,-7.59,4.26,6.9,3,negro,4);
    rectangulo(3.51,-0.68,4.26,6.9,3,negro,4);





    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutInitWindowPosition(10,10);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tama�o de la ventana
    glutCreateWindow("LorosRaros"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);


    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
