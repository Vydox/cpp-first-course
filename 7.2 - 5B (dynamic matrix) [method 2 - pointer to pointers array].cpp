#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int** create_arr(int n);
void fill_arr(int** arr, int n);
void output(int** arr, int n);
int* vector(int** arr, int n);
void output_vect(int* arr, int n);

int main()
{
	int n;
	cout << "Enter matrix size: ";
	cin >> n;

	int** arr = create_arr(n); //Стварэнне масіву

	srand(time(NULL));
	fill_arr(arr, n); //Запаўненне масіву

	output(arr, n); //Вывад масіву

	cout << endl << endl;

	int* vect = new int[2 * n - 1];
	vect = vector(arr, n); //Стварэнне вектара з неабходнымі лічбамі
	output_vect(vect, n);

	//delete[] arr;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	delete[] vect;

	return 0;
}

int** create_arr(int n) {
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	return arr;
}

void fill_arr(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 25;
		}
	}
}

void output(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int* vector(int** arr, int n) {
	int* vect = new int[2 * n - 1];
	int min = arr[0][0];
	vect[0] = min;
	int num = 1;
	for (int j = 1; j <= n - 1; j++) { //перамяшчэнне па першаму радку направа
		int i = 0, l = j;
		min = arr[i][j];
		int k = j; //нумар элементу ў дыяганалі
		while (k > 0) {
			if (arr[++i][--l] < min)  //ссоўванне па дыяганалі ўніз
				min = arr[i][l];
			k--;
		}
		vect[num++] = min;
	}

	
	for (int i = 1; i <= n - 1; i++) { //Перамяшчэнне па апошняму слупку ўніз
		int j = n - 1, l = i;
		min = arr[i][j];
		int k = n - i - 1;
		while (k > 0) {
			if (arr[++l][--j] < min) //Ссоўванне па дыяганалі ўніз
				min = arr[l][j];
			k--;
		}
		vect[num++] = min;
		
	}
	vect[2 * n - 2] = arr[n - 1][n - 1];
	return vect;
}


void output_vect(int* arr, int n) {
	for (int i = 0; i <= 2 * n - 2; i++) {
		cout << arr[i] << " ";
	}
}
