#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include <stdlib.h>
#define M_PI 3.1415

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={34.0/255.0,177.0/255.0,76.0/255.0},green2[]={181.0/255.0,230.0/255.0,29.0/255.0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={0.93,0.54,0.44}, orange[]={1,0.5,0}, brown[]={185.0/255.0,122.0/255.0,87.0/255.0},crema[]={0.937,0.784,0.125},  marron[]={0.55,0.28,0.14};
;


void circulo(float x,float y ,float r ,float *color, int mod,float Theta1,float Theta2)
{
    glColor3fv(color);
    switch (mod)
    {
        case 1 : glBegin(GL_LINE_STRIP); break;
        case 2 : glBegin(GL_POLYGON); break;


    }



    for (float i = Theta1;i >= Theta2; i = i -0.01)
    {
        glVertex2f(r*cos(i)+x,r*sin(i)+y);

    }
    glEnd();


}

void rama(){

    glColor3fv(green2);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.58,0.15);
    glVertex2f(-0.5,0.07);
    glVertex2f(-0.5,0.04);
    glVertex2f(-0.54,0.19);
    glVertex2f(-0.48,0.15);
    glVertex2f(-0.52,0.24);
    glVertex2f(-0.45,0.21);
    glVertex2f(-0.46,0.31);
    glVertex2f(-0.41,0.28);
    glVertex2f(-0.45,0.35);
    glVertex2f(-0.38,0.32);
    glVertex2f(-0.42,0.4);
    glVertex2f(-0.35,0.36);
    glVertex2f(-0.39,0.45);
    glVertex2f(-0.44,0.23);
    glVertex2f(-0.53,0.24);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.21,0.55);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.31,0.51);
    glVertex2f(-0.31,0.39);
    glVertex2f(-0.35,0.49);
    glVertex2f(-0.34,0.37);
    glVertex2f(-0.37,0.48);
    glVertex2f(-0.34,0.37);
    glVertex2f(-0.2,0.4);
     glVertex2f(-0.36,0.34);
    glVertex2f(-0.2,0.38);
     glVertex2f(-0.4,0.3);
    glVertex2f(-0.21,0.36);
    glVertex2f(-0.44,0.24);
    glVertex2f(-0.33,0.27);
    glVertex2f(-0.49,0.1);
    glVertex2f(-0.38,0.13);
    glVertex2f(-0.48,0.13);
    glVertex2f(-0.37,0.17);
    glVertex2f(-0.49,0.08);
    glVertex2f(-0.41,0.11);

    glEnd();

    glColor3fv(green);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.5,0.04);
    glVertex2f(-0.39,0.09);
    glVertex2f(-0.5,0.06);
    glVertex2f(-0.56,0.15);
    glVertex2f(-0.48,0.13);
    glVertex2f(-0.54,0.21);
    glVertex2f(-0.44,0.23);
    glVertex2f(-0.52,0.33);
    glVertex2f(-0.46,0.2);
    glVertex2f(-0.54,0.28);
    glVertex2f(-0.49,0.1);
    glVertex2f(-0.41,0.13);
    glVertex2f(-0.48,0.14);
    glVertex2f(-0.36,0.19);

    glVertex2f(-0.47,0.18);
    glVertex2f(-0.33,0.24);

    glVertex2f(-0.46,0.2);
    glVertex2f(-0.32,0.27);

    glVertex2f(-0.44,0.24);
    glVertex2f(-0.31,0.3);

    glVertex2f(-0.43,0.26);
    glVertex2f(-0.29,0.33);

    glVertex2f(-0.41,0.28);
    glVertex2f(-0.5,0.38);

    glVertex2f(-0.39,0.31);
    glVertex2f(-0.47,0.42);

    glVertex2f(-0.37,0.34);
    glVertex2f(-0.45,0.44);

    glVertex2f(-0.33,0.38);
    glVertex2f(-0.42,0.48);

    glVertex2f(-0.3,0.4);
    glVertex2f(-0.35,0.51);

    glVertex2f(-0.29,0.41);
    glVertex2f(-0.17,0.48);

    glVertex2f(-0.29,0.41);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.19,0.51);

    glVertex2f(-0.3,0.4);
    glVertex2f(-0.2,0.42);

    glVertex2f(-0.35,0.36);
    glVertex2f(-0.23,0.39);
    glVertex2f(-0.38,0.32);
    glVertex2f(-0.23,0.38);
    glEnd();
