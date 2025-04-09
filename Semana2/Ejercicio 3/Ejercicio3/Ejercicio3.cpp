#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;

// Crear un lambda para determinar si la suma de 3 numeros es multiplo de 3

int main()
{
    int num1, num2, num3;
    cout << "Ingrese el primer numero: "; cin >> num1;
    cout << "Ingrese el segundo numero: "; cin >> num3;
    cout << "Ingrese el tercer numero: "; cin >> num2;

    auto multiplo3 = [](int a, int b, int c) {
        return (a + b + c) % 3 == 0;
        };

    cout << (num1 + num2 + num3) << " ";
    if (multiplo3(num1, num2, num3)) cout << "es multiplo de 3";
    else cout << "no es multiplo de 3";

    return 0;
}