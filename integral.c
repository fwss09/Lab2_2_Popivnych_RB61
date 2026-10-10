#include <stdio.h>
#include "integral.h"

// підінтегральна функція f(x) = x^2 + 2x
double function(double x)
{
    return x * x + 2 * x;
}

// метод лівих прямокутників
double leftRectangles(double a, double b, int n)
{
    double h = (b - a) / n; // крок розбиття
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += function(a + i * h); // значення функції в лівому кінці i-го відрізка
    }

    return sum * h;
}

// метод правих прямокутників
double rightRectangles(double a, double b, int n)
{
    double h = (b - a) / n; // крок розбиття
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += function(a + i * h); // значення функції в правому кінці i-го відрізка
    }

    return sum * h;
}

// метод трапецій
double trapezoids(double a, double b, int n)
{
    double h = (b - a) / n;                        // крок розбиття
    double sum = (function(a) + function(b)) / 2;  // половини крайніх значень

    for (int i = 1; i < n; i++) {
        sum += function(a + i * h); // внутрішні вузли додаються з повним коефіцієнтом
    }

    return sum * h;
}

// метод парабол (правило Сімпсона)
double parabolas(double a, double b, int n)
{
    double h = (b - a) / n;                    // крок розбиття
    double sum = function(a) + function(b);    // крайні значення з коефіцієнтом 1

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * function(a + i * h); // парний вузол - коефіцієнт 2
        } else {
            sum += 4 * function(a + i * h); // непарний вузол - коефіцієнт 4
        }
    }

    return sum * h / 3; // ділимо на 3 згідно з формулою Сімпсона
}

// вибір методу числового інтегрування та обчислення інтеграла
double calculateIntegral(int method, double a, double b, int n)
{
    if (method == 1) {
        return leftRectangles(a, b, n);  // метод 1 - ліві прямокутники
    }
    if (method == 2) {
        return rightRectangles(a, b, n); // метод 2 - праві прямокутники
    }
    if (method == 3) {
        return trapezoids(a, b, n);      // метод 3 - трапеції
    }
    return parabolas(a, b, n);           // метод 4 - параболи (Сімпсон)
}

// виведення назви обраного методу інтегрування
void printMethodName(int method)
{
    if (method == 1) {
        printf("Left rectangles");
    } else if (method == 2) {
        printf("Right rectangles");
    } else if (method == 3) {
        printf("Trapezoids");
    } else {
        printf("Parabolas (Simpson)");
    }
}