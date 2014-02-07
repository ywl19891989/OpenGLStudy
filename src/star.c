/*
 * star.c
 *
 *  Created on: 2014-1-27
 *      Author: Hali
 */

#include  <windows.h>
#include  <gl/glut.h>
#include  <math.h>

GLfloat spin = 0.0f;
int rotate = -1;
int starAngle = 36;
int rotateAngle = 360/5;
GLfloat starRadian = (starAngle / 360.0f) * M_PI * 2;
GLfloat a = tan(starRadian * 0.5f);

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	{
		glRotatef(spin, 0.0, 0.0, 1.0);
		{
			glColor3f(1, 0, 0);
			glPushMatrix();
			for (int i = 0; i < 5; i++) {
				glRotatef(rotateAngle, 0.0, 0.0, 1.0);
				glBegin(GL_TRIANGLES);
				{
					glVertex2f(-a, 0);
					glVertex2f(a, 0);
					glVertex2f(0, 1);
				}
				glEnd();
			}
			glPopMatrix();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay() {
	spin += 2.0;
	if (spin > 360) {
		spin -= 360;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				rotate = -rotate;
				glutIdleFunc(rotate > 0 ? spinDisplay : NULL );
			}
			break;
		default:
			break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(400, 400);
	glutCreateWindow("double");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}

