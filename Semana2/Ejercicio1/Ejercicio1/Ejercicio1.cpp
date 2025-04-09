#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	double num1, num2, num3;
	cout << "Ingresa el 1er numero: ";
	cin >> num1;
	cout << "Ingresa el 2edo numero: ";
	cin >> num2;
	cout << "Ingresa el 3ro numero: ";
	cin >> num3;
	auto raizcuadrada = [](double x) { return sqrt(x);};
	auto sumatoria = [](auto x, auto y, auto z) {return x + y + z;};
	cout << raizcuadrada(num1) << endl;
	cout << raizcuadrada(num2) << endl;
	cout << raizcuadrada(num3) << endl;

	cout << "La sumatoria de los tres numeros: " << sumatoria(raizcuadrada(num1), raizcuadrada(num2), raizcuadrada(num3));
}
