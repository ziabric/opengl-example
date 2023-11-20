#define GLEW_STATIC
#define FREEGLUT_STATIC

#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

using namespace std;

GLfloat roate = 0.0;// установить роти roate ying ying ying ying ying ying ying ying yu hao build le
GLfloat rote = 0.0;// угол поворота Shezhi
GLfloat anglex = 0.0;// x -оси вращение
GLfloat angley = 0.0;// y -оси вращение
GLfloat anglez = 0.0;// z wurtation оси
GLint WinW = 400;
GLint WinH = 400;
GLfloat oldx;// Записывают координаты мыши при нажатии левой кнопки
GLfloat oldy;

void init() {
    // все 1 без белого, все 0 черные
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display() {
    // в настоящее время написанный цветовой буфер
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // Включение и привязка текстуры
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, GL_TEXTURE30);

    // Рисование чайника
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(rote, 0.0f, 1.0f, 0.0f);
    glRotatef(anglex, 1.0, 0.0, 0.0);
    glRotatef(angley, 0.0, 1.0, 0.0);
    glRotatef(anglez, 0.0, 0.0, 1.0);
    rote += roate;

    glColor3f(0.0, 1.0, 1.0); // Белый цвет (будет смешиваться с текстурой)
    glutSolidTeapot(1.0);

    //glRotatef(angle, 0.0, 1.0, 0.0);
    //angle += 1.0f;

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            roate = 0;
            rote = 0;
            oldx = x;// Записывают координаты мыши при нажатии левой кнопки
            oldy = y;
            cout << "left" << endl;
        }
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            roate += 1.0f;
            cout << "right" << endl;
        }
    }
}

void motion(int x, int y)
{
    GLint deltax = oldx - x;
    GLint deltay = oldy - y;
    anglex += 360 * (GLfloat)deltax / (GLfloat)WinW;// Установите угол вращения в соответствии с расстоянием мыши, скользящей на экране
    angley += 360 * (GLfloat)deltay / (GLfloat)WinH;
    anglez += 360 * (GLfloat)deltay / (GLfloat)WinH;
    oldx = x;// Записать координаты мыши в это время, обновите координаты мыши
    oldy = y;// Если нет этих двух предложений, скольжение - это вращение, чтобы стать неконтролируемым
    glutPostRedisplay();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HellGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
