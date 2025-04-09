/*
Desarrollar un algoritmo con recursividad, donde permita ingresar un n�mero mayor a 3
d�gitos y realizar la multiplicaci�n de estos d�gitos.
*/

#include <iostream>

using namespace std;

int Multiplicar(int numero)
{
	if (numero < 10) // Caso base
	{
		return numero;
	}
	else
	{
		int digito = numero % 10; // Obtener el �ltimo d�gito
		int resto = numero / 10; // Eliminar el �ltimo d�gito
		return digito * Multiplicar(resto); // Multiplicar el d�gito con la multiplicaci�n del resto
	}
}

int main()
{
	int n;
	do
	{
		cout << "Ingrese un numero mayor a 3 digitos: ";
		cin >> n;

		if (n < 1000)
		{
			cout << "El numero no es mayor a 3 digitos. Intente nuevamente" << endl;
			system("pause");
			system("cls");
		}
	} while (n < 999);
	
	int resultado = Multiplicar(n);

	cout << "El resultado de la multiplicacion de los digitos es: " << resultado << endl;

	system("pause");
	return 0;
}