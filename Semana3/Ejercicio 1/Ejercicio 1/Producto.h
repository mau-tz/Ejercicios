#include <iostream>

using namespace std;

class Producto 
{
private:
    int Id;
    string descripcion;
    double precio;
    string tipoEnvase;
public:
    Producto(int _Id, string _descripcion, double _precio, string _tipoEnvase) : Id(_Id), descripcion(_descripcion), precio(_precio), tipoEnvase(_tipoEnvase) {}

    void print() {
        cout << "ID: " << Id << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Tipo de envase: " << tipoEnvase << endl;
    }

    double getPrecio() { return precio; }

    int getId() { return Id; }
};