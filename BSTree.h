#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int nelem; 
        BSNode<T> *root; //Nodo raíz

        BSNode<T>* search(BSNode<T>* n, T e) const{
            if (n == NULL){
                throw runtime_error("Element not found"); 
            }

            else if(n.e < e){
                return search(n.right, e);
            }

            else if(n.e > e){
                return search(n.left, e); 
            }

            else return n; 
        }

        BSNode<T>* insert(BSNode<T>* n, T e){
            if (n == NULL){
                return new BSNode(e);
            }

            else if(n.e == e){
                throw runtime_error("Duplicated Element");
            }

            else if(n.e < e){
                n.right = insert(n.right, e); 
            }

            else n.left = insert(n.left, e); 

            return n; 
        }

    public: 

        BSTree(){
            nelem = 0; 
            root = nullptr;
        }

        int size() const{
            return nelem; 
        }
        

        T search(T e) const{
            return search(root, e); 
        }

        T operator[](T e) const{
            return search(T e); 
        }

        void insert(T e){
            root = insert(root, e);
        }


        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            
        }
       
    
};

#endif