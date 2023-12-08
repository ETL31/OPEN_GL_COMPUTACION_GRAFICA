#include <windows.h>
#include <iostream>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<cmath>
#endif
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592f
#define M_PI 3.1415

using namespace std;

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

bool click; // VARIABLE BOOLEANA, NO LE ASIGNAMOS VALOR INICIAL
int raton[2]; //ARREGLO QUE CONTIENE 2 ELEMENTOS DE TIPO ENTERO

GLubyte corazon[] =
{
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x0f,0xff,0xff,0xf0,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x01,0x80,0x10,
    0x08,0x03,0xc0,0x10,
    0x08,0x07,0xe0,0x10,
    0x08,0x0f,0xf0,0x10,
    0x08,0x1f,0xf8,0x10,
    0x08,0x3f,0xfc,0x10,
    0x08,0x7f,0xfe,0x10,
    0x08,0xff,0xff,0x10,
    0x09,0xff,0xff,0x90,
    0x0b,0xff,0xff,0xd0,
    0x0b,0xff,0xff,0xd0,
    0x0b,0xff,0xff,0xd0,
    0x0b,0xff,0xff,0xd0,
    0x09,0xfe,0x7f,0x90,
    0x08,0xfc,0x3f,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x08,0x00,0x00,0x10,
    0x0f,0xff,0xff,0xf0,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
};


class Bola {
public:
   float pos[3], vel[2]; // POS ARREGLO FLOTANTE QUE ALMACENA 3 COORDENADAS Y LA VARIABLE VEL QUE ALMACENA VELOCIDAD Y LA TASA DE CAMBIO DE LA POSICION EN COORDENADAS X E Y
   int toques, record, tiempo;  // DEFINIMOS LAS VARIABLES ENTERAS
   char puntos[40]; // DEFINIMOS PUNTOS COMO UN ARREGLO DE 40 ESPACIOS
   bool pausa; // VAARIABLE BOOLEANA EN PAUSA



   //VAMOS A USAR ESTE METODO PARA PARA DIBUJAR LA BOLA EN LA PANTALLA
  void Pintar() {
      glPushMatrix();
      glTranslatef(pos[0],pos[1],pos[2]);

      glColor3f(1,0.5,0.2);
      glEnable(GL_POLYGON_STIPPLE);
      glPolygonStipple(corazon);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glBegin(GL_POLYGON);
         glVertex3f(0,0,1);
         for (float i = 0; i <= (2*PI)+0.2f; i += 0.2f )
            glVertex3f(50*cosf(i),50*sinf(i),1);
      glEnd();
            glDisable(GL_POLYGON_STIPPLE);

    glColor3fv(naranja);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0,0,1);
         for (float i = 0; i <= (2*PI)+0.2f; i += 0.2f )
            glVertex3f(50*cosf(i),50*sinf(i),1);
      glEnd();

      glColor3fv(cyan);
      glBegin(GL_POLYGON);
         glVertex3f(0,0,1);
         for (float i = 0; i <= (2*PI)+0.2f; i += 0.2f )
            glVertex3f((50*sinf(i))/(cosf(i)*cosf(i)+1),(50*cosf(i)*sinf(i))/(cosf(i)*cosf(i)+1),1);
      glEnd();

      glPopMatrix();
      glRasterPos2f(50,10);

