#include <iostream>
#include <iomanip>
#include <math.h>
#include "Functions.h"

void sum(double a, double b, double h, double (*func)(double x, double s, double t), double s, double t, double& S) {
	double x, sum;
	x = a;
	sum = 0;
	while (x <= b)
	{
		x = x + h;
		sum = sum + (*func)(x, s, t);
		
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
}