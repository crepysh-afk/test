#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/** 
* @brief Вычисляет количество отрицательных чисел
* @param a Первое число
 * @param b Второе число
 * @param c Третье число
*/
int countNegative(double a, double b, double c);

/**
* @brief Вычисляет абсолютную сумму 
* @param a Первое число
 * @param b Второе число
 * @param c Третье число
 * @return Абсолютное значение суммы a, b, c
*/
double absSum(double a, double b, double c);

/**
 * @brief проверяет введенное занчение
 * @return возвращает значение переменной value
 */
double getValue();

/**
* @brief Точка входа в программу
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/
int main()
{
	system("chcp 1251");

	printf("Введите переменную а: ");
	double a = getValue();

	printf("Введите переменную b: ");
	double b = getValue();

	printf("Введите переменную c: ");
	double c = getValue();

	int k = countNegative(a,b,c);
	double abs_sum = absSum(a,b,c);


	printf("Количество отрицательных чисел: %d\n ", k);
	printf("Абсолютное значение суммы чисел: %.2f\n ", abs_sum);

	return 0;
}
double absSum(double a, double b, double c)
{
	return fabs(a + b + c);
}

int countNegative(double a, double b, double c)
{
	int k = 0;
	if (a < 0)
	{
		k++;
	}
	if (b < 0)
	{
		k++;
	}
	if (c < 0)
	{
		k++;
	}
	return k;
}
double getValue()
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Неверный ввод!");
		abort();
	}
	return value;
}
