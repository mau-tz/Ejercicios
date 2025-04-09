#include "pch.h"
#include <iostream>
using namespace std;

int main(){
	int num1, num2, num3, num4, num5;
	cout << "Ingresa el 1er numero: ";
	cin >> num1;
	cout << "Ingresa el 2edo numero: ";
	cin >> num2;
	cout << "Ingresa el 3ro numero: ";
	cin >> num3;
	cout << "Ingresa el 4to numero: ";
	cin >> num4;
	cout << "Ingresa el 5to numero: ";
	cin >> num5;
	auto menor = [](int x, int y, int z, int h, int g) {
		int menor = x;
		if (x > y) menor = y;
		if (x > z) menor = z;
		if (x > h) menor = h;
		if (x > g) menor = g;
		return menor;
		};

	cout << "El menor de todos: " << menor(num1, num2, num3, num4, num5);
}
