#include<GL/glut.h>
void init()
{
    glClearColor(0.8, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void home()
{
    //Terrace
    glClear(GL_COLOR_BUFFER_BIT);     
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(370, 400);
    glVertex2i(650, 400);
    glVertex2i(720, 300);
    glVertex2i(440, 300);
    glEnd();

    // Front Wall Top
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 400);
    glVertex2i(440, 300);
    glVertex2i(300, 300);
    glEnd();

    // Front Wall
    glColor3f(0.0, 0.0, 0.8);
    glBegin(GL_POLYGON);
    glVertex2i(300, 300);
    glVertex2i(440, 300);
    glVertex2i(440, 100);
    glVertex2i(300, 100);
    glEnd();

    // Front Gate
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(345, 180);
    glVertex2i(395, 180);
    glVertex2i(395, 100);
    glVertex2i(345, 100);
    glEnd();

    // Wall
    glColor3f(1.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 300);
    glVertex2i(720, 300);
    glVertex2i(720, 100);
    glVertex2i(440, 100);
    glEnd();

    // Window
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(530, 240);
    glVertex2i(630, 240);
    glVertex2i(630, 170);
    glVertex2i(530, 170);
    glEnd();

    // Window's Border
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(580, 239);
    glVertex2i(580, 170);
    glVertex2i(530, 205);
    glVertex2i(630, 205);
    glEnd();
    
    // Land
    glColor3f(0.7, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 100);
    glVertex2i(800, 100);
    glVertex2i(800, 0);
    glVertex2i(0, 0);
    glEnd();
    
    // Trunk
    glColor3f(0.3,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 155);
    glVertex2i(155, 155);
    glVertex2i(155, 100);
    glVertex2i(120, 100);
    glEnd();
 
    // Tree
    glColor3f(0.0, 0.4 , 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(138, 525);
    glVertex2i(215, 155);
    glVertex2i(60, 155);
    glEnd();
    
    // Name
    glColor3f (1.0, 1.0, 1.0);
    glRasterPos2f(550, 20);
    char *string = "Harshit Joshi 500068141";
    while(*string)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
    }

    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exp 1 - Scenery with Hut");
    init();
    glutDisplayFunc(home);
    glutMainLoop();
}