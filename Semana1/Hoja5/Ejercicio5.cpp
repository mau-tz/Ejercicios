#include "pch.h"
#include "iostream"
#include <algorithm>
using namespace System;
using namespace std;

bool esPalindromo(string cadena) {
    cadena.erase(remove_if(cadena.begin(), cadena.end(),
        [](char c) { return isspace(c) || !isalpha(c); }),
        cadena.end());

    int izquierda = 0;
    int derecha = cadena.length() - 1;

    while (izquierda < derecha) {
        if (tolower(cadena[izquierda]) != tolower(cadena[derecha])) {
            return false;
        }
        izquierda++;
        derecha--;
    }
    return true;
}

int main() {
    string palabra;
    cout << "ingrese la palabra: ";
    cin >> palabra;
	if (esPalindromo(palabra)){
		cout << "Es palindromo";
	}
	else {
		cout << "No es palindromo";
	}
}  