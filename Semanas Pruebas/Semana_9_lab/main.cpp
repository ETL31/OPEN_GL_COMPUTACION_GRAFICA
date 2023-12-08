#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define M_PI 3.14159265
#include <stdlib.h>
#include<math.h>
float blue[]={0,0.1,0.4}, black[] = {0,0,0}, white[]={1,1,1};
float cyan[]={0,0.8,0.8};
float red[] = {1,0,0}, green[]={0,0.504,0}, yellow[]={1,1,0};
float  pink[]={0.93,0.54,0.44}, orange[]={1,0.5,0};
float R = 1.25;
float r = 0.5;

void Circunferencia(float *XY, float R, float *rgb, int M, float T,float ini,float fin){
    glColor3fv(rgb);
    switch (M) {
             case 2: {  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                        glPointSize(T);
                        glBegin(GL_POLYGON);
                        break;
                      }
             case 3: {glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                      glLineWidth(T);
                      glBegin(GL_POLYGON);
                      break;
                     }
            default: { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                glBegin(GL_POLYGON);
                glVertex2f(XY[0],XY[1]);
                    }
            }
    glBegin(GL_POLYGON);

    for (float i = ini; i <= fin ; i = i + 0.001){
            glVertex2f(R*cos(i) + XY[0], R*sin(i) + XY[1]);
    }

    glEnd();
}

float GetPointCos(float R, int angle) {
	return (R*cos(angle * M_PI / 180));
}

float GetPointSin(float R, int angle) {
	return (R*sin(angle *M_PI / 180));
}
void estrella (float *A,float *c)
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
void cuadrilatero(float x, float y , float a,float b, float c, float d,float e,float f,float *C,int mod)
{

    glColor3fv(C);
switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_QUADS); break;


    }
    glVertex2f(x,y);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glEnd();

}
void inicio()
{
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-25,25,-25,25);
    glClearColor(0,0,0,0);
}

void display (void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    float C[]={0,0};
    float D[]={0,-5};
    float E[]={0.753*5,2.85*5};
    //float []={0,0};
    Circunferencia(C,23,blue,1,1,0,2*M_PI);
    Circunferencia(D,15,cyan,1,1,5*M_PI/4,7*M_PI_4);

    cuadrilatero(0,-5,0.32*5,-1.06*5,0,-1.37*5,-0.32*5,-1.06*5,blue,2);
    glColor3fv(cyan);
    for (float j=1;j<=2;j=j+1){
    glBegin(GL_POLYGON);

    glVertex2f(0,-5);//C
    glVertex2f(-3.26*5*pow(-1,j),2.37*5);//D
    for (float i = 0.739*M_PI; i <= 143.69/180*M_PI ; i = i + 0.0005){
            glVertex2f(20*cos(i)*pow(-1,j), 20*sin(i));
    }

    glVertex2f(-2.73*5*pow(-1,j),2.92*5);//E
    glVertex2f(-0.91*5*pow(-1,j),1.64*5);//F
    glVertex2f(-0.41*5*pow(-1,j),2.56*5);//G
    glVertex2f(0,2.56*5);//H
    }

    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-2.93*5,1.45*5);//C
    glVertex2f(-3.97*5,0.38*5);//D
    for (float i = 0.8295*M_PI; i <= 174.40/180*M_PI ; i = i + 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(-3.48*5,2.06*5);

    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-2.11*5,0.43*5);//C
    glVertex2f(-3.77*5,-1.26*5);//D
    for (float i = M_PI; i <= 198.55/180*M_PI ; i = i + 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(-4*5,0);
    glVertex2f(-2.77*5,1.24*5);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.01*5,-0.78*5);//C
    glVertex2f(-2.93*5,-2.71*5);//D
    for (float i = 1.131*M_PI; i <= 222.72/180*M_PI ; i = i + 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(-3.63*5,-1.59*5);
    glVertex2f(-1.85*5,0.20*5);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.99*5,1.41*5);//C
    glVertex2f(3.48*5,2.03*5);//D
    for (float i = 0.167*M_PI; i >= 5.59/180*M_PI ; i = i - 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(3.97*5,0.389*5);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.11*5,0.426*5);//C
    glVertex2f(2.81*5,1.19*5);//D
    for (float i = 0; i >= -18.832/180*M_PI ; i = i - 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(4*5,0*5);
    glVertex2f(3.81*5,-1.3*5);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1.03*5,-0.799*5);//C
    glVertex2f(1.88*5,0.144*5);//D
    for (float i =-24.54/180*M_PI; i >= -42.87/180*M_PI ; i = i - 0.0005){
            glVertex2f(20*cos(i), 20*sin(i));
    }
    glVertex2f(3.65*5,-1.67*5);
    glVertex2f(2.94*5,-2.73*5);

    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-0.41*5,2.56*5);//C
    glVertex2f(-0.166*5,3.03*5);//D
    for (float i =67.23/180*M_PI; i <= 93.57/180*M_PI ; i = i + 0.0005){
            glVertex2f(18*cos(i), 18*sin(i));
    }
    glVertex2f(0.79*5,2.76*5);
    glVertex2f(0.49*5,2.55*5);

    glEnd();

Circunferencia(E,2.15,blue,1,1,0,2*M_PI);

    float color[]={234.0/255.0,150.0/255.0,194.0/255.0};
    for (float i=0; i<=M_PI/2;i=i+M_PI/20)
    {
        float A[]={22*cos(i),22*sin(i)};
        color[1]= color[1]-20.0/255.0;
         color[2]= color[2]+3.10/255.0;
        estrella(A,color);
    }

    float color1[]={242.0/255,78.0/255.0,0/255.0};
    for (float i=M_PI/2; i<=M_PI;i=i+M_PI/20)
    {
        float A[]={22*cos(i),22*sin(i)};
        color1[1]= color1[1]-9.35/255.0;
         color1[2]= color1[2]+11.6/255.0;
         color1[3]= color1[3]+1.3/255.0;
        estrella(A,color1);
    }

    float color2[]={26.0/255.0,246.0/255.0,38.0/255.0};
    for (float i=M_PI; i<=3*M_PI/2;i=i+M_PI/20)
    {
        float A[]={22*cos(i),22*sin(i)};
        color2[1]= color2[1]-9.35/255.0;
         color2[2]= color2[2]+11.6/255.0;
         color2[3]= color2[3]-1.3/255.0;
        estrella(A,color2);
    }

 float color3[]={255.0/255.0,251.0/255.0,0/255.0};
    for (float i=3*M_PI/2; i<=2*M_PI;i=i+M_PI/20)
    {
        float A[]={22*cos(i),22*sin(i)};
        color3[1]= color3[1]-9.35/255.0;
         color3[2]= color3[2]+11.6/255.0;
         color3[3]= color3[3]-1.3/255.0;
        estrella(A,color2);
    }

    //glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("Computación Gráfica 1.2");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
