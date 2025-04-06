/*
Escriba una función que permita hacer una copia de un archivo de texto. La función deberá recibir
el nombre del archivo de origen y el nombre del archivo destino.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CopiarArchivo(string, string);

void main()
{
	string nombreOrigen, nombreDestino;

	cout << "Ingrese el nombre del archivo de origen: ";
	getline(cin, nombreOrigen);
	cout << "Ingrese el nombre del archivo de destino: ";
	getline(cin, nombreDestino);

	CopiarArchivo(nombreOrigen, nombreDestino);
	cout << "Archivo copiado exitosamente." << endl;

	system("pause");
}

void CopiarArchivo(string nombreOrigen, string nombreDestino)
{
	ifstream archivoOrigen(nombreOrigen);
	ofstream archivoDestino(nombreDestino);
	if (!archivoOrigen.is_open())
	{
		cout << "Error al abrir el archivo de origen." << endl;
		return;
	}
	if (!archivoDestino.is_open())
	{
		cout << "Error al abrir el archivo de destino." << endl;
		return;
	}
	string linea;
	while (getline(archivoOrigen, linea))
	{
		archivoDestino << linea << endl;
	}
	archivoOrigen.close();
	archivoDestino.close();
}