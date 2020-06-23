#include <GL/freeglut.h>

bool bFullscreen = false;



float start_x = 0.0f;
float start_y = 0.0f;
float unit=0.0002;

int main(int argc, char** argv)
{
	//code
	//function declaration
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GLUT: Y_Nandlal_Lambole");
	


	initialize();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	
	

	glutMainLoop();

	return(0); //this line is not necessary
}
void initialize()
{
	//code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void resize(int width, int height)

{
	//code
	if (height < 0)
		height = 1;

		glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
}

void display(void)
{
	//code
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(10);
	glColor3f(0.078f, 0.976f, 0.816f);

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f + start_x, 0.0f + start_y);
	glEnd();

	start_y += unit;
	start_x += unit;

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-(0.0f + start_x), 0.0f + start_y);
	glEnd();
	

	start_y += unit;
	start_x += unit;

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f , -(0.0f + start_y));
	glEnd();
	
	start_y += unit;

	if (start_x >= 0.5 || start_y >= 0.5)
	{
		unit = 0.0;
	}


	
	glutPostRedisplay();
	glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y)
{
	//code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if(bFullscreen == false)
		{
			glutFullScreen();

			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
}
void mouse(int button, int state, int x, int y)
{
	//code
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}
void uninitialize()
{
	//code
}







// cl.exe /c /EHsc /I C:\freeglut\include Y_Character.cpp
// link.exe Y_Character.obj /LIBPATH:C:\freeglut\lib /SUBSYSTEM:CONSOLE




/* glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(-0.07f, -0.05f);
		glVertex2f(-0.07f, -0.5f);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(0.07f, -0.05f);
		glVertex2f(0.07f, -0.5f);

		glEnd();

		glBegin(GL_LINES);
		glVertex2f(-0.07f, -0.5f);
		glVertex2f(0.07f, -0.5f);

		glEnd();


		//--------------------------------------

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.4f, 0.5f);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.4f, 0.5f);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.07f, -0.05f);

		glEnd();

		//---------------------------------

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.4f, 0.5f);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.4f, 0.5f);

		glEnd();

		glBegin(GL_LINES);
		glColor3f(0.078f, 0.976f, 0.816f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.07f, -0.05f);

		glEnd();*/