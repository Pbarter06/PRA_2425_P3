#include <bits/stdc++.h>
using namespace std; 
const int TABLE_SIZE = 10;


struct Bucket {
    string key;
    int value;
    bool used = false;
};

class HashTable {
private:
    Bucket table[TABLE_SIZE];

    int hashFunction(const string &key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % TABLE_SIZE;
    }

public:
    // Linear probing (si ocupado, avanza)
    void insert(const string &key, int value) {
        int index = hashFunction(key);

        while (table[index].used && table[index].key != key) {
            index = (index + 1) % TABLE_SIZE;  
        }

        table[index].key = key;
        table[index].value = value;
        table[index].used = true;
    }

    
    bool get(const string &key, int &outValue) {
        int index = hashFunction(key);

        //Buscamos el index correcto y ponemos en outValue value
        while (table[index].used) {
            if (table[index].key == key) {
                outValue = table[index].value;
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return false; //No encontrado
    }

    
    void remove(const string &key) {
        int index = hashFunction(key);

        while (table[index].used) {
            if (table[index].key == key) {
                table[index].used = false; //realmente no elimina nada, solo deja disponible la casilla
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
    }

};


int main(){



    return 0; 
}