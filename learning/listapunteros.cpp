#include <stdio.h>
#include <iostream>
using namespace std;

class ListaDinamica {
    private:
        int* elementos;
        int capacidad;
        int tamanio;
    
    public:
        // Constructor
        ListaDinamica(int _tamanio){
            capacidad = _tamanio;
            tamanio = 0;
            elementos = new int[capacidad];
        }
        void agregar(int elemento){
            if (tamanio == capacidad) {
                cout << "Lista llena en " << elemento << endl;
                duplicarCapacidad();
                // return;
            }
            elementos[tamanio] = elemento;
            tamanio++;
        }

        void duplicarCapacidad() {
            int nuevaCapacidad = capacidad * 2;
            int* nuevosElementos = new int[nuevaCapacidad];
            for (int i = 0; i < tamanio; i++) {
                nuevosElementos[i] = elementos[i];
            }
            delete[] elementos;
            elementos = nuevosElementos;
            capacidad = nuevaCapacidad;
            cout << "Capacidad duplicada a " << capacidad << endl;
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
            for (int i=0; i < tamanio; i++) {
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