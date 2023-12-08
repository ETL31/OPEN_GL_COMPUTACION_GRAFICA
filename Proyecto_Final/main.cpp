#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>
#define M_PI 3.14159265
#include <iostream>
#include <mmsystem.h>

using namespace std;

float black[] = {0,0,0}, ladrillo2[]={162.0/255.0,71.0/255.0,40.0/255.0},gris[]={71.0/255.0,71.0/255.0,71.0/255.0},white[]={1,1,1}, morado2[]={88.0/255.0,54.0/255.0,84.0/255.0},blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,0.504,0}, morado[]={175.0/255.0,18.0/255.0,128.0/255.0},ladrillo[]={205.0/255.0,90.0/255.0,51.0/255.0},amarilloT[]={1,238.0/255.0,0},yellow[]={1,1,0};
float brown[]={185.0/255.0,122.0/255.0,87.0/255.0},lightbrown[]={192.0/255.0,137.0/255.0,101.0/255.0}, cyan[]={0,1,1},pink[]={0.93,0.54,0.44}, orange[]={1,0.5,0};
float arena[]={204.0/255.0,163.0/255.0,125.0/255.0};

float tX=-5, tY=1;

float posObsX[] = {10,20,30,40,50,65,75,85,95,100};
float posObsY[] = {29,35,10,0,120,29,29,29,29,29};
float n = 10;


float celebracion=0;

void Circunferencia(float *XY, float R, float *rgb, int M, float T,float theta1, float theta2){
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

for (float i = theta1; i <= theta2 ; i = i + 0.0005)
glVertex2f(R*cos(i) + XY[0], R*sin(i) + XY[1]);
glEnd();
}



void arbol(){

    glColor3fv(brown);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0);
    glVertex2d(+0.5, 0);
    glVertex2f(+0.5, -8);
    glVertex2f(-0.5, -8);
    glEnd();

    float AC[] = {0,0};
    Circunferencia( AC, 2, green, 0, 1, 0, M_PI*2+0.1);

    for( float i = M_PI/8; i <= M_PI*2 + M_PI/8 ; i = i + M_PI/4){
        float A2[] = { cos(i)*2.5, sin(i)*2.45};
        Circunferencia( A2, 1, green, 0, 1, 0, M_PI*2.5+0.1);
    }
}

void casas(){
//arena
glColor3fv(arena);
glBegin(GL_QUADS);
glVertex2f(-40,30);
glVertex2f(-5,30);
glVertex2f(-5,-30);
glVertex2f(-40,-30);
glEnd();

    //vereda
  float  cons=6;
  for (int j=0; j<=10;j++){
        glColor3fv(black);
        glBegin(GL_LINES);
        glVertex2f(-5,30-cons);
        glVertex2f(5,30-cons);
        glVertex2f(95,30-cons);
        glVertex2f(105,30-cons);
        glEnd();
        cons+=6;
        }

    glBegin(GL_LINES);
    glVertex2f(-5,-30);
    glVertex2f(-5,30);
    glEnd();
//casa 1
    glColor3fv(morado2);
    glBegin(GL_QUADS);
     glVertex2f(-40,-5);
    glVertex2f(-15,-5);
    glVertex2f(-15,-30);
    glVertex2f(-40,-30);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-40,-5);
    glVertex2f(-15,-5);
    glVertex2f(-15,-30);
    glEnd();

     glColor3fv(gris);
    glBegin(GL_QUADS);
     glVertex2f(-40,-6);
    glVertex2f(-16,-6);
    glVertex2f(-16,-30);
    glVertex2f(-40,-30);
    glEnd();

     glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-40,-6);
    glVertex2f(-16,-6);
    glVertex2f(-16,-30);
    glEnd();

     glColor3fv(morado);
    glBegin(GL_QUADS);
     glVertex2f(-15,-5);
    glVertex2f(-11.39,-11.04);
    glVertex2f(-11.39,-30);
    glVertex2f(-15,-30);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-15,-5);
    glVertex2f(-11.39,-11.04);
    glVertex2f(-11.39,-30);
    glEnd();




    float c3[]={-13.49,-27.39};
    Circunferencia(c3,1.14,black,4,2,M_PI_2,3*M_PI_2);
    glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-13.52,-26.31);
    glVertex2f(-11.39,-26.31);
    glVertex2f(-11.39,-28.48);
    glVertex2f(-13.52,-28.48);
    glEnd();

    glBegin(GL_QUADS);
     glVertex2f(-13.52,-26.31);
    glVertex2f(-11.39,-26.31);
    glVertex2f(-11.39,-28.48);
    glVertex2f(-13.52,-28.48);
    glEnd();

     float c4[]={-13.41,-19.44};
     Circunferencia(c4,1.21,amarilloT,4,2,M_PI,2*M_PI);

     glColor3fv(amarilloT);
     glBegin(GL_QUADS);
     glVertex2f(-14.62,-19.44);
    glVertex2f(-14.62,-14.44);
    glVertex2f(-12.2,-14.44);
    glVertex2f(-12.2,-19.44);
    glEnd();

   float c5[]={-13.41,-14.44};
     Circunferencia(c5,1.21,amarilloT,4,2,0,M_PI);


