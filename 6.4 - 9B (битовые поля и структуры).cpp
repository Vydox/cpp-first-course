#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

union audit_data {
	unsigned char c; //всего 8 бит
	struct {
		unsigned int f : 3; //3 бита на этаж (1-7)
		unsigned int aud : 5; //5 бит на (1-31)
	};
};

bool comparing(audit_data struct1, audit_data struct2);

int main()
{
	srand(time(NULL));

	/*audit_data a;
	a.f = 7;
	a.aud =	31;
	cout << a.f << " " << a.aud << " " << int (a.c) << endl << endl;*/
	
	audit_data structure[10];

	for (int i = 0; i < 10; i++) {
		structure[i].c = rand() % 255;
	}

	sort(structure, structure + 10, comparing);	//сортировка

	for (int i = 0; i < 10; i++) {
		cout << structure[i].f << " " << structure[i].aud << " " << (int)structure[i].c << endl;
	}
}

bool comparing(audit_data struct1, audit_data struct2) {	//дополнительная функция для сортировки
	/*if (struct1.f < struct2.f) {
		return (struct1.c < struct2.c);
	} else if (struct1.f == struct2.f)
		if (struct1.aud < struct2.aud)
			return (struct1.c < struct2.c);*/
	if (struct1.f == struct2.f)
		return (struct1.c < struct2.c);
	return (struct1.f < struct2.f);
}