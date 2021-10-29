#include <iostream> 
#include <iomanip>
#include <stdio.h>
using namespace std;

int spiral_array(int pow);

int main()
{
	
	int power;
	
	cout << "Enter power: ";
	cin >> power;

	spiral_array(power);

	return(0);
}

int spiral_array(int p) {
	int **m = new int*[p];

}