#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include "Functions.h"

using namespace std;

/*double func(double x, double s, double t);

void sum(double a, double b, double h, double (*func)(double x, double s, double t), double s, double t, double& S);

void integral(double a, double b, double eps, double(*func)(double x, double s, double t), double s, double t, double& I, int& k);*/

int main()
{
	double a = 2.63, b = 3.1, eps = 1e-6;
	double I;
	int K_iter;
	
	chrono::steady_clock sc;

	cout << "s" << setw(15) << "t" << setw(15) << "Int" << setw(15) << "k_iter" << setw(15) << "Time" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int s = 1; s <= 10; s += 3)
	{
		for (int t = 1; t <= 3; t+=1)
		{
			auto start = sc.now();
			
			int k_iter = 0;
			integral(a, b, eps, &func, s, t, I, K_iter);

			auto end = sc.now();
			auto time_span = static_cast<chrono::duration<double>>(end - start);

			cout << s << setw(15) << t << setw(15) << I << setw(15) << K_iter << setw(15) << time_span.count() << " sec." << endl;
		}
	}
}



double func(double x, double s, double t) {
    return (s * (pow(x, 2) / (log(pow(x, t)) + pow(cos(pow(x, 0.333333333)), 2))));
}

/*void sum(double a, double b, double h, double (*func)(double x, double s, double t), double s, double t, double& S) {
	double x, sum;
	x = a;
	sum = 0;
	while (x < b)
	{
		sum = sum + (*func)(x, s, t);
		x = x + h;
	}
	S = h * sum;
}

void integral(double a, double b, double eps, double(*func)(double x, double s, double t), double s, double t, double& I, int& k) {
	int n = 4;
	double h = (b - a) / n;
	double S1 = 0, S2 = 0;
	sum(a, b, h, func, s, t, S1);
	k = 0;
	do
	{
		S2 = S1;
		n *= 2;
		h = (b - a) / n;
		sum(a, b, h, func, s, t, S1);
		k++;

	} while (fabs(S1 - S2) > eps);
	I = S1;
}*/