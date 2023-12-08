#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0}, purple[]={0.8,0,0.408};

void Circunferencia(float *XY, float R, float *rgb, int M, float T){
glColor3fv(rgb);
switch (M) {
         case 2: {  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                    glPointSize(T);
                    break;
                  }
         case 3: {glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                  glLineWidth(T);
                  break;
                 }
        default: { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                }
        }


glBegin(GL_POLYGON);
for (float i = 0; i <= 2*M_PI ; i = i + 0.05)
glVertex2f(R*cos(i) + XY[0], R*sin(i) + XY[1]);
glEnd();
}




void petalo ( float *XY, float R , float *rgb,  float k){
glColor3fv(rgb);

glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glBegin(GL_POLYGON);
    for (float i = k; i <= 2*M_PI +k; i = i + 0.001)
{
    glVertex2f(R*cos(i) + XY[0], R*sin(i) + XY[1]);

}
glEnd();

glBegin(GL_POLYGON);

glVertex2f(R*cos(k+7*M_PI/4) + XY[0],R*sin(k+7*M_PI/4) + XY[1]);
glEnd();

}

void lineas (){

glColor3fv(black);
    glLineWidth(2);
    for ( float i = 0 ; i<= 2*M_PI ; i = i+ M_PI/4){
    glBegin(GL_LINES);
    glVertex2f(0.3*cos(i), 0.3*sin(i));
    glVertex2f(0.15*cos(i), 0.15*sin(i));
    glEnd();
    }
}

void display(void){

    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    float C[]={0,0};

      for ( float i=0; i<=2*M_PI;i=i+M_PI/4)
    {
        float A[]={1.1*cos(i),1.1*sin(i)};
        petalo(A,0.45,black,i);
    }

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Mandala I");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2,2,-2,2);
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
