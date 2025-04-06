/*
Escriba un programa que permita procesar un archivo de texto que contiene un diccionario.
El  programa  deber�  pedirle  al  usuario  que  ingrese  las  primeras  n  letras  de  la  palabra  que  desea
buscar.  Luego  el  programa  mostrar�  todas  las  palabras  que  se  encuentren  en  el  archivo  de  texto
que comiencen con las letras ingresadas.
Usted  puede  asumir  que  cada  palabra  del  archivo  de texto  est�  en  una l�nea  nueva  de la  siguiente
manera:

abuelo
arbol
arbusto
barco
casa
zapato

Si el usuario ingresara ar, el programa deber�a mostrar arbol y arbusto, sin embargo si solo ingresara
la letra a, deber�a mostrar abuelo, arbol y arbusto.
Puede asumir que el diccionario no tiene acentos y que el usuario tampoco ingresar� acentos.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string palabra;
	string prefijo;
	ifstream archivo("Diccionario.txt");
	if (!archivo.is_open()) {
		cout << "Error al abrir el archivo." << endl;
		return 1;
	}
	cout << "Ingrese las primeras letras de la palabra que desea buscar: ";
	cin >> prefijo;
	cout << "Palabras que comienzan con '" << prefijo << "':" << endl;
	while (getline(archivo, palabra)) {
		if (palabra.substr(0, prefijo.length()) == prefijo) {
			cout << palabra << endl;
		}
	}
	archivo.close();

	system("pause");
	return 0;
}