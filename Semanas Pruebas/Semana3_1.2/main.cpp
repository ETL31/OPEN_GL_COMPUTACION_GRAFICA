#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>


float black[]={0,0,0}, white []={1,1,1}, blue[]={0,0,1};
float red[]={1,0,0}, green []={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink []={0.9,0.7,0.7}, orange[]={1,0.5,0};


void Recta(float *X0, float *X1, float *C, float A, int P)
{
 glColor3fv(C);
 glLineWidth(A);
 glEnable(GL_LINE_STIPPLE);
    switch (P)
          {
           case 1: glLineStipple (1, 0x0101); break;
           case 2: glLineStipple (1, 0xAAAA); break;
           case 3: glLineStipple (1, 0x00FF); break;
           case 4: glLineStipple (1, 0x0c0F); break;
           case 5: glLineStipple (1, 0x1C47); break;
           default: glLineStipple (1, 0xFFFF);break;
}
   glBegin(GL_LINES);
   glVertex2fv(X0);
   glVertex2fv(X1);
   glEnd();
glDisable(GL_LINE_STIPPLE);
}
void cuadrado(float x, float y, float lado, float ancho,float tipo1, float tipo2, float tipo3,float tipo4,float tipo5,float tipo6)
{
    float A1[]={x,y}, A2[]={x+lado,y}, A3[]={x+lado,y+lado}, A4[]={x,y+lado};
    Recta(A1,A2,blue,3,0);
    Recta(A2,A3,green,3,0);
    Recta(A3,A4,red,3,0);
    Recta(A4,A1,yellow,3,0);
          //Diagonlaes
    Recta(A2,A4,cyan,3,0);
    Recta(A1,A3,white,3,0);


}


void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BITS);


    cuadrado(-8,0,5,2,1,0,0,0,0,0);
    cuadrado(-2,0,5,2,1,0,0,0,0,0);
    cuadrado(4,0,5,2,1,0,0,0,0,0);
    cuadrado(-8,-6,5,2,1,0,0,0,0,0);
    cuadrado(-2,-6,5,2,1,0,0,0,0,0);
    cuadrado(4,-6,5,2,1,0,0,0,0,0);




    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Primer codigo");
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-12,12,-12,12);
    glutMainLoop();
    return EXIT_SUCCESS;
}
