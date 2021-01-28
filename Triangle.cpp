#include <GL/gl.h>
#include<string>
#include<math.h>
#include <GL/glut.h>
using namespace std;
#define PI 3.141592

int shapeside = 3, left =  -1, right= -1; //left to make shape, right to colour them
float x = 0.5, y = 0.5, radius=0.4, i=0; //size of the triangle
GLfloat twicePi = 2.0f * PI;
GLfloat hu[1] = {0}, hi[1] = {0};

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


if(right>=0)
{
x = hu[0];
y = hi[0];
glColor3f(0.3,0,0.5);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x, y); // center of triangle
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
glRasterPos2f(-0.5,-0.9);
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
glutInitWindowSize(500,500);
glutInitWindowPosition(00,00);
glutCreateWindow("Random Triangle");
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
