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
        int max; //Tamaño de la tabla (Num total de Cubetas)
        ListLinked<TableEntry<V>>* table; //Tabla de cubetas; almacena pares clave ->valor. Se trata de un array de punterosa a listas enlazadas

        //METODOS

        /*Función hash que devuelve la posición (cubeta) en la tabla hash de key.  
        Se calculará como el resto de la divisón entre la suma de los valores ASCII 
        numéricos de los caracteres de la clave y el tamaño de la tabla hash*/
        int h(const string &key){

            unsigned long sum = 0;

            // recorrer los caracteres de la clave (no usar 'n' que es el nº de elementos)
            for (size_t i = 0; i < key.size(); i++) {
                sum += int(key.at(i));
            }
            return (sum % (unsigned long)(max));

        } /*at(i) de std::string permite obtener el carácter situado en la posición i de un string, 
           y la función int(c) permite obtener el valor ASCII numérico del carácter c.*/
            


    public:
        //METODOS


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

         V search(string key) override {
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


        //FIN HEREDADOS

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


        //Sobrecarga de []. Devuelve el valor de key. Lanza excepción si no existe.
        V operator[](string key){
            return search(key);

        }


        //Sobrecarga global de << para imprimir el contenido de la tabla
        friend ostream& operator<<(ostream &out, const HashTable<V> &th){

            out << '{'; 
            for(int i = 0; i < th.max; i++){
                out << "Índice " << i << ':' << th.table[i] << endl;
            }
            out << '}';
            return out;

        }

        

        
};

#endif