#include <iomanip>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	//Инициализация строки
	const int N = 80;
	char s[N] = { 0 }, dr[N] = { 0 };

	cin.getline(s, N);
	cout << endl;

	//Нахождение границы между целой частью и дробной
	int m = 0, k = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '.') {
			m = i;
			break;
		}
	}
	//Загон дробной части в отдельную строку
	for (int l = m + 1; l < strlen(s); l++) {
		dr[k++] = s[l];
	}

	

	//Разбор целой части
	int sum = 0, A;
	int n = m - 1;
	for (int i = 0; i < strlen(s); i++) {
		switch (s[i]) {
		case '0': A = 0; break;
		case '1': A = 1; break;
		case '2': A = 2; break;
		case '3': A = 3; break;
		case '4': A = 4; break;
		case '5': A = 5; break;
		case '6': A = 6; break;
		case '7': A = 7; break;
		case '8': A = 8; break;
		case '9': A = 9; break;
		case 'A': A = 10; break;
		case 'B': A = 11; break;
		case 'C': A = 12; break;
		case 'D': A = 13; break;
		case 'E': A = 14; break;
		case 'F': A = 15; break;
		case '.': break;
		}
		sum = sum + A * pow(16, n);		//сумма для целой части
		n--;
	}


	//Разбор дробной части
	float sum_dr = 0.0, p = -1;
	float B;
	for (int i = 0; i < strlen(dr); i++) {
		switch (dr[i]) {
		case '0': B = 0.0; break;
		case '1': B = 1.0; break;
		case '2': B = 2.0; break;
		case '3': B = 3.0; break;
		case '4': B = 4.0; break;
		case '5': B = 5.0; break;
		case '6': B = 6.0; break;
		case '7': B = 7.0; break;
		case '8': B = 8.0; break;
		case '9': B = 9.0; break;
		case 'A': B = 10.0; break;
		case 'B': B = 11.0; break;
		case 'C': B = 12.0; break;
		case 'D': B = 13.0; break;
		case 'E': B = 14.0; break;
		case 'F': B = 15.0; break;
		}
		sum_dr += B * pow(16, p);	//сумма для дробной части
		p--;
	}
	

	//Итоговая сумма
	float sum_res = sum + sum_dr;
	cout << sum_res;
	
}

