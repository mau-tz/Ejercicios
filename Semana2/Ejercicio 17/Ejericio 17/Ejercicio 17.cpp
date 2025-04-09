/*
Desarrollar un algoritmo con recursividad, que permita ingresar un número entero positivo,
para encontrar la suma de los dígitos pares del número entero. Luego se debe mostrar/imprimir
el resultado.
*/

#include <iostream>

using namespace std;

int SumarPares(int numero)
{
	if (numero < 10)
	{
		return numero;
	}
	else
	{
		int digito = numero % 10; int resto = numero / 10;

		if (digito % 2 == 0) return digito + SumarPares(resto);
		else return SumarPares(resto);
	}
}

int main()
{
	int n, resultado;

	do
	{
		cout << "Ingrese un numero entero positivo: ";
		cin >> n;

		if (n < 0)
		{
			cout << "El numero no es positivo, por favor ingrese un numero positivo." << endl;
			system("pause");
			system("cls");
		}
	} while (n < 0);

	resultado = SumarPares(n);

	if (resultado % 2 == 0) cout << "La suma de los digitos pares es: " << resultado << endl;
	else cout << "No habian nuemros pares para sumar" << endl;
-
	system("pause");
	return 0;
}