

#include <iostream>

using namespace std;

int main()
{
	
	setlocale(LC_ALL, "Rus");

	const int N = 10, M = 7;
	int A[N], B[M];
	int k;

	
	
	//Работа с массивом А

	cout << "Введите массив А:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << "Массив А: ";
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N-1; i++) {
		for (int j = N - 1; j >= i; j--) {
			if (A[j-1] > A[j]) {
				k = A[j];
				A[j] = A[j - 1];
				A[j - 1] = k;
			}
		}
	}
	
	cout << "Отсортированный массив А: ";
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl;

	
	
	//Работа с массивом В

	cout << "Введите массив B:" << endl;
	for (int i = 0; i < M; i++) {
		cin >> B[i];					//ввод массива
	}

	cout << "Массив B: ";
	for (int i = 0; i < M; i++) {
		cout << B[i] << " ";			//вывод сырого массива
	}
	cout << endl;
	for (int i = 0; i < M - 1; i++) {
		for (int j = M - 1; j >= i; j--) {
			if (B[j - 1] > B[j]) {
				k = B[j];					//сортировка массива
				B[j] = B[j - 1];
				B[j - 1] = k;
			}
		}
	}

	cout << "Отсортированный массив B: ";
	for (int i = 0; i < M; i++) {
		cout << B[i] << " ";			//вывод готового массива
	}

	cout << endl;
	
	
	//Сравнение массивов
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (B[j] != A[i])
				A[j] = NULL;
		}
	}
	
	cout << "Итоговый массив С: ";
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";			//вывод итогового массива
	}
}

