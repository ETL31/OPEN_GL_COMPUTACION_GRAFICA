#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define M_PI 3.14159
#include <stdlib.h>
#include <cmath>

using namespace std;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    float a=20;
    gluOrtho2D(-a,a,-a,a);
    glClearColor(1,1,1,1);
}

void circunferencia(double *XY, float R,float *C, int M=1, int G=3)
{
    glColor3fv(C);
    switch(M)
    {
        case 2: {
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
            glPointSize(G);
            break;
        }
        case 3: {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(G);
            break;
        }
        default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glBegin(GL_POLYGON);

    for (float i=0; i<=2*M_PI;i=i+0.01)
    {
        glVertex2f(R*cos(i)+XY[0],R*sin(i)+XY[1]);
    }

    glEnd();
}

void Rosa (float x, float y  ,int n,int d,float r,int mod, float *c)
{
    switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_POLYGON);
        glVertex2f(x,y);
        break;
    }


    for (float i=0;i<2*M_PI;i=i+0.00001)
    {
        glColor3fv(c);
        glVertex2f((r*(cos(n*i))*cos(d*i))+x,(r*(cos(n*i))*sin(d*i))+y);

    }
    glEnd();

}

void rosafor(double *XY, float R,int n,int d,float *C, int M=1, int G=3)
{
    glColor3fv(C);
    switch(M)
    {
        case 2: {
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
            glPointSize(G);
            break;
        }
        case 3: {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(G);
            break;
        }
        default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glBegin(GL_POLYGON);

    for (float i=0; i<=2*M_PI;i=i+0.01)
    {
        glVertex2f((R*(cos(n*i))*cos(d*i))+XY[0],(R*(cos(n*i))*sin(d*i))+XY[1]);
    }

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

    double C[]={0,0};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLineWidth(5);
    circunferencia(C, 14, black,4,4);

for (float i=0; i<=2*M_PI;i=i+M_PI/4 )
    {
        double B[]={7*cos(i),7*sin(i)};
    for (float j=-M_PI/2+i; j<=M_PI/2+i;j=j+M_PI/14)
    {
        double A[]={2*cos(j)+B[0],2*sin(j)+B[1]};
        circunferencia(A, 0.2, white,4,4);
    }

    }


for (float i=0; i<=2*M_PI;i=i+M_PI/40)
    {
        double A[]={7*cos(i),7*sin(i)};
        circunferencia(A, 0.18, cyan,4,4);
    }
 Rosa(0,0,6,7,6.5,1,blue);
 Rosa(0,0,6,3,2,1,white);
 Rosa(0,0,4,1,0.5,1,yellow);
 Rosa(0,0,2,3,3,1,green);
 glColor3fv(orange);
 glPointSize(5);
 glBegin(GL_POINTS);
 glVertex2d(0,0);
 glEnd();

 for (float i=0; i<=2*M_PI;i=i+M_PI/4)
    {
        double A[]={8*cos(i),8*sin(i)};
        circunferencia(A, 0.7, blue,4,4);
    }
for (float i=0; i<=2*M_PI;i=i+M_PI/4)
    {
        double A[]={8*cos(i),8*sin(i)};
        circunferencia(A, 0.5, cyan,4,4);
    }
for (float i=0; i<=2*M_PI;i=i+M_PI/40)
    {
        double A[]={9.5*cos(i),9.5*sin(i)};
        circunferencia(A, 0.25, blue,4,4);
    }
for (float i=0; i<=2*M_PI;i=i+M_PI/8 )
    {
        double B[]={9.6*cos(i),9.6*sin(i)};
    for (float j=-M_PI/2+i; j<=M_PI/2+i;j=j+M_PI/12)
    {
        double A[]={2*cos(j)+B[0],2*sin(j)+B[1]};
        circunferencia(A, 0.2, orange,4,4);
    }

    }

for (float i=0; i<=2*M_PI;i=i+M_PI/8)
    {
        double A[]={10.5*cos(i),10.5*sin(i)};
        rosafor(A,0.8,4,1,red,2,3);
    }

    for (float i=0; i<=2*M_PI;i=i+M_PI/6 )
    {
        double B[]={11.75*cos(i),11.75*sin(i)};
    for (float j=-M_PI/2+i; j<=M_PI/2+i;j=j+M_PI/6)
    {
        double A[]={2*cos(j)+B[0],2*sin(j)+B[1]};
        rosafor(A,0.5,3,1,yellow,2,3);
    }

    }
    for (float i=0; i<=2*M_PI;i=i+M_PI/6)
    {
        double A[]={14*cos(i),14*sin(i)};
        circunferencia(A, 0.7, blue,4,4);
    }
    for (float i=0; i<=2*M_PI;i=i+M_PI/6)
    {
        double A[]={14*cos(i),14*sin(i)};
        circunferencia(A, 0.4, green,4,4);
    }
     for (float i=0; i<=2*M_PI;i=i+M_PI/6)
    {
        double A[]={14*cos(i),14*sin(i)};
        circunferencia(A, 0.2, red,4,4);
    }
    //glFlush();
    glutSwapBuffers();

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("MANDALA");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
