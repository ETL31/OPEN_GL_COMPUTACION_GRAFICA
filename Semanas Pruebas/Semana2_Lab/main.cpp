#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);
    glClearColor(0,0,0,0);
}

void cuadrilatero(double *V1, double *V2, double *V3,double *V4,float *C, int M=0, int G=3)
{
glColor3fv(C);
switch(M)
{
case 1: {
glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
glPointSize(G);
break;
}
case 2: {
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glLineWidth(G);
break;
}
default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
glBegin(GL_POLYGON);
glVertex2d(V1[0],V1[1]);
glVertex2d(V2[0],V2[1]);
glVertex2d(V3[0],V3[1]);
glVertex2d(V4[0],V4[1]);
glEnd();
}

void triangulo(double *V1, double *V2, double *V3,float *C, int M=0, int G=3)
{
glColor3fv(C);
switch(M)
{
case 1: {
glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
glPointSize(G);
break;
}
case 2: {
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glLineWidth(G);
break;
}
default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
glBegin(GL_POLYGON);
glVertex2d(V1[0],V1[1]);
glVertex2d(V2[0],V2[1]);
glVertex2d(V3[0],V3[1]);
glEnd();
}


void display (void)
{
    float blue[]={0,0,1};
    float green[]={0,0.5,0};
    float orange[]={0.9,0.6,0.1};
    float cyan[]={0,1,1};
    float red[]={1,0,0};
    float yellow[]={1,1,0};
    float purple[]={1,0,1};
    float white[]={1,1,1};
    float black[]={0,0,0};
    float brown[]={0.5,0.35,0.05};
    float pink[]={0.9,0.7,0.7};

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    double v1[]={-2.5,3.5};
    double v2[]={1.5,3.5};
    double v3[]={-1,1.5};
    double v4[]={-4.5,1.5};
    cuadrilatero(v1,v2,v3,v4,blue,3,3);
    cuadrilatero(v1,v2,v3,v4,black,2,3);

    double v5[]={-4.5,4.5};
    double v6[]={-3,3};
    double v7[]={-4.5,1.5};
    double v8[]={-6,3};
    cuadrilatero(v5,v6,v7,v8,green,3,3);
    cuadrilatero(v5,v6,v7,v8,black,2,3);

    double a1[]={-4.5,4.5};
    double a2[]={-3,6};
    double a3[]={-3,3};
    triangulo(a1,a2,a3,cyan,3,3);
    triangulo(a1,a2,a3,black,2,3);

    double a4[]={-1,1.5};
    double a5[]={1.5,3.5};
    double a6[]={1.5,0-1.5};
    triangulo(a4,a5,a6,orange,3,3);
    triangulo(a4,a5,a6,black,2,3);

    double a7[]={-6,6};
    double a8[]={-4.5,4.5};
    double a9[]={-6,3};
    triangulo(a7,a8,a9,purple,3,3);
    triangulo(a7,a8,a9,black,2,3);

    double a10[]={1.5,3.5};
    double a11[]={6,0};
    double a12[]={1.5,-4.5};
    triangulo(a10,a11,a12,yellow,3,3);
    triangulo(a10,a11,a12,black,2,3);

    double a13[]={0,-6};
    double a14[]={6,0};
    double a15[]={6,-6};
    triangulo(a13,a14,a15,red,3,3);
    triangulo(a13,a14,a15,black,2,3);








    //glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("Tangram");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
