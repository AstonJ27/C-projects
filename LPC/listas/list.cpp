#define LIST_EXPLICIT_INSTANTIATION
#include "list.h"

// Instanciaciones explícitas para tipos comunes
template class List<int>;          
template class List<float>;          
template class List<double>; 
template class List<char>;   
template class List<std::string>;  

// es necesario para poder anidar listas
template class List<List<int>>;   
template class List<List<float>>;   
template class List<List<double>>;   
template class List<List<char>>;   
template class List<List<std::string>>;   

