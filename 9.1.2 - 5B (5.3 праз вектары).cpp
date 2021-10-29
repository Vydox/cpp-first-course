#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

void max_word(char* str, vector<string>& Max);

int main()
{
	char str[80];
	cout << "Enter a string: ";
	cin.getline(str, 80);

	vector<string> Max;
	max_word(str, Max);
	for (unsigned int i = 0; i < Max.size(); i++)
		cout << Max[i] << " ";
	return (0);
}

void max_word(char* str, vector<string> &Max) {
	const char razd[] = " ,?!;-.";
	char* context = nullptr;
	vector<string> arr;
	char* Ptr = strtok_s(str, razd, &context);
	int n = 0;
	while (Ptr != nullptr)
	{
		arr.push_back(Ptr);
		Ptr = strtok_s(nullptr, razd, &context);
		n++; //колькасць лексем
	}
	int max = 0, k = 0, l = 0;
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == arr[i])
				k++;
		}
		if (k > max) {
			Max.push_back(arr[i]);
			max = k;
		}
		else if (k != 0 && k == max) { //Выпадак, калі самых частых слоў некалькі
			Max.push_back(arr[i]);
		}
	}
}