      sprintf(puntos,"Toques: %i. Record: %i.", toques,record);
      for (int i = 0; i<strlen(puntos); i++)
      {
          glColor3fv(negro);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, puntos[i]);}
   }


    //VAMOS A USAR ESTE METODO PARA INICIALIZAR LA BOLA EN UN POSICION Y VELOCIDAD DETERMINADA Y PONERLA EN PAUSA
   void Iniciar() {
      pos[0] = pos[1] = 300; //INICIAMOS EN LA POSICION 300 EN EL EJE X E 300 EN EL EJE Y
      pos[2] = tiempo = toques = 0; // INICIAMOS POS (2) , TIMER Y TOQUES EN CERO
      vel[0] = vel[1] = 25; // VEL(0) Y VEL(1) EN 25
      pausa = 1;  // PAUSA COMO VARIABLE BOOLEANA EN 1, AFIRMANDO
   }


    //AQUI VAMOS USAR ESTE METODO PARA DETECTAR SI LA BOLA HA SIDO GOLPEDAD Y ACTULIZAR SU VELOCIDAD Y EL NUMERO DE TOQUES
   void Tocar(float x, float y) {
      if ( sqrt( pow(x-pos[0],2) + pow(y-pos[1],2) ) <= 50 && click) {
         tiempo = click = 0;
         toques++;
         if (record < toques) record = toques;
         vel[0] = pos[0] - x;
         vel[1] = fabs(pos[1] - y);
         pausa = 0;
      }
   }


    //ESTE METODO LO VAMOS A UTILIZAR PARA MOVCER LA BOLA EN LA PANTALLA DE ACUERDO A SU VELOCIDAD Y TEMPORIZADOR
    void Avanzar() {   //el metodo Avanzar de la clase bola
      if (!pausa) {    //aqui negamos la funcion pausa osea si no esta detenido avanza
         tiempo++;     //el tiempo avanza de uno en uno
         if (pos[0] > 750 || pos[0] < 50) //si la posicion de la bola en el eje X es mayor  o menor a tal condicion
                 vel[0] = -vel[0]; //la velocidad  en el eje X cambiaria de direccion osea en sentido contrario
                 pos[0] += vel[0]*3 / 10; // la posicion en el eje X aumentaria en 3/10 DE SU VELOCIDAD en el EJE X, osea si la posicion era 10
                                         //  y su velocidad 60 la nueva posicion seria ahora sera 28
                 pos[1] += (vel[1]*3 - tiempo) / 10; // la posicion en el eje Y  aumentaria en 1/10 de (3*velocidad - timer)
      }
   }

   void Perder() {
      if (pos[1] < 50) Iniciar();  //pierdes si la bola esta menos a 50 del EJE Y
      if (pos[0]<50) Iniciar();
      if (pos[0]>750) Iniciar();
   }
} ball;

void circunferencia(float r, float x1, float y1, int patron1, float s,float *rgb)
{
    glColor3fv(rgb);
    glLineWidth(s);

    switch(patron1)
    {
        case 1: glBegin(GL_POINTS); break;
        case 2: glBegin(GL_LINES); break;
        case 3: glBegin(GL_LINE_LOOP); break;
        case 4: glBegin(GL_POLYGON); break;
    }

    for(float theta=0; theta<2*M_PI; theta=theta+0.1)
    {
        glVertex2f(r*cos(theta)+x1,r*sin(theta)+y1);
    }
    glEnd();
}

void Pasto(float *XY,float l, float p, float paso, float *color)
{
    glColor3fv(color);
    glLineWidth(l);
    glBegin(GL_LINE_LOOP);
    for (int i=0 ; i<16 ; i++){
    glVertex2f(XY[0],XY[1]);
    glVertex2f(XY[2],XY[3]);
    glVertex2f(XY[4],XY[5]);
    glVertex2f(XY[6],XY[7]);
    glVertex2f(XY[8],XY[9]);

    XY[0]=XY[0]+paso;
    XY[2]=XY[2]+paso;
    XY[4]=XY[4]+paso;
    XY[6]=XY[6]+paso;
    XY[8]=XY[8]+paso;
   }
     glEnd();
}

void cuadrilatero (float *XY, float h, float v, float s, float *color)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_QUADS);
    glVertex2d(XY[0],XY[1]);
    glVertex2d(XY[0],XY[1]+h);
    glVertex2d(XY[0]+v,XY[1]+h);
    glVertex2d(XY[0]+v,XY[1]);
    glEnd();

}

