#include <stdlib.h> 
#include <GL/glut.h> 
#include <stdio.h>
#include <string.h>


#define Height 400
#define Width 400

bool leftBotton=false;
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

void deleteLine(int primerX, int primerY, int segundX, int segundY)
{
    strcpy(string, "MODO LINEA");
    printText(10, 10, string);
    glLineWidth(10);  
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2f (primerX, primerY);
        glVertex2f(segundX, segundY);
    glEnd();
    glutSwapBuffers();
}

void drawLine(int primerX, int primerY, int segundX, int segundY)
{
    strcpy(string, "MODO LINEA");
    printText(10, 10, string);
    glLineWidth(10);  
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f (primerX, primerY);
        glVertex2f(segundX, segundY);
    glEnd();
    glutSwapBuffers();
}

void myMouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {

        if (state == GLUT_DOWN)
        {
            if(segundX==x && segundY==Height-y || primerX==x && primerY==Height-y)
            {
                leftBotton=true;
                deleteLine(primerX,primerY, segundX, segundY);
                //glutPostRedisplay();
                //drawPoint(primerX, primerY);
            }
            else
            {
                leftBotton=false;
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
            
        }
        else if(state==GLUT_UP)
        {
            //glutPostRedisplay();
            leftBotton=false;

            segundX=x;
            segundY=Height-y;
            //drawLine(primerX, primerY, segundX, segundY);            
        }
    }   
}

void myMouseMove(int x, int y)
{
   if(leftBotton==true)
   {
        segundX=x;
        segundY=Height-y;
        //drawPoint(segundX, segundY);
   }
   printf("%d, %d\n", segundX, segundY);
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

    glutSwapBuffers();
}



static void reshape(int w, int h)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(0, Width, 0, Height, -1.0, 1.0); 
}


int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("OpenGL");

    glutReshapeFunc(reshape);
    glutMotionFunc(myMouseMove);    
    glutMouseFunc(myMouseClick);
    glutDisplayFunc(display);

    glutMainLoop();
}
