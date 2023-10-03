#include <vector>
#include <string>
#include <iostream>

#define ALFABETO 26



/*

Actividad 3.1 Implementación de "Tries" 

David González A01633817
Rogelio Guzman A01639914


La complejidad para el algoritmo de busqueda e insertar es O(n) en donde n es la 
longitud del string, ya que lo busca caracter por caracter

*/


// Definimos la clase del trie. Es un nodo que tiene un puntero a un arreglo de punteros para representar los nodos hijos
class TrieNode{
    public:
        TrieNode* children[ALFABETO];
        bool finalPalabra; // Flag para saber si es el fin de la palabra 

        TrieNode(){
            for (int i = 0; i < ALFABETO; i++) {
                this->children[i] = nullptr;
            }
            this->finalPalabra = false;
        }

        void insertar(std::string);
        bool buscar(std::string);

};


void TrieNode::insertar(std::string key){
    TrieNode* current = this;

    for(int i =0; i<key.length(); i++){
        int head = key[i] - 'a'; // Lo usamos para delimitar el arreglo y guardar un index dentro del rango del arreglo que creamos (26)
        if(current->children[head] == nullptr){ // Checamos si es nullptr en ese lugar, creamos un nuevo nodo para esa letra
            current->children[head] = new TrieNode();
        }

        current = current->children[head]; // Nos vamos moviendo por el nodo raiz, o el trie
    }

    current->finalPalabra = true; // Al final delcaramos el ultimo nodo como final de la palabra
    
}

bool TrieNode::buscar(std::string key){
    if(this == nullptr){
        return false;
    }

    TrieNode* current = this;
    for(int i=0; i< key.length(); i++){ // Hacemos una busqueda de profundidad con las letras de la palabra que queremos buscar
        int head = key[i] - 'a';
        current = current->children[head];

        if(current== nullptr){
            return false;  // Si llegamos a un nullptr, la palabra no existe y regresamos false
        }
    }

    return true; // Si salimos del for loop significa que recorrimos la palabra por DFS y no hubo problema. Si exsite. 
}


int main(){

   TrieNode* root = new TrieNode();
    int N;
    std::cout<<"N: ";
    std::cin>>N;

    int index = 0;
    while(index <N){
        std::string palabra;
        if(!(std::cin>> palabra)){
            std::cout << "invalido" << std::endl;
            return 1;
        }
        else{
            root->insertar(palabra);
            std::cout<<"Palabra agregada"<<std::endl;
            index++;
        }
    }

    index = 0;
    int M;
    std::cout<<"M: ";
    std::cin>>M;

    while(index < M){
        std::string buscar;
        if(!(std::cin>> buscar)){
            std::cout << "invalido" << std::endl;
            return 1;
        }
        else{
            std::cout<< root->buscar(buscar)<<std::endl;
            index++;
        }
    }
    

    

    return 0;
}