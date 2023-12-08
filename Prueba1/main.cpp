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

void cuadrado (float x , float y, float lado, float *C)
{
glColor3fv(C);
glBegin(GL_QUADS);
glVertex2f(x, y);
glVertex2f(x + lado, y);
glVertex2f(x+lado, y - lado );
glVertex2f(x, y-lado );
glEnd();
}

void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0; i<12; i++)
    {
        int s;
        s=10*i;
        cuadrado(-58+s,42,5,black);
    }

/*
    cuadrado(-58,42,5,black);
    cuadrado(-48,42,5,black);
    cuadrado(-38,42,5,black);
    cuadrado(-28,42,5,black);
    cuadrado(-18,42,5,black);
    cuadrado(-8,42,5,black);
    cuadrado(2,42,5,black);
    cuadrado(12,42,5,black);
    cuadrado(22,42,5,black);
    cuadrado(32,42,5,black);
    cuadrado(42,42,5,black);
    cuadrado(52,42,5,black);
    */


    // ojos

    cuadrado(-60,37,120,pink);

    for (int j=0;j<2;j++)
    {
        int l;
        l=60*j;

        cuadrado(-38+l,0,20,white);
        cuadrado(-33+l,-5,9,green);
    }

    /*
    cuadrado(-38,0,20,white);
    cuadrado(-33,-5,9,green);
    cuadrado(22,0,20,white);
    cuadrado(27,-5,9,green);*/

    //nariz

    cuadrado(-8,-25,20,orange);

    //boca

    cuadrado(-38,-60,5,red);

    for (int k=0 ; k<10 ; k++)
    {   int m;
        m=8*k;
        cuadrado(-38+m,-65,8,red);
    }
    cuadrado(-38,-60,5,red);
    cuadrado(37,-60,5,red);

    /*
    cuadrado(-38,-60,5,red);
    cuadrado(-38,-65,8,red);
    cuadrado(-30,-65,8,red);
    cuadrado(-22,-65,8,red);
    cuadrado(-14,-65,8,red);
    cuadrado(-6,-65,8,red);
    cuadrado(2,-65,8,red);
    cuadrado(10,-65,8,red);
    cuadrado(18,-65,8,red);
    cuadrado(26,-65,8,red);
    cuadrado(34,-65,8,red);
    cuadrado(35,-65,8,red);
    cuadrado(38,-60,5,red);
    */

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
