#include"pch.h"
#include <iostream>
using namespace std;

bool esPrimo(int num) {
    int numdivisores = 0;
    for (int i = num; i > 0; i--) {
        if (num % i == 0) {
            numdivisores++;
        }
    }
    return numdivisores == 2;
}

void mostrarPrimos(int num) {
    for (int i = num; i > 0; i--) {
        if (esPrimo(i)) {
            cout << "Numero primo: " << i << endl;
            mostrarPrimos(i - 1);
            break;
        }
    }
}

int main() {
    int num;
    do {
        cout << "Ingrese un numero: ";
        cin >> num;
    } while (num < 0 || num > 1000);
    mostrarPrimos(num);
}