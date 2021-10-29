#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>

using namespace std;

void fill_vect(vector<vector<int>>& Vect, int n);
void output(vector<vector<int>>& Vect, int n);
void vect_fin(vector<vector<int>>& Vect, vector<int>& vect_fin, int n);
void output_vect(vector<int>& vect_fin);

int main()
{
	int n;
	cout << "Enter matrix size: ";
	cin >> n;

	vector<vector<int>> Vect(n, vector<int> (n));

	//create_arr(Vect); //Стварэнне масіву

	srand(time(NULL));
	fill_vect(Vect, n); //Запаўненне масіву

	output(Vect, n); //Вывад масіву

	cout << endl << endl;

	vector<int> vect_final;
	vect_fin(Vect, vect_final, n);
	output_vect(vect_final);
	return 0;
}

/*void create_arr(vector<vector<int>>& Vect) {
	for (unsigned int i = 0; i < Vect.size(); i++) {
		Vect[i].resize(Vect.size());
	}
}*/

void fill_vect(vector<vector<int>>& Vect, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Vect[i][j] = rand() % 25;
		}
	}
}

void output(vector<vector<int>>& Vect, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << Vect[i][j] << " ";
		}
		cout << endl;
	}
}

void vect_fin(vector<vector<int>>& Vect, vector<int>& vect_fin, int n) {
	int min = Vect[0][0];
	vect_fin.push_back(min);
	int num = 1;
	for (int j = 1; j <= n - 1; j++) { //перамяшчэнне па першаму радку направа
		int i = 0, l = j;
		min = Vect[i][j];
		int k = j; //нумар элементу ў дыяганалі
		while (k > 0) {
			if (Vect[++i][--l] < min)  //ссоўванне па дыяганалі ўніз
				min = Vect[i][l];
			k--;
		}
		vect_fin.push_back(min);
	}


	for (int i = 1; i <= n - 1; i++) { //Перамяшчэнне па апошняму слупку ўніз
		int j = n - 1, l = i;
		min = Vect[i][j];
		int k = n - i - 1;
		while (k > 0) {
			if (Vect[++l][--j] < min) //Ссоўванне па дыяганалі ўніз
				min = Vect[l][j];
			k--;
		}
		vect_fin.push_back(min);
	}
}


void output_vect(vector<int>& vect_fin) {
	for (unsigned int i = 0; i < vect_fin.size(); i++) {
		cout << vect_fin[i] << " ";
	}
}
