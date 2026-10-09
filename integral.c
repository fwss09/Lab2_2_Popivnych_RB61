#include <stdio.h>
#include "integral.h"

double function(double x)
{
    return x * x + 2 * x;
}

double leftRectangles(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum += function(a + i * h);
    }

    return sum * h;
}

double rightRectangles(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += function(a + i * h);
    }

    return sum * h;
}

double trapezoids(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = (function(a) + function(b)) / 2;

    for (int i = 1; i < n; i++) {
        sum += function(a + i * h);
    }

    return sum * h;
}

double parabolas(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * function(a + i * h);
        } else {
            sum += 4 * function(a + i * h);
        }
    }

    return sum * h / 3;
}

double calculateIntegral(int method, double a, double b, int n)
{
    if (method == 1) {
        return leftRectangles(a, b, n);
    }
    if (method == 2) {
        return rightRectangles(a, b, n);
    }
    if (method == 3) {
        return trapezoids(a, b, n);
    }
    return parabolas(a, b, n);
}

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