//casa 2

    glColor3fv(ladrillo2);
    glBegin(GL_QUADS);
    glVertex2f(-40,22.62);
    glVertex2f(-20.65,22.62);
    glVertex2f(-20.65,-5);
    glVertex2f(-40,-5);
    glEnd();
    glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-40,22.62);
    glVertex2f(-20.65,22.62);
    glVertex2f(-20.65,-5);
    glEnd();

    glColor3fv(black);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-20.65,22.62);
    glVertex2f(-17.65,18.62);
    glVertex2f(-17.65,-5);
    glEnd();

    glColor3fv(ladrillo);
    glBegin(GL_QUADS);
    glVertex2f(-20.65,22.62);
    glVertex2f(-17.65,18.62);
    glVertex2f(-17.65,-5);
    glVertex2f(-20.65,-5);
    glEnd();
    glColor3fv(black);
    glBegin(GL_LINES);
    glVertex2f(-18.65,19.88);
     glVertex2f(-18.65,-5);
    glVertex2f(-19.65,21.2);
     glVertex2f(-19.65,-5);

    glEnd();

    float co1=2;
    for(float i=0;i<=10;i++){
    glBegin(GL_LINES);
    glVertex2f(-19.65,-5+co1);
     glVertex2f(-20.65,-5+co1);
     glEnd();
     co1+=2.1;
    }
     float co2=3;
    for(float i=0;i<=9;i++){
    glBegin(GL_LINES);
    glVertex2f(-19.65,-5+co2);
     glVertex2f(-18.65,-5+co2);
     glEnd();
     co2+=2.1;
    }

     float co3=2;
    for(float i=0;i<=10;i++){
    glBegin(GL_LINES);
    glVertex2f(-18.65,-5+co3);
     glVertex2f(-17.65,-5+co3);
     glEnd();
     co3+=2.1;
    }
 //reja

 glLineWidth(4);
glColor3fv(black);
 glBegin(GL_LINE_STRIP);
glVertex2f(-17.65,18.62);
glVertex2f(-21.65,23.62);
glVertex2f(-21.65,30);
glEnd();

float cons2=2;
for(int i=0;i<=4;i++){

    glBegin(GL_LINES);
    glVertex2f(-17.65,18.62+cons2);
glVertex2f(-22.65,23.62+cons2);
glEnd();
cons2+=2;
}
glBegin(GL_LINES);
    glVertex2f(-17.65,18.62);
    glVertex2f(-17.65,30);
    glEnd();
}
void lineasPista(){
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(20,2,0);
    for( float i = 0 ; i < 4 ; i++){

        glBegin(GL_QUADS);
        glVertex2f(0,25);
        glVertex2f(1.5,25);
        glVertex2f(1.5,17);
        glVertex2f(0,17);
        glEnd();
        glTranslatef(0,-15,0);
    }
    glPopMatrix();

}

