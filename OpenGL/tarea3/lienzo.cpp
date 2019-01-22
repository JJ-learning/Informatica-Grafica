#include <stdlib.h> 
#include <GL/glut.h> 
#include <stdio.h>
#include <string.h>

#define Height 400
#define Width 400

bool globalVariableMouseDown;
int mouseXPos=0;
int mouseYPos=0;
int firts=0;
int primerX, primerY, segundX, segundY, tercerX, tercerY;
int modo=0;
char string[200];

void printText(int x, int y, char string[200])
{
    int i;
    if(modo==0)
    {
       glColor3f(1.0, 0.0, 0.0); 
    }
    else if(modo==1)
    {
        glColor3f(0.0, 0.0, 1.);
    }
    glRasterPos2f(x, y);
    for (i=0; i<strlen(string); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
}

void drawTriangule(int primerX, int primerY, int segundX, int segundY, int tercerX, int tercerY)
{ 
    strcpy(string, "MODO TRIANGULO");
    printText(300, 10, string);
    glLineWidth(5.0);  
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f (primerX, primerY);
        glVertex2f(segundX, segundY);
        glVertex2f(tercerX, tercerY);
    glEnd();
    glFlush();
}

void drawLine(int primerX, int primerY, int segundX, int segundY)
{
    strcpy(string, "MODO LINEA");
    printText(10, 10, string);
    glLineWidth(5.0);  
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f (primerX, primerY);
        glVertex2f(segundX, segundY);
    glEnd();
    glFlush();
}

void myMouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {

        if (state == GLUT_DOWN)
        {
            globalVariableMouseDown = true;
            if(modo==0)
            {
                switch(firts)
                {
                    case 0:
                        primerX=x;
                        primerY=Height-y;
                        firts=1;
                        break;
                    case 1:
                        segundX=x;
                        segundY=Height-y;
                        drawLine(primerX, primerY, segundX, segundY);
                        firts=0;
                        break;
                }
            }
            else if(modo==1)
            {
                switch(firts)
                {
                    case 0:
                        primerX=x;
                        primerY=Height-y;
                        firts=1;
                        break;
                    case 1:
                        segundX=x;
                        segundY=Height-y;
                        firts=2;
                        break;
                    case 2:
                        tercerX=x;
                        tercerY=Height-y;
                        drawTriangule(primerX, primerY, segundX, segundY, tercerX, tercerY);
                        firts=0;
                        break;
                }
            }               
        }
        else
        {
            globalVariableMouseDown = false; 
        }
    }
    else if(button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            globalVariableMouseDown = true;
            if(modo == 0)
            {
                modo=1;
                glClearColor(0.0f,1.0f,0.0f,0.0f);
                glClear(GL_COLOR_BUFFER_BIT);
            }
            else if(modo==1)
            {
                glClearColor(0.0f,0.0f,1.0f,0.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                modo=0;
            }
        }
        else
        {
            globalVariableMouseDown = false; 
        }
    }
    else if(button == GLUT_MIDDLE_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            globalVariableMouseDown = true;
            glClear(GL_COLOR_BUFFER_BIT);
            if(modo == 0)
            {
                strcpy(string, "MODO LINEA");
                printText(10, 10, string);
            }
            else if(modo==1)
            {
                strcpy(string, "MODO TRIANGULO");
                printText(300, 10, string);
            }
        }
        else
        {
            globalVariableMouseDown = false; 
        }
    }
    //Guardamos los valores del click
    mouseXPos=x;
    mouseYPos=y;
}

void myMouseMove(int x, int y)
{
   printf("estoy en %d %d\n", x,y);
   if(x==segundX && y==segundY)
   {
        primerX=segundX;
        primerY=segundY;
        segundX=x;
        segundY=Height-y;
   }
}

void display(void)
{
    int x, y;

    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f,0.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    
    glColor3f(1, 0, 0);
    strcpy(string, "MODO LINEA");   
    
    printText(10, 10, string);

    glFlush();  
}



static void reshape(int w, int h)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(0, Width, 0, Height, 1.0, -1.0); 
}


int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("OpenGL");

    glutReshapeFunc(reshape);
    glutMotionFunc(myMouseMove);
    glutMouseFunc(myMouseClick);    
    glutDisplayFunc(display);

    glutMainLoop();
}