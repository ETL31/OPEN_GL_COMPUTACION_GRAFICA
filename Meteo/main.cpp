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

#define M_PI 3.141592654
GLint RH=16;
GLint RV=8;
GLint Tx=50,Ty=50,Tz=50;
GLint w,h;

GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };


GLubyte* data;
int width=800,height=800;


GLUquadricObj *obj = gluNewQuadric();
GLUquadricObj *obj_reverse = gluNewQuadric();

//Texture :
GLuint		Nom[12];

//LoadBMP : charge une image 24bpp
#define EXIT {fclose(fichier);return -1;}
#define CTOI(C) (*(int*)&C)	//récupère en int un nombre pointé par un char*


int LoadBMP(char *File)
{
	unsigned char	*Data;
	FILE			*fichier;
	unsigned char	Header[0x36];
	GLuint			DataPos,DataSize;
	GLint			Components;
	GLsizei			Width,Height;
	GLenum			Format,Type;
	GLuint			Name[1];

	//Lit le fichier et son header
	fichier = fopen(File,"rb");if (!fichier) return -1;
	if (fread(Header,1,0x36,fichier)!=0x36) EXIT;
	if (Header[0]!='B' || Header[1]!='M')	EXIT;
	if (CTOI(Header[0x1E])!=0)				EXIT;
	if (CTOI(Header[0x1C])!=24)				EXIT;

	//Récupère les infos du fichier
	DataPos			= CTOI(Header[0x0A]);
	DataSize		= CTOI(Header[0x22]);
	//Récupère les infos de l'image
	Width			= CTOI(Header[0x12]);
	Height			= CTOI(Header[0x16]);
	Type = GL_UNSIGNED_BYTE;
	Format = GL_RGB;
	Components = 3;

	//!!!!
	if (DataSize==0) DataSize=Width*Height*Components;
	if (DataPos==0)  DataPos=0x36;

	//Charge l'image
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

	//Inverse R et B
	unsigned char t;
	for (int x=0;x<Width*Height;x++)
	{
		t=Data[x*3];
		Data[x*3]=Data[x*3+2];
		Data[x*3+2]=t;
	}

	//Envoie la texture à OpenGL
	//	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(1, Name);
	glBindTexture(GL_TEXTURE_2D, Name[0]);


	glTexImage2D
		(
		GL_TEXTURE_2D, 	//target
		0,				//mipmap level
		Components,		//nb couleurs
		Width,			//largeur
		Height,			//hauteur
		0,			 	//largeur du bord
		GL_RGB,			//type des couleurs
		GL_UNSIGNED_BYTE,			//codage de chaque composante
		Data			//Image
		);

	return Name[0];
}


void init(void)
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("textura");
	glClearColor (0.0, 0.0, 0.0, 0.0);

	GLfloat position1 [] = { 0, 0.0F, 0.0F, 1.0F };
	glLightfv(GL_LIGHT0, GL_POSITION, position1);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel (GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glMatrixMode (GL_MODELVIEW);

	Nom[0] = LoadBMP("PTierra.bmp");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);


	glDepthFunc(GL_LESS);
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



}


void display(void)
{
	//glBindTexture(GL_TEXTURE_2D, Nom[9]);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glClear (GL_COLOR_BUFFER_BIT);
	glClear (GL_DEPTH_BUFFER_BIT);

	//efecto  de luminisencia

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);



	glRotatef(0.03,1,1,1);

	glBindTexture(GL_TEXTURE_2D, Nom[0]);
	gluQuadricTexture(obj, GL_TRUE );
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj,30,100,100);



	glutSwapBuffers();
	glutPostRedisplay();
}


void reshape (int width,int height){
	w=width;
	h=height;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-Tx,Tx,-Ty,Ty,-Tz,Tz);
	glMatrixMode(GL_MODELVIEW);

}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
		init (); //inicializamos la ecena
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); // redimension de la ventana


	glutMainLoop();
	return 0;
}
