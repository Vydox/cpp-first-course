//Получить массив, образованный из исходного исключением чисел, которые встречаются в исходном файле ровно один раз, по возрастанию значений (без повторений)

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void create_file(ofstream& tofile, int n, int r);
void arr_empty(int* Arr, int r);
void output(int* Arr, int r);
void arr_count(ifstream& fromfile, int* Arr, int r);
int count(int* Arr, int r);
void arr_fin(int* Arr_fin, int* Arr, int r);

int main()
{
	srand(time(NULL));

	int n = 100, r;
	cout << "Enter range: ";
	cin >> r;
	cout << endl << endl << endl;

	ofstream tofile("f.txt");
	if (!tofile)
	{
		cout << "error1" << endl;
		return 1;
	}

	create_file(tofile, n, r); //File of n random numbers from 0 to r 
	tofile.close();
	
	int* Arr = new int[r + 1];
	
	arr_empty(Arr, r); //Array of r zeros
	/*for (int i = 0; i < r; i++)
		cout << i << " ";
	cout << endl;
	output(Arr, r);

	cout << endl << endl << endl;*/

	ifstream fromfile("f.txt");
	arr_count(fromfile, Arr, r); //Array of amount of each number
	fromfile.close();
	for (int i = 0; i <= r; i++)
		cout << i << " ";
	cout << endl;
	output(Arr, r);

	cout << endl << endl << endl;

	int num = r - count(Arr, r); //Size of final array
	int* Arr_fin = new int[num];

	arr_fin(Arr_fin, Arr, r); //Final array
	output(Arr_fin, num);

	delete[] Arr;
	delete[] Arr_fin;

	return 0;
}

void create_file(ofstream& tofile, int n, int r) {
	for (int i = 0; i < n; i++)
		tofile << rand() % r << endl;
}

void arr_empty(int* Arr, int r) {
	for (int i = 0; i <= r; i++)
		Arr[i] = 0;
}

void output(int* Arr, int r) {
	for (int i = 0; i <= r; i++)
		cout << Arr[i] << " ";
}

void arr_count(ifstream& fromfile, int* Arr, int r) {
	int num;
	while (!fromfile.eof()) {
		fromfile >> num;
		for (int i = 0; i <= r; i++) {
			if (i == num)
				Arr[i]++;
		}
	}
}

int count(int* Arr, int r) {
	int n = 0;
	for (int i = 0; i <= r; i++)
		if (Arr[i] == 1)
			n++;
	return n;
}

void arr_fin(int* Arr_fin, int* Arr, int r) {
	int k = 0;
	for (int i = 0; i <= r; i++)
		if (Arr[i] != 1)
			Arr_fin[k++] = i;
}