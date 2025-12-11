#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
*@brief считывает натуральное значение с клавиатуры с проверкой ввода
*@return возвращает считанное значение
*/
int Value();

/**
 * @brief Получение корректного размера массива от пользователя
 * @param message Указатель на строку с приглашением для ввода
 * @return Возвращает размер массива типа size_t
 */
size_t getSize(const char* message);

/**
 * @brief Ручное заполнение массива пользователем
 * @param arr Указатель на массив для заполнения
 *@param rows количество строк массива
 *@param columns количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
* @brief Вывод элементов массива в консоль
* @param arr Указатель на массив для заполнения
*@param rows количество строк массива
*@param columns количество столбцов массива
*/
void printArray(int** arr, const size_t rows, const size_t columns);

/**
*@brief Заполнение массива случайными числами
*@param arr Указатель на массив для заполнения
*@param rows количество строк массива
*@param columns количество столбцов массива
*/
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
* @brief Проверяет корректность диапазона
* @param start Начальное значение диапазона
* @param end Конечное значение диапазона
*/
void checkRange(const int start, const int end);

/**
 * @brief Создает новый массив с копией первого столбца после каждого столбца с нулями
 * @param arr Указатель на исходный двумерный массив
 * @param columns Количество столбцов в массиве
 * @param rows Количество строк в массиве
 * @return Указатель на новый массив или NULL если нет изменений
 */
int** Fillarr(int** arr, const size_t columns, const size_t rows, size_t* new_columns);

/**
 * @brief Подсчитывает количество столбцов, содержащих нулевые элементы
 * @param arr Указатель на двумерный массив
 * @param columns Количество столбцов в массиве
 * @param rows Количество строк в массиве
 * @return Количество столбцов с нулевыми элементами
 */
int countZeroel(int** arr, const size_t columns, const size_t rows);

/**
 * @brief Выделяет память под двумерный динамический массив
 * @param rows Количество строк в массиве
 * @param columns Количество столбцов в массиве
 * @return Указатель на созданный массив или NULL при ошибке
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Создает копию двумерного массива
 * @param arr Указатель на исходный массив
 * @param rows Количество строк в массиве
 * @param columns Количество столбцов в массиве
 * @return Указатель на копию массива или NULL при ошибке
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
* @brief Освобождает память массива
* @param arr Указатель на массив для освобождения
* @param rows количество строк массива
*/
void freeArray(int** arr, const size_t rows);

/**
* @brief Проверяет валидность указателя на выделенную память
* @param arr Указатель на массив целых чисел
*/
void check_memory(int** arr);

/**
 * @brief Заменяет все нечетные элементы массива на ноль
 * @param arr Указатель на двумерный массив
 * @param columns Количество столбцов в массиве
 * @param rows Количество строк в массиве
 */
void changeNechet(int** arr, const size_t columns, const size_t rows);

