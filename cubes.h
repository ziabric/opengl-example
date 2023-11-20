#pragma once
#include <GL/glut.h>
#include <GL/glu.h>


void initOpenGL() {
    glEnable(GL_DEPTH_TEST); // Включить тест глубины
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Черный фон
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистить экран и буфер глубины
    glLoadIdentity(); // Сбросить просмотр

    // Рисование первого куба
    glPushMatrix(); // Сохранить текущее состояние матрицы
    glTranslatef(-1.5f, 0.0f, -7.0f); // Переместить влево и вглубь экрана
    glColor3f(1.0f, 0.0f, 0.0f); // Красный цвет
    glutSolidCube(1.0); // Рисование куба
    glPopMatrix(); // Восстановить состояние матрицы

    // Рисование второго куба
    glPushMatrix(); // Сохранить текущее состояние матрицы
    glTranslatef(1.5f, 0.0f, -7.0f); // Переместить вправо и вглубь экрана
    glColor3f(0.0f, 1.0f, 0.0f); // Зеленый цвет
    glutSolidCube(1.0); // Рисование куба
    glPopMatrix(); // Восстановить состояние матрицы

    glutSwapBuffers(); // Поменять буферы местами
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1; // Предотвращение деления на ноль
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height); // Установить область просмотра

    glMatrixMode(GL_PROJECTION); // Режим матрицы проекции
    glLoadIdentity(); // Сбросить матрицу проекции
    gluPerspective(45.0f, aspect, 0.1f, 100.0f); // Установить перспективу
    glMatrixMode(GL_MODELVIEW); // Режим матрицы просмотра модели
    glLoadIdentity(); // Сбросить матрицу просмотра модели
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Установить режим дисплея
    glutInitWindowSize(640, 480); // Установить размеры окна
    glutInitWindowPosition(50, 50); // Позиция окна на экране
    glutCreateWindow("Два куба в OpenGL"); // Создать окно с заголовком
    glutDisplayFunc(display); // Функция отображения
    glutReshapeFunc(reshape); // Функция изменения размера окна
    initOpenGL(); // Инициализация OpenGL
    glutMainLoop(); // Войти в основной цикл GLUT
    return 0;
}
