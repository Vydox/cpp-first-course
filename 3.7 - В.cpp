#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	const int M = 5, N = 5;
	int a[M][N];

	srand(time(NULL));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = rand() % 10;

	for (int i = 0; i < M; i++)
		for (int j = i; j < N; j++)
			

	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}*/
}

