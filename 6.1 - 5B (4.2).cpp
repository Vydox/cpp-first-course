#include <iomanip>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

float _16to10(string s);

int main()
{
	string s;
	cout << "Enter string: ";
	cin >> s;
	cout << _16to10(s) << endl;
	return (0);

}

float _16to10(string s) 
{
	int len = s.length();

	//Мяжа паміж цэлай і дробавай часткай
	int m = 0;
	m = s.find('.', 0);
	/*for (int i = 0; i < len; i++) {
		if (s[i] == '.') {
			m = i;
			break;
		}
	}*/

	//Дробавую - у асобны радок
	string dr;
	dr = s.substr(m + 1);
	/*int k = 0;
	for (int l = m + 1; l < len; l++) {
		dr[k++] = s[l];
	}*/

	//Працуем з цэлай часткай
	int sum = 0, A;
	int n = m - 1;
	for (int i = 0; i < len; i++) {
		/*switch (s[i]) {
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
		}*/
		if (s[i] >= '0' && s[i] <= '9')
			A = s[i] - '0';
		if (s[i] >= 'A' && s[i] <= 'F')
			A = s[i] - 'A' + 10;
		if (s[i] == '.')
			break;
		sum = sum + A * pow(16, n);		//сума для цэлай часткі
		n--;
	}


	//Працуем з дробавай часткай
	float sum_dr = 0.0, p = -1;
	float B;
	for (int i = 0; i < dr.length(); i++) {
		/*switch (dr[i]) {
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
		}*/
		if (dr[i] >= '0' && dr[i] <= '9')
			B = dr[i] - '0';
		if (dr[i] >= 'A' && dr[i] <= 'F')
			B = dr[i] - 'A' + 10.0;
		sum_dr += B * pow(16, p);	//сумма для дробной части
		p--;
	}


	//Выніковая сума
	float sum_res = sum + sum_dr;
	return sum_res;
}