#include<stdio.h>
#include<string.h>
#include<GL/glut.h>

#include<math.h>
#define PI 3.1415926535897932384626433832795
#define MAX_CLICK 2
#define INFINITE 99999999

int k=0;
int count=0;
int numbPoint=0;
double vertex[2][2];
double m[99];
double c[99];
char buffer[10];
double P0, dy, dx;

void type(char *string, double X, double Y) //to display things on console
{
	char *c;
	glColor3f(0, 0, 0);
	glRasterPos2f(X+1,Y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}

void myName() //to print name and sap ID
{
	type("Harshit Joshi-500068141", 200, -350);
}

void information()
{
	type("Green Color Line for slope between 1 and Infinity", 75,350);
	type("Black Color Line for slope between 0 and 1",75,325);
	type("Blue Color Line for slope between 0 and -1",75,300);
	type("Red Color Line for slope between -1 and -Infinity",75,275);
} 

void initialize(void) //function to initialize 
{ 	
	// making background color white as first
	gluOrtho2D(-375,375,-375,375);
	glClearColor(1,1,1,0); // all the three argument are 1
	glClear(GL_COLOR_BUFFER_BIT);
	myName(); 
	information();
}

// to appoint max and min values 
int max(double a, double b) {
	return a>b?0:1;
}
int min(double a, double b){
	return a<b?0:1;
}

//function to print X and Y co-ordinate 
void printCordinates(double X, double Y) 
{
	gcvt(X,4,buffer); //function to convert float into string 
	char str[20]={"( "};
	strcat(str, buffer); //function to concate string 
	strcat(str, ", ");
	gcvt(Y,5,buffer);
	strcat(str, buffer);
	strcat(str, " )");
	type(str, X, Y); // calling type function to display
}

//function to print slope of line
void printSlope(double M, double X, double Y)
{
	gcvt(M,5,buffer);
	char str[20]={"m = "};
	strcat(str, buffer);
	type(str, X, Y);
}

//function to draw line 
void DrawLine() 
{
	double P[2][2];
	int maxPoint, minPoint;
	for(int i=0;k<numbPoint;k++,i++)
	{
		P[i][0] = vertex[k][0];
		P[i][1] = vertex[k][1];
	}
	
	double m = (P[1][1] - P[0][1])/(P[1][0] - P[0][0]);
	printf("%lf\n", m);
	printSlope(m,(P[1][0]+P[0][0])/2,(P[1][1]+P[0][1])/2);
	
	if(m >= 0 && m <= 1)
	{
		maxPoint = max(P[0][0], P[1][0]);
		minPoint = min(P[0][0], P[1][0]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];	
		P0 = 2*dy-dx;
		for(;P[minPoint][0]<P[maxPoint][0]; P[minPoint][0]+=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0,0,0);
			if(P0 >= 0)
			{
				P[minPoint][1] += 1;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0 += 2*(dy-dx);
			}
			else if (P0<0)
			{
				P[minPoint][1] += 0;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0+=2*dy; 
			}
			glEnd(); 
			glFlush();
		}
	}
	
	if(m >= -1 && m < 0)
	{
		maxPoint = max(P[0][0], P[1][0]);
		minPoint = min(P[0][0], P[1][0]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];	
		P0 = 2*dy-dx;
		for(;P[minPoint][0]<P[maxPoint][0]; P[maxPoint][0]-=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0,0,1);
			if(P0 >= 0)
			{
				P[maxPoint][1]+=1;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0 -= 2*(dy+dx);
			}
			else if (P0<0)
			{
				P[minPoint][1]+=0;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0-=2*dy; 
			}
			glEnd(); 
			glFlush();
		}
	}

	if(m >=1 && m < INFINITE)
	{
		maxPoint = max(P[0][1], P[1][1]);
		minPoint = min(P[0][1], P[1][1]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];	
		P0 = 2*dx-dy;
		for(;P[minPoint][1]<P[maxPoint][1]; P[minPoint][1]+=1)
		{
			glBegin(GL_POINTS);
			glColor3f(0,1,0);
			if(P0 >= 0)
			{
				P[minPoint][0]+=1;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0 += 2*(dx-dy);
			}
			else if (P0<0)
			{
				P[minPoint][0]+=0;
				glVertex2f(P[minPoint][0],P[minPoint][1]);
				P0+=2*dx; 
			}
			glEnd(); 
			glFlush();
		}
	}
	if(m<= -1 && m > -INFINITE)
	{
		maxPoint = max(P[0][1], P[1][1]);
		minPoint = min(P[0][1], P[1][1]);
		dx = P[maxPoint][0]-P[minPoint][0];
		dy = P[maxPoint][1]-P[minPoint][1];	
		P0 = 2*dx-dy;
		for(;P[minPoint][1]<P[maxPoint][1]; P[maxPoint][1]-=1)
		{
			glBegin(GL_POINTS);
			glColor3f(1,0,0);
			if(P0 >= 0)
			{
				P[maxPoint][0]+=1;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0 -= 2*(dx+dy);
			}
			else if (P0<0)
			{
				P[maxPoint][0]+=0;
				glVertex2f(P[maxPoint][0],P[maxPoint][1]);
				P0-=2*dx; 
			}
			glEnd(); 
			glFlush();
		}
	}
	
}
void store(double X, double Y)
{
	vertex[numbPoint][0] = X;
	vertex[numbPoint][1] = Y;
	printf("Co-ordinates are:(%.2lf, %.2lf)\n", vertex[numbPoint][0], vertex[numbPoint][1]);
	++numbPoint;
	printf("Total Number of Points: %d\n",numbPoint);
	printCordinates(X, Y);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd(); 
	glFlush();
}

void mouseClick(int button, int state, int X, int Y)
{	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(count<=MAX_CLICK)
		{
			store((X-375),(375-Y));
			count++;
			if(count == MAX_CLICK){
				DrawLine();
				count=0;
				printf("Total Number of line(s): %d\n",numbPoint/2);
			}
		}
	}
}
static void Key(unsigned char key, int x, int y)
{
    switch (key) {
      	case 27:
			glutDestroyWindow(1);
			break;
	}
}
int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	// giving window size in X- and Y- direction 
	glutInitWindowSize(750, 750); 
	// Giving name to window 
	glutCreateWindow("Exp4- Bresenhams Algorithm"); 
	initialize(); 
	glutKeyboardFunc(Key);
	glutMouseFunc(mouseClick);
	glutMainLoop(); 
} 