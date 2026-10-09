#include <stdio.h>
#include <math.h>
#include "integral.h"

/**
 * @file main.c
 * @brief головна програма для тестування методів чисельного інтегрування
 */

/**
 * @brief точка входу в програму.
 * @return код завершення програми (0 при успішному виконанні)
 */
int main()
{
  // оголошення змінних
  double a, b, epsilon;
  int n, method;
  int currentN;

  int steps = 0;
  int found = 0;

  double firstResult, secondResult, delta;

  // фіксовані значення n для порівняльної таблиці
  int tableN[4] = {10, 100, 1000, 10000};

  // введення лівої межі
  printf("enter left boundary a: ");
  if (scanf("%lf", &a) != 1) {
    printf("invalid input.\n");
    return 0;
  }

  // введення правої межі
  printf("enter right boundary b: ");
  if (scanf("%lf", &b) != 1) {
    printf("invalid input.\n");
    return 0;
  }

  // введення початкової кількості розбиттів
  printf("enter starting n (positive even number, maximum 10000000): ");
  if (scanf("%d", &n) != 1 || n <= 0 || n > 10000000 || n % 2 != 0) {
    printf("n must be a positive even number no greater than 10000000.\n");
    return 0;
  }

  // введення точності обчислення
  printf("enter epsilon (from 0.00001 to 0.001): ");
  if (scanf("%lf", &epsilon) != 1 || epsilon < 0.00001 || epsilon > 0.001) {
    printf("epsilon must be from 0.00001 to 0.001.\n");
    return 0;
  }

  // вибір методу
  printf("choose method:\n");
  printf("1 - left rectangles\n");
  printf("2 - right rectangles\n");
  printf("3 - trapezoids\n");
  printf("4 - parabolas (Simpson)\n");

  // перевірка коректності вибору методу
  if (scanf("%d", &method) != 1 || method < 1 || method > 4) {
    printf("invalid method\n");
    return 0;
  }

  // виведення результатів усіма методами для заданого n
  printf("\nresults for entered n = %d\n", n);
  printf("left rectangles:  %.10f\n", leftRectangles(a, b, n));
  printf("right rectangles: %.10f\n", rightRectangles(a, b, n));
  printf("trapezoids:       %.10f\n", trapezoids(a, b, n));
  printf("parabolas:        %.10f\n", parabolas(a, b, n));

  // формування порівняльної таблиці для різних n
  printf("\nresults table\n");
  printf("n\tleft\t\tright\t\ttrapezoids\tparabolas\n");
  for (int i = 0; i < 4; i++) {
    int tableCount = tableN[i];
    printf("%d\t%.8f\t%.8f\t%.8f\t%.8f\n",
         tableCount,
         leftRectangles(a, b, tableCount),
         rightRectangles(a, b, tableCount),
         trapezoids(a, b, tableCount),
         parabolas(a, b, tableCount));
  }

  // виведення даних для побудови графіка обраним методом
  printMethodName(method);
  printf(" (n and integral value):\n");
  for (int i = 1; i <= 10; i++) {
    int graphN = i * 10;
    printf("%d\t%.10f\n", graphN, calculateIntegral(method, a, b, graphN));
  }

  // ітераційний пошук необхідної точності зі збільшенням n на 2
  currentN = n;
  while (currentN <= 10000000) {
    firstResult = calculateIntegral(method, a, b, currentN);
    secondResult = calculateIntegral(method, a, b, currentN + 2);
    delta = fabs(firstResult - secondResult);

    // якщо досягнуто бажану точність, то вихід з циклу
    if (delta <= epsilon) {
      found = 1;
      break;
    }

    currentN += 2;
    steps++;
  }

  // виведення результатів перевірки точності
  printMethodName(method);
  printf(":\n");
  if (found) {
    printf("n = %d, I1 = %.10f, I2 = %.10f\n",
         currentN, firstResult, secondResult);
    printf("delta = %.10f, epsilon = %.10f\n", delta, epsilon);
    printf("increments by 2: %d\n", steps);
  } else {
    printf("required accuracy was not reached.\n");
  }

  return 0;
}