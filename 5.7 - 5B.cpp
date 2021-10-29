#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include "Functions.h"

using namespace std;

int main()
{
	const int MAX = 100;
	
	int arr_int1[MAX];
	int	arr_int2[MAX];

	double arr_d1[MAX];
	double arr_d2[MAX];

	float arr_f1[MAX];
	float arr_f2[MAX];

	char arr_ch1[MAX];
	char arr_ch2[MAX];


	int size;
	cout << "Enter massive size: ";
	cin >> size;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Integer
	cout << "INTEGER" << endl << endl;
	int type;
	cout << "1 - ascending, 2 - descending, 3 - randomly: ";
	cin >> type;

	switch (type)
	{
	case 1:

		fill_ascend(type, size, arr_int1, arr_int2);
		break;

	case 2:

		fill_descend(type, size, arr_int1, arr_int2);
		break;

	case 3:

		fill_rand(type, size, arr_int1, arr_int2);
		break;

	default: cout << "ERROR" << endl;
		break;
	}

	//Output (original massive)
	for (int i = 0; i < size; i++)
	{
		cout << arr_int1[i] << " ";
	}
	
	
	cout << endl << endl;

	//Quicksort (int)
	int compar = 0, permut = 0, left = 0, right = size - 1;

	cout << "Quicksort" << endl;
	quick_sort(arr_int1, size, compar, permut, left, right);

	for (int i = 0; i < size; i++)
	{
		cout << arr_int1[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << endl;


	//Insertion sort (int)
	compar = 0, permut = 0;

	cout << "Insertion" << endl;
	insertion_sort(arr_int2, size, compar, permut);

	for (int i = 0; i < size; i++)
	{
		cout << arr_int2[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Double
	cout << "DOUBLE" << endl << endl;
	cout << "1 - ascending, 2 - descending, 3 - randomly: ";
	cin >> type;

	switch (type)
	{
	case 1:

		fill_ascend(type, size, arr_d1, arr_d2);
		break;

	case 2:

		fill_descend(type, size, arr_d1, arr_d2);
		break;

	case 3:

		fill_rand(type, size, arr_d1, arr_d2);
		break;

	default: cout << "ERROR" << endl;
		break;
	}

	//Output (original massive)
	for (int i = 0; i < size; i++)
	{
		cout << arr_d1[i] << " ";
	}


	cout << endl << endl;


	//Quicksort (double)
	compar = 0, permut = 0, left = 0, right = size - 1;

	cout << "Quicksort" << endl;
	quick_sort(arr_d1, size, compar, permut, left, right);

	for (int i = 0; i < size; i++)
	{
		cout << arr_d1[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << endl;


	//Insertion sort (double)
	compar = 0, permut = 0;

	cout << "Insertion" << endl;
	insertion_sort(arr_d2, size, compar, permut);

	for (int i = 0; i < size; i++)
	{
		cout << arr_d2[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << "------------------------------------------------------------------------------" << endl;


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Float
	cout << "FLOAT" << endl << endl;
	cout << "1 - ascending, 2 - descending, 3 - randomly: ";
	cin >> type;

	switch (type)
	{
	case 1:

		fill_ascend(type, size, arr_f1, arr_f2);
		break;

	case 2:

		fill_descend(type, size, arr_f1, arr_f2);
		break;

	case 3:

		fill_rand(type, size, arr_f1, arr_f2);
		break;

	default: cout << "ERROR" << endl;
		break;
	}

	//Output (original massive)
	for (int i = 0; i < size; i++)
	{
		cout << arr_f1[i] << " ";
	}


	cout << endl << endl;


	//Quicksort (float)
	compar = 0, permut = 0, left = 0, right = size - 1;

	cout << "Quicksort" << endl;
	quick_sort(arr_f1, size, compar, permut, left, right);

	for (int i = 0; i < size; i++)
	{
		cout << arr_f1[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << endl;


	//Insertion sort (float)
	compar = 0, permut = 0;

	cout << "Insertion" << endl;
	insertion_sort(arr_f2, size, compar, permut);

	for (int i = 0; i < size; i++)
	{
		cout << arr_f2[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << "------------------------------------------------------------------------------" << endl;


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//Char
	cout << "CHAR" << endl << endl;
	cout << "1 - ascending, 2 - descending, 3 - randomly: ";
	cin >> type;

	switch (type)
	{
	case 1:

		fill_ascend(type, size, arr_ch1, arr_ch2);
		break;

	case 2:

		fill_descend(type, size, arr_ch1, arr_ch2);
		break;

	case 3:

		fill_rand(type, size, arr_ch1, arr_ch2);
		break;

	default: cout << "ERROR" << endl;
		break;
	}

	//Output (original massive)
	for (int i = 0; i < size; i++)
	{
		cout << arr_ch1[i] << " ";
	}


	cout << endl << endl;


	//Quicksort (char)
	compar = 0, permut = 0, left = 0, right = size - 1;

	cout << "Quicksort" << endl;
	quick_sort(arr_ch1, size, compar, permut, left, right);

	for (int i = 0; i < size; i++)
	{
		cout << arr_ch1[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << endl;


	//Insertion sort (float)
	compar = 0, permut = 0;

	cout << "Insertion" << endl;
	insertion_sort(arr_ch2, size, compar, permut);

	for (int i = 0; i < size; i++)
	{
		cout << arr_ch2[i] << " ";
	}

	cout << endl;
	cout << "Comparisons: " << compar << endl;
	cout << "Permutations: " << permut << endl;
	cout << endl;


	
	return 0;
}
