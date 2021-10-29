#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	const int N = 80;
	char s[N] = { 0 };

	cin.getline(s, N);
	cout << s << endl;

	cout << endl;

	int i = 0, j, len = strlen(s);
	char c;
	while (i < len) {
		c = s[i];
		int n = 0;
		for (j = 0; j < len; j++) 
			if (j != i && s[j] == c) 
				n++;
		if (n == 1) {
			for (j = 0; j < len; )
				if (s[j] == c) {
					for (int k = j; k <= len; k++)
						s[k] = s[k + 1];
					len--;
				}
				else j++;
		}
		i++;
	}
	

	cout << s;
	return 0;
}