#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<cmath>
#include <stdlib.h>
#define M_PI 3.1415

float blue[]={0,0,1}, green[]={0,1,0}, orange[]={0.9,0.6,0.1}, cyan[]={0,1,1}, red[]={1,0,0}, yellow[]={1,1,0};
float purple[]={1,0,1}, white[]={1,1,1}, black[]={0,0,0}, brown[]={0.5,0.35,0.05}, pink[]={0.9,0.7,0.7};

void ejes(float k)
{
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(-k,0,0);
    glVertex3f(k,0,0);
    glColor3f(0,1,0);
    glVertex3f(0,-k,0);
    glVertex3f(0,k,0);
    glColor3f(0,0,1);
    glVertex3f(0,0,-k);
    glVertex3f(0,0,k);
    glEnd();
}

void taza()
{
    glBegin(GL_LINE_STRIP);
    for ( float z=0;z<=5;z=z+0.1)
      {   glColor3f(z/15,z/15,z/9);
          for(float t=0;t<=2*M_PI;t=t+0.001)
         { glVertex3f(9*sqrt(z)*cos(t),z,9*sqrt(z)*sin(t));
         }
      }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for ( float z=0;z<=20;z=z+0.01)
      {   glColor3f(z/8,z/18,z/7);
          for(float t=0;t<=2*M_PI;t=t+0.001)
         { glVertex3f(4*sqrt(z)*cos(t),z,4*sqrt(z)*sin(t));
         }
      }
    glEnd();
}


static void display(void)
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ejes(500);

    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslated(0,0,-30);
    taza();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslated(60,0,-30);
    taza();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslated(0,0,30);
    taza();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.3,0.3);
    glTranslated(60,0,30);
    taza();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-50,50,-50,50,0.5,1000);
   //gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 60.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (30.0, 30.0, 30.0, 0, 0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Gráficas 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}
