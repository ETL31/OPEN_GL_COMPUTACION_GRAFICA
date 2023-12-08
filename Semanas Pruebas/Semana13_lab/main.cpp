#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>
#define M_PI 3.14159265

float tX=0, tY=0 , tZ=0;

void Linea(float *X0, float *X1, float *C, float A = 1, int f = 1, int P = 0)
{
    glColor3fv(C);
    glLineWidth(A);
    glEnable(GL_LINE_STIPPLE);
    switch (P){
        case 1: glLineStipple (f, 0x0101); break;
        case 2: glLineStipple (f, 0xAAAA); break;
        case 3: glLineStipple (f, 0x00FF); break;
        case 4: glLineStipple (f, 0x0c0F); break;
        case 5: glLineStipple (f, 0x1C47); break;
        default: glLineStipple (f, 0xFFFF); break;
    }
    glBegin(GL_LINES);
    glVertex3fv(X0);
    glVertex3fv(X1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1);
}

void Ejes(int c){
    float P[]={-50.0,0.0,0.0} , P1[]={50.0,0.0,0.0};
    float P2[]={0.0,-50.0,0.0}, P3[]={0.0,50.0,0.0};
    float P4[]={0.0,0.0,-50.0} , P5[]={0.0,0.0,50.0};
    float C1[]={1,0,0}, C2[]={0,0,1}, C3[]={0,1,0};
    switch (c){ // linea punteada
    case 0:{
        Linea(P,P1,C1,2,2,1);
        Linea(P2,P3,C2,2,2,1);
        Linea(P4,P5,C3,2,2,1);
        break;
    }
    default :{ // linea solida de grosor c
        Linea(P,P1,C1,c);
        Linea(P2,P3,C2,c);
        Linea(P4,P5,C3,c);
        }
    }
}


void vehiculo(float *C){ // Dibuja el vehiculo a usar

//
//GLdouble eqn[4] = {0, -1, 0, 0.0};
//
//glPushMatrix();
//glClipPlane (GL_CLIP_PLANE0, eqn);
//glEnable (GL_CLIP_PLANE0);
//
//
//    glColor3fv(C);
//    glutSolidSphere(5,30,30);
//    glPopMatrix();
//glDisable(GL_CLIP_PLANE0);
//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//glColor3f(0,0,0);
//glBegin(GL_POLYGON);
//glVertex3f(0,0,0);
//
//for (float i = 0; i <= 2*M_PI ; i = i + 0.0005)
//glVertex3f(5*cos(i),0,5*sin(i));
//glEnd();


GLdouble eqn2[4] = {1, 0, 0,0.0};
GLdouble eqn3[4] = {0, 0, 0, 0.0};

glPushMatrix();
glClipPlane (GL_CLIP_PLANE1, eqn2);
glEnable (GL_CLIP_PLANE1);
glClipPlane (GL_CLIP_PLANE2, eqn3);
glEnable (GL_CLIP_PLANE2);
    glColor3fv(C);
    glutSolidSphere(5,30,30);
    glPopMatrix();
glDisable(GL_CLIP_PLANE1);
glDisable(GL_CLIP_PLANE2);


}


void Display(void)
{

glClearColor(1,1,1,0);//color el cual se limpia la ventana
glClear(GL_COLOR_BUFFER_BIT);//limpia la ventana
glLoadIdentity();
gluLookAt (30, 30 , 30, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
Ejes(1);
    float amarillo[]={1,1,0.0};

glPushMatrix();
//glRotated(180,0,1,0);
glTranslated(tX,tY,tZ);
vehiculo(amarillo);
glPopMatrix();


if(tX>=20)tX=20;
if(tX<=-20)tX=-20;
if(tY>=20)tY=20;
if(tY<=-20)tY=-20;
if(tY>=20)tY=20;
if(tY<=-20)tY=-20;


glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-8, 8, -8, 8, 8, 60.0);
    glMatrixMode (GL_MODELVIEW);
}

static void key(unsigned char key, int x, int y)
{
    float paso = 0.3;
    switch (key)
    {
        case 'd':
            tX+=paso;
            break;
        case 'a':
            tX-=paso;
            break;
        case 'w':
            tY+=paso;
            break;
        case 's':
            tY-=paso;
            break;
        case 'q':
            tZ+=paso;
            break;
        case 'e':
            tZ-=paso;
            break;

    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();

}

int main (int argc,char** argv)
{
    //funcion glut para la inicializacion de la ventana
    glutInit(&argc,argv);//inicializamos
    glutInitWindowSize(700,700);// tamanio de la ventana
    glutInitWindowPosition(40,40);//posicionde la ventana
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Computacion Grafica");// crea la venta con nombre

    //funcion glut para el manejo de eventos
    glutDisplayFunc(Display);// evento de renderizado

    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutReshapeFunc(reshape);
    // inicializacion del bucle indefinido de eventos

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20,20,-20,20);
    glutMainLoop();


    return EXIT_SUCCESS;
}
