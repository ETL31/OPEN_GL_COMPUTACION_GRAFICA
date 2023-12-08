#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5,5,-5,5);
    glClearColor(0,0,0,0);
}

void display (void)
{
    glClearColor(0.2,0.2,0.2,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3);
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1,0,0);

    glVertex3d(0.5,1,0);
    glVertex3d(0,0,0);
    glVertex3d(1,0,0);


    glVertex3d(1.5,1,0);

    glEnd();



    //glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("Computación Gráfica 1.2");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
