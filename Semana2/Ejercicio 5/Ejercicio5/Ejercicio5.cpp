#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;

// Ingresar 1 caracter de tipo char donde permita verificar si es un número o letra. 

int main()
{
    char c;
    cout << "Ingrese un caracter para verificar si es un numero o caracter: ";
    cin >> c;

    auto esNumero = [](char a) {
        return (a >= '0' && a <= '9');
        };

    cout << c << " ";
    if (esNumero(c)) cout << "es un numero";
    else cout << "es un caracter";


    return 0;
}