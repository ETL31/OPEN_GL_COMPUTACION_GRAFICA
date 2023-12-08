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






void Circulo(float *XY, float r, float *C, int M=1, int G=3, int N=2,float o=0.1){
    glColor3fv(C);
    switch (M){
        case 2: {
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
            glPointSize(G);
            break;
            }
        case 3: {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(G);
            break;
            }


        default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    glBegin(GL_POLYGON);
    for (float T=0; T<2*M_PI; T = T + o)
        glVertex2f(XY[0]+r*sin(N*T)*cos(T),XY[1]+r*sin(N*T)*sin(T));
    glEnd();
}

void Lamndiscata (float x, float y , float r,int mod, float *c)
{
    glColor3fv(c);
    switch (mod)
    {
        case 1 : glBegin(GL_LINE_LOOP); break;
        case 2 : glBegin(GL_POLYGON);

         break;
    }

    glVertex2f(x,y);


    for (float i=0;i<=2*M_PI;i=i+0.00001)
    {

        glVertex2f((r*(sqrt((cos(2*i)))*cos(i))+x),(r*(sqrt((cos(2*i)))*sin(i)))+y);

    }
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(-0.10,1);
    glVertex2d(0.10,1);
    glVertex2d(0.1,-1);
    glVertex2d(-0.1,-1);
    glEnd();

}

void display(void){
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    Lamndiscata(0,0,0.5,2,green);
    float ef[2]={0,1};
    float gh[2]={0,1-0.35};
    Circulo(ef,0.8,red,1,1,10,0.001);
    Circulo(gh,0.5,yellow,1,5,1,0.001);







    glutSwapBuffers();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(800,900);
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
