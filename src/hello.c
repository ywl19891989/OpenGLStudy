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
	glClear(GL_COLOR_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glColor3f(1.0f, 1.0f, 1.0f);						// Move Left 1.5 Units And Into The Screen 6.0
	glBegin(GL_POLYGON);						// Drawing Using Triangles
	{
		glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(-1.0f, -1.0f, 0.0f);				// Bottom Left
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Right
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Right
	}
	glEnd();											// Finished Drawing The Triangle
	glFlush();
}

void reshape(int width, int height) {
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	glOrtho(-2, 2, -2, 2, -2, 10);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Hello!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
