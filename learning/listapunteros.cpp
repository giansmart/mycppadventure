#include <stdio.h>
#include <iostream>
using namespace std;

class ListaDinamica {
    private:
        int* elementos;
        int capacidad;
        int cantidad_actual;
    
    public:
        // Constructor
        ListaDinamica(int _tamanio){
            capacidad = _tamanio;
            cantidad_actual = 0;
            elementos = new int[capacidad];
        }
        void agregar(int elemento){
            if (cantidad_actual == capacidad) {
                cout << "Lista llena. No se pudo agregar " << elemento << endl;
                return;
            }
            elementos[cantidad_actual] = elemento;
            cantidad_actual++;
        }

        int obtener(int indice) {
            if (indice < 0 || indice >= capacidad) {
                cout << "Indice fuera de rango" << endl;
                return -1;
            }
            return elementos[indice];
        }

        void mostrar() {
            cout << "Elementos de la lista: ";
            for (int i=0; i < cantidad_actual; i++) {
                cout << elementos[i] << " ";
            }
        }

        // Destructor
        ~ListaDinamica() {
            delete[] elementos;
            cout << "\n\nMemoria liberada" << endl;
        }
};

int main(){
    ListaDinamica pares(3);
    pares.agregar(2);
    pares.agregar(4);
    pares.agregar(6);
    pares.agregar(8);

    pares.mostrar();

    return 0;
}