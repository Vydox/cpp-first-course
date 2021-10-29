#include <iostream>
#include <string.h>

using namespace std;

string del_two(string s);

int main()
{
	string s;
	cout << "Enter string: ";
	cin >> s;

	cout <<  del_two(s);

	return 0;
}

string del_two(string s) {
	int i = 0, j, len = s.length();
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
					/*for (int k = j; k < len; k++)
						s[k] = s[k + 1];*/
					s.erase(j, 1);
					len--;
					
				}
				else j++;
		}
		i++;
	}
	return s;
}