#include "list.h"

//---------------------------------°| Class List |°----------------------------------//
//---------------------------------?| Builders |?----------------------------------//
template <class Elem>
List<Elem>::List(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class Elem>
List<Elem>::List(int size){
    Node<Elem>* newNode = new Node<Elem>(Elem());
    head = newNode;
    tail = newNode;
    this->size = size;
    for(int i = 1; i < size; i++){
        newNode = new Node<Elem>(Elem());
        this->tail->setNext(newNode);
        this->tail = newNode;
    }
    this->tail->setNext(nullptr);
}

template <class Elem>
List<Elem>::~List(){
    Node<Elem>* aux = head;
    
    while(aux != nullptr){
        Node<Elem>* next = aux->getNext();
        delete aux;
        aux = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}



//constructor copia
template <class Elem>
List<Elem>::List(const List<Elem> &l):head(nullptr), tail(nullptr), size(0){
    if(l.size > 0){
        Node<Elem> *aux = l.head;

        head = new Node<Elem>(aux->getData());
        tail = head;
        aux = aux->getNext();

        while(aux != nullptr){
            Node<Elem>* newNode = new Node<Elem>(aux->getData());
            tail->setNext(newNode);
            tail = newNode;
            aux = aux->getNext();
        }
        size = l.size;
        tail->setNext(nullptr);
        
    }
}
//---------------------------------| Modify list |----------------------------------//

template<class Elem>
void List<Elem>::insert(Elem e, int pos){
    Node<Elem>* newNode = new Node<Elem>(e);
    if(pos == 1){
        newNode->setNext(head);
        head = newNode;
        if(size == 0){
            tail = newNode;
        }
    }
    else if(pos <= size){
        Node<Elem>* aux = head;
        for(int i = 1; i < pos - 1; i++){
            aux = aux->getNext();
        }
        newNode->setNext(aux->getNext());
        aux->setNext(newNode);
    }else{
        newNode->setNext(nullptr);
        tail->setNext(newNode);
        tail = newNode;
    }
    size++;                        
}

template<class Elem>
void List<Elem>::remove(int pos){
    if(size == 0){
        return;
    }
    if(pos == 1){
        Node<Elem>* aux = head;
        head = head->getNext();
        if(size == 1){
            tail = nullptr;
        }
        delete aux;
    }else{
        Node<Elem>* aux = head;
        for(int i = 1; i < pos-1; i++){
            aux = aux->getNext();
        }
        Node<Elem>* aux2 = aux->getNext();
        aux->setNext(aux2->getNext());
        if(aux2 == tail){
            tail = aux;
        }
        delete aux2;   
    }
    size--;
}

template<class Elem>
void List<Elem>::set(Elem e, int pos){
    Node<Elem>* aux = head;
    for(int i = 1; i < pos; i++){
        aux = aux->getNext();
    }
    aux->setData(e);    
}

template<class Elem>
void List<Elem>::removeAllInstances(Elem e){
    //Eliminar ocurrencias al inicio
    while(head != nullptr && head->getData() == e){
        Node<Elem>* aux = head;
        head = head->getNext();
        delete aux;
        size--;
        if(head == nullptr) tail = nullptr;
    }

    if(head == nullptr) return;

    //Eliminar ocurrencias en el resto de la lista
    Node<Elem>* aux = head;
    while(aux->getNext() != nullptr){
        if(aux->getNext()->getData() == e){
            Node<Elem>* aux2 = aux->getNext();
            aux->setNext(aux2->getNext());
            delete aux2;
            size--;
            if(aux->getNext() == nullptr) tail = aux;
        }else{
            aux = aux->getNext();
        }
    }
}

template<class Elem>
void List<Elem>::clean(){
    Node<Elem>* aux = head;
    while(aux != nullptr){
        Node<Elem>* aux2 = aux;
        aux = aux->getNext();
        delete aux2;
    }
    head = tail = nullptr;
    size = 0;
}

template<class Elem>
void List<Elem>::invert(){
    if(size <= 1) return;
    
    Node<Elem>* prev = nullptr;
    Node<Elem>* current = head;
    Node<Elem>* next = nullptr;
    tail = head;
    
    while(current != nullptr){
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }
    head = prev;
}


//*O(n) 
template<class Elem>
void List<Elem>::concat(List<Elem> l){
    if(l.head == nullptr){
        return;
    }
    
    Node<Elem> *aux = l.head;
    
    while(aux != nullptr){  //O(n)
        insert(aux->getData(),size + 1); //O(1)
        aux = aux->getNext();
    }

}

//*O(n) 
template<class Elem>
void List<Elem>::decat(int pos){
    if(pos < 1 || pos > size){
        return;
    }
    
    Node<Elem>* aux = head;
    for(int i=1; i < pos; i++){
        aux = aux->getNext();
    }
    
    // Cortar la lista
    Node<Elem>* newTail = aux;
    aux = aux->getNext();
    newTail->setNext(nullptr);
    
    // Eliminar nodos restantes
    while(aux != nullptr){
        Node<Elem>* aux2 = aux;
        aux = aux->getNext();
        delete aux2;
        size--;
    }
    tail = newTail;
}

//*O(n) 
template<class Elem>
void List<Elem>::copy(List<Elem> l){
    clean();
    Node<Elem>* aux = l.head;
    while(aux != nullptr){
        insert(aux->getData(), size+1);
        aux = aux->getNext();
    }
}


//---------------------------------| Query methods |----------------------------------//

template<class Elem>
bool List<Elem>::isEmpty(){
    return size == 0;
}

template<class Elem>
int List<Elem>::getSize(){
    return size;
}

//verificar para solo numeros
template<class Elem>
Elem List<Elem>::getMax(){
    if(isEmpty()){
        throw std::logic_error("Lista vacia");
    }

    Elem max = head->getData();
    Node<Elem>* aux = head->getNext();
    while(aux != nullptr){
        if(aux->getData() > max){
            max = aux->getData();
        }
        aux = aux->getNext();
    }
    return max;
}

template<class Elem>
Elem List<Elem>::getMin(){
    if(isEmpty()) throw std::logic_error("Lista vacia");
    
    Elem min = head->getData();
    Node<Elem>* aux = head->getNext();
    while(aux != nullptr){
        if(aux->getData() < min){
            min = aux->getData();
        }
        aux = aux->getNext();
    }
    return min;
}

template<class Elem>
int List<Elem>::seek(Elem e){
    int pos = 1;
    Node<Elem>* aux = head;
    
    while(aux != nullptr){
        if(aux->getData() == e) return pos;
        aux = aux->getNext();
        pos++;
    }
    return -1;
}

template<class Elem>
Elem List<Elem>::query(int pos){
    if(pos == size){
        return this->tail->getData();
    }else if(pos == 1){
        return this->head->getData();
    }else{
        Node<Elem>* aux = head;
        for(int i = 1; i < pos; i++){
            aux = aux->getNext();
        }
        return aux->getData();
    }
}
//! cuidado O(n²)
template<class Elem>
List<Elem> List<Elem>::getIntersection(List<Elem> l){
    List<Elem> result;
    Node<Elem>* aux = head;
    while(aux != nullptr){
        Elem current = aux->getData();
        if(l.seek(current) != -1 && result.seek(current) == -1){
            result.insert(current, result.getSize()+1);
        }
        aux = aux->getNext();
    }
    return result;
}

//! cuidado O(n²)
template<class Elem>
List<Elem> List<Elem>::getUnion(List<Elem> l){
    List<Elem> result = *this; //??
    Node<Elem>* aux = l.head;
    
    while(aux != nullptr){
        Elem current = aux->getData();
        if(result.seek(current) == -1){
            result.insert(current, result.getSize()+1);
        }
        aux = aux->getNext();
    }
    return result;
}

//! cuidado O(n²)
template<class Elem>
bool List<Elem>::isSubList(List<Elem> l){
    if(l.isEmpty()){
        return true;  
    } 
    if(size < l.size){
        return false;
    }
    
    Node<Elem>* aux = head;
    for(int i = 1; i <= size - l.size+1; i++){
        Node<Elem>* aux1 = aux;
        Node<Elem>* aux2 = l.head;
        bool match = true;
        
        while(aux2 != nullptr){
            if(aux1 == nullptr || aux1->getData() != aux2->getData()){
                match = false;
                break;
            }
            aux1 = aux1->getNext();
            aux2 = aux2->getNext();
        }
        if(match){
            return true;  
        } 
        aux = aux->getNext();
    }
    return false;
}

//* O(n)
template<class Elem>
List<Elem> List<Elem>::getSubList(int start, int end){
    if(start < 1 || end > size || start > end){
        throw std::invalid_argument("Rango invalido");
    }
    
    List<Elem> sub;
    Node<Elem>* aux = head;
    for(int i=1; i<start; i++){
        aux = aux->getNext();
    }
    
    for(int i=start; i<=end; i++){
        sub.insert(aux->getData(), sub.getSize()+1);
        aux = aux->getNext();
    }
    return sub;
}
//* O(n)
template<class Elem>
bool List<Elem>::compare(const List<Elem> l){
    if(size != l.size){
        return false;
    } 
    
    Node<Elem>* aux1 = head;
    Node<Elem>* aux2 = l.head;
    while(aux1 != nullptr){
        if(aux1->getData() != aux2->getData()) {
            return false;
        }

        aux1 = aux1->getNext();
        aux2 = aux2->getNext();
    }
    return true;
}



//---------------------------------| Operadores |----------------------------------//

template<class Elem>
void List<Elem>::operator=(const List<Elem>& l){
    if(this != &l){
        clean();
        Node<Elem>* aux = l.head;
        while(aux != nullptr){
            insert(aux->getData(), size+1);
            aux = aux->getNext();
        }
    }
}

template<class Elem>
bool List<Elem>::operator==(const List<Elem>& l){
    return l.compare(*this);
}

template<class Elem>
bool List<Elem>::operator!=(const List<Elem>& l){
    return !l.compare(*this);
}

template <class Elem>
Elem List<Elem>::operator[](int pos){
    if(pos < 0 || pos > size){
        throw std::out_of_range("Posicion fuera de rango");
    }
    return query(pos);        
}


//----------------------------------°| MERGE SORT |°----------------------------------//

template <class Elem>
void List<Elem>::sort() {
    if(head == NULL || head->getNext() == NULL){
        return;
    }

    // Función de partición
    Node<Elem>* mid = split(head);
    
    // Ordenar recursivamente
    List<Elem> left, right;
    left.head = head;
    right.head = mid;
    left.sort();
    right.sort();
    

    Node<Elem>* newTail = NULL; // Necesario para actualizar tail
    // Mezclar y actualizar tail
    head = merge(left.head, right.head, &newTail);
    tail = newTail;

    left.head = NULL;
    right.head = NULL;
}


template <class Elem>
Node<Elem>* List<Elem>::split(Node<Elem>* head) {
    if(head == NULL){
        return NULL;
    }
    
    Node<Elem>* slow = head;
    Node<Elem>* fast = head->getNext();
    
    while(fast != NULL && fast->getNext() != NULL){
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    
    Node<Elem>* mid = slow->getNext();
    slow->setNext(NULL);
    return mid;
}

template <class Elem>
Node<Elem>* List<Elem>::merge(Node<Elem>* a, Node<Elem>* b, Node<Elem>** tailRef) {
    Node<Elem> dummy;
    Node<Elem>* current = &dummy;
    
    while(a != NULL && b != NULL){
        if(a->getData() <= b->getData()){
            current->setNext(a);
            a = a->getNext();
        }else{
            current->setNext(b);
            b = b->getNext();
        }
        current = current->getNext();
    }
    
    current->setNext((a != NULL) ? a : b);
    
    // Actualizar tail
    while(current->getNext() != NULL){
        current = current->getNext();
    }
    *tailRef = current;
    
    return dummy.getNext();
}