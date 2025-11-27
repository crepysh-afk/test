#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

/**
* @brief вычисляет значение y1
* @param a - константа а
* @param x - переменная х
* @return - возвращает значение функции
*/

double gety1(const double x, const double a);

/**
* @brief вычисляет значение y2
* @param a - константа а
* @param x - переменная х
* @return - возвращает значение функции
*/
double gety2(const double x, const double a);

/**
* @brief Точка входа в программу
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/

int main(void)
{
	system("chcp 1251");
	const double a = 1.36;
	double x = 0;
	printf("Введите значение переменной x: ");
	scanf_s("%lf", &x);
	if (x < 0.5)
	{
		printf("Значение функции при x<0.5: %.2f",gety1(x, a));
	}
	if (x >= 0.5)
	{
		printf("Значение функции при x>=0.5: %.2f", gety2(x, a));
	}
	return 0;
}
double gety1(const double x,const double a)
{
	return M_PI / 2 + x * a - exp(a * x);
}
double gety2(const double x, const double a)
{
	return pow(x, 3) * a + 28;
}
