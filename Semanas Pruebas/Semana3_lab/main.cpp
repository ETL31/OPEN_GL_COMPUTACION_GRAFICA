#include <windows.h>
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

    float rojo1[]={0.99,0.25,0.31};
    float rojo2[]={0.99,0.11,0.15};
    float rojo3[]={0.8,0,0.15};
    float rojo4[]={0.65,0,0.11};
    float rojo5[]={0.46,0,0.08};


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





    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(C[0],C[1]);
    glVertex2d(D[0],D[1]);
    glVertex2d(E[0],E[1]);
    glVertex2d(F[0],F[1]);
    glVertex2d(K2[0],K2[1]);
    glVertex2d(H[0],H[1]);
    glVertex2d(J2[0],J2[1]);
    glVertex2d(E2[0],E2[1]);
    glVertex2d(Z2[0],Z2[1]);
    glVertex2d(G2[0],G2[1]);
    glVertex2d(H2[0],H2[1]);
    glVertex2d(I2[0],I2[1]);
    glEnd();

     glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(J2[0],J2[1]);
    glVertex2d(H[0],H[1]);
    glVertex2d(L2[0],L2[1]);
    glVertex2d(E2[0],E2[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(H[0],H[1]);
    glVertex2d(C[0],C[1]);
    glVertex2d(J2[0],J2[1]);
    glVertex2d(L2[0],L2[1]);
    glVertex2d(M2[0],M2[1]);
    glVertex2d(O2[0],O2[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(P2[0],P2[1]);
    glVertex2d(O2[0],O2[1]);
    glVertex2d(F1[0],F1[1]);
    glVertex2d(E1[0],E1[1]);
    glVertex2d(D1[0],D1[1]);
    glVertex2d(C1[0],C1[1]);
    glVertex2d(T2[0],T2[1]);
    glVertex2d(O[0],O[1]);
    glVertex2d(R2[0],R2[1]);
    glVertex2d(S2[0],S2[1]);
    glVertex2d(L3[0],L3[1]);
    glVertex2d(K[0],K[1]);
    glVertex2d(I[0],I[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(C3[0],C3[1]);
    glVertex2d(B3[0],B3[1]);
    glVertex2d(G1[0],G1[1]);
    glVertex2d(H1[0],H1[1]);
    glVertex2d(I1[0],I1[1]);
    glVertex2d(J1[0],J1[1]);
    glVertex2d(D3[0],D3[1]);
    glVertex2d(V1[0],V1[1]);
    glVertex2d(F3[0],F3[1]);
    glVertex2d(B2[0],B2[1]);
    glVertex2d(C2[0],C2[1]);
    glVertex2d(D2[0],D2[1]);
    glVertex2d(E2[0],E2[1]);
    glVertex2d(B3[0],B3[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(F3[0],F3[1]);
    glVertex2d(B2[0],B2[1]);
    glVertex2d(C2[0],C2[1]);
    glVertex2d(K3[0],K3[1]);
    glVertex2d(E3[0],E3[1]);
    glVertex2d(G3[0],G3[1]);
    glVertex2d(V1[0],V1[1]);
    glVertex2d(W1[0],W1[1]);
    glVertex2d(Z1[0],Z1[1]);
    glVertex2d(A2[0],A2[1]);
    glVertex2d(B2[0],B2[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(H3[0],H3[1]);
    glVertex2d(U1[0],U1[1]);
    glVertex2d(V1[0],V1[1]);
    glVertex2d(D3[0],D3[1]);
    glVertex2d(J1[0],J1[1]);
    glVertex2d(K1[0],K1[1]);
    glEnd();


    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(I3[0],I3[1]);
    glVertex2d(U1[0],U1[1]);
    glVertex2d(H3[0],H3[1]);
    glVertex2d(K1[0],K1[1]);
    glVertex2d(L1[0],L1[1]);
    glVertex2d(J3[0],J3[1]);
    glVertex2d(S1[0],S1[1]);
    glVertex2d(T1[0],T1[1]);
    glVertex2d(U1[0],U1[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(Q2[0],Q2[1]);
    glVertex2d(K[0],K[1]);
    glVertex2d(L3[0],L3[1]);
    glVertex2d(S2[0],S2[1]);
    glVertex2d(R2[0],R2[1]);
    glVertex2d(O[0],O[1]);
    glVertex2d(N[0],N[1]);
    glVertex2d(M[0],M[1]);
    glVertex2d(L[0],L[1]);
    glVertex2d(K[0],K[1]);
    glEnd();


    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(V2[0],V2[1]);
    glVertex2d(P[0],P[1]);
    glVertex2d(B1[0],B1[1]);
    glVertex2d(A1[0],A1[1]);
    glVertex2d(W2[0],W2[1]);
    glVertex2d(R[0],R[1]);
    glVertex2d(P[0],P[1]);
    glVertex2d(U2[0],U2[1]);
    glVertex2d(B1[0],B1[1]);
    glEnd();

    glColor3fv(rojo1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(W2[0],W2[1]);
    glVertex2d(V2[0],V2[1]);
    glVertex2d(A1[0],A1[1]);
    glVertex2d(Z[0],Z[1]);
    glVertex2d(T[0],T[1]);
    glVertex2d(S[0],S[1]);
    glVertex2d(R[0],R[1]);
    glVertex2d(V2[0],V2[1]);
    glEnd();







    glColor3fv(rojo3);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(G[0],G[1]);
    glVertex2d(H[0],H[1]);
    glVertex2d(F[0],F[1]);
    glVertex2d(K2[0],K2[1]);
    glEnd();

    glColor3fv(rojo3);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(F2[0],F2[1]);
    glVertex2d(E2[0],E2[1]);
    glVertex2d(G2[0],G2[1]);
    glVertex2d(Z2[0],Z2[1]);
    glEnd();

    glColor3fv(rojo5);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(D[0],D[1]);
    glVertex2d(E[0],E[1]);
    glVertex2d(C[0],C[1]);
    glVertex2d(F[0],F[1]);
    glEnd();

     glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(O2[0],O2[1]);
    glVertex2d(L2[0],L2[1]);
    glVertex2d(N2[0],N2[1]);
    glVertex2d(B3[0],B3[1]);
    glVertex2d(L2[0],L2[1]);
    glVertex2d(E2[0],E2[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(O2[0],O2[1]);
    glVertex2d(H[0],H[1]);
    glVertex2d(I[0],I[1]);
    glVertex2d(P2[0],P2[1]);
    glVertex2d(O2[0],O2[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(F1[0],F1[1]);
    glVertex2d(O2[0],O2[1]);
    glVertex2d(G1[0],G1[1]);
    glVertex2d(B3[0],B3[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(S1[0],S1[1]);
    glVertex2d(J3[0],J3[1]);
    glVertex2d(R1[0],R1[1]);
    glVertex2d(Q1[0],Q1[1]);
    glVertex2d(J3[0],J3[1]);
    glVertex2d(M1[0],M1[1]);
    glVertex2d(J3[0],J3[1]);
    glVertex2d(L1[0],L1[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(Q1[0],Q1[1]);
    glVertex2d(M1[0],M1[1]);
    glVertex2d(N1[0],N1[1]);
    glVertex2d(Q1[0],Q1[1]);
    glVertex2d(P1[0],P1[1]);
    glVertex2d(O1[0],O1[1]);
    glVertex2d(N1[0],N1[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(P[0],P[1]);
    glVertex2d(O[0],O[1]);
    glVertex2d(U2[0],U2[1]);
    glVertex2d(T2[0],T2[1]);
    glVertex2d(C1[0],C1[1]);
    glVertex2d(U2[0],U2[1]);
    glVertex2d(B1[0],B1[1]);
    glVertex2d(C1[0],C1[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(P[0],P[1]);
    glVertex2d(Q[0],Q[1]);
    glVertex2d(R[0],R[1]);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(Z[0],Z[1]);
    glVertex2d(T[0],T[1]);
    glVertex2d(W[0],W[1]);
    glVertex2d(U[0],U[1]);
    glVertex2d(V[0],V[1]);
    glVertex2d(W[0],W[1]);
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
