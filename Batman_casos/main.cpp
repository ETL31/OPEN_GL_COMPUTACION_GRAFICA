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

void elipse(float x, float y, float r1, float r2, float a, float b ,float *c, int n)
{
    glColor3fv(c);
    glLineWidth(2);

    switch (n)
  {
      case 1: glBegin(GL_POINTS); break;
      case 2: glBegin(GL_LINES); break;
      case 3: glBegin(GL_LINE_LOOP); break;
      case 4: glBegin(GL_LINE_STRIP); break;
      case 5: glBegin(GL_POLYGON); break;


  }

    for(float i=a;i<b;i=i+0.00001)
    {
        glVertex2d(x + r1*cos(i),y + r2*sin(i));
    }
    glEnd();
}

void batman(float *c, int mod)
{
    float A=0.7, B=0.4, s=0;
    glColor3fv(c);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    switch (mod)
  {
      case 1: glBegin(GL_POINTS); break;
      case 2: glBegin(GL_LINES); break;
      case 3: glBegin(GL_LINE_LOOP); break;
      case 4: glBegin(GL_LINE_STRIP); break;
      case 5: glBegin(GL_POLYGON); break;


  }
    glVertex2d(0,0);
    for(float i=0; i<2*M_PI; i=i+0.0001)
    {
        if (i>=0 && i<M_PI/3)
        {
            glVertex2f(A*cos(i),B*sin(i));
        }
        else if (i>=2*M_PI/3 && i<5*M_PI_4)
        {
            glVertex2f(A*cos(i), B*sin(i));
        }
        else if (i>=7*M_PI_4 && i<2*M_PI)
        {
            glVertex2f(A*cos(i), B*sin(i));
        }
        else if (i>=4*M_PI/3 && i<3*M_PI_2)
        {
            s=69.0*M_PI_4/4-i*15/8;
            glVertex2f(A/2*sin(2*s)*cos(s), A/2*sin(2*s)*sin(s)-B);
        }
        else if (i>=3*M_PI_2 && i<5*M_PI/3)
        {
            s=53.0*M_PI_4/4-i*15/8;
            glVertex2f(A/2*sin(2*s)*cos(s), A/2*sin(2*s)*sin(s)-B);
        }
        else if (i>=5*M_PI_4 && i<4*M_PI/3)
        {
            s=37.0*i/12-331.0*M_PI/144;
            glVertex2f(-0.3*sin(2*s)*cos(s)-0.505, A/2*sin(2*s)*sin(s)-B);
        }
        else if (i>=5*M_PI/3 && i<7*M_PI_4)
        {
            s=37.0*i/12-713.0*M_PI/144;
            glVertex2f(-0.3*sin(2*s)*cos(s)+0.505, A/2*sin(2*s)*sin(s)-B);
        }
        else if (i>=M_PI/3 && i<4*M_PI/9)
        {
            s=4.0*M_PI-27.0*i/4;
            glVertex2f(0.125*(1-cos(s))*cos(s)+0.32, 0.2*(1-cos(s))*sin(s)+B);
        }
        else if (i>=5*M_PI/9 && i<2*M_PI/3)
        {
            s=11.0*M_PI_4-27.0*i/4;
            glVertex2f(-0.125*(1-cos(s))*cos(s)-0.32, -0.2*(1-cos(s))*sin(s)+B);
        }
        else if (i>=4*M_PI/9 && i<13*M_PI/27)
        {
            glVertex2f(B*cos(i), 2.3*(B*cos(i)-A*cos(4.0*M_PI/9)) + 0.527);
        }
        else if (i>=14*M_PI/27 && i<5*M_PI/9)
        {
            glVertex2f(B*cos(i), -2.3*(B*cos(i)+A*cos(4.0*M_PI/9)) + 0.527);
        }
        else if (i>=13*M_PI/27 && i<14*M_PI/9)
        {
            glVertex2f(B*cos(i), 2.3*(B*cos(13.0*M_PI/27)-A*cos(4.0*M_PI/9)) + 0.527);
        }
    }
    glEnd();
}

void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    elipse(0,0,0.82,0.52,0,2*M_PI,black,5);
    elipse(0,0,0.8,0.5,0,2*M_PI,yellow,5);
    batman(black,5);
    batman(black,3);

    elipse(-0.225,0.381,0.141,0.25,M_PI,61*M_PI/36,yellow,5);
    elipse(0.225,0.381,0.141,0.25,47*M_PI/36,2*M_PI,yellow,5);

    elipse(-0.36,-0.31,0.13,0.175,11*M_PI/36,M_PI,yellow,5);
    elipse(0.36,-0.31,0.13,0.175,0,25*M_PI/36,yellow,5);

    elipse(-0.17,-0.225,0.1,0.09,4*M_PI/9,19*M_PI/18,yellow,5);
    elipse(0.17,-0.225,0.1,0.09,-M_PI/18,5*M_PI/9,yellow,5);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializa la ventana
    glutInitWindowSize(800,900); //Tamaño de la ventana
    glutInitWindowPosition(10,10); //Posición de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Batman");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
    glutDisplayFunc(display); //Evento renderizado

    glutMainLoop();

    return EXIT_SUCCESS;
}
