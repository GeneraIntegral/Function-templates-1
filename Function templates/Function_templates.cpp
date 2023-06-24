// DmitrievaOA_СПД211

#include<iostream>
using namespace std;

#define delimiter "--------------------------------------------\n"

const int ROWS = 5;	// Ко-во строк
const int COLS = 8;	// Кол-во элементов строки

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);

// Т - имя шаблонного типа 
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T> void Sort(T arr[], const int n);
template<typename T> void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T> T Sum(T arr[], const int n);
const char* Sum(char arr[], const int n); // Для того, чтобы обеспечить особое поведение функции для кого-то типа данных нужно перегрузить функцию для этого типа данных
template<typename T> T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T> double Avg(T arr[], const int n);
template<typename T> double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T> T minValueIn(T arr[], const int n);
template<typename T> T minValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T> T maxValueIn(T arr[], const int n);
template<typename T> T maxValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);

void UniqueRand(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	int minRand = 200, maxRand = 300;
	UniqueRand(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(arr, n) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(arr, n) << endl;
	Sort(arr, n);
	Print(arr, n);

	const int SIZE = 8;
	double brr[SIZE];

	FillRand(brr, SIZE, minRand, maxRand);
	Print(brr, SIZE);
	cout << "Сумма элементов массива: " << Sum(brr, SIZE) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(brr, SIZE) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(brr, SIZE) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(brr, SIZE) << endl;
	Sort(brr, SIZE);
	Print(brr, SIZE);

	int i_arr_2[ROWS][COLS]; // i_arr_2 int array 2D
	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

	double d_arr_2[ROWS][COLS] =
	{
		{2.5, 3.14, 4.2},
		{7.8, 5.1, 2.7},
		{1.1, 2.3, 4.7}
	};
	FillRand(d_arr_2, ROWS, COLS);
	Print(d_arr_2, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(d_arr_2, ROWS, COLS) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(d_arr_2, ROWS, COLS) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(d_arr_2, ROWS, COLS) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(d_arr_2, ROWS, COLS) << endl;
	cout << delimiter << endl;
	char c_arr[n];
	FillRand(c_arr, n);
	Print(c_arr, n);
	cout << "Сумма элементов массива: " << Sum(c_arr, n) << endl;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	// Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	// Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	// Заполнение массива случайными числами:
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}

}
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand) / 100;
		}
	}
}

template<typename T> T Print(T arr[], const int n)
{
	// Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T> T Print(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T> T Sort(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	// Сортировка массива:
	for (int i = 0; i < ROWS; i++)	        // Счетчик 'i' выбирает элемент, в который нкжно поместить минимальное значение
	{
		for (int j = i + 1; j < COLS; j++)	// Счетчик 'j' перебирает элементы в поисках минимального значения.
		{                                   // Пeребирается только правая часть массива относительно выбранного элемента.
			if (arr[j] < arr[i])
			{
				T buffer = arr[i];
				arr[i][j] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}

template<typename T> T Sum(T arr[], const int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

const char* Sum(char arr[], const int n)
{
	return "Буквы суммировать нельзя!";
}

template<typename T> T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

template<typename T> double Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

template<typename T> T Avg(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

template<typename T> T minValueIn(T arr[], const int n)
{
	T min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}

template<typename T> T maxValueIn(T arr[], const int n)
{
	T max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

void UniqueRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		bool unique;	// Флаг уникальности
		do
		{
			arr[i] = rand() % n;
			unique = true;	// Предполагаем, что случайное число уникально, но это нужно проверить:
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;	// Ключевое слово break прерывает текущую итерацию, и все последующие.
				}
			}
		} while (!unique);
	}
}