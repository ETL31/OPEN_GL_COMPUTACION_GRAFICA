#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <math.h>

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1};
float red[] = {1,0,0}, green[]={0,1,0.3}, yellow[]={1,1,0};
float cyan[]={ 37/255.0, 252/255.0, 200/255.0 }, pink[]={1,0.5,0.5}, orange[]={1,0.5,0}, purple[]={0.8,0,0.408};

float gris[]={0.95,0.95,0.95};
float morado[]={109/255.0, 37/255.0, 252/255.0};



void HorizontalLines(float x, float y, float length, float separation){
    glColor3fv(black);
    glLineWidth(5);
    for(int i=0; i<5; i++){
    glBegin(GL_LINES);
        glVertex2f(x,y+i*separation);
        glVertex2f(x+length,y+i*separation);
    glEnd();
    }
}


void VerticalLines(float x, float y, float length, float separation){
    glColor3fv(black);
    glLineWidth(5);
    for(int i=0; i<5; i++){
    glBegin(GL_LINES);
        glVertex2f(x+i*separation,y);
        glVertex2f(x+i*separation,y+length);
    glEnd();
    }
}




void HorizontalPatron(float x, float y, float length, float separation){
    glColor3fv(black);
    glLineWidth(8);

    //first line
    glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x+length,y);
    glEnd();

    //second line
        glBegin(GL_LINES);
            glVertex2f(x,y+separation);    float range=20;
            glVertex2f(x+7*length/9,y+separation);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+8*length/9,y+separation);
            glVertex2f(x+length,y+separation);
        glEnd();

    //third line
        for(int i=0;i<5;i++){
        glBegin(GL_LINES);
            glVertex2f(x+2*i*length/9,y+2*separation);
            glVertex2f(x+(2*i+1)*length/9,y+2*separation);
        glEnd();

        }

    //four line
        glBegin(GL_LINES);
            glVertex2f(x,y+3*separation);
            glVertex2f(x+length/9,y+3*separation);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+2*length/9,y+3*separation);
            glVertex2f(x+7*length/9,y+3*separation);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+8*length/9,y+3*separation);
            glVertex2f(x+length,y+3*separation);
        glEnd();

    //end line
     glBegin(GL_LINES);
        glVertex2f(x,y+4*separation);
        glVertex2f(x+length,y+4*separation);
    glEnd();


    }


void Verticalpatron(float x, float y, float length, float separation){
        glColor3fv(black);
    glLineWidth(8);

    //first line
    glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x,y+length);
    glEnd();

    //second line
        glBegin(GL_LINES);
            glVertex2f(x+separation,y);
            glVertex2f(x+separation,y+length/9);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+separation,y+2*length/9);
            glVertex2f(x+separation,y+7*length/9);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+separation,y+8*length/9);
            glVertex2f(x+separation,y+length);
        glEnd();

    //third line
        for(int i=0;i<5;i++){
        glBegin(GL_LINES);
            glVertex2f(x+2*separation,y+2*i*length/9);
            glVertex2f(x+2*separation,y+(2*i+1)*length/9);
        glEnd();

        }

    //four line
        glBegin(GL_LINES);
            glVertex2f(x+3*separation,y);
            glVertex2f(x+3*separation,y+length/9);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+3*separation,y+2*length/9);
            glVertex2f(x+3*separation,y+7*length/9);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(x+3*separation,y+8*length/9);
            glVertex2f(x+3*separation,y+length);
        glEnd();


    //end line
     glBegin(GL_LINES);
        glVertex2f(x+4*separation,y);
        glVertex2f(x+4*separation,y+length);
    glEnd();
}



void drawTable1(float x_start,
                    float y_start,
                    float edge,
                    float width){

    float separation =edge/4;
    // draw table
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if ((j%2+i%2)%2==0){
                VerticalLines(x_start+i*separation,y_start+j*separation,separation,separation/4);
            }
            else{
                HorizontalLines(x_start+i*separation,y_start+j*separation,separation,separation/4);
            }
        }
    }
}



void drawTable2(float x_start,
                    float y_start,
                    float edge,
                    float width){

    float separation =edge/4;
    // draw table
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if ((j%2+i%2)%2==0){
                HorizontalPatron(x_start+i*separation,y_start+j*separation,separation,separation/4);
            }
            else{
                Verticalpatron(x_start+i*separation,y_start+j*separation,separation,separation/4);
            }
        }
    }
}




void display(void){

    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawTable1(-20,0,40,10);
    drawTable2(-20,-44,40,10);


    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,1080);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Preugnta1");
    glMatrixMode(GL_PROJECTION);
    float range=50;
    gluOrtho2D(-range,range,-range,range);
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
