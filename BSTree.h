#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        //ATRIBUTOS 
        int nelem; //Num elementos almacenados en el ABB
        BSNode<T> *root; //Nodo raíz


        //MÉTODOS
        BSNode<T>* search(BSNode<T>* n, T e) const{
            if (n == nullptr){
                throw runtime_error("Element not found"); 
            }

            else if(n->elem < e){
                return search(n->right, e);
            }

            else if(n->elem > e){
                return search(n->left, e); 
            }

            else return n; 
        }

        /*Inserta el elemento e de tipo T de manera ordenada en el (sub)árbol cuya raíz es n.
        Devuelve el nodo que encabeza dicho (sub)árbol modificado*/
        BSNode<T>* insert(BSNode<T>* n, T e){
            //CASO BASE
            if (n == nullptr){
                return new BSNode(e);
            }

            //Ordenación
            else if(n->elem == e){
                throw runtime_error("Duplicated Element");
            }

            else if(n->elem < e){
                n->right = insert(n->right, e); 
            }

            else n->left = insert(n->left, e); 

            //Devolver root
            return n; 
        }


        /*Método recursivo que busca en el BST el orden y lo guarda en out*/
        void print_inorder(std::ostream &out, BSNode<T>* n) const{
            if (n != nullptr){
                print_inorder(out, n->left);
                out << n->elem << ' ';
                print_inorder(out, n->right);
            }
        }


        /*Método recursivo para la eliminación de elementos. Elimina e del (sub)árbol cuya raíz es n.
        Devuelve el nodo que encabeza dicho (sub)árbol modificado. 
        En caso de eliminar un nodo con dos sucesores (izquierdo y derecho), 
        aplicará la politica de reemplazo por el elemento máximo del subárbol izquierdo. 
        Lanza err si e no existe*/
        BSNode<T>* remove(BSNode<T>* n, T e){
            if (n == nullptr){
                throw runtime_error ("Elemento no encontrado"); 
            }

            else if (n->elem < e){
                n->right = remove(n->right, e); 
            }

            else if (n->elem > e){
                n->left = remove(n->left, e);
            }

            else {
                if (n->left != nullptr && n->der != nullptr){
                    n->elem = max(n->left); 
                    n->izq = remove_max(n->izq)
                } //2 desc

                else {
                    n = (n->izq != nullptr)? n->izq : n->der;
                } // 1 o 0 descendientes
            }
            return n; 
        }

        //devuelve el elemento de máximo valor contenido en el (sub-)árbol cuya raíz es n
        T max(BSNode<T>* n) const{
            if (n == nullptr){
                throw runtime_error ("Elemento no encontrado"); 
            }

            else if (n->der != nullptr){
                return max(n->der);
            }

            else return n.elem;
        }
        //elimina el elemento de máximo valor contenido en el (sub-)árbol cuya raíz es n
        BSNode<T>* remove_max(BSNode<T>* n){
            if (n->der == nullptr){
                return n->izq; 
            }

            else 
                n->der = remove_max(n->der); 
                return n; 
        }


        /*Método recursivo para la liberación de la memoria dinámica ocupada por 
        los BSNode<t> que confirman el (sub)árbol cuya raíz es n*/
        void delete_cascade(BSNode<T>* n){
            if (n != nullptr){
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n; 
            }
        }




    public: 

        //Constructor -> Crea un BST vacío
        BSTree(){
            nelem = 0; 
            root = nullptr;
        }

        //Devuelve el num de elementos del BST
        int size() const{
            return nelem; 
        }
        
        /*Busca y devuelve el elemento e en el BST.
        Actúa como método lanzadera del método privado recursivo search(BSNode<T>* n, T e).
        Deberá devolver el elemento contenido por el nodo devuelto por el método privado.*/
        T search(T e) const{
            return search(root, e).elem; 
        } //Es como un comprobador de que el elemento existe
        

        //Sobrecarga []. Actúa como interfaz al método search
        T operator[](T e) const{
            return search(e); 
        }

        /*Inserta el elemento e de manera ordenada en el BST. Método lanzadera del método privado*/
        void insert(T e){
            root = insert(root, e);
        }

        //Sobrecarga de << para mostrar los contenidos del BST, realizando un recorrido inorden ¡
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out, bst); 
            return out; 
        }


        //Elimina el elemento e del BST. 
        void remove(T e){
            root = remove(root, e);
        }

        //Destructor. Delega el método a privado
        ~BSTree(){
            delete_cascade(root);
        }

    
};

#endif