#include <math.h>
#include <iostream>  
#include <iomanip>
#include <stdlib.h> 
#include <time.h>


using namespace std;

int main()

{
	setlocale(LC_ALL, "");
	int N, M;
	do
	{
		cout << "Введите основание числа (M>10): ";
		cin >> M; cout << endl;
		cout << "Введите cтепень числа (N>10): ";
		cin >> N; cout << endl;
		if (N < 10 || M < 10)
		{
			cout << "Введеные числа меньше 10" << endl;
		}
	} while (N <= 10 || M <= 10);
	int n[10000];

	n[0] = 1;
	n[1] = 1;

	for (int p = 0; p < N; ++p) {
		int b = 0;

		for (int i = 1; i <= n[0]; ++i) {
			b += n[i] * M;
			n[i] = b % 10;
			b /= 10;
		}

		if (b != 0) {
			n[0]++;
			n[n[0]] = b;
		}
	}
	cout << endl;
	cout << "M^N = ";

	for (int i = n[0]; i >= 1; --i) {
		cout << n[i];
	}
	cout << endl;

	return 0;
}