#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void Recta(float *X0, float *X1, float *C, float A , int P )
{
glColor3fv(C);
glLineWidth(A);
glEnable(GL_LINE_STIPPLE);
switch (P)
{
       case 1: glLineStipple (1, 0x0101);
    break;
       case 2: glLineStipple (1, 0xAAAA);
    break;
      case 3: glLineStipple (1, 0x00FF);
    break;
      case 4: glLineStipple (1, 0x0c0F);
    break;
      case 5: glLineStipple (1, 0x1C47);
    break;
     default: glLineStipple (1, 0xFFFF);
    break;
}
glBegin(GL_LINES);
   glVertex2fv(X0);
   glVertex2fv(X1);
   glEnd();
glDisable(GL_LINE_STIPPLE);
}


void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BITS);
    float black []={0,0,0}, white[]={1,1,1},  blue[]={0,0,1};
    float green[]={0,0.5,0}, orange[]={0.9,0.6,0.1}, cyan[]={0,1,1};
    float red[]={1,0,0}, yellow[]={1,1,0},purple[]={1,0,1};
    float A1[]={-8,0};
    float A2[]={-4,0};
    float A3[]={-8,4};
    float A4[]={-4,4};

    Recta(A1,A2,blue,2,0);
    Recta(A3,A4,red,2,0);
    Recta(A3,A1,yellow,2,0);
    Recta(A4,A2,green,2,0);
    Recta(A3,A2,cyan,2,0);
    Recta(A4,A1,white,2,0);

    float A5[]={-2,0};
    float A6[]={2,0};
    float A7[]={-2,4};
    float A8[]={2,4};

    Recta(A5,A6,blue,2,2);
    Recta(A7,A8,red,2,2);
    Recta(A7,A5,yellow,2,2);
    Recta(A8,A6,green,2,2);
    Recta(A7,A6,cyan,2,2);
    Recta(A8,A5,white,2,2);

    float A9[]={4,0};
    float A10[]={8,0};
    float A11[]={4,4};
    float A12[]={8,4};

    Recta(A9,A10,blue,2,1);
    Recta(A11,A12,red,2,1);
    Recta(A11,A9,yellow,2,1);
    Recta(A12,A10,green,2,1);
    Recta(A11,A10,cyan,2,1);
    Recta(A12,A9,white,2,1);

    float A13[]={-8,-6};
    float A14[]={-4,-6};
    float A15[]={-8,-2};
    float A16[]={-4,-2};

    Recta(A13,A14,blue,2,3);
    Recta(A15,A16,red,2,3);
    Recta(A15,A13,yellow,2,3);
    Recta(A16,A14,green,2,2);
    Recta(A15,A14,cyan,2,0);
    Recta(A16,A13,white,2,3);

    float A17[]={-2,-6};
    float A18[]={2,-6};
    float A19[]={-2,-2};
    float A20[]={2,-2};

    Recta(A17,A18,blue,2,3);
    Recta(A19,A20,red,3,0);
    Recta(A19,A17,yellow,2,1);
    Recta(A20,A18,green,2,5);
    Recta(A19,A18,cyan,2,2);
    Recta(A20,A17,white,2,3);

    float A21[]={4,-6};
    float A22[]={8,-6};
    float A23[]={4,-2};
    float A24[]={8,-2};

    Recta(A21,A22,blue,2,2);
    Recta(A23,A24,red,3,2);
    Recta(A23,A21,yellow,2,2);
    Recta(A24,A22,green,2,2);
    Recta(A23,A22,cyan,2,4);
    Recta(A24,A21,white,2,4);




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
    gluOrtho2D(-10,10,-10,10);
    glutMainLoop();
    return EXIT_SUCCESS;
}
