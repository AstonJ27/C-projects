#ifndef _NODES_H
#define _NODES_H

#include <vector>
#include <stdexcept>
//-node linked once

template<class Elem>
class Node{
    private:
        Elem data;
        Node<Elem>* next;
    public:
    Node();                     //? builders
    Node(Elem in);
    Node(Elem in, Node* next);
    
    //* setters
    void setData(Elem);
    void setNext(Node<Elem>*);
    
    //* getters
    Elem getData();
    Node* getNext();
};
//-node linked twice

template<class Elem>
class DoubleNode{
    private:
        DoubleNode<Elem>* next;
	Elem data;
	DoubleNode<Elem>* prev;
    public:
    DoubleNode(Elem in);    //? builders
    DoubleNode(Elem in, Node<Elem>* next);
    DoubleNode(Elem in, Node<Elem>* next, Node<Elem>* prev);
    
    //*setters
    void setPrev(Node<Elem>* in);
    void setNext(Node<Elem>* in);
    void setData(Elem in);
    
    //*getters
    DoubleNode<Elem>* getPrev();
    DoubleNode<Elem>* getNext();
    DoubleNode<Elem>* getData();

};


#if !defined(NODE_EXPLICIT_INSTANTIATION)
#include "nodes.tpp"
#endif

#endif // NODES_H


//c++98