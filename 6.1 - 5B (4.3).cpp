#include <string>
#include <iostream>

using namespace std;

void max_vowel(string s, string razd, string& res);

void main()
{
	string s, res;
	//строка из разделителей
	const string razd = " ,?!;-.";
	cout << "Enter string: ";
	getline(cin,s);

	max_vowel(s, razd, res);
	cout << res;
}

void max_vowel(string s, string razd, string& res)
{
	string word;
	unsigned int wordBegin = 0, wordEnd = 0;
	// позиция начала лексемы
	wordBegin = s.find_first_not_of(razd, wordEnd);
	// позиция конца лексемы
	wordEnd = s.find_first_of(razd, wordBegin);
	if (wordEnd >= s.length())
		wordEnd = s.length();

	int k = 0, max = 0;
	while (wordBegin < s.length())
	{ 
		word = s.substr(wordBegin, wordEnd - wordBegin);
		k = 0;
		for (int i = 0; i < word.length(); i++) {
			switch (word[i]) {
			case 'A': k++; break;
			case 'a': k++; break;
			case 'E': k++; break;
			case 'e': k++; break;
			case 'I': k++; break;
			case 'i': k++; break;
			case 'O': k++; break;
			case 'o': k++; break;
			case 'U': k++; break;
			case 'u': k++; break;
			case 'Y': k++; break;
			case 'y': k++; break;
			}
			
		}
		if (k > max) {
			res = word;
			max = k;
		}
		else if (k == max)
			res = res + ' ' + word;
		wordBegin = s.find_first_not_of(razd, wordEnd);
		wordEnd = s.find_first_of(razd, wordBegin);

	}
}