//============================================================================
// Name        : App.cpp
// Author      : wenlong
// Version     :
// Copyright   : All copyrights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include  <windows.h>
#include  <gl/glut.h>
#include  <math.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, 0.0f);						// Move Left 1.5 Units And Into The Screen 6.0
	glBegin(GL_TRIANGLES);						// Drawing Using Triangles
	{
		glColor3f(1, 0, 0);
		glVertex3f(0.0f, 1.0f, 0.0f);					// Top
		glVertex3f(-1.0f, -1.0f, 0.0f);				// Bottom Left
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
	}
	glEnd();											// Finished Drawing The Triangle
	glTranslatef(3.0f, 0.0f, 0.0f);					// Move Right 3 Units
	glBegin(GL_QUADS);									// Draw A Quad
	{
		glColor3f(1, 1, 0);
		glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
		glVertex3f(-1.0f, -1.0f, 0.0f);				// Bottom Left
	}
	glEnd();											// Done Drawing The Quad
	glPopMatrix();
	glFlush();
}

void idle() {
	glutPostRedisplay();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	glOrtho(-5, 5, -5, 5, -5, 10);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello,world!");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
