/*
Escriba  una función  que permita  contar  la  cantidad  de  palabras que  existen  en una  cadena  de
caracteres.  Considere que no existen 2 espacios en blanco continuos.

Escriba un programa que permita contar la cantidad de palabras que existen en un archivo de texto.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream archivo("Texto.txt");
	string linea;
	int contador = 0;
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo." << endl;
		return 1;
	}
	while (getline(archivo, linea)) {
		// Contar palabras en la línea
		bool enPalabra = false;
		for (char c : linea) {
			if (c != ' ') {
				if (!enPalabra) {
					contador++;
					enPalabra = true;
				}
			}
			else {
				enPalabra = false;
			}
		}
	}
	archivo.close();
	cout << "Cantidad de palabras: " << contador << endl;

	system("pause");
	return 0;
}