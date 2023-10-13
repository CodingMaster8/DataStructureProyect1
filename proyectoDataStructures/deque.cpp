#include "deque.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

ipDeque::ipDeque(){
  this->maxSize = 100000;
  this->size = 0;
  front=nullptr;
  rear=nullptr;
}

bool ipDeque::isFull() {
    if (size == maxSize) {
        return true;
    }

    return false;
}

bool ipDeque::isEmpty() {
    if (size == 0) {
        return true;
    }

    return false;
}

//creates the struct and inserts it in the front
void ipDeque::insertFront(std::string line){
    Nodo *temp = new Nodo(line);
    if (front == nullptr){
        front = temp;
        rear = temp;
        size++;
    }else{
        Nodo *aux = front;
        while(aux != nullptr){
            if(temp->dato < aux->dato){
                if (aux == front){
                temp->siguiente = front;
                front->anterior = temp;
                front = temp;
                size++;
                break;
            }else{
                temp->siguiente = aux;
                temp->anterior = aux->anterior;
                aux->anterior->siguiente = temp;
                aux->anterior = temp;
                size++;
                break;
            }
        }else if (temp->dato > aux->dato){
            if (aux == rear){
                temp->anterior = rear;
                rear->siguiente = temp;
                rear = temp;
                size++;
                break;
            }else {
                aux = aux->siguiente;
            }
        }
     }     
   }
} 

//creates the struct and inserts it in the rear
void insertRear(std::string line){} 
void deleteFront(){} //deletes the struct in the front
void deleteRear(){} //deletes the struct in the rear

void ipDeque::print(){
    Nodo *aux = front;
    while(aux != nullptr){
        cout << aux->line<<endl;
        aux = aux->siguiente;
    }
}

void ipSearch(ipDeque *d, long long keyi1, long long keyi2, long long keyi3, long long keyi4, long long keyf1, long long keyf2, long long keyf3, long long keyf4){
    Nodo *aux = d->front;

    unsigned long long start = keyi1 * pow(10,9) + keyi2*pow(10,6) + keyi3*pow(10,3) + keyi4*pow(10,1);
    unsigned long long end = keyf1 * pow(10,9) + keyf2*pow(10,6) + keyf3*pow(10,3) + keyf4*pow(10,1);
    cout << start <<endl;
    cout << end << endl;

    ofstream outputfile("Query_ip.txt");
    outputfile<<aux->line<<endl;
    while (aux != nullptr)
    {
       if (aux->dato >= start && aux->dato <= end){
        cout<<aux->line<<endl;
        outputfile<<aux->line<<endl;
       }
       aux = aux->siguiente;
    }
    outputfile.close();
    outputfile.clear();
}

// NODO

Nodo::Nodo(std::string linea){
  this->siguiente = nullptr;
  this->anterior = nullptr;
  this->line = linea;
  string t = linea;
  char dot = '.';
  char space = ' ';
  char twoSpaces = ':';

  std::replace(t.begin(), t.end(), dot, space);
  std::replace(t.begin(), t.end(), twoSpaces, space);

  string month;
  string day;
  string hour;
  string min;
  string sec;
  string oct1;
  string oct2;
  string oct3;
  string oct4;
  string port;

  stringstream s(t);

  s>>month>>day>>hour>>min>>sec>>oct1>>oct2>>oct3>>oct4>>port;

  this->octal1 = stoll(oct1);
  this->octal2 = stoll(oct2);
  this->octal3 = stoll(oct3);
  this->octal4 = stoll(oct4);

  this->dato = octal1*pow(10,9) + octal2*pow(10,6) + octal3*pow(10,3) + octal4*pow(10,1);

}

Nodo::~Nodo(){
  delete siguiente;
  delete anterior;
}

int main() {
    ipDeque *d = new ipDeque();
    std::string line;
    std::ifstream myfile("errorLog.txt");
    if (myfile.is_open())
    {
    while(getline(myfile, line)) {
        d->insertFront(line);
        }
     //   line = "";
     //   lineCopy = "";
    myfile.close();

    ofstream outputfile("Ordered_ErrorLog.txt");
    Nodo *aux = d->front;
    while (aux != nullptr){
        outputfile<<aux->line<<endl;
        aux = aux->siguiente;
    }
    outputfile.close();
    }
    else {
        std::cout << "Unable to open file";
    }
    long long keyi1, keyi2, keyi3, keyi4, keyf1, keyf2, keyf3, keyf4;
    cout << "Enter initial octal 1" << endl;
    cin >> keyi1;
    cout << "Enter initial octal 2" << endl;
    cin >> keyi2;
    cout << "Enter initial octal 3" << endl;
    cin >> keyi3;
    cout << "Enter initial octal 4" << endl;
    cin >> keyi4;
    cout << "Enter final octal 1" << endl;
    cin >> keyf1;
    cout << "Enter final octal 2" << endl;
    cin >> keyf2;
    cout << "Enter final octal 3" << endl;
    cin >> keyf3;
    cout << "Enter final octal 4" << endl;
    cin >> keyf4;
    
    ipSearch(d, keyi1, keyi2, keyi3, keyi4, keyf1, keyf2, keyf3, keyf4);
    return 0;
    }


