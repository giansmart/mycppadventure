
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class HashTable {
    private:
        int size;
        // vector<string> bucket;
        string bucket[];

    public:
        // Constructor
        HashTable(int _size, string _element){
            size = _size;
            // bucket.resize()
            
        }

        void push(string element){
            // bucket.push_back(element);
            cout << "Elemento insertado: " << element << endl;
        }


};