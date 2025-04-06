/*
Escriba un programa que permita administrar una lista de Alumnos utilizando POO y que permita
almacenar y cargar la información desde un archivo.

Cada alumno deberá tener los siguientes datos:

(a)  Edad
(b)  Promedio
(c)  Codigo
(d)  Nombre

Considere como máximo 100 alumnos y además que no pueden existir alumnos con códigos repetidos.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "GestorAlumnos.h"

using namespace std;

void MostrarMenu();

int main()
{
    GestorAlumnos gestor;
    int opcion;
    string nombreArchivo = "alumnos.dat";

    // Cargamos los datos al inicio
    gestor.CargarDatos(nombreArchivo);

    do
    {
		system("cls");
        MostrarMenu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1: {
            if (gestor.getCantidadAlumnos() >= 100) {
                cout << "No se pueden agregar más alumnos. Límite alcanzado." << endl;
                break;
            }

            Alumno nuevoAlumno;
            int codigo, edad;
            float promedio;
            string nombre;

            cout << "Ingrese el código del alumno: ";
            cin >> codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Ingrese el nombre del alumno: ";
            getline(cin, nombre);

            cout << "Ingrese la edad del alumno: ";
            cin >> edad;

            cout << "Ingrese el promedio del alumno: ";
            cin >> promedio;

            nuevoAlumno.setCodigo(codigo);
            nuevoAlumno.setNombre(nombre);
            nuevoAlumno.setEdad(edad);
            nuevoAlumno.setPromedio(promedio);

            if (gestor.AgregarAlumno(nuevoAlumno)) {
                cout << "Alumno agregado con éxito." << endl;
            }
            break;
        }
        case 2: {
            int codigo;
            cout << "Ingrese el código del alumno a buscar: ";
            cin >> codigo;

            Alumno* alumno = gestor.BuscarAlumno(codigo);
            if (alumno != nullptr) {
                cout << "Alumno encontrado:" << endl;
                cout << "  Código: " << alumno->getCodigo() << endl;
                cout << "  Nombre: " << alumno->getNombre() << endl;
                cout << "  Edad: " << alumno->getEdad() << endl;
                cout << "  Promedio: " << alumno->getPromedio() << endl;
                system("pause");
            }
            else {
                cout << "No se encontró ningún alumno con ese código." << endl;
				system("pause");
            }
            break;
        }
        case 3: {
            int codigo;
            cout << "Ingrese el código del alumno a modificar: ";
            cin >> codigo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Alumno* alumno = gestor.BuscarAlumno(codigo);
            if (alumno != nullptr) {
                Alumno nuevosDatos;
                int nuevoCodigo, nuevaEdad;
                float nuevoPromedio;
                string nuevoNombre;

                cout << "Ingrese el nuevo código (actual: " << alumno->getCodigo() << "): ";
                cin >> nuevoCodigo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Ingrese el nuevo nombre (actual: " << alumno->getNombre() << "): ";
                getline(cin, nuevoNombre);

                cout << "Ingrese la nueva edad (actual: " << alumno->getEdad() << "): ";
                cin >> nuevaEdad;

                cout << "Ingrese el nuevo promedio (actual: " << alumno->getPromedio() << "): ";
                cin >> nuevoPromedio;

                nuevosDatos.setCodigo(nuevoCodigo);
                nuevosDatos.setNombre(nuevoNombre);
                nuevosDatos.setEdad(nuevaEdad);
                nuevosDatos.setPromedio(nuevoPromedio);

                if (gestor.ModificarAlumno(codigo, nuevosDatos)) {
                    cout << "Alumno modificado con éxito." << endl;
                    system("pause");
                }
            }
            else {
                cout << "No se encontró ningún alumno con ese código." << endl;
                system("pause");
            }
            break;
        }
        case 4: {
            int codigo;
            cout << "Ingrese el código del alumno a eliminar: ";
            cin >> codigo;

            if (gestor.EliminarAlumno(codigo)) {
                cout << "Alumno eliminado con éxito." << endl;
                system("pause");
            }
            break;
        }
        case 5:
            gestor.MostrarAlumnos();
            system("pause");
            break;
        case 6:
            gestor.GuardarDatos(nombreArchivo);
            system("pause");
            break;
        case 7:
            gestor.CargarDatos(nombreArchivo);
            system("pause");
            break;
        case 8:
            cout << "Guardando datos antes de salir..." << endl;
            gestor.GuardarDatos(nombreArchivo);
            cout << "¡Hasta luego!" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            system("pause");
        }

    } while (opcion != 8);

	return 0;
}

void MostrarMenu() 
{
    cout << "\n===== SISTEMA DE GESTION DE ALUMNOS =====" << endl;
    cout << "1. Agregar alumno" << endl;
    cout << "2. Buscar alumno" << endl;
    cout << "3. Modificar alumno" << endl;
    cout << "4. Eliminar alumno" << endl;
    cout << "5. Mostrar todos los alumnos" << endl;
    cout << "6. Guardar datos" << endl;
    cout << "7. Cargar datos" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opcion: ";
}