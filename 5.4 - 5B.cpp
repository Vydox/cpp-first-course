#include <iostream>

using namespace std;

int& max(int n, int arr[]);

int main()
{
	int n = 5, k;
	int arr[] = {1, 2, 3, 4, 5};
	cout << max(n, arr) << endl;

	cout << "Enter k: ";
	cin >> k;
	max(n, arr) = k;
	for (int i = 0; i < n; i++)
		cout << " " << arr[i];

	return (0);
}

int& max(int n, int arr[])
{
	int a = 0, num = 0;
	int max = 0;
	for (int j = 1; j < n; j++)
		if (arr[j] > max)
			max = j;

	for (int i = 0; i < n; i++) {
		a = arr[i];
		int l = 1;
		for (int g = i + 1; g < n; g++) {
			if (arr[g] == a)
				l++;
		}

		if (l > 2)
			num = i;
		else num = max;
	}
	return arr[num];
}