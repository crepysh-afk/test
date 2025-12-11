#include<stdlib.h>
#include<stdio.h>

/* @brief считывает целое значение с клавиатуры с проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/* @brief проверяет можно ли расположить дома на участке с определенным размером
* @param a длина участка
* @param b ширина участка 
* @param p длина 1-го дома
* @param q ширина 1-го дома
* @param r длина 2-го дома
* @param s ширина 2-го дома
*/
void can_place(const int a,const int b,const int p,const int q,const int r,const int s);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main()
{
	system("chcp 1251");
	printf("Введите размер участка (a,b):");
	int a = getValue();
	int b = getValue();
	printf("Введите размер первого дома (p,q):");
	int p = getValue();
	int q = getValue();
	printf("Введите размер второго дома (r,s):");
	int r = getValue();
	int s = getValue();

	can_place(a, b, p, q, r, s);

	return 0;
}
int getValue()
{
	int value = 0;
	if (!scanf_s("%d",&value))
	{
		printf("Error");
		exit(1);
	}
	return value;
}

void can_place(const int a,const int b,const int p,const int q,const int r,const int s) 
{
	if (
		((p + r) <= a && q <= b && s <= b) ||
		((p + s) <= a && q <= b && r <= b) ||
		((q + r) <= a && p <= b && s <= b) ||
		((q + s) <= a && p <= b && r <= b) ||
		((q + s) <= b && p <= a && r <= a) ||
		((q + r) <= b && p <= a && s <= a) ||
		((p + s) <= b && q <= a && r <= a) ||
		((p + r) <= b && q <= a && s <= a)
		)
	{
		printf("Дома можно разместить на участке");
	}
	else
	{
		printf("Дома нельзя разместить на участке");
	}
}