void fondo(){

    //glColor3f(250/255, 250/255, 250/255);
    glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_QUADS);
    glVertex2f(5,30);
    glVertex2f(100,30);
    glVertex2f(100,-30);
    glVertex2f(5,-30);
    glEnd();

    glPushMatrix();
    for ( int i = 0 ; i<4 ; i++){
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex2f(-5,30);
        glVertex2f(5,30);
        glVertex2f(5,-30);
        glVertex2f(-5,-30);
        glEnd();
        glTranslatef(100,0,0);

    }
    glPopMatrix();

    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(105,30);
    glVertex2f(180,30);
    glVertex2f(180,-30);
    glVertex2f(105,-30);
    glEnd();

    glPushMatrix();
    for ( int i = 0 ; i<4 ; i++){
        lineasPista();
        glTranslatef(20,0,0);
    }
    glPopMatrix();

    casas();

    glPushMatrix();
    glTranslated(120,25,0);
    arbol();
    glTranslated(20,-10,0);
    arbol();
    glTranslated(7,-20,0);
    arbol();
    glTranslated(-14,-10,0);
    arbol();
    glTranslated(-16,+5,0);
    arbol();
    glPopMatrix();


}

void vehiculo(){ // Dibuja el vehiculo a usar

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glColor3fv(brown);
    glVertex2f(-5,1);
    glVertex2f(-5+2,1);
    glVertex2f(-5+2,1-2);
    glVertex2f(-5,1-2);
    glEnd();;
    glBegin(GL_POLYGON);
    glVertex2f(-3.17,1.63);
    glVertex2f(-3,1);
    glVertex2f(-3.33,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-3.17-1,1.63);
    glVertex2f(-3-1,1);
    glVertex2f(-3.33-1,1);
    glEnd();

    glLineWidth(2);
    glColor3fv(black);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-5,1);
    glVertex2f(-5+2,1);
    glVertex2f(-5+2,1-2);
    glVertex2f(-5,1-2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3.17,1.63);
    glVertex2f(-3,1);
    glVertex2f(-3.33,1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(-3.17-1,1.63);
    glVertex2f(-3-1,1);
    glVertex2f(-3.33-1,1);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-4.33,1);
    glVertex2f(-3.88,-0.01);
    glVertex2f(-3.88,-0.01);
    glVertex2f(-3.53,-0.01);
    glVertex2f(-3.53,-0.01);
    glVertex2f(-3,1);
    glEnd();
    float c[]={-3.45,+0.79}, c1[]={-3.45-0.5,+0.79};
    Circunferencia(c,0.1,black,4,4,0,2*M_PI);
    Circunferencia(c1,0.1,black,4,4,0,2*M_PI);

    glColor3fv(black);
    glBegin(GL_POLYGON);
    glVertex2f(-3.96,0.17);
    glVertex2f(-3.43,0.17);
    glVertex2f(-3.53,-0.01);
    glVertex2f(-3.88,-0.01);
    glEnd();
}



void combi2 (float x, float y){

    glColor3f(1,1,0);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x+5,y);
    glVertex2f(x+5,y-9);
    glVertex2f(x,y-9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x, y-7.8);
    glVertex2f(x-0.25, y-7.6);
    glVertex2f(x-0.25, y-8.1);
    glVertex2f(x, y-8.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x+5, y-7.8);
    glVertex2f(x +5+0.25, y-7.6);
    glVertex2f(x +5+0.25, y-8.1);
    glVertex2f(x+5, y-8.4);
    glEnd();

    // VENTANAS

    glColor3f(0.5 , 0.5 , 0.5);
    glBegin(GL_QUADS);
    glVertex2f(x+0.7,y - 7.2);
    glVertex2f(x+4.3,y - 7.2);
    glVertex2f(x+4.5,y - 8.5);
    glVertex2f(x+0.5,y - 8.5);
    glEnd();

    ///////

    glBegin(GL_QUADS);
    glVertex2f(x+0.2, y - 5.5);
    glVertex2f(x+0.6, y - 5.5);
    glVertex2f(x+0.6, y - 7.0);
    glVertex2f(x+0.2, y - 7.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x+0.2, y - 1.4);
    glVertex2f(x+0.6, y - 1.4);
    glVertex2f(x+0.6, y - 4.4);
    glVertex2f(x+0.2, y - 4.4);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x+5-0.2, y - 5.5);
    glVertex2f(x+5-0.6, y - 5.5);
    glVertex2f(x+5-0.6, y - 7.0);
    glVertex2f(x+5-0.2, y - 7.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x+5-0.2, y - 1.4);
    glVertex2f(x+5-0.6, y - 1.4);
    glVertex2f(x+5-0.6, y - 4.4);
    glVertex2f(x+5-0.2, y - 4.4);
    glEnd();

}


