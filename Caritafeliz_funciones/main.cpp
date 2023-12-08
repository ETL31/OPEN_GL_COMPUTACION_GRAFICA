#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>


float pink []={0.9,0.7,0.7}, orange[]={1,0.5,0};

void cuadrado (float x , float y, float lado,float *C)
{
glColor3fv(C);
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + lado, y);
glVertex2f(x+lado, y - lado );
glVertex2f(x, y-lado );
glEnd();
}

void pelo()
{
    float x=0,y=0,z=0;
    float v=0;


    for(int j=0; j<12; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-58+v,42);
        glVertex2d(-53+v,42);
        glVertex2d(-53+v,37);
        glVertex2d(-58+v,37);
        glEnd();


        v+=10;
    }
}

void boca1()
{
    float x=1,y=0,z=0;
    float  v=0;


    for(int j=0; j<11; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-38+v,-65);
        glVertex2d(-30+v,-65);
        glVertex2d(-30+v,-73);
        glVertex2d(-38+v,-73);
        glEnd();


        v+=7.1;

    }
}

void boca2()
{
    float x=1,y=0,z=0;
    float  v=0;


    for(int j=0; j<2; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-38+v,-60);
        glVertex2d(-33+v,-60);
        glVertex2d(-33+v,-65);
        glVertex2d(-38+v,-65);
        glEnd();


        v+=74;

    }
}

void ojos()
{
    float x=1,y=1,z=1;
    float  v=0;


    for(int j=0; j<2; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-38+v,0);
        glVertex2d(-18+v,0);
        glVertex2d(-18+v,-20);
        glVertex2d(-38+v,-20);
        glEnd();


        v+=60;

    }
}
void pupilas()
{
    float x=0,y=1,z=0;
    float v=0;


    for(int j=0; j<2; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-33+v,-5);
        glVertex2d(-24+v,-5);
        glVertex2d(-24+v,-14);
        glVertex2d(-33+v,-14);
        glEnd();


        v+=60;

    }
}


void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);


    pelo();
    cuadrado(-60,37,120,pink);
    boca1();
    boca2();
    ojos();
    pupilas();
    cuadrado(-8,-25,20,orange);


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
    gluOrtho2D(-100,100,-100,100);
    glutMainLoop();
    return EXIT_SUCCESS;
}