/**
* @brief Перечисление для выбора режимов работы программы
* @brief RANDOM Режим заполнения массива случайными числами
* @brief MANUAL Режим ручного ввода элементов массива
* @brief task1 Выбор задания 1: замена нечетных элементов на 0
* @brief task2 Выбор задания 2: вставка копии первого столбца после столбцов с нулями
*/
enum { RANDOM = 1, MANUAL, task1 = 1, task2 };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    system("chcp 1251");
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    int** arr = getArray(rows, columns);

    printf("Выберите способ заполнения массива:\n%d случайными числами %d вручную\n", RANDOM, MANUAL);
    int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, rows, columns);
        break;
    case MANUAL:
        fillArray(arr, rows, columns);
        break;
    default:
        printf("Error: некорректный выбор\n");
        freeArray(arr, rows);
        return 1;
    }

    printf("\nИсходный массив:\n");
    printArray(arr, rows, columns);

    printf("Выберите задание для выполнения:\n%d task1 %d task2:\n", task1, task2);
    int secondchoice = Value();

    int** result_array = NULL;
    size_t result_rows = rows;
    size_t result_columns = columns;

    switch (secondchoice)
    {
    case task1:
    {
        int** arr_copy = copyArray(arr, rows, columns);
        changeNechet(arr_copy, columns, rows);
        result_array = arr_copy;
        printf("\nМассив после преобразования (task1):\n");
        printArray(result_array, result_rows, result_columns);
        freeArray(arr, rows);
        arr = result_array;
    }
    break;
    case task2:
    {
        size_t new_columns = 0;
        result_array = Fillarr(arr, columns, rows, &new_columns);
        if (result_array != NULL)
        {
            result_columns = new_columns;
            printf("\nМассив после преобразования (task2):\n");
            printArray(result_array, result_rows, result_columns);
            freeArray(arr, rows);
            arr = result_array;
        }
        else
        {
            int** arr_copy = copyArray(arr, rows, columns);
            freeArray(arr, rows);
            arr = arr_copy;
            result_array = arr;
            printf("\nМассив без изменений (нет столбцов с нулями):\n");
            printArray(result_array, result_rows, result_columns);
        }
    }
    break;
    default:
        printf("Error: некорректный выбор задания\n");
        freeArray(arr, rows);
        return 1;
    }

    if (arr != NULL)
    {
        freeArray(arr, result_rows);
    }

    return 0;
}

int Value()
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        printf("Error: некорректный ввод\n");
        exit(1);
    }
    return value;
}

size_t getSize(const char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Error: размер должен быть положительным\n");
        exit(1);
    }
    return (size_t)value;
}

void check_memory(int** arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error: ошибка выделения памяти\n");
        exit(1);
    }
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    check_memory(arr);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    check_memory(arr);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    check_memory(arr);
    srand((unsigned int)time(NULL));
    printf("Введите начало диапазона: ");
    int start = Value();
    printf("Введите конец диапазона: ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        fprintf(stderr, "Error: не удалось выделить память для строк\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = (int*)malloc(columns * sizeof(int));
        if (arr[i] == NULL) {
            fprintf(stderr, "Error: не удалось выделить память для строки %zu\n", i);
            for (size_t j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }

    return arr;
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    if (arr == NULL) {
        return NULL;
    }
    
    int** copy = getArray(rows, columns);
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copy[i][j] = arr[i][j];
        }
    }
    
    return copy;
}

void freeArray(int** arr, const size_t rows)
{
    if (arr != NULL)
    {
        for (size_t i = 0; i < rows; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Error: начало диапазона должно быть меньше или равно концу\n");
        exit(1);
    }
}

void changeNechet(int** arr, const size_t columns, const size_t rows)
{
    check_memory(arr);
    for (size_t i = 0; i < rows; i++)
    {
        check_memory(arr[i]);
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] % 2 != 0)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int countZeroel(int** arr, const size_t columns, const size_t rows)
{
    check_memory(arr);
    int k = 0;
    for (size_t j = 0; j < columns; j++)
    {
        for (size_t i = 0; i < rows; i++)
        {
            if (arr[i][j] == 0)
            {
                k++;
                break;
            }
        }
    }
    return k;
}

int** Fillarr(int** arr, const size_t columns, const size_t rows, size_t* new_columns)
{
    check_memory(arr);

    const int count = countZeroel(arr, columns, rows);

    if (count == 0)
    {
        *new_columns = columns;
        return NULL;
    }

    *new_columns = columns + count;

    int** arr_2 = getArray(rows, *new_columns);
    size_t next_idx = 0;

    for (size_t j = 0; j < columns; j++)
    {
        for (size_t i = 0; i < rows; i++)
        {
            arr_2[i][next_idx] = arr[i][j];
        }
        next_idx++;

        int has_zero = 0;
        for (size_t i = 0; i < rows; i++)
        {
            if (arr[i][j] == 0)
            {
                has_zero = 1;
                break;
            }
        }
        if (has_zero)
        {
            for (size_t i = 0; i < rows; i++)
            {
                arr_2[i][next_idx] = arr[i][0];
            }
            next_idx++;
        }
    }

    return arr_2;
}
