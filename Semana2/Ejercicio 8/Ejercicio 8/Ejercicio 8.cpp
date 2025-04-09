/*
Ejercicios lambda
Ingresar dos números para luego realizar la suma de estos y poder verificar si el número es
múltiplo de 3, por ejemplo 34 + 56 = 90, 90 es múltiplo de 3.
*/

#include "pch.h"
#include <iostream>
using namespace std;

// Funcion lambda para verificar si un numero es multiplo de 3
auto VerificarMultiploDeTres = [](int num) {
	return num % 3 == 0;
};

int main()
{
	int num1, num2, suma;
	cout << "Ingrese el primer numero: ";
	cin >> num1;
	cout << "Ingrese el segundo numero: ";
	cin >> num2;

	suma = num1 + num2;

	cout << "La suma de " << num1 << " y " << num2 << " es: " << suma << endl;

	// Verificamos si la suma es multiplo de 3
	if (VerificarMultiploDeTres(suma)) {
		cout << suma << " es múltiplo de 3." << endl;
	}
	else {
		cout << suma << " no es mltiplo de 3." << endl;
	}

    return 0;
}
