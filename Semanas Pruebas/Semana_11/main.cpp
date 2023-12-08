#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>
float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1}, marron[] = {0.5,0.35,0.05};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};



void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1,1,1 );
    glLoadIdentity ();
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0);
    glScalef (1.0, 2.0, 1.0);
    glutWireCube (1.0);
    glutSwapBuffers();
}

void reshape (int w,int h)
{
    glViewport(0,0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1.5,20);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializa la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutInitWindowPosition(1,1); //Posición de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("código");
    glutDisplayFunc(display); //Evento renderizado
    glutReshapeFunc(reshape);
    glutMainLoop();

    return EXIT_SUCCESS;
}
