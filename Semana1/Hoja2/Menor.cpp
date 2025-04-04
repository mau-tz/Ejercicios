#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

template<typename T>
T min(T a, T b, T c) {
	T menor = a;
	if (b < menor) menor = b;
	if (c < menor) menor = c;
	return menor;
}
int main() {
	int num1, num2, num3;
	cout << "Ingrese el primer numero: ";
	cin >> num1;
	cout << "Ingrese el segundo numero: ";
	cin >> num2;
	cout << "Ingrese el tercer numero: ";
	cin >> num3;
	cout << "El menor de los tres es: " << min(num1, num2, num3);
}