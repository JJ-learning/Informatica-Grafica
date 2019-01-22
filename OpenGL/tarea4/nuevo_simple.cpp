#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

GLfloat llegada[] = {1.f, 0.0f, 0.0f, 0.0f};
GLfloat salida[] = {1.0f, 0.0f, 0.0f, 0.0f};
GLfloat caida[] = {0.f, 0.0f, 0.0f, 0.0f};
GLfloat Pisable[] = {0.5f, 0.5f, 1.0f, 1.0f};
GLfloat Pelota[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat light_position[] = {1.0,1.0,-100.0,20.0};
GLfloat mat_shininess[] = { 50.0 };

float MovimientoX=-2.5;
float MovimientoY=-2.5;
float MovimientoZ=0.0;
char string[200];

void myMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{

        if (state == GLUT_DOWN)
        {
        	MovimientoX=-2.5;
        	MovimientoY=-2.5;
        	glutPostRedisplay();
        }
    }
}

void printText(float x, float y, char string[200])
{
	int i;
	//glColor3f(0.0, 1.0, 0.0); 
    glRasterPos2f(x, y);
    for (i=0; i<strlen(string); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);

}

void TeclasMovimiento(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT:
        	if(MovimientoX>2.8)
        	{
        		glutPostRedisplay();
        	}
        	else if((MovimientoX>0.1 && MovimientoX<0.9 && MovimientoY<-2.1) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>-1.9 && MovimientoX<-1.2 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>2.1 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>1.1 && MovimientoY<1.9))
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else
        	{
        		MovimientoX += 0.1;
	            glTranslatef(MovimientoX,MovimientoY,MovimientoZ); 
	            glutPostRedisplay();
        	}            
            break;
        case GLUT_KEY_LEFT:
        	if(MovimientoX<-2.8)
        	{
        		glutPostRedisplay();
        	}
        	else if((MovimientoX>0.1 && MovimientoX<0.9 && MovimientoY<-2.1) || (MovimientoX<-2.1 && MovimientoY>-1.9 && MovimientoY<-1.1) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>-1.9 && MovimientoX<-1.2 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX<-2.1 && MovimientoY>2.2))
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else
        	{
        		MovimientoX -= 0.1;
	            glTranslatef(MovimientoX,MovimientoY,MovimientoZ);
	            glutPostRedisplay();
        	}
            break;
        case GLUT_KEY_UP:
    		if(MovimientoY>2.8)
    		{
    			glutPostRedisplay();
    		}
    		else if((MovimientoX<-2.1 && MovimientoY>-1.9 && MovimientoY<-1.1) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>-1.9 && MovimientoX<-1.2 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>2.1 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX<-2.1 && MovimientoY>2.2))
    		{
    			MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
    		}
    		else
    		{
    			MovimientoY += 0.1;
	       		glTranslatef(MovimientoX,MovimientoY,MovimientoZ); 
	        	glutPostRedisplay();
    		}           
            break;
        case GLUT_KEY_DOWN:
        	if(MovimientoY<-2.8)
        	{
        		glutPostRedisplay();
        	}
        	else if((MovimientoX>0.1 && MovimientoX<0.9 && MovimientoY<-2.1) || (MovimientoX<-2.1 && MovimientoY>-1.9 && MovimientoY<-1.1) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>-0.9 && MovimientoY<-0.1) || (MovimientoX>-1.9 && MovimientoX<-1.2 && MovimientoY>0.1 && MovimientoY<0.9) || (MovimientoX>-0.9 && MovimientoX<-0.1 && MovimientoY>1.1 && MovimientoY<1.9) || (MovimientoX>1.1 && MovimientoX<1.9 && MovimientoY>1.1 && MovimientoY<1.9))
    		{
    			MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
    		}
    		else
    		{
    			MovimientoY -= 0.1;
	            glTranslatef(MovimientoX,MovimientoY,MovimientoZ); 
	            glutPostRedisplay();
    		}
            break;
    }
}



