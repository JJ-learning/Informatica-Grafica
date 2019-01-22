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
GLfloat Pared[] = {0.8f, 1.0f, 1.0f, 1.0f};
GLfloat Pelota[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat light_position[] = {0.2,0.2,-600.0,20.0};
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
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Pelota);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glRasterPos2f(x, y);
    for (i=0; i<strlen(string); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);

}

void TeclasMovimiento(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT:
        	if(MovimientoX>3)
        	{
        		glutPostRedisplay();
        	}
        	else if((MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY<-2.3) || (MovimientoX>-0.8 && MovimientoY>-1.3 && MovimientoX<0.0 && MovimientoY<-0.5) || (MovimientoX>2 && MovimientoY>-0.7 && MovimientoY<0.0) || (MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY>0.3 && MovimientoY<1.1))
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else if((MovimientoX<-1.8 && MovimientoY>-1.2 && MovimientoY<0.2))
        	{
        		MovimientoX+=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoY>-2.2 && MovimientoX>1.8 && MovimientoY<-1.1)
        	{
        		MovimientoX-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX<-1.8 && MovimientoY>1.8)
        	{
        		MovimientoY-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX>1.8 && MovimientoY>0.8 && MovimientoY<1.9)
        	{
        		MovimientoX-=0.1;
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
        	if(MovimientoX<-3)
        	{
        		glutPostRedisplay();
        	}
        	else if((MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY<-2.3) || (MovimientoX>-0.8 && MovimientoY>-1.3 && MovimientoX<0.0 && MovimientoY<-0.5) || (MovimientoX>2 && MovimientoY>-0.7 && MovimientoY<0.0) || (MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY>0.3 && MovimientoY<1.1))
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else if((MovimientoX<-1.8 && MovimientoY>-1.2 && MovimientoY<0.2))
        	{
        		MovimientoX+=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoY>-2.2 && MovimientoX>1.8 && MovimientoY<-1.1)
        	{
        		MovimientoX-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX<-1.8 && MovimientoY>1.8)
        	{
        		MovimientoY-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX>1.8 && MovimientoY>0.8 && MovimientoY<1.9)
        	{
        		MovimientoX-=0.1;
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
    		if((MovimientoY>2 && MovimientoX>-0.9 && MovimientoX<-0.0) || (MovimientoX>0.0 && MovimientoY>3.0) || (MovimientoX<-0.9 && MovimientoY>2.1))
    		{
    			glutPostRedisplay();
    		}
    		else if((MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY<-2.3) || (MovimientoX>-0.8 && MovimientoY>-1.3 && MovimientoX<0.0 && MovimientoY<-0.5) || (MovimientoX>2 && MovimientoY>-0.7 && MovimientoY<0.0) || (MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY>0.3 && MovimientoY<1.1) )
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else if((MovimientoX<-1.8 && MovimientoY>-1.2 && MovimientoY<0.2))
        	{
        		MovimientoX+=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoY>-2.2 && MovimientoX>1.8 && MovimientoY<-1.1)
        	{
        		MovimientoX-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX<-1.8 && MovimientoY>1.8)
        	{
        		MovimientoY-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX>1.8 && MovimientoY>0.8 && MovimientoY<1.9)
    			{
    				MovimientoX-=0.1;
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
        	if(MovimientoY<-2.9)
        	{
        		glutPostRedisplay();
        	}
    		else if((MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY<-2.3) || (MovimientoX>-0.8 && MovimientoY>-1.3 && MovimientoX<0.0 && MovimientoY<-0.5) || (MovimientoX>2 && MovimientoY>-0.7 && MovimientoY<0.0) || (MovimientoX>-0.8 && MovimientoX<0.0 && MovimientoY>0.3 && MovimientoY<1.1))
        	{
        		MovimientoX=-2.5;
        		MovimientoY=-2.5;
        		glutPostRedisplay();
        	}
        	else if((MovimientoX<-1.8 && MovimientoY>-1.2 && MovimientoY<0.2))
        	{
        		MovimientoX+=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoY>-2.2 && MovimientoX>1.8 && MovimientoY<-1.1)
        	{
        		MovimientoX-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX<-1.8 && MovimientoY>1.8)
        	{
        		MovimientoY-=0.1;
        		glutPostRedisplay();
        	}
        	else if(MovimientoX>1.8 && MovimientoY>0.8 && MovimientoY<1.9)
        	{
        		MovimientoX-=0.1;
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
	glLightfv(GL_LIGHT0,GL_DIFFUSE,llegada);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*Fila0*/
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -3.0); //V0
			glVertex2f(-3.0, -2.0); //v1
			glVertex2f(-2.0,-3.0); //v2
			glVertex2f(-2.0,-2.0); //v3
	 	glEnd();
	glPopMatrix();
	
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, -3.0, 0.0); //V0
			glVertex3f(-2.0, -2.0, 0.0); //v1
			glVertex3f(-1.5,-3.0, -0.5); //v2
			glVertex3f(-1.5,-2.0, -0.5); //v3
			glVertex3f(-1.0,-3.0,-1.0);//v4
			glVertex3f(-1.0,-2.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0, -3.0,-1.0); //V0
			glVertex3f(0.0, -2.0,-1.0); //v1
			glVertex3f(0.5,-3.0,-0.5); //v2
			glVertex3f(0.5,-2.0,-0.5); //v3
			glVertex3f(1.0,-3.0,0.0);//v4
			glVertex3f(1.0,-2.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,-3.0, 0.0); //v2
			glVertex3f(1.0,-2.0, -0.0); //v3
			glVertex3f(2.0,-3.0,0.0); //v2
			glVertex3f(2.0,-2.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0,-3.0, 0.0); //v2
			glVertex3f(2.0,-2.0, -0.0); //v3
			glVertex3f(3.0,-3.0,0.0); //v2
			glVertex3f(3.0,-2.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	/*FIN DE LA FILA0*/

	/*Fila1*/
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -2.0); //V0
			glVertex2f(-3.0, -1.0); //v1
			glVertex2f(-2.0,-2.0); //v2
			glVertex2f(-2.0,-1.0); //v3
	 	glEnd();
	glPopMatrix();

	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, -2.0, 0.0); //V0
			glVertex3f(-2.0, -1.0, 0.0); //v1
			glVertex3f(-1.5,-2.0, -0.5); //v2
			glVertex3f(-1.5,-1.0, -0.5); //v3
			glVertex3f(-1.0,-2.0,-1.0);//v4
			glVertex3f(-1.0,-1.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-1.0,-2.0, -1.0); //v2
			glVertex3f(-1.0,-1.0, -1.0); //v3
			glVertex3f(0.0,-2.0, -1.0); //v2
			glVertex3f(0.0,-1.0, -1.0); //v3
	 	glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0, -2.0,-1.0); //V0
			glVertex3f(0.0, -1.0,-1.0); //v1
			glVertex3f(0.5,-2.0,-0.5); //v2
			glVertex3f(0.5,-1.0,-0.5); //v3
			glVertex3f(1.0,-2.0,0.0);//v4
			glVertex3f(1.0,-1.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,-2.0, 0.0); //v2
			glVertex3f(1.0,-1.0, -0.0); //v3
			glVertex3f(2.0,-2.0,0.0); //v2
			glVertex3f(2.0,-1.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
	//PARED
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pared);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, -1.0,0.0); //V0
			glVertex3f(2.0, -1.0,0.5); //v1
			glVertex3f(3.0,-1.0,0.0); //v2
			glVertex3f(3.0,-1.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, -1.0,0.0); //V0
			glVertex3f(2.0, -1.0,0.5); //v1
			glVertex3f(2.0,-2.0,0.0); //v2
			glVertex3f(2.0,-2.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, -2.0,0.0); //V0
			glVertex3f(2.0,-2.0,0.5); //v1
			glVertex3f(3.0,-2.0,0.0); //v2
			glVertex3f(3.0,-2.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	/*FIN DE LA PARED*/
	/*FIN DE LA FILA1*/

/*FILA3*/
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, -0.0); //V0
			glVertex2f(-3.0, 1.0); //v1
			glVertex2f(-2.0,0.0); //v2
			glVertex2f(-2.0,1.0); //v3
	 	glEnd();
	glPopMatrix();

	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0,0.0, 0.0); //V0
			glVertex3f(-2.0,1.0, 0.0); //v1
			glVertex3f(-1.5,0.0, -0.5); //v2
			glVertex3f(-1.5,1.0, -0.5); //v3
			glVertex3f(-1.0,0.0,-1.0);//v4
			glVertex3f(-1.0,1.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-1.0,0.0, -1.0); //v2
			glVertex3f(-1.0,1.0, -1.0); //v3
			glVertex3f(0.0,0.0, -1.0); //v2
			glVertex3f(0.0,1.0, -1.0); //v3
	 	glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0, 0.0,-1.0); //V0
			glVertex3f(0.0, 1.0,-1.0); //v1
			glVertex3f(0.5,0.0,-0.5); //v2
			glVertex3f(0.5,1.0,-0.5); //v3
			glVertex3f(1.0,0.0,0.0);//v4
			glVertex3f(1.0,1.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,0.0, 0.0); //v2
			glVertex3f(1.0,1.0, -0.0); //v3
			glVertex3f(2.0,0.0,0.0); //v2
			glVertex3f(2.0,1.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0,0.0, 0.0); //v2
			glVertex3f(2.0,1.0, -0.0); //v3
			glVertex3f(3.0,0.0,0.0); //v2
			glVertex3f(3.0,1.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	

	/*FIN DE LA FILA3*/

	/*FILA 2*/
	//PARED
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pared);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-3.0, -1.0,0.0); //V0
			glVertex3f(-3.0, -1.0,0.5); //v1
			glVertex3f(-2.0,-1.0,0.0); //v2
			glVertex3f(-2.0,-1.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 0.0,0.0); //V0
			glVertex3f(-2.0, 0.0,0.5); //v1
			glVertex3f(-2.0,-1.0,0.0); //v2
			glVertex3f(-2.0,-1.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 0.0,0.0); //V0
			glVertex3f(-2.0, 0.0,0.5); //v1
			glVertex3f(-3.0,-0.0,0.0); //v2
			glVertex3f(-3.0,-0.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	/*FIN DE LA PARED*/
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, -1.0, 0.0); //V0
			glVertex3f(-2.0, -0.0, 0.0); //v1
			glVertex3f(-1.5,-1.0, -0.5); //v2
			glVertex3f(-1.5,-0.0, -0.5); //v3
			glVertex3f(-1.0,-1.0,-1.0);//v4
			glVertex3f(-1.0,-0.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0,-1.0,-1.0); //V0
			glVertex3f(0.0, 0.0,-1.0); //v1
			glVertex3f(0.5,-1.0,-0.5); //v2
			glVertex3f(0.5,0.0,-0.5); //v3
			glVertex3f(1.0,-1.0,0.0);//v4
			glVertex3f(1.0,0.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,-1.0, 0.0); //v2
			glVertex3f(1.0,0.0, -0.0); //v3
			glVertex3f(2.0,-1.0,0.0); //v2
			glVertex3f(2.0,0.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	
	/*FIN DE LA FILA2*/

	/*Fila5*/
	//PARED
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pared);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-3.0, 2.0,0.0); //V0
			glVertex3f(-3.0, 2.0,0.5); //v1
			glVertex3f(-2.0,2.0,0.0); //v2
			glVertex3f(-2.0,2.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 2.0,0.0); //V0
			glVertex3f(-2.0, 2.0,0.5); //v1
			glVertex3f(-2.0,3.0,0.0); //v2
			glVertex3f(-2.0,3.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 3.0,0.0); //V0
			glVertex3f(-2.0, 3.0,0.5); //v1
			glVertex3f(-3.0,3.0,0.0); //v2
			glVertex3f(-3.0,3.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	/*FIN DE LA PARED*/
	
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 2.0, 0.0); //V0
			glVertex3f(-2.0, 3.0, 0.0); //v1
			glVertex3f(-1.5,2.0, -0.5); //v2
			glVertex3f(-1.5,3.0, -0.5); //v3
			glVertex3f(-1.0,2.0,-1.0);//v4
			glVertex3f(-1.0,3.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-1.0,2.0, -1.0); //v2
			glVertex3f(-1.0,3.0, -1.0); //v3
			glVertex3f(0.0,2.0, -1.0); //v2
			glVertex3f(0.0,3.0, -1.0); //v3
	 	glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0, 2.0,-1.0); //V0
			glVertex3f(0.0, 3.0,-1.0); //v1
			glVertex3f(0.5,2.0,-0.5); //v2
			glVertex3f(0.5,3.0,-0.5); //v3
			glVertex3f(1.0,2.0,0.0);//v4
			glVertex3f(1.0,3.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,2.0, 0.0); //v2
			glVertex3f(1.0,3.0, -0.0); //v3
			glVertex3f(2.0,2.0,0.0); //v2
			glVertex3f(2.0,3.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	glLightfv(GL_LIGHT0,GL_DIFFUSE,llegada);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0,2.0, 0.0); //v2
			glVertex3f(2.0,3.0, -0.0); //v3
			glVertex3f(3.0,2.0,0.0); //v2
			glVertex3f(3.0,3.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();

	/*FIN DE LA PARED*/
	/*FIN DE LA FILA5*/

	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pisable);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/*Fila4*/
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex2f(-3.0, 1.0); //V0
			glVertex2f(-3.0, 2.0); //v1
			glVertex2f(-2.0,1.0); //v2
			glVertex2f(-2.0,2.0); //v3
	 	glEnd();
	glPopMatrix();
	
	//BAJADA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(-2.0, 1.0, 0.0); //V0
			glVertex3f(-2.0, 2.0, 0.0); //v1
			glVertex3f(-1.5,1.0, -0.5); //v2
			glVertex3f(-1.5,2.0, -0.5); //v3
			glVertex3f(-1.0,1.0,-1.0);//v4
			glVertex3f(-1.0,2.0,-1.0);//v5
		glEnd();
	glPopMatrix();
	//SUBIDA
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(0.0, 1.0,-1.0); //V0
			glVertex3f(0.0, 2.0,-1.0); //v1
			glVertex3f(0.5,1.0,-0.5); //v2
			glVertex3f(0.5,2.0,-0.5); //v3
			glVertex3f(1.0,1.0,0.0);//v4
			glVertex3f(1.0,2.0,0.0);//v5
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(1.0,1.0, 0.0); //v2
			glVertex3f(1.0,2.0, -0.0); //v3
			glVertex3f(2.0,1.0,0.0); //v2
			glVertex3f(2.0,2.0, 0.0); //v3
	 	glEnd();
	glPopMatrix();
	//PARED
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Pared);   
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, 1.0,0.0); //V0
			glVertex3f(2.0, 1.0,0.5); //v1
			glVertex3f(3.0,1.0,0.0); //v2
			glVertex3f(3.0,1.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, 1.0,0.0); //V0
			glVertex3f(2.0, 1.0,0.5); //v1
			glVertex3f(2.0,2.0,0.0); //v2
			glVertex3f(2.0,2.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	glPushMatrix();
		glBegin(GL_QUAD_STRIP);
			glVertex3f(2.0, 2.0,0.0); //V0
			glVertex3f(2.0,2.0,0.5); //v1
			glVertex3f(3.0,2.0,0.0); //v2
			glVertex3f(3.0,2.0,0.5); //v3
	 	glEnd();
	glPopMatrix();
	/*FIN DE LA PARED*/

	/*FIN DE LA FILA4*/

	
	
	
	
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   
   glLoadIdentity ();     
   gluLookAt (0.0, -4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   drawPanel();
 	if(MovimientoX>2.2 && MovimientoY>2.2)
    {
    	strcpy(string, "HAS GANADO!");
		printText(1.2, -2.8, string);
    }
    strcpy(string, "PULSA BOTON IZQUIERDO PARA COMENZAR");
    printText(0.2, -2.9, string);

   glLightfv(GL_LIGHT0, GL_DIFFUSE, Pelota);
   glLightfv(GL_LIGHT0,GL_POSITION,light_position);   
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
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMouseFunc(myMouseClick);
   glutSpecialFunc(TeclasMovimiento);
   glutMainLoop();
   return 0;
}