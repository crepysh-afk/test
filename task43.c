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
size_t getSize(char* message);

/**
 * @brief Ручное заполнение массива пользователем
 * @param arr Указатель на массив для заполнения
 *@param rows количество строк массива
 *@param columns количество стобцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
* @brief Вывод элементов массива в консоль
* @param arr Указатель на массив для заполнения
*@param rows количество строк массива
*@param columns количество стобцов массива
*/
void printArray(int** arr, const size_t rows, const size_t columns);

/**
*@brief Заполнение массива случайными числами
*@param arr Указатель на массив для заполнения
*@param rows количество строк массива
*@param columns количество стобцов массива
*/
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
* @brief Проверяет корректность диапазона
* @param start Начальное значение диапазона
* @param end Конечное значение диапазона
*/
void checkRange(const int start, const int end);

/**
 * @brief Выполняет преобразование массива: вставляет копию первого столбца после столбцов с нулями
 * @param arr Указатель на двумерный массив
 * @param columns Количество столбцов в массиве
 * @param rows Количество строк в массиве
 */
void Fillarr(int** arr, const size_t columns, const size_t rows);

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
@brief Освобождает память массива, выделенную через malloc
*@param arr Указатель на массив для освобождения
*@param rows количество строк массива
*@param columns количество стобцов массива
*/
int** freeArray(int** arr, const size_t rows);

/**
* @brief Проверяет валидность указателя на выделенную память
* @param arr Указатель на массив целых чисел
*/
void check_memory(const int** arr);

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
* @brief task1 Выбор задания 1: замена последнего элемента, кратного 3, на 0
* @brief task2 Выбор задания 2: вставка числа K после каждого чётного элемента
* @brief task3 Выбор задания 3: преобразование массива по специальному правилу
*/
enum { RANDOM = 1, MANUAL, task1 = 1, task2 };

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно, иначе 1
 */
int main()
{
	system("chcp 1251");
	size_t rows = getSize("Введите количество строк массива: ");
	size_t columns = getSize("Введите количество столбцов массива: ");
	int** arr = getArray(rows, columns);
	printf("Выберите способ заполнения массива:\n""%d случайными числами %d вручную", RANDOM, MANUAL);
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
		printf("Error");
		free(arr);
		break;
	}

	printArray(arr, rows, columns);

	printf("Выберите задание для выполнения:\n""%d task1 %d task2:", task1, task2);
	int secondchoice = Value();
	switch (secondchoice)
	{
	case task1:
		changeNechet(arr, rows, columns);
		break;
	case task2:

	default:
		printf("Error");
		free(arr);
		break;
	}
	freeArray(arr, rows);
	return 0;
}

int Value()
{
	int value = 0;
	if (!scanf_s("%d", &value))
	{
		printf("Error\n");
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
		printf("Error");
		exit(1);
	}
	return (size_t)value;
}

void check_memory(int** arr)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Error");
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
	srand(time(NULL));
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

int** freeArray(int** arr, const size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void checkRange(const int start, const int end)
{
	if (start > end)
	{
		printf("Error\n");
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
	printArray(arr, rows, columns);
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

void Fillarr(int** arr, const size_t columns, const size_t rows)
{
	check_memory(arr);
	const int count = countZeroel(arr, columns, rows);
	if (count == 0)
	{
		printArray(arr, rows, columns);
	}
	else
	{
		int* index = calloc(columns, sizeof(int));

		for (size_t j = 0; j < columns; j++)
		{
			for (size_t i = 0; i < rows; i++)
			{
				if (arr[i][j] == 0)
				{
					index[j] = 1;
					break;
				}
			}
		}

		size_t new_columns = columns + count;
		int** arr_2 = getArray(rows, new_columns);
		size_t next_idx = 0;

		for (size_t j = 0; j < columns; j++)
		{
			for (size_t i = 0; i < rows; i++)
			{
				arr_2[i][next_idx] = arr[i][j];
			}
			next_idx++;
			if (index[j] == 1)
			{
				for (size_t i = 0; i < rows; i++)
				{
					arr_2[i][next_idx] = arr[i][0];
				}
				next_idx++;
			}
		}

		printArray(arr_2, rows, new_columns);
		free(index);
		freeArray(arr_2, rows);
	}
}

