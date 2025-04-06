/*
Escriba una función que busque en un archivo de texto una palabra determinada y de encontrarla
devuelva el número de línea donde se encontró. Si no la encuentra devuelva -1. Considere que las
líneas del archivo de texto tienen como máximo 1024 caracteres.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream archivo("Texto.txt");
    string palabra;
    string linea;
    int numeroLinea = 0;
    int lineaEncontrada = -1;

    cout << "Ingresa una palabra para buscar: ";
    cin >> palabra;

    while (getline(archivo, linea))
    {
        numeroLinea++;
        if (linea.find(palabra) != string::npos)
        {
            lineaEncontrada = numeroLinea;
            break;
        }
    }

    archivo.close();

    if (lineaEncontrada != -1)
    {
        cout << "La palabra se encuentra en la linea: " << lineaEncontrada << endl;
    }
    else
    {
        cout << "La palabra no se encontró en el archivo." << endl;
    }

	system("pause");

    return 0;
}