void PintarEscena() {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0,800,0,600,-1,1); // define los parametros de los Ejes X Y , Z (-x,x,-y,y,-z,z)


   glColor3fv(negro); // aca pintamos


   glRectf(0,0,800,600); //aqui se define el tama�o del cuadro de la ventana
                         //que puede tomar la ESCENA DEL JUEGO OSEA LOS LIMITES empiezan en el  0,0 y termina en 800,600

    float a[]={0,0,0,25,25,50,50,25,50,0};
    float b[]={0,0};
    float c[]={775,0};

    float d[]={400,300};

    for (int i=0; i<50 ; i++)
        {
            circunferencia(10+30*i,400,300,3,5,blanco);
        }

    Pasto(a,10,3,50,verde);
    cuadrilatero(b,800,25,3,rosa);
    cuadrilatero(c,800,25,3,amarillo);
    cuadrilatero(b,25,800,3,verde);




   ball.Pintar();        //aqui usamos la funcion pintar bola


   glutSwapBuffers();
}

void ReProyectar(int w, int h) {
   glutReshapeWindow(800,600);//solicita un cambio en el tama�o de la ventana actual .
                              // Los par�metros de ancho y alto son extensiones de tama�o en p�xeles
   glViewport(0, 0, w, h);   //  glViewport( entero x, y, w, h)
                            //   x,y: la esquina inferior izquierda del rect�ngulo de la ventana gr�fica, en p�xeles. El valor predeterminado es (0,0).
                            //   ancho, alto: el ancho y alto de la ventana gr�fica.
                            //   Cuando un contexto OpenGL se adjunta por primera vez a una ventana, el ancho y el alto se establecen en las dimensiones de esa ventana.

     PintarEscena(); //INICIA LA FUNCION PINTAR ESCENA
}

void Mover(int value) {  //Funci�n para que la bola se mueva
   glutTimerFunc(16,Mover,1); //Para programar una funci�n que se ejecute en un intervalo de tiempo espec�fico
                              //glutTimerFunc(unsigned int millis, void (*func)(int), int value);
                              //millis: es el n�mero de milisegundos que deben transcurrir antes de que se ejecute la funci�n.
                              //func: es el nombre de la funci�n que se va a ejecutar.
                              //value: es un valor entero que se pasa a la funci�n cuando se llama.

   glutPostRedisplay();       //Se solicita una actualizaci�n de la pantalla.
                              //Esta funci�n se suele llamar despu�s de realizar cambios en la escena que se est� dibujando
                              //para indicar que es necesario volver a dibujar la pantalla y mostrar los cambios
                              //en la ventana gr�fica.
                              //No es una funci�n que realice la actualizaci�n de la pantalla de forma inmediata,
                              //sino que simplemente solicita una actualizaci�n.

   ball.Tocar(raton[0],raton[1]); //llamando con dos argumentos, raton[0] y raton[1]
   ball.Avanzar();                //Para mover la bola en la escena
   ball.Perder();                 //Para indicar que se ha perdido la partida.
}

void Raton(int button, int state, int x, int y) {  //Funci�n Rat�n de clicks
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) click = 1; //Si el bot�n izquierdo del rat�n se encuentra
                                                                    //en un estado de pulsaci�n.
                                                                    //Si se cumple esta condici�n,
                                                                    //se asignar� el valor 1 a la variable click.

   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) click = 0;   //Si el bot�n izquierdo del rat�n se encuentra
                                                                    //en un estado de liberaci�n.
                                                                    //Si se cumple esta condici�n,
                                                                    //se asignar� el valor 0 a la variable click.

   raton[0] = x;
   raton[1] = 600 - y;
}

void RatonMov(int x, int y) {  //Funci�n Movimiento del Rat�n
   raton[0] = x;
   raton[1] = 600 - y;
}

