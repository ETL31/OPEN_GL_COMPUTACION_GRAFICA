#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void inicio()//define funcion inicio
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10); //posicion
    glClearColor(0,0,0,0);
}

void bull(){

    double A[]={-7.96,-7.08};
    double B[]={7.56,-6.99};
    double C[]={0,-6.51};
    double D[]={-1.47,-6.31};
    double E[]={-2.49,-5.11};
    double F[]={-2.8,-3.47};
    double G[]={-3.41,-2.11};
    double H[]={-3.22,-1.11};
    double I[]={-3.43,-0.36};
    double J[]={-4.33,-0.29};
    double K[]={-4.79,-0.40};
    double L[]={-6.52,0.16};
    double M[]={-6.96,0.62};
    double N[]={-6.52,0.97};
    double O[]={-5.62,1.18};
    double P[]={-6.47,1.67};
    double Q[]={-7.15,2.28};
    double R[]={-7.37,3.02};
    double S[]={-7.17,4.23};
    double T[]={-6.47,5.01};
    double U[]={-5.91,5.71};
    double V[]={-5.42,6.63};
    double W[]={-5.40,5.41};
    double Z[]={-5.56,4.55};
    double A1[]={-5.95,3.66};
    double B1[]={-5.40,2.96};
    double C1[]={-4.00,2.48};
    double D1[]={-3.37,2.54};
    double E1[]={-2.60,2.83};
    double F1[]={-0.52,3.24};
    double G1[]={0,3.33};
    double H1[]={2.09,2.85};
    double I1[]={2.84,2.50};
    double J1[]={3.51,2.48};
    double K1[]={4.81,3.00};
    double L1[]={5.46,3.70};
    double M1[]={5.00,4.66};
    double N1[]={4.83,5.47};
    double O1[]={4.94,6.72};
    double P1[]={5.37,5.67};
    double Q1[]={5.90,5.06};
    double R1[]={6.60,4.31};
    double S1[]={6.84,3.24};
    double T1[]={6.62,2.34};
    double U1[]={5.94,1.73};
    double V1[]={5.18,1.32};
    double W1[]={6.05,0.99};
    double Z1[]={6.40,0.75};
    double A2[]={6.10,0.20};
    double B2[]={4.41,-0.40};
    double C2[]={3.84,-0.25};
    double D2[]={2.99,-0.29};
    double E2[]={2.81,-1.08};
    double F2[]={3.01,-2.26};
    double G2[]={2.42,-3.25};
    double H2[]={1.98,-5.19};
    double I2[]={1.26,-6.22};
    double J2[]={0,-4.47};
    double K2[]={-2.496,-2.486};
    double L2[]={0,-2.50};
    double M2[]={-0.46,-1.26};
    double N2[]={-0.26,0.55};
    double O2[]={-1.14,0.55};
    double P2[]={-3.21,1.21};
    double Q2[]={-5.97,0.62};
    double R2[]={-4.64,1.18};
    double S2[]={-4.46,0.88};
    double T2[]={-4.9,1.73};
    double U2[]={-5.9,2.3};
    double V2[]={-6.48,2.83};
    double W2[]={-6.54,4.05};
    double Z2[]={1.5,-3.71};
    double A3[]={0.30,-1.28};
    double B3[]={0.67,0.53};
    double C3[]={2.71,1.27};
    double D3[]={4.32,1.73};
    double E3[]={2.71,1.27};
    double F3[]={5.57,0.70};
    double G3[]={4.15,1.21};
    double H3[]={5.37,2.41};
    double I3[]={5.90,2.87};
    double J3[]={6.01,4.14};
    double K3[]={3.67,0.07};
    double L3[]={-4.11,0};

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2dv(A1);
    glVertex2dv(Z);
    glVertex2dv(W);
    glVertex2dv(V);
    glVertex2dv(U);
    glVertex2dv(T);
    glVertex2dv(S);
    glVertex2dv(R);
    glVertex2dv(Q);
    glVertex2dv(P);
    glVertex2dv(O);
    glVertex2dv(B1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2dv(L1);
    glVertex2dv(M1);
    glVertex2dv(N1);
    glVertex2dv(O1);
    glVertex2dv(P1);
    glVertex2dv(Q1);
    glVertex2dv(R1);
    glVertex2dv(S1);
    glVertex2dv(T1);
    glVertex2dv(V1);
    glVertex2dv(K1);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2dv(H);
    glVertex2dv(E2);
    glVertex2dv(F2);
    glVertex2dv(G2);
    glVertex2dv(H2);
    glVertex2dv(I2);
    glVertex2dv(C);
    glVertex2dv(D);
    glVertex2dv(E);
    glVertex2dv(F);
    glVertex2dv(G);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2dv(P2);
    glVertex2dv(C1);
    glVertex2dv(D1);
    glVertex2dv(E1);
    glVertex2dv(F1);
    glVertex2dv(G1);
    glVertex2dv(H1);
    glVertex2dv(I1);
    glVertex2dv(C3);
    glVertex2dv(D2);
    glVertex2dv(E2);
    glVertex2dv(H);
    glVertex2dv(I);

    glEnd();

    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    glVertex2dv(O);
    glVertex2dv(B1);
    glVertex2dv(C1);
    glVertex2dv(P2);
    glVertex2dv(I);
    glVertex2dv(K);
    glVertex2dv(L);
    glVertex2dv(M);
    glVertex2dv(N);
    glVertex2dv(O);
    glEnd();


    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    glVertex2dv(V1);
    glVertex2dv(W1);
    glVertex2dv(Z1);
    glVertex2dv(A2);
    glVertex2dv(B2);
    glVertex2dv(C2);
    glVertex2dv(D2);
    glVertex2dv(C3);
    glVertex2dv(I1);
    glVertex2dv(J1);
    glVertex2dv(K1);
    glVertex2dv(V1);

    glEnd();




}


void display (void)
{

    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);

    bull();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    glutCreateWindow("BULL");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
