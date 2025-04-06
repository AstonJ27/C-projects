#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "../nodos/nodes.h"

template <class Elem>
class Queue {
private:
    Node<Elem>* front;
    Node<Elem>* back;
    int size;


public:
    Queue();
    Queue(const Queue<Elem>& q);
    ~Queue();

    void enqueue(Elem data);
    void dequeue();
    void clean();
    void copy(const Queue<Elem>& q);
    
    int getSize();
    bool isEmpty();
    Elem peek();
    bool compare(const Queue<Elem>& q);

    #ifdef DEBBUG_QUEUE
        void print() const;
    #endif
    


    void operator=(const Queue<Elem>& q);
    bool operator==(const Queue<Elem>& q);
    bool operator!=(const Queue<Elem>& q);

};

#if !defined(QUEUE_EXPLICIT_INSTANTIATION)
    #include "queue.tpp"
#endif

#endif