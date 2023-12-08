#include <windows.h> // utiliza la función Sleep (hace que se vea mas lento la ejecución)
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>// herramienta para opengl / se usa para el uso texturas
#endif
#include <stdlib.h>
void display(void)
{
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glLineWidth(4);
glColor3f(1,1,0);
glEnable(GL_LINE_STIPPLE);
glLineStipple (3, 0x1C47);
    glBegin(GL_LINES);
     glVertex2d(-0.5,0.0);
     glVertex2d(0.7,0.0);
    glEnd();
glDisable(GL_LINE_STIPPLE);

 glutSwapBuffers(); // intercambio de buffers (espacio en memoria.)

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);// inicializa la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(500,500);

    glutInitWindowPosition(0,0);
    glutCreateWindow("Pregunta 1a");
    glutDisplayFunc(display);

    glutMainLoop();// hace un bucle infinito

    }
    return EXIT_SUCCESS;
