/*
Función recursiva para calcular el factorial de un número.
*/

#include <iostream>

using namespace std;

int CalcularFactorial(int n)
{
	if (n == 0 || n == 1) return 1;
	else return n * CalcularFactorial(n - 1);
}

void main()
{
	int n;

	do
	{
		cout << "Ingrese un numero entero positivo: ";
		cin >> n;

		if (n <= 0)
		{
			cout << "El numero debe ser positivo. Intentelo nuevamente" << endl;
			system("pause");
			system("cls");
		}
	} while (n <= 0);
	
	int resultado = CalcularFactorial(n);
	cout << "El factorial de " << n << " es: " << resultado << endl;

	system("pause");
}