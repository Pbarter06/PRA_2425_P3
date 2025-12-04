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

            int sum = 0; 

            for(int i = 0; i < n; i++){
                sum += int(key[i]); 
            }
            return sum % max; 

        }
            


    public:
        //METODOS

        //Constructor. Reservará memoria dinámica
        HashTable(int size){
            max = size; 
            n = 0; 
            table = new ListLinked<TableEntry<V>>[max]; 
            
        }

        //Destructor
        ~HashTable(){
            delete[] table;

        }

        //Devuelve el num total de cubetas de la tabla
        int capacity(){
            return max; 

        }

        //Sobrecarga global de << para imprimir el contenido de la tabla
        friend ostream& operator<<(ostream &out, const HashTable<V> &th){

            out << '{'; 
            for(int i = 0; i < th.max; i++){
                out << "Índice " << i << << ':' << th.table[i] << endl;
            }

        }

        //Sobrecarga de []. Devuelve el valor de key
        V operator[](string key){
            return search(key);

        }


        //HEREDADAS
         void insert(string key, V value) override{
            int index = h(key); 
            TableEntry<V> te(key, value); 

            int pos = table[index].search(te); 
            if(pos != -1){
                throw runtime_error("Clave ya existe");
            } table[index].append(te);
            n++; 
         }

         V search(string key)override {
            int index = h(key); 
            TableEntry<V> te(key);
            int pos = table[index].search(te);
            if(pos == -1){
                throw runtime_error("Clave no encontrada");
            }
            return table[index].get(pos).value;
            
         }

         V remove(string key) override {
            int index = h(key); 
            TableEntry<V> te(key); 
            int pos = table[index].search(te); 
            if(pos == -1){
                throw runtime_error("Clave no encontrada");
            }
            return table[index].remove(pos).value; 

         }

         int entries() override{
            return n; 

         }
        
};

#endif