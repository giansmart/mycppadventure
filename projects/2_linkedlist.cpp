#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
};

class LinkedList {
    public:
        Node* head;

        LinkedList(){
            head = nullptr;
        }

        void insertFront(int value){
            Node* newNode = new Node(value);
            if (head == nullptr){
                head = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        void insertEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            } 
            current->next = newNode;
        }

        void deleteNode(int value){
            if (head == nullptr) 
                return;
            if (head->data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* current = head;
            while(current->next != nullptr) {
                if (current->next->data == value) {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    return; // elimina solo la primera ocurrencia
                }
                current = current->next;
            }
        }

        void print() {
            Node* current = head;
            while(current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "null" << endl;
        }

};

int main() {
    cout << "Inicio de lista" << endl;
    LinkedList lista; // crea directamente en el stack
    lista.insertEnd(1);
    lista.insertEnd(3);
    lista.insertEnd(5);
    lista.insertFront(4);
    lista.insertFront(0);

    cout << "Fin de las inserciones" << endl;
    lista.print();

    cout << "\neliminando 5" << endl;
    lista.deleteNode(5);
    lista.print();
    return 0;
}