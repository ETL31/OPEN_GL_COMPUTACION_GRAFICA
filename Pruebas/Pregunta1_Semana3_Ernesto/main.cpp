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
/*
void lineas(float x, float y, float a, float b, float c, float d, float e, float f, float *color, int grosor, int pattern)
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
    glLineStipple(3,pat);
    glLineWidth(grosor);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);

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
    glLineStipple(2,pat);
    glLineWidth(grosor);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+lado,y);
    glVertex2f(x+lado,y+lado);
    glVertex2f(x,y+lado);

    glEnd();
    glDisable(GL_LINE_STIPPLE);


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



void rellenodepoligono(float x, float y, float lado, float *color, int s,int tamano)
{
    glColor3fv(color);
    int pat;

    switch (s)
    {
        case 0:
             glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
             glLineWidth(tamano);
        break;
        case 1:
             glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
             glLineWidth(tamano);
        break;
        case 2:
             glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
             glLineWidth(tamano);
        break;
    }

    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+lado,y);
    glVertex2f(x+lado,y+lado);
    glVertex2f(x,y+lado);
    glEnd();

}
*/

void display (void)
{
    glClearColor(0,0,0,0); //opcional:color de la venta (negro)
    glClear(GL_COLOR_BUFFER_BIT);

GLubyte mosca[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08 } ;


glColor3f(0,1,0);
glEnable(GL_POLYGON_STIPPLE);
glPolygonStipple(mosca);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

glBegin(GL_POLYGON);
glVertex2f(-4,-4);
glVertex2f(4,-4);
glVertex2f(4,4);
glVertex2f(-4,4);
glEnd();

glDisable(GL_POLYGON_MODE);


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
