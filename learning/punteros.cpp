#include <iostream>

using namespace std;

int main() {
    int x = 50; //variable
    int* ptr = &x; //  puntero que guarda la dirección de x

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;
    cout << "Contenido del puntero ptr: " << ptr << endl;
    cout << "Valor apuntado por ptr: " << *ptr << endl;

    return 0;
}