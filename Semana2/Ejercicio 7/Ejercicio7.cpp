#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;

// Ingresar n�mero de 5 d�gitos entero que permita verificar si el d�gito del centro es un n�mero
// par, por ejemplo : 34267, el 2 es un n�mero par.

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