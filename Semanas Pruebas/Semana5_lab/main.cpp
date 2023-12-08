#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<cmath>
#define M_PI 3.141516




float white[]={1,1,1};
float black[]={0,0,0};
float negro[]={0,0,0},blanco[]={1,1,1},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};




void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-16,16,-16,16);
    glClearColor(0,0,0,0);
}


void circulo2(float x1,float y1,float a,float b,float radio,float *color) {
    glBegin(GL_POLYGON);
    glColor3fv(color);
    for(float Theta=a;Theta<b;Theta=Theta=Theta+0.01){


        glVertex2d(x1+radio*cos(Theta),y1+radio*sin(Theta));
    }
    glEnd();


}



void circulo(float x, float y,float r, float *color, int mod,float theta1,float theta2)
{
    glColor3fv(color);
    switch(mod)
    {
            case 1: glBegin(GL_LINE_LOOP);
                    break;
            case 2: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    glBegin(GL_POLYGON);
                    break;
    }
    glVertex2f(x,y);
    for(float i=theta1;i>=theta2;i=i-0.01){
        glVertex2f(r*cos(i)+x,r*sin(i)+y);
    }
    glEnd();


}


void sector(float *centro ,float *c,float radio,float Theta1,float Theta2,int n)
{


    for (int k=1; k<=2;k++)
    {
        switch (k)
        {
            case 1 : {
                glColor3fv(c);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(black);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }
        glBegin(GL_POLYGON);
        glVertex2fv(centro);

        switch (n)
        {
            case 1: {
            for (float i = Theta1;i <= Theta2; i = i + 0.01)
        {
            glVertex2f(radio*cos(i)+centro[0],radio*sin(i)+centro[1]);

        }
        break;
        }
        case 2: {
        for (float i = Theta1;i >= Theta2; i = i -0.01)
        {
            glVertex2f(radio*cos(i)+centro[0],radio*sin(i)+centro[1]);

        }
        break;
        }
        }


        glEnd();

    }
}
void cuadrado()
{

   for (int k=1; k<=2;k++)
    {
        switch (k)
        {
            case 1 : {
                glColor3fv(verde);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(negro);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }
        glBegin(GL_POLYGON);

        glVertex2f(-15, -1);
        glVertex2f(-7, -1);
        glVertex2f(-7, -14 );
        glVertex2f(-15, -14 );
        glEnd();

        glBegin(GL_POLYGON);

        glVertex2f(-15, 12);
        glVertex2f(-7, 12);
        glVertex2f(-7, -1 );
        glVertex2f(-15, -1 );
        glEnd();

        glBegin(GL_POLYGON);

        glVertex2f(6, 12);
        glVertex2f(14, 12);
        glVertex2f(14, -1 );
        glVertex2f(6, -1 );
        glEnd();

        glBegin(GL_POLYGON);

        glVertex2f(6, -1);
        glVertex2f(14, -1);
        glVertex2f(14, -14 );
        glVertex2f(6, -14 );
        glEnd();

         glBegin(GL_POLYGON);

        glVertex2f(-7, -1);
        glVertex2f(6, -1);
        glVertex2f(6, -14 );
        glVertex2f(-7, -14 );
        glEnd();

        glBegin(GL_POLYGON);

        glVertex2f(-7, 12);
        glVertex2f(6, 12);
        glVertex2f(6, -1 );
        glVertex2f(-7, -1 );
        glEnd();
    }

     for (int s=1; s<=2;s++)
    {
        switch (s)
        {
            case 1 : {
                glColor3fv(rojo);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(negro);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }
        glBegin(GL_POLYGON);

        glVertex2f(-10, 3);
        glVertex2f(-9, 3);
        glVertex2f(-9, 2);
        glVertex2f(-10, 2);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(12, 3);
        glVertex2f(11, 3);
        glVertex2f(11, 2);
        glVertex2f(12, 2);
        glEnd();

    }
for (int n=1; n<=2;n++)
    {
        switch (n)
        {
            case 1 : {
                glColor3fv(amarillo);
                glLineWidth(3);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
            }
            case 2 : {
                glColor3fv(negro);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(5);
                break;
            }
        }
        glBegin(GL_POLYGON);

        glVertex2f(8, -10);
        glVertex2f(9, -10);
        glVertex2f(9, -11);
        glVertex2f(8, -11);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(-13, -10);
        glVertex2f(-12, -10);
        glVertex2f(-12, -11);
        glVertex2f(-13, -11);
        glEnd();

    }

}



void aureo()
{



   cuadrado();

    float C1[]={0,-1,0,-2,1,-2,1,0,-2,0,-2,-5};
    float c4[]={0,-1,0,-2,-1,-2,-1,0,2,0,2,-5};

    float *color[]={rojo,amarillo,rojo,azul,amarillo,rojo};
    float *color2[]={amarillo,azul,amarillo,rojo,amarillo,azul};

    int k = 0;
    int r=0;
    int R=1;
    int l=0;

    //int s= 0;
    for(float i=0;i<3*M_PI;i=i+M_PI_2)//float i=M_PI_2;i<=5*M_PI_2;i=i+M_PI_2)
    {
        int s=R+r;
        float C2[]={C1[k]+8,C1[k+1]-9};
        float *c[]={color[l]};

        sector(C2,*c, s, i, i+M_PI_2,1);


        r=R;
        R=s;
        k=k+2;
        l=l+1;
    }

    int w = 0;
    int a=0;
    int d=1;
    int x=0;

     for(float i=0;i<5*M_PI/2;i=i+M_PI_2)//float i=M_PI_2;i<=5*M_PI_2;i=i+M_PI_2)
    {
        int q=d+a;
        float C3[]={C1[w]-13,C1[w+1]-9};
        float *c[]={color[x]};
        sector(C3,*c, q, i, i+M_PI/2,1);

        a=d;
        d=q;
        w=w+2;
        x=x+1;
    }



    int t = 0;
    int f=0;
    int g=1;
    int n=0;

    //int s= 0;
    for(float i=M_PI;i>-2*M_PI;i=i-M_PI_2)//float i=M_PI_2;i<=5*M_PI_2;i=i+M_PI_2)
    {
        int p1=g+f;
        float C5[]={c4[t]-9, c4[t+1]+4};
        float *c[]={color2[n]};

        sector(C5,*c, p1, i, i-M_PI_2,2);


        f=g;
        g=p1;
        t=t+2;
        n=n+1;
    }

    int t1 = 0;
    int f1=0;
    int g1=1;
    int n1=0;

    //int s= 0;
    for(float i=M_PI;i>-3*M_PI/2;i=i-M_PI_2)//float i=M_PI_2;i<=5*M_PI_2;i=i+M_PI_2)
    {
        int p2=g1+f1;
        float C5[]={c4[t1]+12, c4[t1+1]+4};
        float *c[]={color2[n1]};

        sector(C5,*c, p2, i, i-M_PI_2,2);


        f1=g1;
        g1=p2;
        t1=t1+2;
        n1=n1+1;
    }

    circulo(-5,7,0.75,negro,2,2*M_PI,0);
    circulo(-5,7,0.55,blanco,2,2*M_PI,0);
    circulo(-5,7,0.2,negro,2,2*M_PI,0);

    circulo(9,6,0.75,negro,2,2*M_PI,0);
    circulo(9,6,0.55,blanco,2,2*M_PI,0);
    circulo(9,6,0.2,negro,2,2*M_PI,0);

    circulo(4,-6,0.75,negro,2,2*M_PI,0);
    circulo(4,-6,0.55,blanco,2,2*M_PI,0);
    circulo(4,-6,0.2,negro,2,2*M_PI,0);

    circulo(-10,-7,0.75,negro,2,2*M_PI,0);
    circulo(-10,-7,0.55,blanco,2,2*M_PI,0);
    circulo(-10,-7,0.2,negro,2,2*M_PI,0);
}






void display (void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);


//    circulo(2,2,black,2,3*M_PI_4,M_PI_4);


    aureo();


    //circulo2(0.01,0.11,M_PI_2,3*M_PI_2,7,amarillo);//semicirculo
    //glFlush();
    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);




    glutCreateWindow("Sector");
    inicio();
    glutDisplayFunc(display);
    glutMainLoop();


    return EXIT_SUCCESS;
}
