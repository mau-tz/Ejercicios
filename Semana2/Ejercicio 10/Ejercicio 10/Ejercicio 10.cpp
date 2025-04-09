/*
Ejercicios con funciones Lambda
Ordene n numeros de manera ascendente utilizando una funcion lambda para definir el
criterio de ordenamiento.
*/

#include <iostream>
#include <vector>
#include <algorithm> // Para el sort

using namespace std;

int main()
{ 
	int n;
	
	do
	{
		cout << "Ingrese la cantidad de numeros a ordenar: ";
		cin >> n;

		if (n < 0)
		{
			cout << "La cantidad de numeros no puede ser negativa. Intente de nuevo." << endl;
			system("pause");
			system("cls");
		}	
	} while (n < 0);
	
	vector<int> numeros(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Ingrese el numero " << i + 1 << ": ";
		cin >> numeros[i];
	}

	// Ordenar el vector usando una funcion lambda
	sort(numeros.begin(), numeros.end(), [](int a, int b) 
		{
		return a < b;
		});

	cout << "Los numeros ordenados son: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << numeros[i] << " " << endl;
	}

	system("pause");
	return 0;
}