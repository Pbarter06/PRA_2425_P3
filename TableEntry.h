#ifndef TABLEENTRY_H
#define TABLEENTRY_H
using namespace std; 
#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
        //ATRIBUTOS 
        string key; 
        V value; 


        //METODOS

        //Constructor
        TableEntry(string key, V value){
            this->key = key; 
            this-> value = value; 
        }

        //Crea una entrada solo con clave (sin valor)
        TableEntry(string key){
            this->key = key; 
            this->value = V(); 
        }

        //Crea una entrada con clave "" (cadena vacía) y sin valor
        TableEntry(){
            this->key = ""; 
            this->value = V(); 
        }

        /*Sobrecarga global del operador == para determinar que dos 
        instancias de TableEntry son iguales solo si comparten la misma 
        clave (con independencia del valor).*/
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key == te2.key; 
        }


        /*Sobrecarga global del operador != para determinar que dos instancias 
        de TableEntry son diferentes solo si sus claves son distintas 
        (con independencia del valor)*/
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key != te2.key; 
        }

        /*Sobrecarga global del operador << para imprimir el contenido de la entrada 
        (par clave->valor) por pantalla. Recuerda incluir la cabecera <ostream> en el .h.*/
        friend ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
            out << '{' << te.key << ':' << te.value << '}'; 
            return out; 
        }
    
};

#endif