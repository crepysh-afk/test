#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/**
*@brief считывает натуральное значение с клавиатуры с проверкой ввода
*@return возвращает считанное значение 
*/
int Value();

/**
* @brief Проверяет корректность диапазона
* @param start Начальное значение диапазона
* @param end Конечное значение диапазона
*/
void checkRange(const int start, const int end);

/**
@brief Освобождает память массива, выделенную через malloc
*@param arr Указатель на массив для освобождения
*@param size размер массива
*/
int* freeArray(int* arr, const size_t size);


/**
 * @brief Получение корректного размера массива от пользователя
 * @param message Указатель на строку с приглашением для ввода
 * @return Возвращает размер массива типа size_t
 */
size_t getSize(char* message);

/**
 * @brief Ручное заполнение массива пользователем
 * @param arr Указатель на массив для заполнения
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
* @brief Вывод элементов массива в консоль
* @param arr Указатель на массив для заполнения
* @param size размер массива
*/
void printArray(int* arr, const size_t size);

/**
* @brief Находит последний элемент массива, кратный 3, и заменяет его на 0
* @param arr Указатель на массив целых чисел
* @param size Размер массива
*/
void changelastArr3(int* arr, size_t size);

/**
* @brief Создает новый массив, вставляя число K после каждого чётного элемента
* @param arr Указатель на массив целых чисел
* @param size Размер массива
*/
void fillnumK(const int* arr, size_t size);

/**
* @brief Подсчитывает количество чётных элементов в массиве
* @param arr Указатель на массив целых чисел
* @param size Размер массива
*/
const int getCountChet(const int* arr, size_t size);

/**
* @brief Проверяет валидность указателя на выделенную память
* @param arr Указатель на массив целых чисел
*/
void check_memory(const int* arr);

/**
* @brief Преобразует массив по специальному правилу
* @param arr Указатель на массив целых чисел
* @param size Размер массива
*/
void getArrM(int* arr, size_t size);

/**
*@brief Заполнение массива случайными числами
*@param arr Указатель на массив для заполнения
*@param rows количество строк массива 
*@param columns количество стобцов массива
*/
void fillRandom(int* arr, const size_t size);

/**
* @brief Перечесление определяет два возможных режима работы для генератора данных
*/
enum { RANDOM=1, MANUAL, task1=1, task2, task3 };

/**
*@brief точка входа в программу 
*@return возвращает 0, если программа выполнена корректно, иначе 1
*/
int main()
{
	system("chcp 1251");
	size_t size = getSize("Введите размер массива: ");
	int* arr = calloc(size,sizeof(int));
	check_memory(arr);
	printf("Введите способ заполнения массива:\n""%d случайными числами %d вручную", RANDOM, MANUAL);
	int choise = Value();
	switch (choise)
	{
		case RANDOM:
			fillRandom(arr, size);
			break;
		case MANUAL:
			fillArray(arr, size);
			break;
		default:
			printf("error");
			free(arr);
			break;
	
	}

	printArray(arr, size);

	printf("Выберите задание для выполнения:\n");
	int second_choise = Value();
	switch (second_choise)
	{
	case task1:
		changelastArr3(arr, size);
		break;
	case task2:
		fillnumK(arr, size);
		break;
	case task3:
		getArrM(arr, size);
		break;
	default:
		printf("ERROR");
		free(arr);
		break;
	}

	
	return 0;
}
int Value() 
{
	int Value = 0;
	if (!scanf_s("%d" ,&Value))
	{
		printf("ERROR\n");
		exit(1);
	}
	return Value;
}

size_t getSize(char* message)
{
	printf("%s", message);
	int value = Value();
	if (value <= 0)
	{
		printf("ERROR");
		exit(1);
	}
	return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
	check_memory(arr);
	for (size_t i = 0; i < size; i++)
	{
		printf("Введите элемент [%zu]: ", i);
		arr[i] = Value();
	}
}

void printArray(int* arr, const size_t size)
{
	check_memory(arr);
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
	check_memory(arr);
	srand(time(NULL));
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


void checkRange(const int start, const int end)
{
	if (start > end)
	{
		printf("Error\n");
		exit(1);
	}
}


void changelastArr3(int* arr, size_t size)
{
	check_memory(arr);
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (arr[i] % 3 == 0)
		{
			arr[i] = 0;
			break;
		}
	}
	printArray(arr, size);
}

void fillnumK(const int* arr, size_t size)
{
	check_memory(arr);
	int k = Value();
	int newsize = size + getCountChet(arr, size);
	int* arr_2 = calloc(newsize, sizeof(int));
	check_memory(arr_2);
	size_t g = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (g < newsize)
		{
			arr_2[g++] = arr[i];
		}
		else
		{
			printf("Выход за пределы массива");
			exit(1);
		}
		if (arr[i] % 2 == 0)
		{
			if (g < newsize)
			{
				arr_2[g++] = k;
			}
			else
			{
				printf("Выход за пределы массива");
				exit(1);
			}
		}
	}
	printArray(arr_2, newsize);
	free(arr_2);
}

const int getCountChet(const int* arr, size_t size)
{
	check_memory(arr);
	int countChet = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			countChet++;
		}
	}
	return countChet;
}

void check_memory(const int* arr)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
}
void getArrM(int* arr, size_t size)
{
	check_memory(arr);
	for (size_t i = 0; i < size; i++)
	{
		if (i % 4 == 0)
		{
			arr[i] = 4 * abs(arr[i]);
		}
		else
		{
			arr[i] = -1 * arr[i] * (i + 1);
		}
	}
	arr[0] = 0;
	arr[size-1] = 0;
	printArray(arr, size);
}
