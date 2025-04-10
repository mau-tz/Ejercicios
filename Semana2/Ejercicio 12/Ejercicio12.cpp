#include "pch.h"
#include <iostream>
using namespace std;

void decimalAHexadecimal(int numero) {
    if (numero == 0) return;
    decimalAHexadecimal(numero / 16);

    int resto = numero % 16;

    if (resto < 10) {
        cout << resto;
    }else {
        cout << static_cast<char>('A' + (resto - 10));
    }
}

int main() {
    int numero;
    cout << "Ingresa un numero decimal: ";
    cin >> numero;

    cout << "Equivalente en hexadecimal: ";
    if (numero == 0) {
        cout << 0;
    }else {
        decimalAHexadecimal(numero);
    }
}
