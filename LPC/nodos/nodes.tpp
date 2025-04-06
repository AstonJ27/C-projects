//°#################################|class Node|##################################
//?#################################|Builders|####################################

template<class Elem>
Node<Elem>::Node(){
    this->next = nullptr;
}

template<class Elem>
Node<Elem>::Node(Elem in){
    this->data = in;
    this->next = nullptr;
}

template<class Elem>
Node<Elem>::Node(Elem in, Node<Elem>* next){
    this->data = in;
    this->next = next;
}


//*##################################|Setters|##################################

template<class Elem>
void Node<Elem>::setData(Elem in){
    this->data = in;
}

template<class Elem>
void Node<Elem>::setNext(Node<Elem>* nex){
    this->next = nex;
}

//*##################################|Getters|##################################

template<class Elem>
Elem Node<Elem>::getData(){
    return(this->data);
}

template<class Elem>
Node<Elem>* Node<Elem>::getNext(){
    return(this->next);
}

//°#############################|class DoubleNode|##############################
//?#################################|Builders|##################################

template<class Elem>
DoubleNode<Elem>::DoubleNode(Elem in){
    this->data = in;
    this->next = nullptr;
    this->prev = nullptr;    
}

template<class Elem>
DoubleNode<Elem>::DoubleNode(Elem in, Node<Elem>* next){
    this->data = in;
    this->next = next;
    this->prev = nullptr;    
}

template<class Elem>
DoubleNode<Elem>::DoubleNode(Elem in, Node<Elem>* next, Node<Elem>* prev){
    this->data = in;
    this->next = next;
    this->prev = prev;    
}
//*##################################|Setters|##################################

template<class Elem>
void DoubleNode<Elem>::setPrev(Node<Elem>* in){
    this->prev = in;
}

template<class Elem>
void DoubleNode<Elem>::setNext(Node<Elem>* in){
    this->prev = in;
}

template<class Elem>
void DoubleNode<Elem>::setData(Elem in){
    this->data = in;
}


//*##################################|Getters|##################################

template<class Elem>
DoubleNode<Elem>* DoubleNode<Elem>::getPrev(){
    return(this->prev);
}

template<class Elem>
DoubleNode<Elem>* DoubleNode<Elem>::getNext(){
    return(this->next);
}

template<class Elem>
DoubleNode<Elem>* DoubleNode<Elem>::getData(){
    return(this->data);
}
