

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int k;
    cout << "Введите k: ";
    cin >> k;

    /*string line = "1";
    char n;
    for (int i = 2; i <= (k*k); i++) {
        n = static_cast<char>(i);
        line = line + n;
    }
    cout << line[k] << endl;*/

    int i = k;
    unsigned long a = 1, d = 10;
    int dp = 1;

    while (i - dp > 0) {
        i -= dp;
        a += 1;
        if (a >= d) {
            dp++;
            d *= 10;
        }
    }

    cout << (long)(a / pow(10, dp - i)) % 10 << endl;

    return (0);
}

