#include <stdio.h>

/**
* @brief
* @param t0 - начальная температура тела
* @param t - конечная температура тела
* @param m - масса тела
* @param c - удельная теплоемкость 
* @param q - количество теплоты, затраченное на нагрев тела
* @return Рассчитаное значение
*/

double gettepl(const double t0,const double t,const double m,const double c);

/**
* @brief Точка входа в программу
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/

int main()
{
 system("chcp 1251");
 double t0 = 0;
 double t = 0;
 double m = 0;
 double q = 0;
 const int c = 480;
 printf("Введите начальную температуру тела: ");
 scanf_s("%lf", &t0);
 printf("Введите конечную температуру тела: ");
 scanf_s("%lf", &t);
 printf("Введите массу тела: ");
 scanf_s("%lf", &m);
 printf("Количество теплоты, израсходованное на нагрев: %.2f Дж\n", gettepl(t0, t, m, c));

 return 0;

}
double gettepl(const double t0,const double t,const double m,const double c)
{
 return c * m * (t - t0);
}
