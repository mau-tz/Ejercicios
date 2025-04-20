#include "Producto.h"

struct Nodo {
    Producto p;
    Nodo* next; // Guia a otro nodo

    Nodo(Producto _p) : p(_p) {
        next = nullptr;
    }
};

class LinkedList {
private:
    Nodo* head; // Producto que encabeza

public:
    LinkedList() {
        head = nullptr;
    }

    void anadirAlFinal(Producto nuevo) {
        Nodo* newNode = new Nodo(nuevo);

        if (head == nullptr) { // Verificamos si la cabeza esta vacia
            head = newNode;
            return;
        }

        Nodo* current = head; // Va a buscar hasta el final, por ello lo inicializamos como head
        while (current->next != nullptr) {
            current = current->next; // Pasa al siguiente
        }
        current->next = newNode;
    }

    void printLista() {
        Nodo* temp = head;
        if (head == nullptr) {
            cout << "No hay elementos" << endl;
            return;
        }
        while (temp != nullptr) {
            temp->p.print();
            cout << endl;
            temp = temp->next;
        }
    }

    void eliminarPosicion(int pos) {
        int contador = 2;

        if (head == nullptr) return;

        Nodo* current = head;

        if (pos == 1) {
            head = head->next;
            delete current;
            return;
        }

        while (current->next != nullptr) {
            if (contador == pos) {
                Nodo* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            contador++;
            current = current->next;
        }
    }

    void eliminarFinal() {
        Nodo* temp = head;
        if (head == nullptr) return;

        if (head->next == nullptr) {// si solo esta la cabeza
            delete head;
            head = nullptr;
            return;
        }

        while (temp->next->next != nullptr) {// recorre hasta el penultimo
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void ordenar() {
        bool swaap;
        Nodo* temp = head;
        Nodo* aux = nullptr;
        bool swapped;
        do {
            swapped = false;
            temp = head;
            while (temp->next != nullptr) {
                aux = temp->next;

                if (temp->p.getId() > aux->p.getId()) {
                    Producto tempProduct = temp->p;
                    temp->p = aux->p;
                    aux->p = tempProduct;

                    swapped = true;
                }


                temp = temp->next;
            }

        } while (swapped);
    }

    void mostrarMayor() {
        Nodo* current = head;
        if (head == nullptr) return;
        double mayorPrecio = 0;
        while (current != nullptr) {
            if (current->p.getPrecio() > mayorPrecio) {
                mayorPrecio = current->p.getPrecio();
            }
            current = current->next;
        }

        current = head;
        cout << "Productos con el mayor precio:" << endl;

        while (current != nullptr) {
            if (current->p.getPrecio() == mayorPrecio) {
                current->p.print();
                cout << endl;
            }
            current = current->next;
        }
    }

};