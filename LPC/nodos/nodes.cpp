#define NODE_EXPLICIT_INSTANTIATION
#include "nodes.h"

// Instanciaciones explícitas para tipos comunes
template class Node<int>;          
template class Node<std::string>;  
template class Node<float>;          
template class Node<double>;          
