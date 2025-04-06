#include "pch.h"
#include "iostream"
using namespace System;
using namespace std;

int contarCaracterRepetido(string palabra, char letra) {
	int contador = 0;
	for (int i = 0; i < palabra.length(); i++) {
		if (palabra[i] == letra) {
			contador++;
		}
	}
	return contador;
}

int main() {
	string palabra;
	char letra;
	cout << "Ingrese una palabra: ";
	cin >> palabra;
	cout << "Ingrese un caracter: ";
	cin >> letra;
	cout << "El caracter " << letra << " se repite " << contarCaracterRepetido(palabra, letra) << " veces en la palabra." << endl;
}