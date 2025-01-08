#include "listas.h"
//////////////////////////////   NODE  /////////////////////////////////////
template <class data>
node<data>::node(data input){
    info = input;
    next = nullptr;
}

template <class data>
node<data>::~node(){}

template <class data>
data node<data>::getData(){
    return info;
}

template <class data>
void node<data>::setData(data){
    info = data;
}

template <class data>
node<data>* node<data>::getNext(){
    return next;
}

template <class data>
void node<data>::setNext(node<data>* nextNode){
    next = nextNode;
}

//////////////////////////////   LISTS  /////////////////////////////////////

template <class data>
list<data>::list(){
    header = nullptr;
    size = 0;
}

template <class data>
list<data>::~list(){
    while(header != nullptr){
        node<data> temp;
        temp = header;
        header = header->getNext();
        delete temp;
    }
}

template <class data>
void list<data>::insert(data value){
    node<data>* newNode = new node<data>(value);
    //if is void
    if(newNode == nullptr){
        cout << "Error asignando un nodo"
        return;
    }

    if(header == nullptr){
        header = newNode;
    }else{
        node<data>* temp = header;
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    size++;
}

template <class data>

void list<data>::remove(int position){
    if(position > size){
        cout << "Error: posición fuera de rango"
    }
    if(header == nullptr){
        cout << "Error, lista vacia"
        return;
    }else{
        int i = 1;
        node<data>* temp = header;
        // previous node
        while(i < position - 1){
            temp = temp->getNext();
            i++;
        }
        node<data>* temp2 = temp->getNext();
        temp->setNext(temp2->getNext());
        delete temp2;
        size--;
    }
}
    
template <class data>
void  list<data>::print(){
    node<data>* temp = header;
    while(temp != nullptr){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

template <class data>
int list<data>::getSize(){
    return size;
}

//////////////////////////////   INT LISTS  /////////////////////////////////////

int intList::add(){
    int value = 0;
    node<int>* temp = header;
    while(temp != nullptr){
        value = value + temp->getData();
        temp = temp->getNext();
    }
    return value;
}

int intList::multiply(){
    int value = 1;
    node<int>* temp = header;
    while(temp != nullptr){
        value = value * temp->getData();
        temp = temp->getNext();
    }
    return value;
}

void intList::increment(int add){
    node<int>* temp = header;
    while(temp != nullptr){
        temp->setData(temp->getData() + add);
        temp = temp->getNext();
    }   
}

void intList::decrement(int add){
    node<int>* temp = header;
    while(temp != nullptr){
        temp->setData(temp->getData() - add);
        temp = temp->getNext();
    }   
}

