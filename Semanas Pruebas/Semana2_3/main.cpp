#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void convexo(float x, float y, float lado, float a,  int s)
{
    switch(s)
    {
        case 0: glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
        glPointSize(3);
        glColor3f(1,1,1);
        break;
        case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glLineWidth(3);
        glColor3f(1,0,1);
        break;
        case 2: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glLineWidth(3);
        glColor3f(0,1,1);
        break;
    }
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+(lado/2),y-a);
    glVertex2f(x+lado,y);
    glVertex2f(x+lado,y-lado+a);
    glVertex2f(x+(lado/2),y-lado);
    glVertex2f(x,y-lado+a);

    glEnd();


}
void triangleconv(float x, float y, float lado, float a,  int s)
{
    switch(s)
    {

        case 0: glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glLineWidth(3);
        glColor3f(1,0,1);
        break;
        case 1: glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glLineWidth(3);
        glColor3f(0,1,1);
        break;
    }
      glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(x+lado,y);
    glVertex2f(x+lado,y-lado+a);
    glVertex2f(x+(lado/2),y-a);
    glVertex2f(x+(lado/2),y-lado);
    glVertex2f(x,y);
    glVertex2f(x,y-lado+a);
    glEnd();

    }
void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BITS);
    convexo(-10,10,4,1,0);
    convexo(7,10,4,1,1);
    convexo(-1,5,4,1,2);
    triangleconv(-10,-6,4,1,0);
    triangleconv(7,-6,4,1,1);

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
