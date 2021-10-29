#include <stdlib.h>
#include <time.h>
#include "Functions.h"

//Filling
//Ascending
void fill_ascend(int type, int size, int* Arr, int* Arr2) //int
{
	srand(time(NULL));
	Arr[0] = rand() % 20;
	Arr2[0] = Arr[0];
	for (int i = 1; i < size; i++)
	{
		Arr[i] = Arr[i - 1] + rand() % 20;
		Arr2[i] = Arr[i];
	}

}

void fill_ascend(int type, int size, double* Arr, double* Arr2) //double
{
	srand(time(NULL));
	Arr[0] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
	Arr2[0] = Arr[0];
	for (int i = 1; i < size; i++)
	{
		Arr[i] = Arr[i - 1] + (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}

}

void fill_ascend(int type, int size, float* Arr, float* Arr2) //float
{
	srand(time(NULL));
	Arr[0] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
	Arr2[0] = Arr[0];
	for (int i = 1; i < size; i++)
	{
		Arr[i] = Arr[i - 1] + (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}

}

void fill_ascend(int type, int size, char* Arr, char* Arr2) //char
{
	srand(time(NULL));
	Arr[0] = (rand() % 26 + 65);
	Arr2[0] = Arr[0];
	for (int i = 1; i < size; i++)
	{
		Arr[i] = Arr[i - 1] + (rand() % 26 + 65);
		Arr2[i] = Arr[i];
	}

}







//Descending
void fill_descend(int type, int size, int* Arr, int* Arr2)
{
	srand(time(NULL));
	Arr[size - 1] = rand() % 20;
	Arr2[size - 1] = Arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		Arr[i] = Arr[i + 1] + rand() % 20;
		Arr2[i] = Arr[i];
	}
}

void fill_descend(int type, int size, double* Arr, double* Arr2)
{
	srand(time(NULL));
	Arr[size - 1] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
	Arr2[size - 1] = Arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		Arr[i] = Arr[i + 1] + (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}
}

void fill_descend(int type, int size, float* Arr, float* Arr2)
{
	srand(time(NULL));
	Arr[size - 1] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
	Arr2[size - 1] = Arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		Arr[i] = Arr[i + 1] + (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}
}

void fill_descend(int type, int size, char* Arr, char* Arr2)
{
	srand(time(NULL));
	Arr[size - 1] = (rand() % 26 + 65);
	Arr2[size - 1] = Arr[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		Arr[i] = Arr[i + 1] + (rand() % 26 + 65);
		Arr2[i] = Arr[i];
	}
}






//Random
void fill_rand(int type, int size, int* Arr, int* Arr2)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		Arr[i] = rand() % 20;
		Arr2[i] = Arr[i];
	}

}

void fill_rand(int type, int size, double* Arr, double* Arr2)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		Arr[i] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}
}

void fill_rand(int type, int size, float* Arr, float* Arr2)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		Arr[i] = (rand() % 20 * 1.0) + (rand() % 20 * 1.0) / 100;
		Arr2[i] = Arr[i];
	}
}

void fill_rand(int type, int size, char* Arr, char* Arr2)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		Arr[i] = rand() % 26 + 65;
		Arr2[i] = Arr[i];
	}

}