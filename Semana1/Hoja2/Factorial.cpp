#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

template<typename T>
T factorial(T n) {
	T resultado = 1;
	
	for (T i = 1; i <= n; i++){
		resultado *= i;
	}
	return resultado;
}

int main() {
	int num;
	cout << "Ingrese un numero: ";
	cin >> num;
	if (num < 0) {
		cout << "El factorial no esta definido para numeros negativos" << endl;
	}
	else {
		cout << "El factorial de " << num << " es: " << factorial(num);
	}
}