void obstaculo2() {

//double t = glutGet(GLUT_ELAPSED_TIME) / 70.0;
//double a = t;
for(int i=0;i<=5000;i=i+1){


float a = 0.0004;
for ( int c = 0 ; c < n ; c++){
    combi2(posObsX[c], posObsY[c]);

    posObsY[c]-=a;
    a=a*1.175;

    if (posObsY[c] <-35){
    posObsY[c]=40;
    }

    if(tX  < posObsX[c] + 10 &&   tX-3 > posObsX[c]  &&   tY < posObsY[c]  &&    tY > posObsY[c]-9){

    tX=0;
    tY=0;
    }
}

}

}

void ganaste(float posx, float posy){

    /*glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(pos,0);
    glVertex2f(pos+20,0);
    glVertex2f(pos+20,20);
    glVertex2f(pos,20);
    glEnd();*/
    //cout<<"ganaste";

    float P1[] = {posx -4.25 , posy+4};
    float P2[] = {posx -3.0 , posy+4};
    Circunferencia(P1, 0.75 ,red, 0, 1, 0, M_PI*2+0.1);
    Circunferencia(P2, 0.75 ,red, 0, 1, 0, M_PI*2+0.1);
    glBegin(GL_POLYGON);
    glVertex2f(posx -4.25 -0.75 , posy+4 -0.3);
    glVertex2f(posx -3.0 + 0.75 , posy+4 -0.3);
    glVertex2f(posx -3.625 , posy+2.2);
    glEnd();

}


void Display(void)
{

glClearColor(1,1,1,0);//color el cual se limpia la ventana
glClear(GL_COLOR_BUFFER_BIT);//limpia la ventana
glLoadIdentity();
gluLookAt (tX, 0, 30, tX, 0.0, 0.0, 0.0, 1.0, 0.0);

fondo();

glPushMatrix();

glTranslated(tX,tY,0);
if (celebracion>0){
    glPushMatrix();
    glTranslated(-4,0,0);
    glRotatef(celebracion,0,0,1);
    glTranslated(+4,0,0);
    vehiculo();
    glPopMatrix();
}
else{
    vehiculo();
}
glPopMatrix();


glPushMatrix();
glRotatef(180,0,1,0);
glTranslated(-120,0,0);
vehiculo();
glPopMatrix();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(123.72  ,1.5 -0.3);
glVertex2f(124.72 - 0.1 ,2.0 -0.3);
glVertex2f(124.72 - 0.1 ,1.0 -0.3);
glVertex2f(122.72 + 0.1 ,2.0 -0.3);
glVertex2f(122.72 + 0.1 ,1.0 -0.3);
glEnd();


if(tX>=122 && tY >-2 && tY<=2 ){
    ganaste(tX,tY);
    celebracion+=5;
    }
if(tX>=130)tX=130;
if(tX<=-7)tX=-7;
if(tY>=30)tY=30;
if(tY<=-30)tY=-30;

obstaculo2();


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
    float paso = 1;
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

    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();

}

int main (int argc,char** argv){

    cout<< "   -----------------------------\n ";
    cout<< "   \n";
    cout<< "             RUN RUN  \n";
    cout<< "   \n";
    cout<< "   -----------------------------\n";
    cout<< "   \n";
    cout<< "   \n";
    cout<< "   AYUDA A RUNRUN A LLEGAR CON SU NOVIA \n";
    cout<< "   Muevete usando:\n";
    cout<< "   w: mover arriba \n";
    cout<< "   s: mover abajo \n";
    cout<< "   a: mover izquieda \n";
    cout<< "   d: mover derecha \n";
    cout<< "   EVITA LAS COMBIS O VOLVERAS A EMPEZAR \n";

    if(tX>=122 && tY >-2 && tY<=2 ){

        cout<< "  \n\n GANASTE\n";
    }

    PlaySound(TEXT("C:\\Users\\elanh\\Documents\\UNMSM\\Computacion Grafica\\Proyecto_Final\\bin\\Debug\\Juaneco y su combo - Me robaron mi runa mula - The Roots of Chicha.wav"), NULL, SND_ASYNC | SND_LOOP);
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
    glutMainLoop();


    return EXIT_SUCCESS;
}
