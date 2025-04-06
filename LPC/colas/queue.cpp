#define QUEUE_EXPLICIT_INSTANTIATION
#include "queue.h"

// Instanciaciones explícitas para tipos comunes
template class Queue<int>;          
template class Queue<float>;          
template class Queue<double>; 
template class Queue<char>;   
template class Queue<std::string>;  

// es necesario para poder anidar colas
template class Queue<Queue<int>>;   
template class Queue<Queue<float>>;   
template class Queue<Queue<double>>;   
template class Queue<Queue<char>>;   
template class Queue<Queue<std::string>>;   

