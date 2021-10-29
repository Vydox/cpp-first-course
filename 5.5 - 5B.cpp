/*Вычислить корень уравнения
f(x) = 0

на отрезке[a; b] с точностью  = 10–6
,
используя заданный метод(М = 1 – метод половинного деления, М = 2 – метод
    касательных, М = 3 – метод хорд) для заданных функций.Вычисление корня
    уравнения оформить в виде функции с функциональным параметром, параметры
    a, b, , s – в виде аргументов по умолчанию.

    Результат представить в виде таблицы(s – значение параметра, х – вычис -
        ленный корень уравнения, f(x) – значение функции в найденной точке х, k_iter – ко -
        личество итераций цикла для получения корня с заданной точностью)

        а) f(x) = (x-1)^2 - 5, [-3, 0], M2
        б) f(x) = x^2 - sin(5*x^S), [0.5, 0.8], S e [0.7, 1.6], dS = 0.3, M2
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x, double S = 0);

double func1(double eps, double x0, int& i, double(*p_func)(double, double), double(*der1)(double, double), double S = 0);

double der1(double x, double S = 0);



double f2(double x, double S);

double der2(double x, double S);

double func2(double eps, double x, int& i, double(*f1)(double, double), double(*der1)(double, double), double S);

int main()
{
    //Частка а)
    int k;
    double x = func1(1e-6, -3.0, k, f1, der1);
    cout << x << setw(15) << f1(x, 0) << setw(15) << k << endl;

    cout << endl << endl;

    //Частка б)
    int it;
    for (double S = 0.7; S <= 1.6; S += 0.3) {
        x = func2(1e-6, 0.8, it, f2, der2, S);
        cout << S << setw(15) << x << setw(15) << f2(x, 0) << setw(15) << it << endl;
    }
}

double f1(double x, double S) {
    return (pow(x - 1, 2.0) - 5);
}

double der1(double x, double S) {
    return (2 * x - 2);
}

double func1(double eps, double x, int &i, double(*f1)(double, double), double(*der1)(double, double), double S) {
    for (i = 1; fabs(f1(x, S)) > eps; i++)
    {
        x -= (f1(x, S)/der1(x, S));
    }
    return x;
}




double f2(double x, double S) {
    return (pow(x, 2.0) - sin(5*pow(x, S)));
}

double der2(double x, double S) {
    return (2 * x - 5 * S * pow(x, S - 1) * cos(5 * pow(x, S)));
}

double func2(double eps, double x, int& i, double(*f2)(double, double), double(*der2)(double, double), double S) {
    for (i = 1; fabs(f2(x, S)) > eps; i++)
    {
        x -= (f2(x, S) / der2(x, S));
    }
    return x;
}