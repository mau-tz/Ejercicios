#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;

int main()
{
	int num1, num2, num3;
	cout << "Ingresa el 1er numero: ";
	cin >> num1;
	cout << "Ingresa el 2edo numero: ";
	cin >> num2;
	cout << "Ingresa el 3ro numero: ";
	cin >> num3;
	auto mayor = [](int x, int y, int z) {
		int mayor = x;
		if (y > x) mayor = y;
		if (z > x) mayor = z;
		return mayor;
		};
	cout << "El mayor de todos: " << mayor(num1, num2, num3);
}
