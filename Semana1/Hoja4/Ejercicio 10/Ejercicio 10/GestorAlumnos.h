#pragma once
#include <iostream>
#include <string>
#include "Alumno.h"

using namespace std;

class GestorAlumnos
{
private:
    Alumno listaAlumnos[100];
    int cantidadAlumnos;

    // Verificamos que el codigo no este duplicado
    bool codigoExiste(int codigo) 
    {
        for (int i = 0; i < cantidadAlumnos; i++) 
        {
            if (listaAlumnos[i].getCodigo() == codigo) 
            {
                return true;
            }
        }
        return false;
    }
public:
	GestorAlumnos();
	~GestorAlumnos();

    bool AgregarAlumno(const Alumno&);
    Alumno* BuscarAlumno(int);
    bool ModificarAlumno(int, const Alumno&);
    bool EliminarAlumno(int);
    void MostrarAlumnos();
    bool GuardarDatos(const string&);
    bool CargarDatos(const string&);

    int getCantidadAlumnos();
};

GestorAlumnos::GestorAlumnos() 
{
    cantidadAlumnos = 0;
}

GestorAlumnos::~GestorAlumnos() {}

int GestorAlumnos::getCantidadAlumnos() { return cantidadAlumnos; }

bool GestorAlumnos::AgregarAlumno(const Alumno& alumno) 
{
    if (cantidadAlumnos >= 100) 
    {
        cout << "Error: No se pueden agregar más alumnos. Límite alcanzado (100)." << endl;
        return false;
    }

    if (codigoExiste(alumno.getCodigo())) 
    {
        cout << "Error: Ya existe un alumno con el código " << alumno.getCodigo() << endl;
        return false;
    }

    listaAlumnos[cantidadAlumnos] = alumno;
    cantidadAlumnos++;
    return true;
}

Alumno* GestorAlumnos::BuscarAlumno(int codigo) 
{
    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        if (listaAlumnos[i].getCodigo() == codigo) 
        {
            return &listaAlumnos[i];
        }
    }
    return nullptr;
}

bool GestorAlumnos::ModificarAlumno(int codigo, const Alumno& nuevosDatos) 
{
    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        if (listaAlumnos[i].getCodigo() == codigo) 
        {
            // Si el código nuevo ya existe y no es el mismo del alumno a modificar
            if (nuevosDatos.getCodigo() != codigo && codigoExiste(nuevosDatos.getCodigo())) 
            {
                cout << "Error: El nuevo código ya existe." << endl;
                return false;
            }
            listaAlumnos[i] = nuevosDatos;
            return true;
        }
    }
    cout << "Error: No se encontró alumno con el código " << codigo << endl;
    return false;
}

bool GestorAlumnos::EliminarAlumno(int codigo) 
{
    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        if (listaAlumnos[i].getCodigo() == codigo) 
        {
            // Desplazar todos los elementos posteriores una posición hacia atrás
            for (int j = i; j < cantidadAlumnos - 1; j++) 
            {
                listaAlumnos[j] = listaAlumnos[j + 1];
            }
            cantidadAlumnos--;
            return true;
        }
    }
    cout << "Error: No se encontró alumno con el código " << codigo << endl;
    return false;
}

void GestorAlumnos::MostrarAlumnos() 
{
    if (cantidadAlumnos == 0) 
    {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    cout << "=== LISTA DE ALUMNOS ===" << endl;
    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        cout << "Alumno " << (i + 1) << ":" << endl;
        cout << "  Código: " << listaAlumnos[i].getCodigo() << endl;
        cout << "  Nombre: " << listaAlumnos[i].getNombre() << endl;
        cout << "  Edad: " << listaAlumnos[i].getEdad() << endl;
        cout << "  Promedio: " << listaAlumnos[i].getPromedio() << endl;
        cout << "------------------------" << endl;
    }
}

bool GestorAlumnos::GuardarDatos(const string& nombreArchivo) 
{
    ofstream archivo(nombreArchivo, ios::binary);

    if (!archivo) 
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        return false;
    }

    // Escribimos la cantidad de alumnos
    archivo.write(reinterpret_cast<char*>(&cantidadAlumnos), sizeof(cantidadAlumnos));

    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        int codigo = listaAlumnos[i].getCodigo();
        int edad = listaAlumnos[i].getEdad();
        float promedio = listaAlumnos[i].getPromedio();
        string nombre = listaAlumnos[i].getNombre();
        int longitudNombre = nombre.length();

        archivo.write(reinterpret_cast<char*>(&codigo), sizeof(codigo));
        archivo.write(reinterpret_cast<char*>(&edad), sizeof(edad));
        archivo.write(reinterpret_cast<char*>(&promedio), sizeof(promedio));
        archivo.write(reinterpret_cast<char*>(&longitudNombre), sizeof(longitudNombre));
        archivo.write(nombre.c_str(), longitudNombre);
    }

    archivo.close();
    cout << "Datos guardados con éxito en " << nombreArchivo << endl;
    return true;
}

bool GestorAlumnos::CargarDatos(const string& nombreArchivo) 
{
    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo) 
    {
        cout << "Error al abrir el archivo para lectura." << endl;
        return false;
    }

    // Leemos la cantidad de alumnos
    archivo.read(reinterpret_cast<char*>(&cantidadAlumnos), sizeof(cantidadAlumnos));

    // Leemos cada alumno
    for (int i = 0; i < cantidadAlumnos; i++) 
    {
        int codigo, edad, longitudNombre;
        float promedio;

        // Leemos los datos
        archivo.read(reinterpret_cast<char*>(&codigo), sizeof(codigo));
        archivo.read(reinterpret_cast<char*>(&edad), sizeof(edad));
        archivo.read(reinterpret_cast<char*>(&promedio), sizeof(promedio));
        archivo.read(reinterpret_cast<char*>(&longitudNombre), sizeof(longitudNombre));

        // Leemos el nombre
        char* nombreBuffer = new char[longitudNombre + 1];
        archivo.read(nombreBuffer, longitudNombre);
        nombreBuffer[longitudNombre] = '\0';
        string nombre(nombreBuffer);
        delete[] nombreBuffer;

        // Creamos el alumno y lo agregamos a la lista
        Alumno alumno;
        alumno.setCodigo(codigo);
        alumno.setEdad(edad);
        alumno.setPromedio(promedio);
        alumno.setNombre(nombre);

        listaAlumnos[i] = alumno;
    }

    archivo.close();
    cout << "Datos cargados con éxito desde " << nombreArchivo << endl;
    return true;
}