/*
Escriba un programa que permita listar un archivo binario llamado "empleados.dat" que contiene la siguiente estructura:

char nombre[10];
int edad;
double salario;
*/

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

// Definicion de la estructura
struct Empleado
{
	char nombre[10];
	int edad;
	double salario;
};

// Variables globales
string nombresEmpleados[] = { "Juan", "Pedro", "Maria", "Ana", "Luis" };
int edadesEmpleados[] = { 25, 30, 22, 28, 35 };
double salariosEmpleados[] = { 2500.50, 3000.75, 2200.00, 2800.25, 3500.80 };

// Prototipos de funciones
void CrearArchivo();
void RellenarDatosAutomaticamente();

void main()
{
	CrearArchivo();
	RellenarDatosAutomaticamente();

	// Abrir el archivo en modo lectura
	ifstream nomArchivo;
	nomArchivo.open("empleados.dat", ios::in | ios::binary);
	if (nomArchivo.fail())
	{
		exit(1);
	}
	// Leer y mostrar los datos del archivo
	Empleado empleado;
	while (nomArchivo.read((char*)&empleado, sizeof(empleado)))
	{
		cout << "Nombre: " << empleado.nombre << ", Edad: " << empleado.edad << ", Salario: " << empleado.salario << endl;
	}
	nomArchivo.close();

	system("pause");
}

void CrearArchivo()
{
	ofstream nomArchivo;
	nomArchivo.open("empleados.dat", ios::out | ios::binary);
	if (nomArchivo.fail())
	{
		exit(1);
	}
	nomArchivo.close();
}

void RellenarDatosAutomaticamente()
{
	ofstream nomArchivo;
	nomArchivo.open("empleados.dat", ios::out | ios::binary);
	if (nomArchivo.fail())
	{
		exit(1);
	}
	Empleado empleado;
	for (int i = 0; i < 5; i++)
	{
		strcpy(empleado.nombre, nombresEmpleados[i].c_str());
		empleado.edad = edadesEmpleados[i];
		empleado.salario = salariosEmpleados[i];
		nomArchivo.write((char*)&empleado, sizeof(empleado));
	}
	nomArchivo.close();
}