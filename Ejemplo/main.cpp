
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>


void cuadrado()
{
    float x=0.1,y=0.3,z=0.3;
    float h=0,v=0;


    for(int j=0; j<6; j++){
        glColor3f(x,y,z);
        glBegin(GL_QUADS);
        glVertex2d(-0.9+v,0.9+h);
        glVertex2d(-0.4+v,0.9+h);
        glVertex2d(-0.4+v,0.3+h);
        glVertex2d(-0.9+v,0.3+h);
        glEnd();


        v+=0.6; x+=0.2; y = 0.2; z+=0.2;
        if(j==2){
            h=-0.9; v=0;
        }
    }
}
static void display(void)
{
     glClearColor(0,0,0,0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    cuadrado();




    glutSwapBuffers();
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializa
    glutInitWindowSize(640,480); //tamaño de ventana
    glutInitWindowPosition(10,10); //posicion de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("Primer Codigo");


    glutDisplayFunc(display);
    gluOrtho2D(-100,100,-100,100);


    glutMainLoop();


    return EXIT_SUCCESS;
}
