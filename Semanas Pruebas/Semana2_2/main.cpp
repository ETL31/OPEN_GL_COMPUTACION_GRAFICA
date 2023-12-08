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
    gluOrtho2D(-12,12,-12,12);
    glClearColor(0,0,0,0);

}


void display (void)
{

    glClearColor(0.2,0.2,0.2,0.2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glPointSize(3);

    glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
    glBegin(GL_POLYGON);
    glVertex2d(-10,10);
    glVertex2d(-8,9);
    glVertex2d(-6,10);
    glVertex2d(-6,7);
    glVertex2d(-8,6);
    glVertex2d(-10,7);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2d(10,10);
    glVertex2d(10,7);
    glVertex2d(8,6);
    glVertex2d(6,7);
    glVertex2d(6,10);
    glVertex2d(8,9);
    glEnd();


    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2d(2,5);
    glVertex2d(2,2);
    glVertex2d(0,1);
    glVertex2d(-2,2);
    glVertex2d(-2,5);
    glVertex2d(0,4);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_TRIANGLE_STRIP);

    glVertex2d(-6,-10);
    glVertex2d(-6,-7);
    glVertex2d(-8,-11);
    glVertex2d(-8,-8);
    glVertex2d(-10,-10);
    glVertex2d(-10,-7);


    glEnd();



//    glVertex2d(-8,-11);
//
//
//    glVertex2d(-6,-10);
//
//
//    glVertex2d(-6,-7);
//
//
//    glVertex2d(-8,-8);
//
//
//    glVertex2d(-10,-7);
//

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(10,-10);
    glVertex2d(10,-7);
    glVertex2d(8,-11);
    glVertex2d(8,-8);
    glVertex2d(6,-10);
    glVertex2d(6,-7);





    glEnd();





    //glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);



    glutCreateWindow("Polygono Convexo");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
