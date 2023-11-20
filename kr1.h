#include<GL/glut.h>
#include<GL/glu.h>

GLUnurbsObj* theNurb;
// массив точек определяющего многоугольника
GLfloat ctlarray[][4] = {
        {-1.0, 0.2, 0.0, 1.0},
        {-0.8, 0.8, 0.0, 1.0},
        {-0.6, 0.2, 0.0, 1.0},
        {-0.4, 0.8, 0.0, 1.0},
        {-0.2, 0.2, 0.0, 1.0},
        {-0.0, 0.8, 0.0, 1.0},
        {0.2, 0.2, 0.0, 1.0},
        {0.4, 0.8, 0.0, 1.0},
};
GLfloat knot[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
int k = 3;
int points = 8;

GLfloat colors[][3] = {
        {1,0,0},
        {0.6, 0.0, 0.4},
        {0.3, 0.2, 0.7},
        {0, 1, 0},
        {0.3, 1, 0.5},
        {0.5, 0.5, 0.5},
        {0, 0, 1},
        {1, 0, 1},
        {0.3, 0.1, 0.1},
        {0, 1, 1}
};

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1);
}

// Расчет базисной функции B-сплайна с использованием формулы Кокса-де Бура
float calculateBasis(int i, int k, float t) {
    if (k == 1)
        return (knot[i] <= t && knot[i + 1] >= t) ? GLfloat(1) : GLfloat(0);
    else {
        float basis1 = 0.0f;
        float basis2 = 0.0f;

        if (knot[i + k - 1] - knot[i] != 0)
            basis1 = (t - knot[i]) / (knot[i + k - 1] - knot[i]) * calculateBasis(i, k - 1, t);
        if (knot[i + k] - knot[i + 1] != 0)
            basis2 = (knot[i + k] - t) / (knot[i + k] - knot[i + 1]) * calculateBasis(i + 1, k - 1, t);

        return basis1 + basis2;
    }
}

void Display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);
    glColor3f(0.8, 0.2, 0.2);

    glBegin(GL_POINTS);
    for (int i = 0; i < 9; i++) {
        glVertex3f(ctlarray[i][0], ctlarray[i][1], ctlarray[i][2]);
    }
    glEnd();

    glColor3f(0.1, 0.1, 0.8);
    glPointSize(2);
    glBegin(GL_POINTS);

    for (float t = k - 1; t <= points; t += 0.01f)
    {
        float x = 0.0f;
        float y = 0.0f;
        for (int i = 0; i < points; i++) {
            float basis = calculateBasis(i, k, t);
            x += ctlarray[i][0] * basis;
            y += ctlarray[i][1] * basis;
        }
        glVertex3f(x, y, 1);
    }
    glEnd();

    glFlush();

    glPointSize(1.5);
    glBegin(GL_POINTS);
    for (int i = -1; i < 14; i++)
    {

        glColor3f(colors[i][0], colors[i][1], colors[i][2]);

        for (GLfloat t = 0; t <= 5; t += 0.001)
        {
            glVertex3f(1.2 * (t / 3) - 1.4, 2 * (calculateBasis(i, k, t) / 3) - 0.4, 0.0);
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(1000, 500);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
}