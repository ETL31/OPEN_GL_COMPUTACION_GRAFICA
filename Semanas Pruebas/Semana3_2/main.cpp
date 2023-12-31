#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

    float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
    float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
    float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};

void tablero(float *XY , float *S )
{

    glBegin(GL_QUADS);
    glVertex2f(XY[0], XY[1]);
    glVertex2f(XY[0] + S[1], XY[1]);
    glVertex2f(XY[0] + S[1], XY[1] - S[0] );
    glVertex2f(XY[0], XY[1] - S[0] );
    glEnd();

}

void lineas(float *X, float *M )
{
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(X[0], X[1]);
    glVertex2f(X[0] + M[1], X[1]);
    glVertex2f(X[0] + M[1], X[1] - M[0] );
    glVertex2f(X[0], X[1] - M[0] );
    glEnd();
}

void display(void)
{
    glClearColor (0.1,0.4,0.1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpia el color, y el otro se encarga de los buffers
    float r=0, l=0;



    for(int i=0;i<8;i++)
    {
        float A[]={-80+l,80-r},S[]={20,20},X[]={-80+l,80-r},M[]={20,20};
        for (int j=0;j<8;j++)
        {
        float A[]={-80+l,80-r},S[]={20,20},X[]={-80+l,80-r},M[]={20,20};
            if(i%2==0)
             { if (j%2==0)
                {glColor3f(1,0,0);}
               else
                {glColor3f(0,0,0);}
            }
            else
            {
                if (j%2!=0)
                {glColor3f(1,0,0);}
                else
                {glColor3f(0,0,0);}

            }

        tablero(A,S);
        glColor3f(0.5,0.5,0.5);
        lineas(X,M);
        l=l+20;
        }
        l=0;
        r=r+20;
    }

    glutSwapBuffers();//limpia la consola,
    //glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //inicializando
    glutInitWindowSize(800,900); //tama�o de la ventana
    glutInitWindowPosition(10,10); //posicion de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Ajedrez"); //nombre de la ventana
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-120,120,-120,120);

    glutMainLoop(); //que aparesca la consola

    return EXIT_SUCCESS;
}
