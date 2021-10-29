#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;

int* create_arr(int n);
void fill_arr(int* arr, int n);
void output_arr(int* arr, int n);
void vect(vector<int>& Vect, int* arr, int n);
void output_vect(vector<int>& Vect);

int main()
{
	int n;
	cout << "Enter matrix size: ";
	cin >> n;

	int* arr = create_arr(n); //Стварэнне масіву

	srand(time(NULL));
	fill_arr(arr, n); //Запаўненне масіву

	output_arr(arr, n); //Вывад масіву

	cout << endl << endl;

	vector<int> Vect;
	vect(Vect, arr, n); //Стварэнне вектара з неабходнымі лічбамі
	output_vect(Vect);

	delete[] arr;

	return 0;
}

int* create_arr(int n) {
	int* arr = new int[n * n];
	return arr;
}

void fill_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i * n + j] = rand() % 25;
		}
	}
}

void output_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << arr[i * n + j] << " ";
		}
		cout << endl;
	}
}

void vect(vector<int>& Vect, int* arr, int n) {
	int min = arr[0];
	Vect.push_back(min);
	int num = 1;
	for (int i = 1; i <= n - 1; i++) { //перамяшчэнне па першаму радку направа
		min = arr[i];
		int k = 1; //нумар элементу ў дыяганалі
		while (k < i + 1) {
			if (arr[i + k * (n - 1)] < min)  //ссоўванне па дыяганалі ўніз
				min = arr[i + k * (n - 1)];
			k++;
		}
		Vect.push_back(min);
	}

	int k = n - 1;
	for (int i = 2 * n - 1; i <= (n * n) - 1; i += n) { //Перамяшчэнне па апошняму слупку ўніз
		min = arr[i];
		int l = 1;
		while (l < k) {
			if (arr[i + l * (n - 1)] < min)	//Ссоўванне па дыяганалі ўніз
				min = arr[i + l * (n - 1)];
			l++;
		}
		Vect.push_back(min);
		k--;
	}
	//Vect.push_back(arr[n * n - 1]);
}


void output_vect(vector<int>& Vect) {
	for (unsigned int i = 0; i < Vect.size(); i++) {
		cout << Vect[i] << " ";
	}
}
