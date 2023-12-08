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
    int a=9;
    gluOrtho2D(-a,a,-a,a);
}

void lineas(float x, float y, float a, float b, float *color, int grosor, int pattern)
{
    glColor3fv(color);
    int pat;

    switch (pattern)
    {
        case 0:
             pat=0x0101;
        break;
        case 1:
             pat=0xAAAA;
        break;
        case 2:
             pat=0x00FF ;
        break;
        case 3:
             pat=0x0C0F;
        break;
        case 4:
             pat=0x1C47;
        break;
    }

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,pat);
    glLineWidth(grosor);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(a,b);

    glEnd();
    glDisable(GL_LINE_STIPPLE);

}

void lineacuadrado(float x, float y, float lado, float *color, int grosor, int pattern)
{
    glColor3fv(color);
    int pat;

    switch (pattern)
    {
        case 0:
             pat=0x0101;
        break;
        case 1:
             pat=0xAAAA;
        break;
        case 2:
             pat=0x00FF ;
        break;
        case 3:
             pat=0x0C0F;
        break;
        case 4:
             pat=0x1C47;
        break;
    }

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,pat);
    glLineWidth(grosor);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+lado,y);
    glVertex2f(x+lado,y+lado);
    glVertex2f(x,y+lado);

    glEnd();
    glDisable(GL_LINE_STIPPLE);


}


void display (void)
{
    glClearColor(0,0,0,0); //opcional:color de la venta (negro)
    glClear(GL_COLOR_BUFFER_BIT);

    lineacuadrado(-8,1,4,rojo,3,0);
    lineas(-8,1,-4,5,blanco,3,0);
    lineas(-8,5,-4,1,amarillo,3,0);

    lineacuadrado(-3,1,4,azul,3,1);
    lineas(-3,1,1,5,verde,3,1);
    lineas(-3,5,1,1,naranja,3,1);

    lineacuadrado(2,1,4,amarillo,3,2);
    lineas(2,1,6,5,rojo,3,2);
    lineas(2,5,6,1,rosa,3,2);

    lineas(-8,-1,-8,-5,amarillo,3,1);
    lineas(-8,-5,-4,-5,azul,3,0);
    lineas(-4,-5,-4,-1,verde,3,2);
    lineas(-4,-1,-8,-1,rojo,3,3);
    lineas(-8,-1,-4,-5,cyan,3,0);
    lineas(-8,-5,-4,-1,blanco,3,1);

    lineas(-3,-1,-3,-5,amarillo,3,0);
    lineas(-3,-5,1,-5,azul,3,2);
    lineas(1,-5,1,-1,verde,3,1);
    lineas(1,-1,-3,-1,rojo,3,0);
    lineas(-3,-1,1,-5,cyan,3,2);
    lineas(-3,-5,1,-1,blanco,3,1);

    lineas(2,-1,2,-5,amarillo,3,1);
    lineas(2,-5,6,-5,azul,3,1);
    lineas(6,-5,6,-1,verde,3,1);
    lineas(6,-1,2,-1,rojo,3,1);
    lineas(2,-1,6,-5,cyan,3,0);
    lineas(2,-5,6,-1,blanco,3,0);


    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana
    glutInitWindowPosition(0,0);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutCreateWindow("Pregunta1"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);
    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
