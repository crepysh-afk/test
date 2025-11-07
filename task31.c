#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief проверяет введенное занчение
 * @return возвращает значение переменной value
 */
double getValue();

/**
 * @brief проверяет, что шаг положительный
 * @param step значение переменной step
 * @param end значение переменной end
 */
void checkStep(const double step, const double end);

/**
 * @brief рассчитывает значение функции
 * @param x значение переменной x
 * @return возвращает значение y
 */
double getY(const double x);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    system("chcp 1251");
    printf("Введите начальное значение x: ");
    double start = getValue();

    printf("Введите конечное значение x: ");
    double end = getValue();

    printf("Введите шаг delta(x): ");
    double step = getValue();

    checkStep(step, end);

    double x = start;

    while (x <= end)
    {
        printf("x = %.2lf, y = %.4lf\n", x, getY(x));
        x += step;
    }

    return 0;
}

double getValue()
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return value;
}

void checkstep(const double step, const double end)
{
    if (step <= 0)
    {
        printf("Ошибка: шаг должен быть положительным\n");
        abort();
    }
}

double getY(const double x)
{
    return sqrt(1-x)*tan(x);
}
