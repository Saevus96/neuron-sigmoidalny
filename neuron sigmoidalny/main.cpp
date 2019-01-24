#include <iostream>
#include <math.h>

double beta = 0.6;

double f(double s) {
	return (1 - exp(-beta * s)) / (1 + exp(-beta * s));
}

double f1(double s) {
	return beta * (1 - f(s)*f(s));
}

int main()
{

	double tabx1[5] = { 1,-2, 0,-1, 1 }; //x1
	double tabx2[5] = { 0,1.5,-0.5,-1,1 }; //x2
	double tabx3[5] = { -1,1,0.5,-1,1 }; //x3

	//waga
	double wx1[5] = { 0, 0, 0, 0, 0 };
	double wx2[5] = { 0, 0, 0, 0, 0 };
	double wx3[5] = { 0, 0, 0, 0, 0 };

	//wartosci oczekiwane
	double d1 = -1;
	double d2 = -1;
	double d3 = 1;

	//wspó³czynnik uczenia
	double ni = 0.4;

	double y1 = 0;
	double y2 = 0;
	double y3 = 0;
	double suma1 = 0;
	double suma2 = 0;
	double suma3 = 0;

	//b³ad
	double E;
	double E1;
	double E2;
	double E3;

	do {
		E = 0;

		for (int i = 0; i < 5; i++)
		{
			suma1 += tabx1[i] * wx1[i];
			suma2 += tabx2[i] * wx2[i];
			suma3 += tabx3[i] * wx3[i];
		}

		y1 = f(suma1);
		y2 = f(suma2);
		y3 = f(suma3);

		for (int i = 0; i < 5; i++)
		{
			wx1[i] = wx1[i] + ni * (d1 - f(suma1)) * f1(y1) * tabx1[i];
			wx2[i] = wx2[i] + ni * (d2 - f(suma2)) * f1(y2) * tabx2[i];
			wx3[i] = wx3[i] + ni * (d3 - f(suma3)) * f1(y3) * tabx3[i];
		}

		E1 = 0.5 * (d1 - y1)*(d1 - y1);
		E2 = 0.5 * (d2 - y2)*(d2 - y2);
		E3 = 0.5 * (d3 - y3)*(d3 - y3);

		E = E1 + E3 + E2;



	} while (E >= 0.0003);

	std::cout << "wynik dla tabx1: " << y1 <<" Wynik dla tabx2: "<<y2<<"  Wynik dla tabx3: "<<y3<< std::endl;
	




	system("PAUSE");
	return 0;
}