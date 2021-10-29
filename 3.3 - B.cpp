#include <math.h>
#include <iostream>  
#include <iomanip>
using namespace std;

void main() {
    const long int N = 100000;
    bool a[N] = { 0 };
    for (int i = 2; i < N; i++)   
        a[i] = true; 

    unsigned int n = sqrt(double(N));

    for (int i = 2; i <= n; i++)   
        if (a[i])     
            for (int j = i *2; j < N; j += i)     
                a[j] = false; 

	for (int i = 11; i < N; i+=10) {
		if (a[i] &&  a[i + 2] && a[i + 6] && a[i + 8]) {
            cout << i << setw(10) << i + 2 << setw(10) << i + 6 << setw(10) << i + 8 << endl;
		}
	}
	
    cout << endl;

}