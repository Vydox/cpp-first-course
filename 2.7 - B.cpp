
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double x0 = 1, xm = 5, dx = 0.5;
    double x;
    
    
    int n;
    cout << "Vvedite n: ";
    cin >> n;

    for (x = x0; x <= xm; x += dx) {
        double y = 5, X = 1;
        int m1 = 1;
        int sum = 0, mult = 0;

        for (int i = 1; i <= n; i++) {
            X *= pow(x, 2 * i - 1);
            m1 *= -1;
            y += (m1 * i * X);
            sum++;
            mult += i;
        }

        cout << x << setw(10) << y << endl;
        cout << sum << setw(10) << mult << endl;


        for ()
    }
}

