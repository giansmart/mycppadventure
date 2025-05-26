
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class HashTable {
    private:
        int size;
        vector<string> bucket;
        // string bucket[];

    public:
        // Constructor
        HashTable(int _size){
            size = _size;
            bucket.resize(size);
        }

        int hashFunction(string key) {
            int sumAscii = 0;
            for (char c: key) {
                int charAscii = c;
                // cout << "Caracter: " << c << " -> ASCII: " << charAscii << endl;
                sumAscii += charAscii;
            }
            return sumAscii % size;

        }

        void put(string key, string value){
            int index = hashFunction(key);
            cout << "index: " << index << " for key: " << key << endl;
            bucket.at(index) = value;
        }

        void show() {
            for (int i = 0; i < bucket.size(); i++) {
                cout << "(i) " << i << " -> " << bucket[i] << endl;
            }
        }

        string get(string key) {
            int index = hashFunction(key);
            return bucket.at(index);
        }


};

int main() {
    HashTable ht(10);
    ht.put("name", "Alice");
    ht.put("age", "30");
    ht.put("city", "New York");
    ht.show();

    cout << "Value for 'name': " << ht.get("name") << endl;
    cout << "Value for 'age': " << ht.get("age") << endl;
    cout << "Value for 'city': " << ht.get("city") << endl;

    return 0;
}