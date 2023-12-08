#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>


float black[]={0,0,0}, white []={1,1,1}, blue[]={0,0,1};
float red[]={1,0,0}, green []={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink []={0.9,0.7,0.7}, orange[]={1,0.5,0};


void Rectangulo (float *XY , float *S, float *C, int M  , float G )
{  glColor3fv(C);
   switch (M)
     { case 2:{glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
        glPointSize(G);
        break;}
    case 3: { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         glLineWidth(G);
         break;}
    default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
glBegin(GL_QUADS);
glVertex2f(XY[0], XY[1]);
glVertex2f(XY[0] + S[1], XY[1]);
glVertex2f(XY[0] + S[1], XY[1] - S[0] );
glVertex2f(XY[0], XY[1] - S[0] );
glEnd();
}


void print2DcolorVertex (GLint size, GLint *count,
GLfloat *buffer)
{
int i;
printf (" ");
for (i = 0; i < 7; i++) {
printf ("%4.2f ", buffer[size-(*count)]);
*count = *count - 1;
}
printf ("\n");
}




void printBuffer(GLint size, GLfloat *buffer)

{
GLint count;
GLfloat token;
count = size;
while (count) {
token = buffer[size-count]; count--;
if (token == GL_PASS_THROUGH_TOKEN) {
printf ("GL_PASS_THROUGH_TOKEN\n");
printf (" %4.2f\n", buffer[size-count]);
count--;
}
else if (token == GL_POINT_TOKEN) {
printf ("GL_POINT_TOKEN\n");
print2DcolorVertex (size, &count, buffer);
}
else if (token == GL_LINE_TOKEN) {
printf ("GL_LINE_TOKEN\n");
print2DcolorVertex (size, &count, buffer);
print2DcolorVertex (size, &count, buffer);
}
else if (token == GL_LINE_RESET_TOKEN) {
printf ("GL_LINE_RESET_TOKEN\n");
print2DcolorVertex (size, &count, buffer);
print2DcolorVertex (size, &count, buffer);
}
}
}


void display(void)
{
    GLint size;
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BITS);
    GLfloat feedBuffer[1024];
    float A[]={0,0}, B[]={3,2};
    glFeedbackBuffer (1024, GL_3D_COLOR, feedBuffer);
    (void) glRenderMode (GL_FEEDBACK);
    Rectangulo(A,B,green,3,2);
    (int) glRenderMode (GL_RENDER);
size = glRenderMode (GL_RENDER);
printBuffer (size, feedBuffer);
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
