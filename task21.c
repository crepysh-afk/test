#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Вычисляет количество отрицательных чисел и абсолютную величину суммы
 * @param a Первое число
 * @param b Второе число
 * @param c Третье число
 * @param k Указатель на переменную для записи количества отрицательных чисел
 * @return Абсолютное значение суммы a, b, c
 */
double analyze_numbers(double a, double b, double c, int* k) 
{
	*k = 0;
	if (a < 0) (*k)++;
	if (b < 0) (*k)++;
	if (c < 0) (*k)++;

	double sum = a + b + c;
	return abs(sum);
}


/**
* @brief Точка входа в программу
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/


int main()
{
	system("chcp 1251");
	double a;
	double b;
	double c;
	double abs_sum = 0;
	int k = 0;

	printf("Введите переменную а: ");
	scanf_s("%lf", &a);

	printf("Введите переменную b: ");
	scanf_s("%lf", &b);

	printf("Введите переменную c: ");
	scanf_s("%lf", &c);

	abs_sum = analyze_numbers(a, b, c, &k);
	
	printf("Количество отрицательных чисел: %d\n ", k);
	printf("Абсолютное значение суммы чисел: %.2f\n ", abs_sum);

	return 0;
}

