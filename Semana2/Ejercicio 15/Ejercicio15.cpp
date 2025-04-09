#include "pch.h"
#include <iostream>
using namespace std;

// Desarrollar un algoritmo con recursividad, que permita mostrar lo números Fibonacci de
// acuerdo a un número ingresado por teclado Ejemplo, 6 = 1 1 2 3 5 8 13 21

int numeros[10001];

int fibonacci(int num) {
    if (num <= 0) return 0;
    if (numeros[num] != 0) return numeros[num];

    numeros[num] = fibonacci(num - 1) + fibonacci(num - 2);
    cout << " " << numeros[num];
    return numeros[num];
}

int main()
{
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;

    numeros[1] = numeros[2] = 1;
    cout << 1 << " " << 1;

    int prueba = fibonacci(num + 2);
}
