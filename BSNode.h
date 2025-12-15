#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:

        //ATRIBUTOS
        T elem; //elemento almacenado en el nodo
        BSNode<T>* left; //puntero al nodo sucesor izq
        BSNode<T>* right; //puntero al nodo sucesor der


        //MÉTODOS

        //Constructor: left y right -> Nulos por defecto 
        BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr){
            this->elem = elem; 
            this->left = left; 
            this->right = right; 
        }


        //Sobrecarga de << para imprimir el nodo por pantalla. -> El elemento 
        friend ostream& operator<<(outstream &out, const BSNode<T> &bsn){
            out << bsn.elem; 
            return out; 
        }


    
};

#endif