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


   glRectf(0,0,800,600); //aqui se define el tamaño del cuadro de la ventana
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
   glutReshapeWindow(800,600);//solicita un cambio en el tamaño de la ventana actual .
                              // Los parámetros de ancho y alto son extensiones de tamaño en píxeles
   glViewport(0, 0, w, h);   //  glViewport( entero x, y, w, h)
                            //   x,y: la esquina inferior izquierda del rectángulo de la ventana gráfica, en píxeles. El valor predeterminado es (0,0).
                            //   ancho, alto: el ancho y alto de la ventana gráfica.
                            //   Cuando un contexto OpenGL se adjunta por primera vez a una ventana, el ancho y el alto se establecen en las dimensiones de esa ventana.

     PintarEscena(); //INICIA LA FUNCION PINTAR ESCENA
}

void Mover(int value) {  //Función para que la bola se mueva
   glutTimerFunc(16,Mover,1); //Para programar una función que se ejecute en un intervalo de tiempo específico
                              //glutTimerFunc(unsigned int millis, void (*func)(int), int value);
                              //millis: es el número de milisegundos que deben transcurrir antes de que se ejecute la función.
                              //func: es el nombre de la función que se va a ejecutar.
                              //value: es un valor entero que se pasa a la función cuando se llama.

   glutPostRedisplay();       //Se solicita una actualización de la pantalla.
                              //Esta función se suele llamar después de realizar cambios en la escena que se está dibujando
                              //para indicar que es necesario volver a dibujar la pantalla y mostrar los cambios
                              //en la ventana gráfica.
                              //No es una función que realice la actualización de la pantalla de forma inmediata,
                              //sino que simplemente solicita una actualización.

   ball.Tocar(raton[0],raton[1]); //llamando con dos argumentos, raton[0] y raton[1]
   ball.Avanzar();                //Para mover la bola en la escena
   ball.Perder();                 //Para indicar que se ha perdido la partida.
}

void Raton(int button, int state, int x, int y) {  //Función Ratón de clicks
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) click = 1; //Si el botón izquierdo del ratón se encuentra
                                                                    //en un estado de pulsación.
                                                                    //Si se cumple esta condición,
                                                                    //se asignará el valor 1 a la variable click.

   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) click = 0;   //Si el botón izquierdo del ratón se encuentra
                                                                    //en un estado de liberación.
                                                                    //Si se cumple esta condición,
                                                                    //se asignará el valor 0 a la variable click.

   raton[0] = x;
   raton[1] = 600 - y;
}

void RatonMov(int x, int y) {  //Función Movimiento del Ratón
   raton[0] = x;
   raton[1] = 600 - y;
}

