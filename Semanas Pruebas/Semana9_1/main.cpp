#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

float blue[]={0,0,1}, green[]={0,1,0}, orange[]={0.9,0.6,0.1}, cyan[]={0,1,1}, red[]={1,0,0}, yellow[]={1,1,0};
float purple[]={1,0,1}, white[]={1,1,1}, black[]={0,0,0}, brown[]={0.5,0.35,0.05}, pink[]={0.9,0.7,0.7};

void LogBatman()
{
    float A=0.7, B=0.4, s=0;

    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    for (float i = 0; i <= 2*M_PI; i = i + 0.009)
    {
            if ( i >=0 && i < M_PI/3)
        {
          glVertex2f(A*cos(i) , B*sin(i) );
        }
        else if ( i >=2*M_PI/3 && i <5*M_PI_4)
        {
         glVertex2f(A*cos(i) , B*sin(i) );
        }
        else if ( i >=7*M_PI_4 && i < 2*M_PI)
        {
        glVertex2f(A*cos(i) , B*sin(i));
        }

        else if (i >= 4*M_PI/3 && i< 3*M_PI_2)
           {  s=69*M_PI_4/4 - i*15/8;
           glVertex2f(A/2*sin(2*s)*cos(s) , A/2*sin(2*s)*sin(s) - B);
           }
        else if (i >= 3*M_PI_2 && i<5*M_PI/3)
        { s=53.0*M_PI_4/4 - i*15/8;
          glVertex2f(A/2*sin(2*s)*cos(s) , A/2*sin(2*s)*sin(s) - B);
        }

        else if (i > (5*M_PI_4) && i<4*M_PI/3)
            { s=37.0*i/12 - 331.0*M_PI/144;
            glVertex2f(-0.3*sin(2*s)*cos(s)-0.505, A/2*sin(2*s)*sin(s) - B);
            }

        else if (i >= 5*M_PI/3 && i<=7*M_PI_4)
            { s=37.0*i/12 - 713*M_PI/144;
             glVertex2f(-0.3*sin(2*s)*cos(s)+0.505, A/2*sin(2*s)*sin(s) - B);
            }
        if ( i >= M_PI/3 && i < 4*M_PI/9)
            { s= 4.0*M_PI - 27.0*i/4;
              glVertex2f(0.125*(1-cos(s))*cos(s) + 0.32 , 0.2*(1-cos(s))*sin(s)+B);
            }
        if ( i >=5*M_PI/9 && i < 2*M_PI/3)
        { s= 11.0*M_PI_4 - 27.0*i/4;
          glVertex2f(-0.125*(1-cos(s))*cos(s) - 0.32 , -0.2*(1-cos(s))*sin(s)+ B );
        }

        if ( i >= 4*M_PI/9 && i < 13.0*M_PI/27)
            { glVertex2f(B*cos(i) , 2.3*(B*cos(i)-A*cos(4.0*M_PI/9)) + 0.527);
            }

        if ( i >= 14.0*M_PI/27 && i < 5*M_PI/9)
            { glVertex2f(B*cos(i) , -2.3*(B*cos(i)+A*cos(4.0*M_PI/9)) + 0.527);
            }
        if ( i >= 13.0*M_PI/27 && i < 14.0*M_PI/27)
            { glVertex2f(B*cos(i), 2.3*(B*cos(13.0*M_PI/27) - A*cos(4.0*M_PI/9)) + 0.527);
            }

    }
    glEnd();
}
void display (void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    LogBatman();


    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Logo de Batman");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
