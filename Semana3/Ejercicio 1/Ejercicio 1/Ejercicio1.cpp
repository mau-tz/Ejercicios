/*
Para el Producto con las siguientes características: Id, descripción, precio, tipo envase.
1. Crear un método para eliminar de acuerdo posición: eliminarPos()
2. Crear un método para eliminar final: eliminarFinal()
3. Crear un método para ordenar los elementos de los nodos: ordenar()
4. Crear un nodo para poder mostrar el nodo mayor
*/

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void MostrarMenu();

int main()
{
    LinkedList lista;

    int cantidad, id, opc;
    double precio;
    string descripcion, tipoEnvase;
    
    do
    {
        cout << "Ingrese la cantidad de productos: ";
        cin >> cantidad; cin.ignore();
    } while (cantidad <= 0);
	
    system("cls"); 

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Producto N " << i + 1 << endl;
        cout << "--------------------------" << endl;
        cout << "Ingrese el id del producto: ";
        cin >> id; cin.ignore();
        cout << "Ingrese la descripcion del producto: ";
        getline(cin, descripcion);
        cout << "Ingrese el precio del producto: ";
        cin >> precio; cin.ignore();
        cout << "Ingrese el tipo de envase del producto: ";
        getline(cin, tipoEnvase);

        lista.anadirAlFinal(Producto(id, descripcion, precio, tipoEnvase));
        system("cls");
    }

    do
    {
		MostrarMenu();
		cin >> opc; cin.ignore();

        switch (opc)
        {
		case 1:
			cout << "Ingrese la posicion a eliminar: ";
			cin >> id; cin.ignore();
			lista.eliminarPosicion(id);
            system("pause");
			break;
		case 2:
			lista.eliminarFinal();
            system("pause");
			break;
		case 3:
			lista.ordenar();
            system("pause");
			break;
		case 4:
			lista.mostrarMayor();
            system("pause");
			break;
        case 5:
            lista.printLista();
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
    } while (opc != 6);

    lista.printLista();
	system("pause");
    return 0;
}

void MostrarMenu()
{
	cout << "1. Eliminar por posicion" << endl;
	cout << "2. Eliminar al final" << endl;
	cout << "3. Ordenar" << endl;
	cout << "4. Mostrar mayor" << endl;
    cout << "5. Mostrar lista" << endl;
	cout << "6. Salir" << endl;
	cout << "Ingrese una opcion: ";
}