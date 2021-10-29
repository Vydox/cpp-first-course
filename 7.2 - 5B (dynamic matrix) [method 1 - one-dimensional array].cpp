#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int* create_arr(int n);
void fill_arr(int* arr, int n);
void output_arr(int* arr, int n);
int* vector(int* arr, int n);
void output_vect(int* arr, int n);

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

	int* vect = new int[2 * n - 1];
	vect = vector(arr, n); //Стварэнне вектара з неабходнымі лічбамі
	output_vect(vect, n);

	delete[] arr;
	delete[] vect;

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

int* vector(int* arr, int n) {
	int* vect = new int[2 * n - 1];
	int min = arr[0];
	vect[0] = min;
	int num = 1;
	for (int i = 1; i <= n - 1; i++) { //перамяшчэнне па першаму радку направа
		min = arr[i];
		int k = 1; //нумар элементу ў дыяганалі
		while (k < i + 1) {
			if (arr[i + k * (n - 1)] < min)  //ссоўванне па дыяганалі ўніз
				min = arr[i + k * (n - 1)]; 
			k++;
		}
		vect[num++] = min;
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
		vect[num++] = min;
		k--;
	}
	vect[2*n-2] = arr[n * n - 1];
	return vect;
}


void output_vect(int* arr, int n) {
	for (int i = 0; i <= 2*n-2; i++) {
		cout << arr[i] << " ";
	}
}
