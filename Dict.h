#ifndef DICT_H
#define DICT_H
#include <string>

using namespace std; 
template <typename V>
class Dict {

    public: 
        //Inserta el par key -> value en el diccionario. Lanza excepción si key ya exixste 
        virtual void insert(string key, V value) = 0; 

        //Busca el valor de key
        virtual V search(string key) = 0; 

        //Elimina el par key-> value si se encuentra en el diccionario. Lanza una excepción si no existe
        virtual V remove(string key) = 0; 

        //Devuelve el num de elementos que tiene el Diccionario 
        virtual int entries() = 0; 
};


#endif