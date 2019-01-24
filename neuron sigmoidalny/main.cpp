#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

double beta = 0.4;
double f(double s) {
	return (1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));
}

double fprim(double s) {
	return beta * (1 - (f(s)*f(s)));
}

int main() {

	double ni = 0.4;
	double E;
	double taby[3];
	double tabx[3][5] = { { 1.0, 1.0, -2.0, 0.0, -1.0 },{ 1.0, 0.0, 1.5, -0.5, -1 },{ 1.0, -1.0, 1.0, 0.5, -1.0 } };
	double d[3] = { -1.0, -1.0, 1.0 };
	double wx[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double sum;

	do
	{
		E = 0.0;
		for (int p = 0; p < 3; p++) {
			sum = 0.0;
			for (int i = 0; i < 5; i++) {
				sum += tabx[p][i] * wx[i];
			}

			taby[p] = f(sum);

			for (int i = 0; i < 5; i++) {
				wx[i] = wx[i] + ni * (d[p] - taby[p])*fprim(sum)*tabx[p][i];
			}

			E += 0.5 * (d[p] - taby[p])*(d[p] - taby[p]);
		}

	} while (E > 0.003);

	std::cout << "dla x1: " << taby[0] << "   dla x2: " << taby[1] << "  dla x3: " << taby[2] << std::endl;

	system("pause");

	return 0;
}