void drawPanel()
{	
	//Fila0
	glLightfv(GL_LIGHT0,GL_DIFFUSE,salida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -3.0); //V0
			glVertex2f(-3.0, -2.0); //v1
			glVertex2f(-2.0,-3.0); //v2
			glVertex2f(-2.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();
	
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, -3.0); //V0
			glVertex2f(-2.0, -2.0); //v1
			glVertex2f(-1.0,-3.0); //v2
			glVertex2f(-1.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, -3.0); //V0
			glVertex2f(-1.0, -2.0); //v1
			glVertex2f(0.0,-3.0); //v2
			glVertex2f(0.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.0, -3.0); //V0
			glVertex2f(0.0, -2.0); //v1
			glVertex2f(1.0,-3.0); //v2
			glVertex2f(1.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, -3.0); //V0
			glVertex2f(1.0, -2.0); //v1
			glVertex2f(2.0,-3.0); //v2
			glVertex2f(2.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, -3.0); //V0
			glVertex2f(2.0, -2.0); //v1
			glVertex2f(3.0,-3.0); //v2
			glVertex2f(3.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();
	/*Fin de la fila0*/

	//Fila 1
	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -2.0); //V0
			glVertex2f(-3.0, -1.0); //v1
			glVertex2f(-2.0,-2.0); //v2
			glVertex2f(-2.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, -2.0); //V0
			glVertex2f(-2.0, -1.0); //v1
			glVertex2f(-1.0,-2.0); //v2
			glVertex2f(-1.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, -2.0); //V0
			glVertex2f(-1.0, -1.0); //v1
			glVertex2f(-0.0,-2.0); //v2
			glVertex2f(-0.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.0, -2.0); //V0
			glVertex2f(0.0, -1.0); //v1
			glVertex2f(1.0,-2.0); //v2
			glVertex2f(1.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, -2.0); //V0
			glVertex2f(1.0, -1.0); //v1
			glVertex2f(2.0,-2.0); //v2
			glVertex2f(2.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, -2.0); //V0
			glVertex2f(2.0, -1.0); //v1
			glVertex2f(3.0,-2.0); //v2
			glVertex2f(3.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();
	 /*Fin de la fila 1*/

	//Fila2
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -1.0); //V0
			glVertex2f(-3.0, -0.0); //v1
			glVertex2f(-2.0,-1.0); //v2
			glVertex2f(-2.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, -1.0); //V0
			glVertex2f(-2.0, -0.0); //v1
			glVertex2f(-1.0,-1.0); //v2
			glVertex2f(-1.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, -1.0); //V0
			glVertex2f(-1.0, -0.0); //v1
			glVertex2f(-0.0,-1.0); //v2
			glVertex2f(-0.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-0.0, -1.0); //V0
			glVertex2f(-0.0, -0.0); //v1
			glVertex2f(1.0,-1.0); //v2
			glVertex2f(1.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, -1.0); //V0
			glVertex2f(1.0, -0.0); //v1
			glVertex2f(2.0,-1.0); //v2
			glVertex2f(2.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, -1.0); //V0
			glVertex2f(2.0, -0.0); //v1
			glVertex2f(3.0,-1.0); //v2
			glVertex2f(3.0,-0.0); //v3
	 	glEnd();
	glPopMatrix();
	 /*Fin de la fila2*/
	
	//Fila3
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -0.0); //V0
			glVertex2f(-3.0, 1.0); //v1
			glVertex2f(-2.0,-0.0); //v2
			glVertex2f(-2.0,1.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, -0.0); //V0
			glVertex2f(-2.0, 1.0); //v1
			glVertex2f(-1.0,-0.0); //v2
			glVertex2f(-1.0,1.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, -0.0); //V0
			glVertex2f(-1.0, 1.0); //v1
			glVertex2f(-0.0,-0.0); //v2
			glVertex2f(-0.0,1.0); //v3
	 	glEnd();
	glPopMatrix();
	 glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.0, -0.0); //V0
			glVertex2f(0.0, 1.0); //v1
			glVertex2f(1.0,-0.0); //v2
			glVertex2f(1.0,1.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, -0.0); //V0
			glVertex2f(1.0, 1.0); //v1
			glVertex2f(2.0,-0.0); //v2
			glVertex2f(2.0,1.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, -0.0); //V0
			glVertex2f(2.0, 1.0); //v1
			glVertex2f(3.0,-0.0); //v2
			glVertex2f(3.0,1.0); //v3
	 	glEnd();
	glPopMatrix();
	/*Fin de la fila3*/

	//Fila4
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, 1.0); //V0
			glVertex2f(-3.0, 2.0); //v1
			glVertex2f(-2.0,1.0); //v2
			glVertex2f(-2.0,2.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, 1.0); //V0
			glVertex2f(-2.0, 2.0); //v1
			glVertex2f(-1.0,1.0); //v2
			glVertex2f(-1.0,2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, 1.0); //V0
			glVertex2f(-1.0, 2.0); //v1
			glVertex2f(0.0,1.0); //v2
			glVertex2f(0.0,2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.0, 1.0); //V0
			glVertex2f(0.0, 2.0); //v1
			glVertex2f(1.0,1.0); //v2
			glVertex2f(1.0,2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, 1.0); //V0
			glVertex2f(1.0, 2.0); //v1
			glVertex2f(2.0,1.0); //v2
			glVertex2f(2.0,2.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, 1.0); //V0
			glVertex2f(2.0, 2.0); //v1
			glVertex2f(3.0,1.0); //v2
			glVertex2f(3.0,2.0); //v3
	 	glEnd();
	glPopMatrix();
	 /*Fin de la fila4*/

	//Fila5
	glLightfv(GL_LIGHT0,GL_DIFFUSE,caida);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, 2.0); //V0
			glVertex2f(-3.0, 3.0); //v1
			glVertex2f(-2.0,2.0); //v2
			glVertex2f(-2.0,3.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-2.0, 2.0); //V0
			glVertex2f(-2.0, 3.0); //v1
			glVertex2f(-1.0,2.0); //v2
			glVertex2f(-1.0,3.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-1.0, 2.0); //V0
			glVertex2f(-1.0, 3.0); //v1
			glVertex2f(0.0,2.0); //v2
			glVertex2f(0.0,3.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(0.0, 2.0); //V0
			glVertex2f(0.0, 3.0); //v1
			glVertex2f(1.0,2.0); //v2
			glVertex2f(1.0,3.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(1.0, 2.0); //V0
			glVertex2f(1.0, 3.0); //v1
			glVertex2f(2.0,2.0); //v2
			glVertex2f(2.0,3.0); //v3
	 	glEnd();
	glPopMatrix();

	glLightfv(GL_LIGHT0,GL_DIFFUSE,llegada);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(2.0, 2.0); //V0
			glVertex2f(2.0, 3.0); //v1
			glVertex2f(3.0,2.0); //v2
			glVertex2f(3.0,3.0); //v3
	 	glEnd();
	glPopMatrix();
	/*Fin de la fila5*/
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   
   glLoadIdentity ();             /* clear the matrix */
           /* viewing transformation  */
   gluLookAt (0, -4.2, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   drawPanel();
 	if(MovimientoX>2.2 && MovimientoY>2.2)
    {
    	strcpy(string, "HAS GANADO!");
		printText(1.2, -2, string);
    }
    strcpy(string, "PULSA BOTON IZQUIERDO PARA COMENZAR");
    printText(0.2, -1.8, string);

   glLightfv(GL_LIGHT0, GL_DIFFUSE, Pelota);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);    // This has to be light not material
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	
   	glTranslatef(MovimientoX,MovimientoY,MovimientoZ);
   	printf("%f \t%f \t%f\n",MovimientoX, MovimientoY, MovimientoZ );
   glColor3f(0.0f,0.0f,1.0f);
   glPushMatrix();
		glutSolidSphere(0.2,50,50);
	glPopMatrix();

	

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Nuevo");
   //init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMouseFunc(myMouseClick);
   glutSpecialFunc(TeclasMovimiento);
   glutMainLoop();
   return 0;
}