int main(int argc, char **argv) {  //Funci�n de entrada del programa
                                   //La funci�n main tiene dos par�metros: int argc y char **argv.
                                   //El par�metro int argc indica el n�mero de argumentos
                                   //de l�nea de comandos que se han pasado al programa al ejecutarlo.
                                   //El par�metro char **argv es un array de cadenas de caracteres
                                   //que contiene los argumentos de l�nea de comandos pasados al programa.

      cout<< "********************************************************"<<endl;
      cout<< "********************************************************"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "***      GRUPO CONFORMADO POR:                       ***"<<endl;
      cout<< "***      - Ernesto Mihael Tolentino Leon             ***"<<endl;
      cout<< "***      - Jose Antonio Panca Trujillo               ***"<<endl;
      cout<< "***      - Cristhian Michael Romero Lazo             ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "***     Ayuda a la Bola Arania a no caer             ***"<<endl;
      cout<< "***     dandole CLICKS izquierdo.                    ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "***     OJO!                                         ***"<<endl;
      cout<< "***     Cada click lanzara a la bola mas alto        ***"<<endl;
      cout<< "***     si el click est� alejado del centro          ***"<<endl;
      cout<< "***     de la bola.                                  ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "***            !! EVITA CAER AL PASTO!!              ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "********************************************************"<<endl;
      cout<< "********************************************************"<<endl;

     glutInit(&argc,argv);   //Inicializa GLUT y procesa los argumentos
                             //de l�nea de comandos pasados al programa al ejecutarlo.
                             //Debe llamarse antes de llamar a cualquier otra funci�n de GLUT.
                             //La funci�n glutInit toma dos argumentos: &argc y argv.
                             //El primer argumento, &argc, es el n�mero de argumentos
                             //de l�nea de comandos pasados al programa, y se pasa por referencia
                             //para permitir que la funci�n glutInit modifique este valor si es necesario.
                             //El segundo argumento, argv, es un array de cadenas de caracteres
                             //que contiene los argumentos de l�nea de comandos pasados al programa.

     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //Indica que la ventana de visualizaci�n de OpenGL
                                                   //deber�a utilizar un buffer de pantalla doble y
                                                   //un modelo de color RGB para mostrar
                                                   //im�genes de alta calidad sin parpadeos.
                                                   //La funci�n recibe como par�metro una constante
                                                   //o una combinaci�n de constantes que determinan
                                                   //c�mo se mostrar� la ventana.
                                                   //Estas constantes indican que la ventana de visualizaci�n
                                                   //deber�a utilizar un buffer de pantalla doble (double buffer)
                                                   //y un modelo de color RGB (Red, Green, Blue).
                                                   //El buffer de pantalla doble es una t�cnica utilizada
                                                   //para evitar parpadeos en la pantalla durante
                                                   //la actualizaci�n de im�genes.
                                                   //Se dibuja la imagen en un buffer oculto y
                                                   //luego se muestra en la pantalla de una sola vez,
                                                   //lo que evita que los usuarios vean parpadeos
                                                   //mientras se actualiza la imagen.

     glutInitWindowSize(800,600);    //Se utiliza para especificar el tama�o inicial
                                     //de la ventana de visualizaci�n.
                                     //La funci�n recibe dos par�metros enteros
                                     //que indican el ancho y el alto de la ventana, en pixels.
                                     //Esto indica que la ventana de visualizaci�n
                                     //tendr� un ancho de 800 pixels y un alto de 600 pixels.
                                     //Se utiliza como tama�o predeterminado
                                     //y no es necesariamente el tama�o final de la ventana.

     glutInitWindowPosition(40,40);  //Es una funci�n que se utiliza para especificar
                                     //la posici�n inicial de la ventana de visualizaci�n
                                     //y establece la posici�n de la esquina superior izquierda
                                     //de la ventana 40 pixels a la derecha y 40 pixels hacia abajo
                                     //desde la esquina superior izquierda de la pantalla.
                                     //Solo se utiliza como posici�n predeterminada
                                     //y no es necesariamente la posici�n final de la ventana.

     glutCreateWindow("PROYECTO BOLA ARANIA"); //Es una funci�n que se utiliza para crear una ventana
                                               //de visualizaci�n con el t�tulo "PROYECTO BOLA ARANIA".

     ball.Iniciar();   //Funci�n para iniciar el juego.

     glutReshapeFunc(ReProyectar);  //Es una funci�n que se utiliza para establecer la funci�n de devoluci�n
                                    //de llamada "ReProyectar" como la funci�n que se ejecutar�
                                    //cuando se produzca un cambio en el tama�o de la ventana de visualizaci�n.
                                    //La funci�n de devoluci�n de llamada "ReProyectar" debe realizar
                                    //las operaciones necesarias para actualizar el tama�o de la ventana
                                    //y para adaptar el contenido de la ventana al nuevo tama�o.

     glutDisplayFunc(PintarEscena); //Es una funci�n que se utiliza para establecer la funci�n de devoluci�n
                                    //de llamada "PintarEscena" como la funci�n que se ejecutar�
                                    //cuando se produzca un evento de visualizaci�n.
                                    //La funci�n de devoluci�n de llamada PintarEscena debe realizar
                                    //las operaciones necesarias para dibujar la escena en la
                                    //ventana de visualizaci�n.
                                    //No recibe ning�n par�metro

     glutMouseFunc(Raton);  //Se utiliza para establecer una funci�n de devoluci�n de llamada
                            //que se ejecutar� cuando se produzca un evento de rat�n.
                            //Esto establece la funci�n de devoluci�n de llamada Raton
                            //como la funci�n que se ejecutar� cuando se produzca un evento de rat�n.
                            //La funci�n de devoluci�n de llamada Raton recibe cuatro par�metros:
                            //void Raton(int boton, int estado, int x, int y)
                            //Boton: Un entero que indica el bot�n del rat�n que ha generado el evento.
                            //Estado: Un entero que indica el estado del bot�n del rat�n.
                            //x: un entero que indica la posici�n horizontal del cursor del rat�n en la ventana.
                            //y: un entero que indica la posici�n vertical del cursor del rat�n en la ventana.

     glutMotionFunc(RatonMov);  //Establece la funci�n de devoluci�n de llamada RatonMov
                                //como la funci�n que se ejecutar� cuando se produzca un evento de movimiento del rat�n.
                                //Permite el uso del rat�n para interactuar con la interfaz gr�fica
                                //void RatonMov(int x, int y)
                                //La funci�n de devoluci�n de llamada RatonMov recibe dos par�metros:
                                //x: Un entero que indica la posici�n horizontal del cursor del rat�n en la ventana.
                                //y: Un entero que indica la posici�n vertical del cursor del rat�n en la ventana.

     glutPassiveMotionFunc(RatonMov);  //Establece la funci�n de devoluci�n de llamada RatonMov
                                       //como la funci�n que se ejecutar� cuando se produzca
                                       //un evento de movimiento pasivo del rat�n.
                                       //Un evento de movimiento pasivo del rat�n se produce cuando
                                       //el usuario mueve el cursor del rat�n sobre la ventana de visualizaci�n
                                       //sin presionar ning�n bot�n del rat�n.
                                       //Por lo tanto, la funci�n de devoluci�n de llamada RatonMov
                                       //se ejecutar� cada vez que el usuario mueva el cursor del rat�n
                                       //sobre la ventana de visualizaci�n de OpenGL sin presionar ning�n bot�n del rat�n.
                                       //void RatonMov(int x, int y)
                                       //La funci�n de devoluci�n de llamada RatonMov recibe dos par�metros:
                                       //x: un entero que indica la posici�n horizontal del cursor del rat�n en la ventana
                                       //y: un entero que indica la posici�n vertical del cursor del rat�n en la ventana


     glutTimerFunc(16,Mover,1); //El primer argumento especifica el intervalo de tiempo en milisegundos
                                //(en este caso, 16 milisegundos).
                                //El segundo argumento es la funci�n de retrollamada que se ejecutar�
                                //cuando se produzca el evento de temporizador.
                                //El tercer argumento es un valor que se pasa
                                //a la funci�n de retrollamada cuando se ejecuta.

     glutMainLoop();    //Se utiliza para iniciar el bucle principal de la aplicaci�n gr�fica.
                        //Una vez que se llama a glutMainLoop,
                        //la aplicaci�n entra en un estado de "bucle principal"
                        //y comienza a procesar eventos del sistema, como entradas del teclado y del rat�n,
                        //redibujar la pantalla, etc.
                        //Es una funci�n de bloqueo que no regresa hasta que se cierre la aplicaci�n gr�fica.



   return 0;       //Se utiliza para finalizar la ejecuci�n de una funci�n
                   //y devolver un valor a la funci�n que la llam�.
                   //En el caso de la funci�n main, return 0;
                   //se utiliza para indicar que el programa se ha ejecutado correctamente.
}
