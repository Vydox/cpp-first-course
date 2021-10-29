#include <string.h>
#include <iostream>
using namespace std;

string max_word(char* str, string Max[10]);

int main()
{
	char str[80];
	string Max[10];
	cout << "Enter a string: ";
	cin.getline(str, 80);

	max_word(str, Max);
	for (int x = 0; ; x++)
		cout << Max[x] << " ";
	return (0);
}

string max_word(char* str, string Max[10]) {
	const char razd[] = " ,?!;-.";
	char* context = nullptr;
	string arr[20];
	char* Ptr = strtok_s(str, razd, &context);
	int i = 0, n = 0;
	while (Ptr != nullptr)
	{
		arr[i] = Ptr;
		Ptr = strtok_s(nullptr, razd, &context);
		i++;
		n++; //колькасць лексем
	}
	/*for (int j = 0; j < i; j++)
		cout << arr[j] << endl;*/
	int max = 0, k = 0, l = 0;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == arr[i])
				k++;
		}
		if (k > max) {
			Max[l] = arr[i];
			max = k;
		}
		else if (k == max) { //Выпадак, калі самых частых слоў некалькі
			l++;
			Max[l] = arr[i];
		}
	}
	return Max[l];
	
}