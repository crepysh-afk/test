#include<stdio.h>
#include<math.h>

/**
* @brief Рассчитывает значение функции А
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Рассчитанное значение
*/
double defA(const double X, const double Y, const double Z);

/**
* @brief Рассчитывает значение функции B
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Рассчитанное значение
*/
double defB(const double X, const double Y, const double Z);

/**
* @brief Точка входа в программу
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	const double X = 0.3;
	const double Y = 2.9;
	const double Z = 0.5;

	printf("A = %.6f\nB = %.6f", defA(X, Y, Z), defB(X, Y, Z));

	return 0;
}

double defA(const double X, const double Y, const double Z)
{
	return (pow(Z, 2) * X + exp(-X) * cos(Y * X)) / (Y * X - exp(-X) * sin(Y * X) + 1);
}

double defB(const double X, const double Y, const double Z)
{
	return exp(2 * X) * log(Z + X) - pow(Y, 3 * X) * log(Y - X);
}
