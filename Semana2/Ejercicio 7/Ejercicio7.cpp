#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;

// Ingresar número de 5 dígitos entero que permita verificar si el dígito del centro es un número
// par, por ejemplo : 34267, el 2 es un número par.

int main()
{
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    auto medioPar = [](int numero) {
        return (numero / 100) % 2 == 0;
        };


    if (medioPar(num)) cout << "El valor de medio es par";
    else cout << "El valor de medio es impar";
}