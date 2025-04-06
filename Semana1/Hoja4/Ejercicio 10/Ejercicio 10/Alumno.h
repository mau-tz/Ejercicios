#pragma once
#include <iostream>
#include <string>

using namespace std;

class Alumno
{
private:
	int edad;
	float promedio;
	int codigo;
	string nombre;
public:
	Alumno();
	~Alumno();

	// Getters
	int getEdad() const { return edad; }
	float getPromedio() const { return promedio; }
	int getCodigo() const { return codigo; }
	string getNombre() const { return nombre; }

	// Setters
	void setEdad(int e) { edad = e; }
	void setPromedio(float p) { promedio = p; }
	void setCodigo(int c) { codigo = c; }
	void setNombre(string n) { nombre = n; }
};

Alumno::Alumno() {}

Alumno::~Alumno() {}