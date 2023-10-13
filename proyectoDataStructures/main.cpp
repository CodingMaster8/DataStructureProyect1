#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include "deque.h"

using namespace std;

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


