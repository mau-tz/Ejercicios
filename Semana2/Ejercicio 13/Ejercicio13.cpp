#include "pch.h"
#include <iostream>
using namespace std;
int sumaDivisores(int n, int i) {
	if (i == 0) return 0;
	if (n % i == 0) {
		return i + sumaDivisores(n, i - 1);
	}
	else {
		return sumaDivisores(n, i - 1);
	}
}

bool esPerfecto(int n) {
	return sumaDivisores(n,n-1) == n;
}
int main(){
    int n;
	cout << "Ingrese un numero: ";
	cin >> n;
	if (esPerfecto(n)) {
		cout << n << " es un numero perfecto." << endl;
	}
	else {
		cout << n << " no es un numero perfecto." << endl;
	}
}
