/*
Escriba un programa que devuelva las siguientes estadísticas con respecto a un archivo de texto:
(a)  Cantidad de caracteres (letras + espacios + símbolos)
(b)  Cantidad de letras
(c)  Cantidad de espacios
(d)  Cantidad de símbolos
(e)  Cantidad de vocales
(f)  Cantidad de mayúsculas
(g)  Cantidad  de  minúsculas
(h)  Frecuencia de letras.

Los resultados deberán ser escritos en un archivo de texto que tenga el mismo nombre del archivo
procesado y .estat.txt

Ejemplo:
(a)  Archivo a procesar: Datos.txt
(b)  Archivo de resultados: Datos.txt.estat.txt
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int totalCaracteres = 0;
    int totalLetras = 0;
    int totalEspacios = 0;
    int totalSimbolos = 0;
    int totalVocales = 0;
    int totalMayusculas = 0;
    int totalMinusculas = 0;
    int frecuenciaLetras[26] = { 0 }; 
    char c;
    string nombreArchivo;

    cout << "Ingrese el nombre del archivo a procesar: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (archivo.get(c)) {
        totalCaracteres++;

        if (isalpha(c)) {
            totalLetras++;

            // Convertir a minúscula para contar frecuencia
            char letraMinuscula = tolower(c);
            frecuenciaLetras[letraMinuscula - 'a']++;

            if (isupper(c)) {
                totalMayusculas++;
            }
            else {
                totalMinusculas++;
            }

            if (letraMinuscula == 'a' || letraMinuscula == 'e' || letraMinuscula == 'i' ||
                letraMinuscula == 'o' || letraMinuscula == 'u') {
                totalVocales++;
            }
        }
        else if (isspace(c)) {
            totalEspacios++;
        }
        else {
            totalSimbolos++;
        }
    }

    archivo.close();

    ofstream archivoSalida(nombreArchivo + ".estat.txt");
    if (!archivoSalida.is_open()) {
        cerr << "Error al crear el archivo de resultados." << endl;
        return 1;
    }

    archivoSalida << "(a) Cantidad de caracteres: " << totalCaracteres << endl;
    archivoSalida << "(b) Cantidad de letras: " << totalLetras << endl;
    archivoSalida << "(c) Cantidad de espacios: " << totalEspacios << endl;
    archivoSalida << "(d) Cantidad de simbolos: " << totalSimbolos << endl;
    archivoSalida << "(e) Cantidad de vocales: " << totalVocales << endl;
    archivoSalida << "(f) Cantidad de mayusculas: " << totalMayusculas << endl;
    archivoSalida << "(g) Cantidad de minusculas: " << totalMinusculas << endl;
    archivoSalida << "(h) Frecuencia de letras:" << endl;

    for (int i = 0; i < 26; i++) {
        char letra = 'a' + i;
        if (frecuenciaLetras[i] > 0) {
            archivoSalida << "    " << letra << ": " << frecuenciaLetras[i] << endl;
        }
    }

    archivoSalida.close();

    cout << "Estadisticas escritas en el archivo: " << nombreArchivo + ".estat.txt" << endl;

    system("pause");
    return 0;
}