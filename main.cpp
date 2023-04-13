#include <GL/glut.h>
#include <cmath>

GLfloat angle = 0.0;
GLfloat moonAngle = 0.0;
GLfloat earthAngle = 0.0;

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);
  glRotatef(angle, 0.0, 1.0, 0.0);
  glColor3f(1.0, 1.0, 0.0); // Soarele este galben
  glutWireSphere(1.0, 20, 20);

  glPushMatrix();
  glRotatef(moonAngle, 0.0, 1.0, 0.0);
  glRotatef(angle, 0.0, 1.0, 0.0);
  glRotatef(earthAngle, 0.0, 1.0, 0.0);
  glTranslatef(2.0, 0.0, 0.0);
  glColor3f(0.0, 0.5, 1.0); // Pamantul este albastru
  glutWireSphere(0.3, 20, 20);

  glPushMatrix();
  glRotatef(moonAngle, 0.0, 1.0, 0.0);
  glTranslatef(0.5, 0.0, 0.0);
  glColor3f(0.7, 0.7, 0.7); // Luna este gri
  glutWireSphere(0.1, 20, 20);
  glPopMatrix();

  glPopMatrix();

  glutSwapBuffers();
}

void idle() {
  angle += 0.001;
  moonAngle += 0.01;
  glutPostRedisplay();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Sistem Planetar");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
  return 0;
}
