#include <iomanip>
#include <stdlib.h> 
#include <iostream> 


using namespace std;


int main()
{
	const int M = 5, N = 5;
	int a[M][N];
	
	srand(time(NULL));

	for (int i = 0; i < M; i++)   
		for (int j = 0; j < N; j++)    
			a[i][j] = rand() % 10;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)    
			cout << setw(3) << a[i][j];  
		cout << endl;  
	}

	int k;
	int max;

	cout << endl;

	int b[M][N];
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			k=0;
			max = a[i][j];
			while (k < N) {
				if (a[k][j] > max) {
					max = a[k][j];
				}
				k++;
			}
			k = 0;
			while (k < M) {
				if (a[i][k] > max) {
					max = a[i][k];
				}
				k++;
			}

			b[i][j] = max;
		}


	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << setw(3) << b[i][j];
		cout << endl;
	}



	
	/*cout << " 1 " << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = 1; // заполнение 1

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
	cout << endl << " 2" << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = i; // заполнение номером строки

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
	cout << endl << " 3" << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = j; // заполнение номером столбца

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}

	
		cout << endl << " 4 " << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) // заполнение числами
			a[i][j] = i * N + j; // от 0..n m-1

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
	cout << endl << " 5 " << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) // заполнение случайными
			a[i][j] = rand() % 100; // числами 0..99

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
	cout << endl << " 6 " << endl;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) // значения элементов
			cin >> a[i][j]; // матрицы вводятся с
			// клавиатуры

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
	cout << endl;*/
}