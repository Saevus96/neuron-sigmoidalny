#include<iostream>
#include<cmath>

double beta = 4.0;
double f(double s)
{	
	return(1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));
}
double fprim(double f) {
	return beta * (1 - f * f);
}

int main() {

	//wartosci
	double tabx1[4] = {1.0, -2.0, 0.0, -1.0};
	double tabx2[4] = { 0, 1.5, -0.5,-1 };
	double tabx3[4] = { -1, 1, 0.5, -1 };

	//wartosci oczekiwane
	double d1 = -1.0;
	double d2 = -1;
	double d3 = 1;

	//przypisanie wag 
	double wx1[4] = { 0.0,0.0,0.0,0.0 };
	double wx2[4] = { 0.0,0.0,0.0,0.0 };
	double wx3[4] = { 0.0,0.0,0.0,0.0 };

	//wpolczynnik uczenia
	double ni = 0.4;

	//blad 
	double E;
	double E1;
	double E2;
	double E3;	

	//wartosc funkcji
	double y1;
	double y2;
	double y3;

	//wartosc fprim
	double y1prim;
	double y2prim;
	double y3prim;

	//suma
	double sum;

	//krok programu
	int d = 0;
	do {

		//dla x1
		sum = 0;
		for (int i = 0; i < 4; i++) {
			sum = sum + tabx1[i] * wx1[i];
			y1 = f(sum);
			y1prim = fprim(y1);
			wx1[i] = wx1[i] + ni * (d1 - y1)*y1prim*tabx1[i];
			E1 = (0.5)*((d1 - y1)*(d1 - y1));
			d++;
		}

		//dla x2

		sum = 0;
		for (int i = 0; i < 4; i++) {
			sum = sum + tabx2[i] * wx2[i];
			y2 = f(sum);
			y2prim = fprim(y2);
			wx2[i] = wx2[i] + ni * (d2 - y2)*y2prim*tabx2[i];
			E2 = (0.5)*((d2 - y2)*(d2 - y2));
			d++;
		}

		//dla x3

		sum = 0;
		for (int i = 0; i < 4; i++) {
			sum = sum + tabx3[i] * wx3[i];
			y3 = f(sum);
			y3prim = fprim(y3);
			wx3[i] = wx3[i] + ni * (d3 - y3)*y3prim*tabx3[i];
			E3 = (0.5)*((d3 - y3)*(d3 - y3));
			d++;
		}
		d++;
		E = E1 + E2 + E3;
		
		if (E < 0.03) {
			std::cout << "Wynik dla x1: " << y1 << "  Wynik dla x2: " << y2 << "  Wynik dla x3: " << y3 << std::endl;
			std::cout << "Kroki programu:  " << d<<std::endl;
		}
	} while (E > 0.03);
	
	system("pause");
	return 0;
}