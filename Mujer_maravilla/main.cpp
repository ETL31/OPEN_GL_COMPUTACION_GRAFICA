#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<math.h>
#endif


#include <stdlib.h>

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0.2,0.19,0.90};
float red[] = {1,0.19,0.18}, green[]={0,1,0}, yellow[]={1,0.96,0.14};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0},grey[]={0.30,0.29,0.29};
float R = 0.5;
float r = 0.2;


void sector(float *centro ,float *c,float radio,float Theta1,float Theta2)
{
    for (int k=1; k<=2;k++)
    {
        switch (k)
        {
            case 1 : {
                glColor3fv(c);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(black);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }
         glVertex2fv(centro);
        glBegin(GL_POLYGON);


            for (float i = Theta1;i <= Theta2; i = i + 0.01)
        {
            glVertex2f(radio*cos(i)+centro[0],radio*sin(i)+centro[1]);

        }

        glEnd();

    }
}
float GetPointCos(float R, int angle) {
	return (R*cos(angle * M_PI / 180));
}

float GetPointSin(float R, int angle) {
	return (R*sin(angle *M_PI / 180));
}

void estrella (float *A)
{
    float pointA[2] = { 0+A[0], R +A[1]};
	float pointB[2] = { GetPointCos(R, 18)+A[0], GetPointSin(R, 18)+A[1] };
	float pointC[2] = { GetPointCos(R, 54)+A[0], -GetPointSin(R, 54)+A[1] };
	float pointD[2] = { -GetPointCos(R, 54)+A[0], -GetPointSin(R, 54)+A[1] };
	float pointE[2] = { -GetPointCos(R, 18)+A[0], GetPointSin(R, 18)+A[1] };
	float pointa[2] = { 0+A[0], -r +A[1]};
	float pointb[2] = { -GetPointCos(r, 18)+A[0], -GetPointSin(r, 18)+A[1] };
	float pointc[2] = { -GetPointCos(r, 54)+A[0], GetPointSin(r, 54)+A[1] };
	float pointd[2] = { GetPointCos(r, 54)+A[0], GetPointSin(r, 54) +A[1]};
	float pointe[2] = { GetPointCos(r, 18)+A[0], -GetPointSin(r, 18) +A[1]};

	  for (int k=1; k<=2;k++)
    {
        switch (k)
        {
            case 1 : {
                glColor3fv(white);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(black);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }

    glBegin(GL_POLYGON);

	glVertex2fv(pointd);
	glVertex2fv(pointB);
	glVertex2fv(pointe);
	glVertex2fv(pointC);
	glVertex2fv(pointa);
	glVertex2fv(pointD);
	glVertex2fv(pointb);
	glVertex2fv(pointE);
	glVertex2fv(pointc);
    glVertex2fv(pointA);

	glEnd();
}
}
void simbolo ()
{
      glLineWidth(4);
    glColor3fv(yellow);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glVertex2d(-0.8,-0.7);
        glVertex2d(0, 1.3);
        glVertex2d(-0.8, -0.2);
        glVertex2d(-1.4, 1.3);
        glVertex2d(-4.3, 1.3);
        glVertex2d(-2.7, -0.5);
        glVertex2d(-1.8, -0.5);
        glVertex2d(-0.8,-2.5);
        glVertex2d(0, -1);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glVertex2d(0.8,-0.7);
        glVertex2d(0,-1);
        glVertex2d(0.8,-2.5);
        glVertex2d(1.8, -0.5);
        glVertex2d(2.7, -0.5);
        glVertex2d(4.3, 1.3);
        glVertex2d(1.4, 1.3);
        glVertex2d(0.8,- 0.2);
        glVertex2d(0,1.3);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glVertex2d(-0.8,-0.7);
        glVertex2d(0,1.3);
        glVertex2d(0.8,-0.7);
        glVertex2d(0,-1);
    glEnd();
//
    glColor3fv(black);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
        glVertex2d(0,1.3);
        glVertex2d(-0.8, -0.2);
        glVertex2d(-1.4, 1.3);
        glVertex2d(-4.3, 1.3);
        glVertex2d(-2.7, -0.5);
        glVertex2d(-1.8, -0.5);
        glVertex2d(-0.8,-2.5);
        glVertex2d(0, -1);
        glVertex2d(0.8,-2.5);
        glVertex2d(1.8, -0.5);
        glVertex2d(2.7, -0.5);
        glVertex2d(4.3, 1.3);
        glVertex2d(1.4, 1.3);
        glVertex2d(0.8,- 0.2);
        glVertex2d(0,1.3);
    glEnd();
//
    glBegin(GL_LINE_STRIP);
        glVertex2d(-3.8,0.7);
        glVertex2d(-1.8,0.7);
        glVertex2d(-0.8,-1.3);
        glVertex2d(0,0.5);
        glVertex2d(0.8,-1.3);
        glVertex2d(1.8,0.7);
        glVertex2d(3.8,0.7);
    glEnd();
//
    glBegin(GL_LINES);
        glVertex2d(-3.22,0.1);
        glVertex2d(-1.5,0.1);

        glVertex2d(3.22,0.1);
        glVertex2d(1.5,0.1);
    glEnd();
}

void display(void){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    float c1[]={0,0};
    sector(c1,grey,5,0,2*M_PI);
    sector(c1,red,4.75,0,2*M_PI);
    sector(c1,yellow,3.5,0,2*M_PI);
    sector(c1,blue,3.2,0,2*M_PI);

    for (float i=0; i<=2*M_PI;i=i+M_PI/4)
    {
        float A[]={4.1*cos(i),4.1*sin(i)};
        estrella(A);
    }
    simbolo();

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
