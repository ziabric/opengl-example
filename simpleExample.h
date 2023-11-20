#pragma once

#include <GL/glut.h> // Подключение библиотеки GLUT

// Функция для рисования
void renderFunction() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Установка черного цвета фона
    glClear(GL_COLOR_BUFFER_BIT); // Очистка буфера цвета
    glColor3f(1.0, 0.0, 0.0); // Установка красного цвета для рисования
    glBegin(GL_TRIANGLES); // Начало рисования треугольника
    glVertex2f(-0.5, -0.5); // Координаты первой вершины
    glVertex2f(0.5, -0.5); // Координаты второй вершины
    glVertex2f(0.0, 0.5); // Координаты третьей вершины
    glEnd(); // Конец рисования треугольника
    glFlush(); // Принудительная отправка команд OpenGL на выполнение
}

// Основная функция
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Инициализация GLUT
    glutCreateWindow("OpenGL Example - Triangle"); // Создание окна с заголовком
    glutDisplayFunc(renderFunction); // Регистрация функции рисования
    glutMainLoop(); // Запуск главного цикла GLUT
    return 0;
}