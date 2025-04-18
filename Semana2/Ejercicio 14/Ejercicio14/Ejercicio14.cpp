#include "pch.h"
#include <iostream>
using namespace std;

// Desarrollar un algoritmo con recursividad, que permita mostrar si un número es primo.
// Ejemplo, 7 es primo.

bool esPrimo(int& num, int divisor) {
    if (num < divisor * 2) return true;
    else {
        if (num % divisor == 0) return false;
        else return esPrimo(num, divisor + 1);
    }

}

int main()
{
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    cout << num << " ";
    if (esPrimo(num, 2)) cout << "es primo";
    else cout << "no es primo";
}
