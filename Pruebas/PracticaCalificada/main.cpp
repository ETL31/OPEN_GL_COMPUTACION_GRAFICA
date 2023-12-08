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
    int a=10;
    gluOrtho2D(-a,a,-a,a);
}


void triangulolinea(float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}


void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    triangulolinea(-5,-1.7,0.3,4.96,5.78,-1.64,amarillo,10);
    triangulolinea(-5.16,0.88,5.68,0.9,0.3,-5.6,amarillo,10);

    triangulolinea(0.34,0.08,-3.44,-4.16,4.18,-4.12,azul,10);
    triangulolinea(-3.84,2.06,4.24,1.98,0.3,-4.02,azul,10);
    triangulolinea(0.265,3.449,-3.560,-2.661,4.149,-2.604,verde,10);

    triangulolinea(-3.008,3.677,3.635,3.620,0.265,-1.462,verde,10);
    triangulolinea(-1.714,0.212,2.264,0.193,0.265,-2.528,rojo,10);
    triangulolinea(-1.714,-1.043,2.207,-1.06,0.322,1.869,rojo,10);
    triangulolinea(-1.104,-0.567,0.322,0.688,1.674,-0.567,cyan,10);





    glutSwapBuffers();
 }

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializar la ventana

    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//Especifica el tipo de modo de visualizacion al crear una ventana(Activa el buffer de colores de tipo RGB

    glutInitWindowPosition(10,10);//Posicion de la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutCreateWindow("Pregunta1"); //Nombre que se le da a la ventana
    glutDisplayFunc(display);


    inicio();


    glutMainLoop(); //Hace que aparezca la ventana
    return EXIT_SUCCESS; //Puedes colocar tambien Return 0

}
