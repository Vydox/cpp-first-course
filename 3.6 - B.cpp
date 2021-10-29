#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int M, N;
    cout << "Введите М: ";
    cin >> M;
    cout << "Введите N: ";
    cin >> N;

    if (N < 10) {
        cout << "Incorrect value of N";
        return (0);
    }

    long int n = pow(M, N);
    cout << n;
}

