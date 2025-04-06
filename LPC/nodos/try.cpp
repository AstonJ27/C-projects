#include "nodes.h"
#include <iostream>

struct Punto3D {
    double x, y, z;
};

int main(){
    // Create a new node
    Node<double>* head = new Node(1.5);
    Node<double>* a = new Node(2.4);
    //Node<int> a(2);
    Punto3D p= {1.5, 5.0,6.1};
    Node<Punto3D> *ph= new Node(p);
    p = {5.5, 7.0,0.1};
    Node<Punto3D> *ph2 = new Node(p);

    std::cout <<"hola"<<std::endl;
    head->setNext(a);
    ph->setNext(ph2);


    delete ph2;
    delete ph;

    delete a;
    delete head;

    return 0;
}