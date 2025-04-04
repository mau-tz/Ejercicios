#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

template<typename T>
T suma(T a , T b) {
	return a + b;
}
template<typename T>

T resta(T a, T b) {
	return a - b;
}

template<typename T>
T multiplicacion(T a, T b) {
	return a * b;
}

template<typename T>
T division(T a, T b) {
	if (b == 0) cout << "Error Division por cero!" << endl;
	return a / b;
}
int main(){
	double num1, num2;

	cout << "Ingrese el primer numero: ";
	cin >> num1;
	cout << "Ingrese el segundo numero: ";
	cin >> num2;
	cout << "Suma: " << suma(num1, num2) << endl;
	cout << "Resta: " << resta(num1, num2) << endl;
	cout << "Multiplicacion: " << multiplicacion(num1, num2) << endl;
	cout << "Division: " << division(num1, num2) << endl;
}