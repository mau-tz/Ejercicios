/*
Escriba una función que permita hacer una copia de un archivo de texto. La función deberá recibir 
el nombre del archivo de origen y el nombre del archivo destino. El archivo destino deberá tener 
todas las letras vocales convertidas a la letra ‘a’. 

Ejemplo:  arcoiris -> arcaaras 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CopiarArchivo(string, string);

int main()
{
	string origen, destino;
	cout << "Ingrese el nombre del archivo de origen: ";
	cin >> origen;
	cout << "Ingrese el nombre del archivo de destino: ";
	cin >> destino;
	CopiarArchivo(origen, destino);

	system("pause");
	return 0;
}

void CopiarArchivo(string archivoOrigen, string archivoDestino)
{
	ifstream origen(archivoOrigen);
	ofstream destino(archivoDestino);

	if (!origen.is_open())
	{
		cout << "Error al abrir el archivo de origen." << endl;
		return;
	}
	if (!destino.is_open())
	{
		cout << "Error al abrir el archivo de destino." << endl;
		return;
	}
	string linea;
	while (getline(origen, linea))
	{
		for (char& c : linea)
		{
			if (c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				c = 'a';
			}
		}
		destino << linea << endl;
	}
	origen.close();
	destino.close();
	cout << "Archivo copiado con vocales convertidas a 'a'." << endl;
}