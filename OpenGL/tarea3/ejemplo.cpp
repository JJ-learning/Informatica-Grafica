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

void deletePoint(int primerX, int primerY)
{
    strcpy(string, "MODO LINEA");
    printText(10, 10, string);
    glPointSize(7);  
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
        glVertex2f (primerX, primerY);
    glEnd();
    glutSwapBuffers();
}

void drawPoint(int primerX, int primerY)
{
    strcpy(string, "MODO LINEA");
    printText(10, 10, string);
    glPointSize(7);  
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
        glVertex2f (primerX, primerY);
    glEnd();
    glutSwapBuffers();
}

void myMouseClick(int button, int state, int x, int y)
{
    int antiX=primerX;
    int antiY=primerY;
    if (button == GLUT_LEFT_BUTTON) {

        if (state == GLUT_DOWN)
        {
            if(primerX==x && primerY==Height-y)
            {
                leftBotton=true;
                deletePoint(antiX,antiY);
                //glutPostRedisplay();
                //drawPoint(primerX, primerY);
            }
            else
            {
                leftBotton=false;
                primerX=x;
                primerY=Height-y;
                drawPoint(primerX, primerY);
            }
            
        }
        else if(state==GLUT_UP)
        {
            //glutPostRedisplay();
            leftBotton=false;
            primerX=x;
            primerY=Height-y;
            drawPoint(primerX, primerY);            
        }
    }   
}

void myMouseMove(int x, int y)
{
   if(leftBotton==true)
   {
        primerX=x;
        primerY=Height-y;
        //drawPoint(primerX, primerY);
   }
   printf("%d, %d\n", primerX, primerY);
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
