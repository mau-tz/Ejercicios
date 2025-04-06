/*
Escriba un programa que permita listar al revés un archivo binario llamado "empleados.dat" que 
contiene la siguiente estructura: 
El archivo no deberá ser modificado. 

char nombre[10];
int edad;
double salario;
*/

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Empleado
{
	char nombre[10];
	int edad;
	double salario;
};

string nombresEmpleados[5] = { "Juan", "Pedro", "Maria", "Ana", "Luis" };
int edadesEmpleados[5] = { 25, 30, 28, 22, 35 };
double salariosEmpleados[5] = { 2500.50, 3000.75, 2800.00, 2200.25, 3500.80 };

void CrearArchivo();
void ListarArchivo();

void main()
{
	CrearArchivo();
	ListarArchivo();
	system("pause");
}

void CrearArchivo()
{
	ofstream archivo("empleados.dat", ios::binary);
	if (!archivo)
	{
		cout << "Error al crear el archivo." << endl;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		Empleado empleado;
		strncpy(empleado.nombre, nombresEmpleados[i].c_str(), sizeof(empleado.nombre));
		empleado.edad = edadesEmpleados[i];
		empleado.salario = salariosEmpleados[i];
		archivo.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
	}
	archivo.close();
	cout << "Archivo creado exitosamente." << endl;
}

void ListarArchivo()
{
	ifstream archivo("empleados.dat", ios::binary);
	if (!archivo)
	{
		cout << "Error al abrir el archivo." << endl;
		return;
	}
	archivo.seekg(0, ios::end);
	int tamano = archivo.tellg();
	int numEmpleados = tamano / sizeof(Empleado);
	archivo.seekg(0, ios::beg);
	Empleado empleado;
	for (int i = numEmpleados - 1; i >= 0; i--)
	{
		archivo.seekg(i * sizeof(Empleado), ios::beg);
		archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
		cout << "Nombre: " << empleado.nombre << ", Edad: " << empleado.edad << ", Salario: " << empleado.salario << endl;
	}
	archivo.close();
}