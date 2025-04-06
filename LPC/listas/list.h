#ifndef LIST_H
#define LIST_H
#include "../nodos/nodes.h"

template <class Elem>
class List{
    private:
        Node<Elem> *head, *tail;
        int size;
        
        //* Methods for merge sort
        Node<Elem>* split(Node<Elem>* head);
        Node<Elem>* merge(Node<Elem>* a, Node<Elem>* b, Node<Elem>** tailRef);
    public:
        //- constructors
        List();
        List(int size);     //? create a list with a designed size (in 0)
        
        //° copy constructor
        List(const List<Elem> &l);

        //- methods for change the list

        void insert(Elem e, int pos);
        void remove(int pos);
        void set(Elem e, int pos);
        void removeAllInstances(Elem e);
        void clean();
        void sort();
        void concat(List<Elem> l);
        void decat(int pos);
        void invert();
        void copy(List<Elem> l);

        //- query methods
        
        bool isEmpty();
        int getSize();
        Elem getMax();
        Elem getMin();
        int seek(Elem e);
        Elem query(int pos);
        List<Elem> getIntersection(List<Elem> l);    //? Intersection operation
        List<Elem> getUnion(List<Elem> l);           //? Union operation
        bool isSubList(List<Elem> l);                //? 
        List<Elem> getSubList(int start, int end);
        bool compare(const List<Elem>);

        //! Destructor
        ~List();

        //° operator overloading

        void operator=(const List<Elem>& l);     //° Assignment
        bool operator==(const List<Elem>& l);    //° Comparison
        bool operator!=(const List<Elem>& l);    //° Comparison 2
        Elem operator[](int pos);                //° Access

};

#if !defined(LIST_EXPLICIT_INSTANTIATION)
#include "list.tpp"
#endif
#endif //LIST_H
// rango