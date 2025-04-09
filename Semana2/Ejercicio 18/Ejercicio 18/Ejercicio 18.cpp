/*
Desarrollar un algoritmo con recursividad, que permita al usuario introducir una cadena de
texto numerica de mas de 4 dígitos y sume estos digitos individualmente.
*/

#include <iostream>
#include <string>

using namespace std;

int DescomponerAndSumar(string cadenaNumero)
{
	int suma = 0;
	if (cadenaNumero.length() == 0)
	{
		return 0;
	}
	else
	{
		suma = (cadenaNumero[0] - '0') + DescomponerAndSumar(cadenaNumero.substr(1));
		return suma;
	}
	return suma;
}

int main()
{
	int resultado;
	string cadena;

	do
	{
		cout << "Ingrese un numero positivo de 4 digitos: ";
		getline(cin, cadena);

		if (cadena.length() < 4)
		{
			cout << "El numero tiene menos de 4 digitos. Intente nuevamente" << endl;
			system("pause");
			system("cls");
		}
	} while (cadena.length() < 4);

	resultado = DescomponerAndSumar(cadena);

	cout << "La suma de los digitos es: " << resultado << endl;
	
	system("pause");
	return 0;
}