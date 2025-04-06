#define STACK_EXPLICIT_INSTANTIATION
#include "stack.h"

// Instanciaciones explícitas para tipos comunes
template class Stack<int>;          
template class Stack<float>;          
template class Stack<double>; 
template class Stack<char>;   
template class Stack<std::string>;  

// es necesario para poder anidar pila
template class Stack<Stack<int>>;   
template class Stack<Stack<float>>;   
template class Stack<Stack<double>>;   
template class Stack<Stack<char>>;   
template class Stack<Stack<std::string>>;   

