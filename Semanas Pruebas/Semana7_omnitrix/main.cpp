#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<math.h>
#endif


#include <stdlib.h>


float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};

void circulo(float x,float y ,float r ,float *color, int mod,float Theta1,float Theta2)
{
    glColor3fv(color);
    switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_POLYGON);


         break;


    }
    glVertex2f(x,y);

    for (float i = Theta1;i >= Theta2; i = i -0.01)
    {
        glVertex2f(r*cos(i)+x,r*sin(i)+y);

    }
    glEnd();


}
void lineas ()
{
    glColor3fv(black);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2d(-5.5,0);
    glVertex2d(5.5,0);
    glVertex2d(0,-5.5);
    glVertex2d(0,5.5);
    glEnd();


}



void display(void){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);


circulo(0,0,5.5,white,2,2*M_PI,0);
lineas();
circulo(0,0,5,black,2,2*M_PI,0);
circulo(0,-1,5,green,2,3*M_PI/4,M_PI/4);
circulo(0,1,5,green,2,7*M_PI/4,5*M_PI/4);





    glutSwapBuffers();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Codigo");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);
    glClearColor(0,0,0,0);


    glutDisplayFunc(display);


    glutMainLoop();


    return EXIT_SUCCESS;
}
