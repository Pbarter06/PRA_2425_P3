#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree; //BST con elementos de tipo TableEntry<V> 

    public:

        //Constructor -> Crea un diccionario vacío con memoria dinámica
        BSTreeDict(){
            tree = new BSTree<TableEntry<V>>();
        }

        //Destructor -> Libera la memoria dinámica ocupada por el BST
        ~BSTreeDict(){
            delete tree;
        }

        /*Sobrecarga global del operador <<  para imprimir el contenido del 
        Diccionario por pantalla*/
        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            out << *(bs.tree);  //Mirar sobrecarga de << en TableEntry y BSTree
            return out;
        }

        /*Sobrecarga del operador []. 
        Actúa como interfaz al método de interfaz heredado*/
        V operator[](string key){
            return search(key);
        }

        
        //HEREDADOS
        
        //Inserta el par key -> value en el diccionario. Lanza excepción si key ya exixste 
        void insert(string key, V value) override {
            TableEntry<V> te(key, value); 
            tree->insert(te);
        }

        //Busca el valor de key
        V search(string key) override {
            TableEntry<V> te(key); 
            return tree->search(te).value;

        }

        //Elimina el par key-> value si se encuentra en el diccionario. Lanza una excepción si no existe
        V remove(string key) override {
            TableEntry<V> te(key); 
            V val = tree->search(te).value; 
            tree->remove(te); 
            return val;

        }

        //Devuelve el num de elementos que tiene el Diccionario 
        int entries() override {
            return tree->size();

        }

        //FIN HEREDADOS
};

#endif