circulo(0,0,0.5,brown,1,M_PI,M_PI_2+0.6);



}

petalo(){
    float A[]={0,0};

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    glColor3fv(crema);
    glVertex2f(0.0, 0.0);

    glVertex2f (0.0, 5.0);

    glColor3fv(black);
    glVertex2f(1.82, 2.5);

    glEnd();
/////////////
    glShadeModel (GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    glColor3fv(crema);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 5.0);

    glColor3fv(black);
    glVertex2f(-1.82, 2.5);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,0);
    glVertex2f(0,1);
    glEnd();
}

void copo(float* v,float r){
    glColor3fv(red);
    glBegin(GL_LINE_LOOP);
    for(float i=M_PI/8;i<=2*M_PI+M_PI/8;i+=M_PI/4){
        float A[]={r*cos(i)+v[0],r*sin(i)+v[1]};
        float B[]={r/2*cos(i+M_PI/8)+v[0],r/2*sin(i+M_PI/8)+v[1]};
        glVertex2fv(A);
        glVertex2fv(B);
    }
    glEnd();
    glBegin(GL_LINES);
    for(float i=0;i<=2*M_PI;i+=M_PI/4){
        glVertex2f(v[0],v[1]);
        glVertex2f(v[0]+2*r*cos(i),v[1]+2*r*sin(i));
    }
    for(float i=0;i<=2*M_PI;i+=M_PI/4){
        float A[]={1.7*r*cos(i)+v[0],1.7*r*sin(i)+v[1]};
        float B[]={2*r*cos(i+M_PI/24)+v[0],2*r*sin(i+M_PI/24)+v[1]};
        float C[]={2*r*cos(i-M_PI/24)+v[0],2*r*sin(i-M_PI/24)+v[1]};

        float D[]={1.3*r*cos(i)+v[0],1.3*r*sin(i)+v[1]};
        float E[]={1.5*r*cos(i+M_PI/24)+v[0],1.5*r*sin(i+M_PI/24)+v[1]};
        float F[]={1.5*r*cos(i-M_PI/24)+v[0],1.5*r*sin(i-M_PI/24)+v[1]};
        glVertex2fv(A);
        glVertex2fv(B);
        glVertex2fv(A);
        glVertex2fv(C);
        glVertex2fv(D);
        glVertex2fv(E);
        glVertex2fv(D);
        glVertex2fv(F);

    }
    glEnd();
}
void baston(void){

    glColor3fv(white);
    glLineWidth(20);/*
    glBegin(GL_LINES);
    glVertex2f(0, -5);
    glVertex2f(0,0);
    glEnd();*/

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -5);
    glVertex2f(-0.5,0);
    glVertex2f(+0.5,0);
    glVertex2f(+0.5,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    for(float i = 0 ; i <=M_PI/4 +0.1 ; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/4) , 1.5*sin(M_PI/4));
    for(float i = M_PI/4 ; i <=M_PI/2 +0.1 ; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/2) , 1.5*sin(M_PI/2));
    for(float i = M_PI/2 ; i <=3*M_PI/4 +0.1; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(3*M_PI/4) , 1.5*sin(3*M_PI/4));
    for(float i = 3*M_PI/4 ; i <=M_PI +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    /*
    glPointSize(20);
    glBegin(GL_POINTS);
    for(float i = 0 ; i <=M_PI ; i = i + 0.01){

        glVertex2f(-1.5 +1.5*cos(i) , 1.5*sin(i));
    }


    glEnd();*/
    glColor3fv(red);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-3.2);
    glVertex2f(+0.5,-2.8);
    glVertex2f(+0.5,-3.8);
    glVertex2f(-0.5,-4.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-1.2);
    glVertex2f(+0.5,-0.8);
    glVertex2f(+0.5,-1.8);
    glVertex2f(-0.5,-2.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.3);
    glVertex2f(+0.5, 0.7);
    glVertex2f(+0.5, -0.3);
    glVertex2f(-0.5,-0.7);
    glEnd();

    glColor3fv(white);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.2);
    glVertex2f(+0.5, 0.2);
    glVertex2f(+0.5, -0.3);
    glVertex2f(-0.5,-0.7);
    glEnd();


    glColor3fv(red);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(3*M_PI/4- M_PI/5) , 1.5*sin(3*M_PI/4 - M_PI/5));
    for(float i = 3*M_PI/4 - M_PI/5 ; i <=M_PI - M_PI/5 +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/4 - M_PI/5) , 1.5*sin(M_PI/4 - M_PI/5 ));
    for(float i = M_PI/4  - M_PI/5; i <=M_PI/2 - M_PI/5 +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(50.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 8.0, 1.5, 2.0, 0.0, 0.0, 1.0, 0.0);
}
void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3fv(marron);
    glVertex2d(1.5,0.5);
    glVertex2d(2.2,0.5);
    glVertex2d(2.2,-1);
    glVertex2d(1.5,-1);
    glEnd();

    rama();
    glTranslated(0.2,0,0);
    rama();
    glTranslated(0.2,0,0);
    rama();

    for(int i=0 ;i<10;i=i+1){
        glTranslated(0.2,0,0);



        rama();

    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=10 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);


        rama();

    }
glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<9;i=i+1){
        glTranslated(0.2,0,0);


        rama();

    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=7 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }

    glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<5;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=4 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }

    glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<3;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=2 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }
glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<1;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }


    glTranslated(1.5,-4,0);
     glRotated(180,0,1,0);

     rama();
    glTranslated(0.2,0,0);
    rama();
    glTranslated(0.2,0,0);
    rama();

     for(int i=0 ;i<10;i=i+1){
        glTranslated(0.2,0,0);



        rama();

    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=10 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);


        rama();

    }
glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<9;i=i+1){
        glTranslated(0.2,0,0);


        rama();

    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=7 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }

    glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<5;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=4 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }

    glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<3;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }
    glTranslated(0,0.5,0);
    rama();

    for(int i=2 ;i>0;i=i-1){
        glTranslated(-0.2,0,0);

        rama();

    }
glTranslated(0.2,0.5,0);
    rama();

    for(int i=0 ;i<1;i=i+1){
        glTranslated(0.2,0,0);

        rama();


    }

    glTranslated(-0.35,0.8,0);
    glScalef(0.1,0.1,0.1);

    petalo();
    glRotatef(72, 0, 0, 1);
    petalo();
    glRotatef(72, 0, 0, 1);
    petalo();
    glRotatef(72, 0, 0, 1);
    petalo();
    glRotatef(72, 0, 0, 1);
    petalo();
    glRotatef(72, 0, 0, 1);
    petalo();

  float A[]={0,0};

    glTranslated(0,-20,0);
    copo(A,1);
    glTranslated(5,0,0);
    copo(A,1);
     glTranslated(-10,0,0);
    copo(A,1);
    glTranslated(0,10,0);
    copo(A,1);
glTranslated(5,0,0);
    copo(A,1);
    glTranslated(5,0,0);
    copo(A,1);
    glTranslated(0,-20,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(-15,0,0);
    copo(A,1);
     glTranslated(-5,0,0);
    copo(A,1);
     glTranslated(-5,0,0);
    copo(A,1);
     glTranslated(-5,0,0);
    copo(A,1);
    glTranslated(0,-10,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);
     glTranslated(5,0,0);
    copo(A,1);


    glRotated(180,0,1,0);

    glTranslated(2,5,0);
    baston();
     glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(-5,10,0);
    baston();
     glTranslated(-5,0,0);
    baston();
    glTranslated(-5,0,0);
    baston();
    glTranslated(-5,0,0);
    baston();
    glTranslated(-5,0,0);
    baston();
    glTranslated(3,10,0);
    baston();
    glTranslated(5,0,0);
    baston();
    glTranslated(5,0,0);
    baston();




     glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);

    glutInitWindowPosition(1,1);
    glutCreateWindow("Primer codigo");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-4,8,-2,8);


    glutMainLoop();
    return EXIT_SUCCESS;
}

