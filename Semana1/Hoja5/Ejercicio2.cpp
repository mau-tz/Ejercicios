#include "pch.h"
#include "iostream"
using namespace System;
using namespace std;


int contarPalabras(const char* cadena) {
    if (cadena == nullptr || strlen(cadena) == 0) {
        return 0;
    }

    int contador = 1;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ' ') {
            contador++;
        }
    }
	return contador;    
}


int main(){
    char cadena[100];
    cout << "Ingrese la palabra: ";
	cin.getline(cadena, 100);
    cout << "La cadena contiene " << contarPalabras(cadena) << " palabras" <<endl;
}