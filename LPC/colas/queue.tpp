#ifndef QUEUE_TPP
#define QUEUE_TPP

#include "queue.h"
template <class Elem>
Queue<Elem>::Queue(){
    front = nullptr;
    back = nullptr;
}


//? copia
template <class Elem>
Queue<Elem>::Queue(const Queue<Elem>& q) : front(nullptr), back(nullptr), size(0){
    Node<Elem>* current = q.front;
    while(current != nullptr){
        enqueue(current->getData());
        current = current->getNext();
    }
}


//----------------------------| Methods for change the stack |---------------------------


template <class Elem>
Queue<Elem>::~Queue(){
    clean();
    front = nullptr;
    back = nullptr;
    size = 0;
}



//* O(1)
template <class Elem>
void Queue<Elem>::enqueue(Elem data){
    Node<Elem>* newNode = new Node<Elem>(data);
    if(isEmpty()){
        front = back = newNode;
    } else {
        back->setNext(newNode);
        back = newNode;
    }
    size++;
}

//* O(1)
template <class Elem>
void Queue<Elem>::dequeue(){
    if(!isEmpty()){
        Node<Elem>* aux = front;
        front = front->getNext();
        delete aux;
        size--;
        if(front == nullptr){
            back = nullptr;
        }
    }
}



//* O(n)
template <class Elem>
void Queue<Elem>::clean(){
    while(!isEmpty()){
        dequeue();
    }
}

//* O(1)
template <class Elem>
void Queue<Elem>::copy(const Queue<Elem>& q){
    clean();
    Node<Elem>* current = q.front;
    while(current != nullptr){
        enqueue(current->getData());
        current = current->getNext();
    }
}

//------------------------------------| Query methods |-----------------------------------//

//* O(1)
template <class Elem>
int Queue<Elem>::getSize(){
    return size;
}

//* O(1)
template <class Elem>
bool Queue<Elem>::isEmpty(){
    return front == nullptr;
}


//* O(1)
template <class Elem>
Elem Queue<Elem>::peek(){
    if(isEmpty()){
        throw std::runtime_error("Peek en cola vacía");
    }
    return front->getData();
}



//* O(n)
template <class Elem>
bool Queue<Elem>::compare(const Queue<Elem>& q){
    if(size != q.size){
        return false;
    }

    Node<Elem>* aux1 = front;
    Node<Elem>* aux2 = q.front;
    while(aux1 != nullptr){
        if(aux1->getData() != aux2->getData()){
            return false;
        }
        aux1 = aux1->getNext();
        aux2 = aux2->getNext();
    }
    return true;
}

#ifdef DEBBUG_QUEUE

template <class Elem>
void Queue<Elem>::print(){
    Node<Elem>* aux = front;
    
    while(aux != nullptr){
        std::cout << aux->getData() << " ";
        aux = aux->getNext();
    }
    std::cout << std::endl;
}

#endif

//* O(n)
template <class Elem>
void Queue<Elem>::operator=(const Queue<Elem>& q){
    copy();
}

//* O(n)
template <class Elem>
bool Queue<Elem>::operator==(const Queue<Elem>& q){
    return this->compare(q);
}


//* O(n)
template <class Elem>
bool Queue<Elem>::operator!=(const Queue<Elem>& q){
    return !this->compare(q);
}


#endif