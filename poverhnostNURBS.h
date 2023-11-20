#pragma once

#include <GL/glut.h>
#include <GL/glu.h>

GLUnurbsObj *nurbsObject;

void init() {
    nurbsObject = gluNewNurbsRenderer();

    gluNurbsProperty(nurbsObject, GLU_SAMPLING_TOLERANCE, 25.0);
    gluNurbsProperty(nurbsObject, GLU_DISPLAY_MODE, GLU_FILL);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat controlPoints[4][4][3] = {
            {{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0}, {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}},
            {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 3.0}, {0.5, -0.5, 0.0}, {1.5, -0.5, -1.0}},
            {{-1.5,  0.5, 4.0}, {-0.5,  0.5, 0.0}, {0.5,  0.5, 3.0}, {1.5,  0.5, 4.0}},
            {{-1.5,  1.5, -2.0}, {-0.5,  1.5, -2.0}, {0.5,  1.5, 0.0}, {1.5,  1.5, -1.0}}
    };

    int uKnotCount = 8;
    int vKnotCount = 8;
    GLfloat uKnots[] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
    GLfloat vKnots[] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};

    gluBeginSurface(nurbsObject);
    gluNurbsSurface(nurbsObject, uKnotCount, uKnots, vKnotCount, vKnots,
                    4 * 3, 3, &controlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurbsObject);

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("NURBS Surface Example");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}