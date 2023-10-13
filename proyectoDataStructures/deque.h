#ifndef DEQUE_H
#define DEQUE_H

#include <string>
#include <iostream>

class Nodo
{
  public:
    long long dato; // Contiene el valor de la ip ordenamiento
    std::string line; // Contiene la linea original
    Nodo *siguiente; // Espacio de memoria
    Nodo *anterior; // Espacio de memoria

    long long octal1;
    long long octal2;
    long long octal3;
    long long octal4;

    //Constructor con parámetro
    Nodo(std::string line);
    //Destructor
    ~Nodo();

};


class ipDeque {

    public:
        Nodo* front;
        Nodo* rear;
        int size;
        int maxSize;

        ipDeque();
        

        void insertFront(std::string line); //creates the struct and inserts it in the front
        void insertRear(std::string line); //creates the struct and inserts it in the rear

        void deleteFront(); //deletes the struct in the front
        void deleteRear(); //deletes the struct in the rear

        bool isFull();
        bool isEmpty();

        void print(); // prints the Nodes
};

void ipSearch(ipDeque *d, long long keyi1, long long keyi2, long long keyi3, long long keyi4, long long keyf1, long long keyf2, long long keyf3, long long keyf4);
// Writes the selected elements of the deque in query.txt
// void writeIPQuery(ipDeque* deque, int key1, int key2, std::string fileName);



#endif