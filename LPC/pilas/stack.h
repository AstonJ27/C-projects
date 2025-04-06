#ifndef STACK_H
#define STACK_H
#include "../nodos/nodes.h"

template<class Elem>
class Stack{
    private:
        Node<Elem> *top;
        int size;
    public:
        //- constructors
        Stack();                //? Create an empty stack 
        Stack(Elem first);    //? Create a stack with first data 
        
        //° copy constructor
        Stack(const Stack<Elem> &s);

        //- methods for change the stack
        void push(Elem data);               //? Add data to the top of the stack
        void pop();                         //? Remove an element from stack
        void clean();                       //? Remove all elements from stack
        void copy(const Stack<Elem>&s);     //? Clean the stack and copy th argument
        void dumpInto(const Stack<Elem>&s); //? Drops all elements of the stack into the instance 
        void merge(Stack<Elem> &s);         //? Merge a stack whith the instance
        void reverse();                     //? Reverse the stack
        


        //-query methods
        bool isEmpty();             
        int getSize();
        Elem peek();
        bool compare(const Stack<Elem> &s);
                

        //! destructor
        ~Stack();

        // sobrecarga de operadores
        Stack<Elem> &operator=(const Stack<Elem> &s); //assignment
        bool operator==(const Stack<Elem> &s);      //is equal?
        bool operator!=(const Stack<Elem> &s);      //is 
        

    //EndClass
};


#if !defined(STACK_EXPLICIT_INSTANTIATION)
    #include "stack.tpp"
#endif


#endif //LIST_H