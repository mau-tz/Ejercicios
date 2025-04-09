/*
Ejercicios con funciones LAMBDA
Ingresar número de 4 dígitos enteros que permita indicar si los dos dígitos enteros de la derecha
es un número mayor a 50, y los dos números de la izquierda verificar si es impar.
*/

#include <iostream>

using namespace std;

int main()
{
	int n;

	do
	{
		cout << "Ingrese un numero de 4 digitos: ";
		cin >> n;

		if (n < 1000 || n > 9999)
		{
			cout << "El numero no es de 4 digitos. Intente nuevamente." << endl;
			system("pause");
			system("cls");
		}
	} while (n < 1000 || n > 9999);
	

	auto esMayor50 = [](int n) { 
		return (n % 100) > 50; 
		};
	auto esImpar = [](int n) { 
		return (n / 1000) % 2 != 0; 
		};

	if (esMayor50(n) && esImpar(n))
	{
		cout << "Los dos digitos de la derecha son mayores a 50 y los dos de la izquierda son impares." << endl;
	}
	else
	{
		cout << "No cumple con las condiciones." << endl;
	}

	system("pause");
	return 0;
}