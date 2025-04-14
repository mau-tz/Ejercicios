/*
Implementar una funci�n recursiva que, dado un n�mero decimal, convierta a su
equivalente en el sistema binario.
*/

#include <iostream>

using namespace std;

void DecimalToBinario(int n) 
{
	if (n > 1) { DecimalToBinario(n / 2); }

	cout << n % 2;
}

void main() 
{
	double n;
	cout << "Ingrese un numero decimal: ";
	cin >> n;


	cout << "El numero en binario es: ";
	DecimalToBinario(n);
	cout << endl;

	system("pause");
}