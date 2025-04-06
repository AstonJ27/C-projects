#include "stack.h"

template <class Elem>
Stack<Elem>::Stack(){
    top = nullptr;
    size = 0;
}

template <class Elem>
Stack<Elem>::Stack(Elem first){
    top = new Node<Elem>(first);
    size = 1;
}

//??
template<class Elem>
Stack<Elem>::Stack(const Stack<Elem> &s):top(nullptr), size(0){
    this->copy(s);
}

//----------------------------| Methods for change the stack |---------------------------
template<class Elem>
void Stack<Elem>::push(Elem data){
    Node<Elem>* newNode = new Node<Elem>(data);
    newNode->setNext(top);
    top = newNode;
    size++;
}

template<class Elem>
void Stack<Elem>::pop(){
    if(top != nullptr){
        Node<Elem>* aux = top;
        top = top->getNext();
        delete aux;
        size--;
    }
}

template<class Elem>
void Stack<Elem>::clean(){
    while(top != nullptr){
        Node<Elem>* aux = top;
        top = top->getNext();
        delete aux;
    }
    size = 0;
}

template<class Elem>
void Stack<Elem>::copy(const Stack<Elem>&s){
    this->clean(); //Limpiar la pila actual
    
    //Crear pila temporal invertida para mantener el orden
    Stack<Elem> temp;
    Node<Elem>* aux = s.top;
    while(aux != nullptr){
        temp.push(aux->getData());
        aux = aux->getNext();
    }
    
    // Copiar los elementos manteniendo el orden original
    aux = temp.top;
    while(aux != nullptr){
        this->push(aux->getData());
        aux = aux->getNext();
    }
}

template<class Elem>
void Stack<Elem>::dumpInto(const Stack<Elem>&s){
    // Crear pila temporal invertida para mantener el orden
    Stack<Elem> temp;
    Node<Elem>* aux = s.top;
    while(aux != nullptr){
        temp.push(aux->getData());
        aux = aux->getNext();
    }
    
    // Volcar los elementos en la pila actual
    aux = temp.top;
    while(aux != nullptr){
        this->push(aux->getData());
        aux = aux->getNext();
    }
}
//----------------------------| Query methods |---------------------------

template<class Elem>
bool Stack<Elem>::isEmpty(){
    return top == nullptr;
}
template<class Elem>
Elem Stack<Elem>::peek(){
    if(top == nullptr){
        throw std::runtime_error("Pila vacía");
    }
    return top->getData();
        
}

template<class Elem>
int Stack<Elem>::getSize(){
    return size;
}

template<class Elem>
bool Stack<Elem>::compare(const Stack<Elem> &s){
    if(size != s.size){
        return false;
    }
    
    Node<Elem>* aux1 = top;
    Node<Elem>* aux2 = s.top;
    
    while(aux1 != nullptr){
        if(aux1->getData() != aux2->getData()){
            return false;
        }
        aux1 = aux1->getNext();
        aux2 = aux2->getNext();
    }
    return true;
}

//°---------------------------------|Destructor|------------------------------------
template<class Elem>
Stack<Elem>::~Stack(){
    clean();
    top = nullptr;
    size = 0;
}

//----------------------------Additional methods---------------------------

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template<class Elem>
void Stack<Elem>::merge(Stack<Elem> &s){
    Elem aux1, aux2;
    if(!this->isEmpty() && !s.isEmpty()){
        aux1 = this->peek();
        this->pop();
        aux2 = s.peek();
        s.pop();
        merge(s);

        this->push(aux1);
        this->push(aux2);
        s.push(aux2);
    
    }else if(this->isEmpty() && !s.isEmpty()){
        aux2 = s.peek();
        s.pop();
        merge(s);
        this->push(aux2);
        s.push(aux2);

    }else if(s.isEmpty() && !this->isEmpty()){
        aux1 = this->peek();
        this->pop();

        merge(s);
        
        this->push(aux1);
    }
}

template<class Elem>
void Stack<Elem>::reverse(){
    Node<Elem>* prev = nullptr;
    Node<Elem>* current = top;
    Node<Elem>* next = nullptr;
    
    while(current != nullptr){
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }
    top = prev;
}

//---------------------------------| Operadores |----------------------------------//
template<class Elem>
void Stack<Elem>::operator=(const Stack<Elem>& s){
    copy(s);
}

template<class Elem>
bool Stack<Elem>::operator==(const Stack<Elem>& s){
    return this->equals(s);
}

template<class Elem>
bool Stack<Elem>::operator!=(const Stack<Elem>& s){
    return !this->equals(s);
}