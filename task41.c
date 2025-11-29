#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief Получение корректного размера массива от пользователя
 * @param message Указатель на строку с приглашением для ввода
 * @return Возвращает размер массива типа size_t
 */
size_t getSize(char* message);
/**
 * @brief Ручное заполнение массива пользователем
 * @param arr Указатель на массив для заполнения
 * @param size Размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Вывод элементов массива в консоль
 * @param arr Указатель на массив для вывода
 * @param size Размер массива
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Заполнение массива случайными числами
 * @param arr Указатель на массив для заполнения
 * @param size Размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Вычисление суммы однозначных чисел в массиве
 * @param arr Указатель на массив для анализа
 * @param size Размер массива
 * @return Сумма однозначных чисел
 */
int sumSingleDigitNumbers(int* arr, const size_t size);

/**
 * @brief Разворот элементов между минимальным и максимальным элементами
 * @param arr Указатель на массив для модификации
 * @param size Размер массива
 */
void reverseBetweenMinMax(int* arr, const size_t size);

/**
 * @brief Поиск последней пары соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив для анализа
 * @param size Размер массива
 * @param targetProduct Целевое значение для сравнения произведения
 * @return Индекс первого элемента пары или -1 если не найдено
 */
int findLastPairWithSameSign(int* arr, const size_t size, int targetProduct);

/**
*@brief Перечисление определяет два возможных режима работы для генератора данных
*/
enum { RANDOM = 1, MANUAL };

int main()
{
    system("chcp 1251");
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    printf("Выберите способ заполнения массива:\n" "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("Неверный выбор!\n");
        free(arr);
        exit(1);
    }

    printf("\nИсходный массив: ");
    printArray(arr, size);

    int sumSingle = sumSingleDigitNumbers(arr, size);
    printf("\n1. Сумма однозначных чисел: %d\n", sumSingle);

    int* copyArr = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        copyArr[i] = arr[i];
    }
    reverseBetweenMinMax(copyArr, size);
    printf("2. Массив после разворота между min и max: ");
    printArray(copyArr, size);

    printf("\nВведите число для сравнения произведения: ");
    int target = Value();
    int lastPairIndex = findLastPairWithSameSign(arr, size, target);
    if (lastPairIndex != -1) 
    {
        printf("3. Последняя пара с одинаковыми знаками (индекс %d): [%d, %d]\n",lastPairIndex, arr[lastPairIndex], arr[lastPairIndex + 1]);
    }
    else 
    {
        printf("3. Пара с одинаковыми знаками не найдена\n");
    }

    free(copyArr);
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        printf("ERROR: Неверный ввод!\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR: Размер должен быть положительным!\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент [%zu]: ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    printf("Начало диапазона: ");
    int start = Value();
    printf("Конец диапазона: ");
    int end = Value();

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int sumSingleDigitNumbers(int* arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] >= -9 && arr[i] <= 9 && arr[i] != 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

void reverseBetweenMinMax(int* arr, const size_t size)
{
    if (size < 3) {
        printf("  (Нечего разворачивать - массив слишком мал)\n");
        return;
    }

    size_t minIndex = 0, maxIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    printf("  Min: arr[%zu] = %d, Max: arr[%zu] = %d\n",
        minIndex, arr[minIndex], maxIndex, arr[maxIndex]);

    size_t start, end;
    if (minIndex < maxIndex) {
        start = minIndex + 1;
        end = maxIndex - 1;
    }
    else {
        start = maxIndex + 1;
        end = minIndex - 1;
    }

    printf("  Разворот элементов с индекса %zu по %zu\n", start, end);

    if (start >= end) {
        printf("  (Нечего разворачивать - min и max соседние или рядом)\n");
        return;
    }

    size_t left = start;
    size_t right = end;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int findLastPairWithSameSign(int* arr, const size_t size, int targetProduct)
{
    int lastFoundIndex = -1;

    for (size_t i = 0; i < size - 1; i++)
    {
        if ((arr[i] > 0 && arr[i + 1] > 0) || (arr[i] < 0 && arr[i + 1] < 0))
        {
            if (arr[i] * arr[i + 1] < targetProduct)
            {
                lastFoundIndex = i;
            }
        }
    }

    return lastFoundIndex;
}
