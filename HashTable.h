#ifndef HASHTABLE_H
#define HASHTABLE_H
using namespace std; 
#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../../pract_1/PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:

        //ATRIBUTOS
        int n; //numero de elementos almacenados en la tabla 
        int max; //Tamaño de la tabla 
        ListLinked<TableEntry<V>>* table; //Tabla de cubetas; almacena pares clave ->valor

        //METODOS

        //devuelve la posicion en la tabla de key
        int h(string key){


        }
            


    public:
        //METODOS

        //Constructor. Reservará memoria dinámica
        HashTable(int size){
            
        }

        //Destructor
        ~HashTable(){

        }

        //Devuelve el num total de cubetas de la tabla
        int capacity(){

        }

        //Sobrecarga global de << para imprimir el contenido de la tabla
        friend ostream& operator<<(ostream &out, const HashTable<V> &th){

        }

        //Sobrecarga de []. Devuelve el valor de key
        V operator[](string key){

        }
        
};

#endif