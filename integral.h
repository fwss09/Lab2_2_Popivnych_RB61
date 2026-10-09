#ifndef INTEGRAL_H
#define INTEGRAL_H

/**
 * @file integral.h
 * @brief оголошення функцій для чисельного інтегрування та допоміжних методів.
 */

/**
 * @brief обчислює значення підінтегральної функції f(x) = x^2 + 2x.
 * @param x точка, в якій обчислюється значення функції.
 * @return значення функції в точці x.
 */
double function(double x);

/**
 * @brief обчислює визначений інтеграл методом лівих прямокутників.
 * @param a нижня межа інтегрування.
 * @param b верхня межа інтегрування.
 * @param n кількість розбиттів відрізка.
 * @return наближене значення інтеграла.
 */
double leftRectangles(double a, double b, int n);

/**
 * @brief обчислює визначений інтеграл методом правих прямокутників.
 * @param a нижня межа інтегрування.
 * @param b верхня межа інтегрування.
 * @param n кількість розбиттів відрізка.
 * @return наближене значення інтеграла.
 */
double rightRectangles(double a, double b, int n);

/**
 * @brief обчислює визначений інтеграл методом трапецій.
 * @param a нижня межа інтегрування.
 * @param b верхня межа інтегрування.
 * @param n кількість розбиттів відрізка.
 * @return наближене значення інтеграла.
 */
double trapezoids(double a, double b, int n);

/**
 * @brief обчислює визначений інтеграл методом парабол (Сімпсона).
 * @param a нижня межа інтегрування.
 * @param b верхня межа інтегрування.
 * @param n кількість розбиттів відрізка (парне число кроків).
 * @return наближене значення інтеграла.
 */
double parabolas(double a, double b, int n);

/**
 * @brief обчислює визначений інтеграл обраним методом за його номером.
 * @param method номер методу (1: ліві прямокутники, 2: праві прямокутники, 3: трапеції, інше: параболи).
 * @param a нижня межа інтегрування.
 * @param b верхня межа інтегрування.
 * @param n кількість розбиттів відрізка.
 * @return наближене значення інтеграла.
 */
double calculateIntegral(int method, double a, double b, int n);

/**
 * @brief виводить назву обраного методу чисельного інтегрування в консоль.
 * @param method номер методу (1: Left rectangles, 2: Right rectangles, 3: Trapezoids, інше: Parabolas).
 */
void printMethodName(int method);

#endif