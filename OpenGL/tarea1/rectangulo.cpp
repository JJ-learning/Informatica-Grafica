#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include <GL/glut.h> 

#define Height 400
#define Width 440

GLfloat x=0, y=320;
GLfloat x2=40, y2=400;
int i=0;
int vueltas=0, r=1,g=0,b=0;

void bajar()
{
	y=y-1;
	y2=y2-1;
}

void subir()
{
	y=y+1;
	y2=y2+1;
}

void derecha()
{
	x=x+1;
	x2=x2+1;
}

void izquierda()
{
	x=x-1;
	x2=x2-1;
}

void aumento()
{
	if(x>40)
		x=x-1;
	if(y>0)
		y=y-1;
	if(x2<=440)
		x2=x2+1;
	if(y2<=400)
		y2=y2+1;
}

void disminuir()
{
	if(x<=200)
		x=x+1;
	if(y<=160)
		y=y+1;
	if(x2>240)
		x2=x2-1;
	if(y2>240)
		y2=y2-1;

}

void display(void)
{

	glViewport(0, 0, Width, Height); //Para cambiar el tamaño de ventana
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f,0.0f,1.0f, 0.0f);
    glLoadIdentity();

	glColor3f(r, g, 0);
    glRectf( x, y, x2, y2);

	glutSwapBuffers(); //Para renderizarlo	glFlush() para imágenes
}

void MueveRectangulo()
{
	//Ida
	if(i==0)
	{
		
		if(y2<=400 && x==0 && y<=320 && x2==40)
		{
			bajar();
		}
		if(y==0 && y2==80 && x>=0 && x2<=440)
		{
			derecha();
		}
		if(x==400 && x2==440 && y>=0 && y2<=360)
		{
			subir();
		}
		if(y2==360 && y==280 && x2<=440 && x>=40)
		{
			izquierda();
		}
		if(x==40 && x2==80 && y>=40 && y2<=360)
		{
			bajar();
		}
		if(y==40 && y2==120 && x>=40 && x2<=400)
		{
			derecha();
		}
		if(x==360 && x2==400 && y>=40 && y2<=320)
		{
			subir();
		}
		if(y==240 && y2==320 && x2<=400 && x>=80)
		{
			izquierda();
		}
		if(x==80 && x2==120 && y>=80 && y2<=320)
		{
			bajar();
		}
		if(y==80 && y2==160 && x>=80 && x2<=360)
		{
			derecha();
		}
		if(x==320 && x2==360 && y>=80 && y2<=280)
		{
			subir();
		}
		if(y==200 && y2==280 && x2<=360 && x>=120)
		{
			izquierda();
		}
		if(x==120 && x2==160 && y2<=280 && y>=120)
		{
			bajar();
		}
		if(y==120 && y2==200 && x>=120 && x2<=320)
		{
			derecha();
		}
		if(x==280 && x2==320 && y>=120 && y2<=240)
		{
			subir();
		}
		if(y==160 && y2==240 && x2<=320 && x>=200)
		{
			izquierda();
			if(x==200)
			{	
				i=2;
			}
		}
	}

	//Cambio de color
	if(vueltas==1)
	{
		r=0;
		g=1;
		b=0;
		i==1;
	}
	if(vueltas==2)
	{
		r=0;
		g=0;
		b=1;
		i==1;
	}
	if(vueltas==3)
	{
		r=1;
		g=0;
		b=0;
		i==1;
		vueltas=4;
	}
	//Aumentamos y disminuimos
	if(i==2)
	{
		aumento();
		if(x2>=400 && y2>=400 && x<=40 && y<=0)
		{
			i=3;
			
		}
	}

	if(i==3)
	{
		disminuir();
		if(x2<=240 && y2<=240 && x>=200 && y>=160)
		{
			vueltas++;
			i=1;
		}
	}
	if(i==0 && vueltas>3)
	{
		glutPostRedisplay();
	}
	//vuelta
	if(i==1)
	{
		if(y2<=400 && x==0 && y<=320 && x2==40)
		{
			subir();
			if(y2==400)
			{
				i=0;
			}
		}
		if(y==0 && y2==80 && x>=0 && x2<=440)
		{
			izquierda();
		}
		if(x==400 && x2==440 && y>=0 && y2<=360)
		{
			bajar();
		}
		if(y2==360 && y==280 && x2<=440 && x>=40)
		{
			derecha();
		}
		if(x==40 && x2==80 && y>=40 && y2<=360)
		{
			subir();
		}
		if(y==40 && y2==120 && x>=40 && x2<=400)
		{
			izquierda();
		}
		if(x==360 && x2==400 && y>=40 && y2<=320)
		{
			bajar();
		}
		if(y==240 && y2==320 && x2<=400 && x>=80)
		{
			derecha();
		}
		if(x==80 && x2==120 && y>=80 && y2<=320)
		{
			subir();
		}
		if(y==80 && y2==160 && x>=80 && x2<=360)
		{
			izquierda();
		}
		if(x==320 && x2==360 && y>=80 && y2<=280)
		{
			bajar();
		}
		if(y==200 && y2==280 && x2<=360 && x>=120)
		{
			derecha();
		}
		if(x==120 && x2==160 && y2<=280 && y>=120)
		{
			subir();
		}
		if(y==120 && y2==200 && x>=120 && x2<=320)
		{
			izquierda();
		}
		if(x==280 && x2==320 && y>=120 && y2<=240)
		{
			bajar();
		}
		if(y==160 && y2==240 && x2<=320 && x>=200)
		{
			derecha();
		}
	}
	//Limpiamos la pantalla antes de mostrarlo para que salga el fondo azul
	glClear(GL_COLOR_BUFFER_BIT); 
	glutPostRedisplay();
}

static void reshape(int w, int h)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(0, Width, 0, Height, -1.0, 1.0); 
}


int main(int argc, char **argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); //Double para hacer animaciones, SINGLE para estáticas
    glutInitWindowSize(Width, Height);
    glutCreateWindow("OpenGL");

    glutReshapeFunc(reshape); 
    glutDisplayFunc(display); //Funcion para dibujar
    glutIdleFunc(MueveRectangulo); //Para la animación

    glutMainLoop();
}
