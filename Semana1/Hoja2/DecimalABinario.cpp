#include "pch.h"
#include "iostream"
#include "string"
using namespace System;
using namespace std;

template<typename T>
string decimalABinario(T num) {
	string binario = "";
	while (num > 0) {
		binario = to_string(num%2) + binario;
		num /= 2;
	}
	return binario;
}
int main() {
	int num;
	cout << "Ingrese el numero en sistema decimal: ";
	cin >> num;
	if (num < 0) {
		cout << "Por favor, ingrese un numero positivo." << endl;
	}
	else {
		cout << "El numero binario es: " << decimalABinario(num) << endl;
	}
}