#include "pch.h"
#include "iostream"
using namespace System;
using namespace std;


int contarHastaCaracter(string palabra, char letra) {
    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] == letra) {
            return i + 1;
        }
    }
    return 0;
}
int main() {
    string palabra;
    char caracter;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    cout << "Ingrese un caracter: ";
    cin >> caracter;
    int resultado = contarHastaCaracter(palabra, caracter);

    if (resultado != 0) {
        cout << "Se encontraron " << resultado << " caracteres hasta " << caracter << endl;
    }
    else {
        cout << "El caracter '" << caracter << "' no se encuentra en la cadena." << endl;
    }
}