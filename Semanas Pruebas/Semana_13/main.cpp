#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <gl/glut.h>
#include<GL/glu.h>
#include<windows.h>

#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "opengl32.lib")





#define M_PI 3.141592654 // define la constante M_PI

float blue[]={0,0,1}, green[]={0,1,0}, orange[]={0.9,0.6,0.1}, cyan[]={0,1,1}, red[]={1,0,0}, yellow[]={1,1,0};
float purple[]={1,0,1}, white[]={1,1,1}, black[]={0,0,0}, brown[]={0.5,0.35,0.05}, pink[]={0.9,0.7,0.7};
long hours = 0;
float RotEarthDay=0.0, RotEarth=0.0, RotMoon=0.0;
GLubyte* data;
GLUquadricObj *obj = gluNewQuadric();
GLUquadricObj *obj_reverse = gluNewQuadric();
GLint Nom[12];
GLint w,h;

//LoadBMP : carga une imagen de 24bmp
#define EXIT {fclose(fichier);return -1;}
#define CTOI(C) (*(int*)&C)

int LoadBMP(char *File)// carga une imagen en formato bmp
{
unsigned char *Data;
FILE *fichier;
unsigned char Header[0x36];
GLuint DataPos,DataSize;
GLint Components;
GLsizei Width,Height;
GLenum Format,Type;
GLuint Name[1];

fichier = fopen(File,"rb");if (!fichier) return -1;
if (fread(Header,1,0x36,fichier)!=0x36) EXIT;
if (Header[0]!='B' || Header[1]!='M') EXIT;
if (CTOI(Header[0x1E])!=0) EXIT;
if (CTOI(Header[0x1C])!=24) EXIT;

DataPos = CTOI(Header[0x0A]);
DataSize = CTOI(Header[0x22]);

Width = CTOI(Header[0x12]);
Height = CTOI(Header[0x16]);
Type = GL_UNSIGNED_BYTE;
Format = GL_RGB;
Components = 3;

if (DataSize==0) DataSize=Width*Height*Components;
if (DataPos==0) DataPos=0x36;

fseek(fichier,DataPos,0);
Data = new unsigned char[DataSize];
if (!Data) EXIT;

if (fread(Data,1,DataSize,fichier)!=DataSize)
{
delete Data;
fclose(fichier);
return -1;
}

fclose(fichier);

unsigned char t;
for (int x=0;x<Width*Height;x++)
{
t=Data[x*3];
Data[x*3]=Data[x*3+2];
Data[x*3+2]=t;
}

glGenTextures(1, Name);
glBindTexture(GL_TEXTURE_2D, Name[0]);


glTexImage2D(GL_TEXTURE_2D,0,Components,Width,Height,0,GL_RGB,GL_UNSIGNED_BYTE,Data);

return Name[0];
}

void Inicializacion(void)
{
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );/* modo en el q va a dibujarse*/
glutInitWindowSize (800, 600); /* tamaño de ventana*/
glutInitWindowPosition (100, 100);/*posicion de la ventana */
glutCreateWindow ("Tierra: ");/* crea la ventana de nombre sistema solar*/
glClearColor (0.0, 0.0, 0.0, 0.0);/* color de la ventana*/

GLfloat position1 [] = { 0, 0.0F, 0.0F, 1.0F };/* declaramos el vector position*/
/* activa efectos de luminosidad y sombreado */
glLightfv(GL_LIGHT0, GL_POSITION, position1);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel (GL_SMOOTH);
/* propiedades de luminosidad y sombreado */
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_TEXTURE_2D);
glMatrixMode (GL_MODELVIEW);


Nom[3] = LoadBMP("PTierra.bmp");
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

glDepthFunc(GL_LESS);
glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void display(void)
{

    glBindTexture(GL_TEXTURE_2D, Nom[9]);

/* limpia los bufferes de color y profundidad*/
// bufferes : espacios de memoria
glClear (GL_COLOR_BUFFER_BIT);
glClear (GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
    RotEarthDay = (hours % 24) * (360/24.0);



    glPushMatrix();
    glRotatef (RotEarth, 0.0, 0.0, 1.0);
    glRotatef (RotEarthDay, 0.0, 0.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    Nom[3] = LoadBMP("PTierra.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    gluQuadricTexture(obj, GL_TRUE );// hace la cuadratura en el objeto
    gluQuadricDrawStyle(obj, GLU_FILL);//dibuja la cuadratura en el objeto
    gluSphere(obj,3,100,100);
    glPopMatrix();


    glutSwapBuffers();

}

void reshape (int width, int height)
{
  w=width;//ancho de ventana actual
h=height;//alto de ventana actual
glViewport(0, 0, w, h);//define el area rectangular de la ventana de visualizacion(x,y)
glMatrixMode(GL_PROJECTION);
glLoadIdentity();//limpía la matriz de proyeccion reseteandola a la matriz identidad
glOrtho(-5,5,-5,5,-5,5);//cambia tamaño del area de vista
glMatrixMode(GL_MODELVIEW);
}
void actualiza (unsigned char key, int x, int y)
{
hours++;
glutPostRedisplay();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    Inicializacion();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc (actualiza);

    glMatrixMode(GL_PROJECTION);
    glutMainLoop();
    return EXIT_SUCCESS;
}
