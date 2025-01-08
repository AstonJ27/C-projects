#ifndef LIST_H
#define LIST_H
// this module makes a template of a generic list (but the elements only can be natives)
#include <iostream>

// class node for the linked list
template <class data>
class node{
    private:
        data info;
        node *next;
    //end atributes
    public:
        node(data); // Builder
        ~node(); // Destroyer
        data getData(); // getter method
        void setData(data); // setter method for change initial value
        node* getNext(); // getter method
        void setNext(node*); // setter method
    //end methods
};


template <class data>
class list{
    protected:
        node<data>* header;
        int size;
        
    public:
        list();
        ~list();
        void insert(data);
        void remove(int position); // remove an element in a specific position
        void print();
        int getSize();
        //void setSize(int);
};

class intList : public list<int>{
    public:
        int add(); //this method returns addition of every int in the list
        
        int multiply(); //this method returns product of every int in the list
        void increment(int); // this method add an int number to all elements of the list
        void decrement(int);
};

class stringList : public list<std::string>{
    public:
    std::string concatenate(bool space); //this method returns concatenation of every string in the list, with or without spaces
    bool isPalindrome(int position); // this method verify if a string of the list is palindrome in the specified position

};

#endif