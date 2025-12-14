#include <stdio.h>
#include <math.h>

/**
* @brief 
* @param Vb - значение скорости лодки в стоячей воде
* @param Vr - скорость течения реки
* @param t - время движения
* @return Рассчитаное значение
*/

double defA(const double Vb, const double Vr, const double t);

/**
* @brief Точка входа в программу 
* @return Возваращет 0, если программа была выполнена корректно, иначе 1
*/

int main(void) {
    double Vb; 
    double Vr; 
    double t;   

    printf("Введите скорость лодки в стоячей воде (км/ч): ");
    scanf_s("%lf", &Vb);

    printf("Введите скорость течения реки (км/ч): ");
    scanf_s("%lf", &Vr);

    printf("Введите время движения (часы): ");
    scanf_s("%lf", &t);
    
    printf("Путь, пройденный лодкой по течению: %.2f км\n", defA(Vb, Vr, t));

    return 0;
}

double defA(const double Vb, const double Vr, const double t)
{
    return (Vb + Vr) * t;
}
