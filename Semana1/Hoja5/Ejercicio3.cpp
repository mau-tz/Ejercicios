#include "pch.h"
#include "iostream"
using namespace System;
using namespace std;

string invertirCadena(string palabra) {
    string invertido;
    for (int i = palabra.length() - 1; i >= 0; i--) {
        invertido += palabra[i];
    }
    return invertido;
}

int main() {
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    cout << "La cadena invertida es: " << invertirCadena(palabra) << endl;
}