int main(int argc, char **argv) {  //Función de entrada del programa
                                   //La función main tiene dos parámetros: int argc y char **argv.
                                   //El parámetro int argc indica el número de argumentos
                                   //de línea de comandos que se han pasado al programa al ejecutarlo.
                                   //El parámetro char **argv es un array de cadenas de caracteres
                                   //que contiene los argumentos de línea de comandos pasados al programa.

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
      cout<< "***     si el click está alejado del centro          ***"<<endl;
      cout<< "***     de la bola.                                  ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "***            !! EVITA CAER AL PASTO!!              ***"<<endl;
      cout<< "***                                                  ***"<<endl;
      cout<< "********************************************************"<<endl;
      cout<< "********************************************************"<<endl;

     glutInit(&argc,argv);   //Inicializa GLUT y procesa los argumentos
                             //de línea de comandos pasados al programa al ejecutarlo.
                             //Debe llamarse antes de llamar a cualquier otra función de GLUT.
                             //La función glutInit toma dos argumentos: &argc y argv.
                             //El primer argumento, &argc, es el número de argumentos
                             //de línea de comandos pasados al programa, y se pasa por referencia
                             //para permitir que la función glutInit modifique este valor si es necesario.
                             //El segundo argumento, argv, es un array de cadenas de caracteres
                             //que contiene los argumentos de línea de comandos pasados al programa.

     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //Indica que la ventana de visualización de OpenGL
                                                   //debería utilizar un buffer de pantalla doble y
                                                   //un modelo de color RGB para mostrar
                                                   //imágenes de alta calidad sin parpadeos.
                                                   //La función recibe como parámetro una constante
                                                   //o una combinación de constantes que determinan
                                                   //cómo se mostrará la ventana.
                                                   //Estas constantes indican que la ventana de visualización
                                                   //debería utilizar un buffer de pantalla doble (double buffer)
                                                   //y un modelo de color RGB (Red, Green, Blue).
                                                   //El buffer de pantalla doble es una técnica utilizada
                                                   //para evitar parpadeos en la pantalla durante
                                                   //la actualización de imágenes.
                                                   //Se dibuja la imagen en un buffer oculto y
                                                   //luego se muestra en la pantalla de una sola vez,
                                                   //lo que evita que los usuarios vean parpadeos
                                                   //mientras se actualiza la imagen.

     glutInitWindowSize(800,600);    //Se utiliza para especificar el tamaño inicial
                                     //de la ventana de visualización.
                                     //La función recibe dos parámetros enteros
                                     //que indican el ancho y el alto de la ventana, en pixels.
                                     //Esto indica que la ventana de visualización
                                     //tendrá un ancho de 800 pixels y un alto de 600 pixels.
                                     //Se utiliza como tamaño predeterminado
                                     //y no es necesariamente el tamaño final de la ventana.

     glutInitWindowPosition(40,40);  //Es una función que se utiliza para especificar
                                     //la posición inicial de la ventana de visualización
                                     //y establece la posición de la esquina superior izquierda
                                     //de la ventana 40 pixels a la derecha y 40 pixels hacia abajo
                                     //desde la esquina superior izquierda de la pantalla.
                                     //Solo se utiliza como posición predeterminada
                                     //y no es necesariamente la posición final de la ventana.

     glutCreateWindow("PROYECTO BOLA ARANIA"); //Es una función que se utiliza para crear una ventana
                                               //de visualización con el título "PROYECTO BOLA ARANIA".

     ball.Iniciar();   //Función para iniciar el juego.

     glutReshapeFunc(ReProyectar);  //Es una función que se utiliza para establecer la función de devolución
                                    //de llamada "ReProyectar" como la función que se ejecutará
                                    //cuando se produzca un cambio en el tamaño de la ventana de visualización.
                                    //La función de devolución de llamada "ReProyectar" debe realizar
                                    //las operaciones necesarias para actualizar el tamaño de la ventana
                                    //y para adaptar el contenido de la ventana al nuevo tamaño.

     glutDisplayFunc(PintarEscena); //Es una función que se utiliza para establecer la función de devolución
                                    //de llamada "PintarEscena" como la función que se ejecutará
                                    //cuando se produzca un evento de visualización.
                                    //La función de devolución de llamada PintarEscena debe realizar
                                    //las operaciones necesarias para dibujar la escena en la
                                    //ventana de visualización.
                                    //No recibe ningún parámetro

     glutMouseFunc(Raton);  //Se utiliza para establecer una función de devolución de llamada
                            //que se ejecutará cuando se produzca un evento de ratón.
                            //Esto establece la función de devolución de llamada Raton
                            //como la función que se ejecutará cuando se produzca un evento de ratón.
                            //La función de devolución de llamada Raton recibe cuatro parámetros:
                            //void Raton(int boton, int estado, int x, int y)
                            //Boton: Un entero que indica el botón del ratón que ha generado el evento.
                            //Estado: Un entero que indica el estado del botón del ratón.
                            //x: un entero que indica la posición horizontal del cursor del ratón en la ventana.
                            //y: un entero que indica la posición vertical del cursor del ratón en la ventana.

     glutMotionFunc(RatonMov);  //Establece la función de devolución de llamada RatonMov
                                //como la función que se ejecutará cuando se produzca un evento de movimiento del ratón.
                                //Permite el uso del ratón para interactuar con la interfaz gráfica
                                //void RatonMov(int x, int y)
                                //La función de devolución de llamada RatonMov recibe dos parámetros:
                                //x: Un entero que indica la posición horizontal del cursor del ratón en la ventana.
                                //y: Un entero que indica la posición vertical del cursor del ratón en la ventana.

     glutPassiveMotionFunc(RatonMov);  //Establece la función de devolución de llamada RatonMov
                                       //como la función que se ejecutará cuando se produzca
                                       //un evento de movimiento pasivo del ratón.
                                       //Un evento de movimiento pasivo del ratón se produce cuando
                                       //el usuario mueve el cursor del ratón sobre la ventana de visualización
                                       //sin presionar ningún botón del ratón.
                                       //Por lo tanto, la función de devolución de llamada RatonMov
                                       //se ejecutará cada vez que el usuario mueva el cursor del ratón
                                       //sobre la ventana de visualización de OpenGL sin presionar ningún botón del ratón.
                                       //void RatonMov(int x, int y)
                                       //La función de devolución de llamada RatonMov recibe dos parámetros:
                                       //x: un entero que indica la posición horizontal del cursor del ratón en la ventana
                                       //y: un entero que indica la posición vertical del cursor del ratón en la ventana


     glutTimerFunc(16,Mover,1); //El primer argumento especifica el intervalo de tiempo en milisegundos
                                //(en este caso, 16 milisegundos).
                                //El segundo argumento es la función de retrollamada que se ejecutará
                                //cuando se produzca el evento de temporizador.
                                //El tercer argumento es un valor que se pasa
                                //a la función de retrollamada cuando se ejecuta.

     glutMainLoop();    //Se utiliza para iniciar el bucle principal de la aplicación gráfica.
                        //Una vez que se llama a glutMainLoop,
                        //la aplicación entra en un estado de "bucle principal"
                        //y comienza a procesar eventos del sistema, como entradas del teclado y del ratón,
                        //redibujar la pantalla, etc.
                        //Es una función de bloqueo que no regresa hasta que se cierre la aplicación gráfica.



   return 0;       //Se utiliza para finalizar la ejecución de una función
                   //y devolver un valor a la función que la llamó.
                   //En el caso de la función main, return 0;
                   //se utiliza para indicar que el programa se ha ejecutado correctamente.
}
