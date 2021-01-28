#include <GL/gl.h>
#include<string>
#include<math.h>
#include <GL/glut.h> 
using namespace std;
#define PI 3.141592

int shapeside = 5, left =  -1, right= -1; //left to make shape, right to colour them
float x = 0.5, y = 0.5, radius=0.2, i=0; //size of the pentagon
GLfloat twicePi = 2.0f * PI;
GLfloat hu[6] = {-0.7,0.4,0.8,-0.6,0.1,-0.1}, hi[6] = {0.35,-0.4,0.5,-0.8,0.2,-0.2};

void display()
{ 
glClearColor(1,1,1,1); 
glClear(GL_COLOR_BUFFER_BIT);

if(left>=0)
{       
x = hu[0];
y = hi[0];
glColor3f(0,0,0);
glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	
	if(left>=1)
	{       
		x = hu[1];
        	y = hi[1];
        	glColor3f(0,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	
	if(left>=2)
	{       
		x = hu[3];
        	y = hi[3];
        	glColor3f(0,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	
	if(left>=3)
	{       
		x = hu[4];
        	y = hi[4];
        	glColor3f(0,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	
	if(left>=4)
	{       
		x = hu[5];
        	y = hi[5];
        	glColor3f(0,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	
	if(left>=5)
	{       
		x = hu[6];
        	y = hi[6];
        	glColor4f(0,0,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // centroid of pentagon
		for(i = 0; i <= shapeside;i++) 
		{ 
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)), 
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=0)
	{
		x = hu[0];
        	y = hi[0];
        	glColor3f(0.3,0,0.5);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=1)
	{
		x = hu[1];
        	y = hi[1];
        	glColor3f(0,0.5,0.5);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=2)
	{
		x = hu[3];
        	y = hi[3];
        	glColor3f(1,0,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=3)
	{
		x = hu[4];
        	y = hi[4];
        	glColor3f(0,1,0);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=4)
	{
		x = hu[5];
        	y = hi[5];
        	glColor3f(0.5,0.5,0.5);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}

	if(right>=5)
	{
		x = hu[6];
        	y = hi[6];
        	glColor3f(0.5,0.5,0.5);
        	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of pentagon
		for(i = 0; i <= shapeside;i++)
		{
			glVertex2f
			(
		            x + (radius * sin(i *  twicePi / shapeside)),
			    y + (radius * cos(i * twicePi / shapeside))
			);
		}
	    	glEnd();
	}
	glColor4f(0,0,0,0);
	string s="Harshit Joshi - 500068141";
	glRasterPos2f(0.55,-0.9);
	int n=s.size();
	for(int i=0;i<n;i++)
    		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[i]);
 	glEnd();
 	glFlush();
 	glutSwapBuffers(); 
}

void mouse(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{ 
        	left++;   
       	glutPostRedisplay();
   	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
	{ 
		right++; 
       	glutPostRedisplay();
   	}
}

void keyboard(unsigned char key, int x, int y) 
{
   	if(key == 27) // escape key
        	exit(0);

	if(key != 32) 
    		return;
    
        if(radius > 0.0)
        {
            	left--;
		right--;
            	glutPostRedisplay();
        }
}

int main( int argc, char** argv ) 
{
   	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_SINGLE);
   	glutInitWindowSize(1150,610);
   	glutInitWindowPosition(00,00);   
   	glutCreateWindow("Experiment2-Event Handling"); 
   	glutDisplayFunc(display);    
   	glutMouseFunc(mouse);
   	glutKeyboardFunc(keyboard);
   	glutMainLoop();
   	return 0;
}


