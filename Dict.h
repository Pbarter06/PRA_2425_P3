#ifndef DICT_H
#define DICT_H
#include <string>

using namespace std; 
template <typename V>
class Dict {
    public: 
        void insert(string key, V value); 
        V search(string key); 
        V remove(string key); 
        int entries(); 
};


#endif