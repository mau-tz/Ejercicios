#include "pch.h"
#include <iostream>
using namespace std;

// Ingresar 3 números de tipo float donde permita indicar si los tres números son iguales o no

int main()
{
    float num1, num2, num3;

    cout << "Ingrese el primer numero: "; cin >> num1;
    cout << "Ingrese el segundo numero: "; cin >> num2;
    cout << "Ingrese el tercer numero: "; cin >> num3;

    auto iguales = [](float a, float b, float c) {
        if (a == b) return a == c;
        return false;
        };

    if (iguales(num1, num2, num3)) cout << "Los numeros son iguales";
    else cout << "Los numeros son distintos";

    return 0;
}
