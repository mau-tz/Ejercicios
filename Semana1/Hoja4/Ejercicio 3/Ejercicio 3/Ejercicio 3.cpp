/*
Escriba un  programa  que  elimine  de un  archivo  binario,  todos  los registros  que tengan  un  código
que tenga como primer dígito un número par.  La estructura del archivo es como sigue:

char codigo[8];
char nombre[20];
int edad;
*/

#include <iostream>
#include <fstream>

using namespace std;

struct Registro {
	char codigo[8];
	char nombre[20];
	int edad;
};

char codigos[10][8] = { "1234567", "2345678", "3456789", "4567890", "5678901", "6789012", "7890123", "8901234", "9012345", "0123456" };
char nombres[10][20] = { "Juan", "Pedro", "Maria", "Ana", "Luis", "Carlos", "Javier", "Sofia", "Laura", "Diego" };
int edades[10] = { 20, 25, 30, 35, 40, 45, 50, 55, 60, 65 };

void CrearArchivo();
void ListarRegistros();
void EliminarRegistros();

void main()
{
	CrearArchivo();
	ListarRegistros();
	EliminarRegistros();
	ListarRegistros();
	system("pause");
}

void CrearArchivo()
{
	ofstream archivo("registros.dat", ios::binary);
	if (!archivo) {
		cerr << "Error al crear el archivo." << endl;
		return;
	}
	for (int i = 0; i < 10; i++) {
		Registro reg;
		strcpy(reg.codigo, codigos[i]);
		strcpy(reg.nombre, nombres[i]);
		reg.edad = edades[i];
		archivo.write(reinterpret_cast<char*>(&reg), sizeof(Registro));
	}
	archivo.close();
	cout << "Archivo creado con exito." << endl;
}

void ListarRegistros()
{
	ifstream archivo("registros.dat", ios::binary);
	if (!archivo) {
		cerr << "Error al abrir el archivo." << endl;
		return;
	}
	Registro reg;
	cout << "Registros en el archivo:" << endl;
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) {
		cout << "Codigo: " << reg.codigo << ", Nombre: " << reg.nombre << ", Edad: " << reg.edad << endl;
	}
	archivo.close();
}

void EliminarRegistros()
{
	ifstream archivo("registros.dat", ios::binary);
	if (!archivo) {
		cerr << "Error al abrir el archivo." << endl;
		return;
	}
	ofstream temp("temp.dat", ios::binary);
	if (!temp) {
		cerr << "Error al crear el archivo temporal." << endl;
		return;
	}
	Registro reg;
	while (archivo.read(reinterpret_cast<char*>(&reg), sizeof(Registro))) {
		if ((reg.codigo[0] - '0') % 2 != 0) { // Si el primer dígito del código es impar
			temp.write(reinterpret_cast<char*>(&reg), sizeof(Registro));
		}
	}
	archivo.close();
	temp.close();
	remove("registros.dat");
	rename("temp.dat", "registros.dat");
	cout << "Registros eliminados con exito." << endl;
}