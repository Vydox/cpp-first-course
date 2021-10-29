#include <iostream>
#include <time.h>
#include <iomanip>


using namespace std;


int main()
{

	//Первая матрица
	const int M = 5, N = 5;
	int a[M][N];

	srand(time(NULL));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = rand() % 50;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}

	cout << endl;

	int min = a[M - 1][0];

	//Вторая матрица
	int b[M][N];
	b[M - 1][0] = min;

	for (int i = 2; i <= M; i++) {
		int k = i;
		int l = 0;
		while (k >= 1) {
			if (a[M - k][l] < min) {
				min = a[M - k][l];
			}
			k--;
			l++;
		}
		int n = i;
		int p = 0;
		while (n >= 1)
		b[M - n--][p++] = min;
	}

	for (int i = 1; i < N; i++) {
		int k = 0;
		int l = i;
		while (l < N) {
			if (a[k][l] < min) {
				min = a[k][l];
			}
			k++;
			l++;
		}
		int n = 0;
		int p = i;
		while (p < N)
			b[n++][p++] = min;
	}
	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << setw(3) << b[i][j];
		cout << endl;
	}

}

