#include <iostream>
#include <stdexcept>
#include "list.h"

using namespace std;

// Función auxiliar para imprimir elementos individuales
template<typename T>
void printElement(const T& element) {
    cout << element;
}

// Función auxiliar para imprimir listas (maneja recursión para listas anidadas)
template<typename U>
void printElement(List<U>& element) {
    cout << "[";
    int m = element.getSize();
    for(int j = 1; j <= m; ++j) {
        printElement(element[j]);
        if(j < m) {
            cout << ", ";
        }
    }
    cout << "]";
}

// Función para imprimir cualquier lista (modificada para usar query y no modificar la lista)
template<class T>
void printList(List<T> list, const string& name) {
    cout << name << " (" << list.getSize() << " elementos): [";
    int n = list.getSize();
    for(int i = 1; i <= n; ++i) {
        T element = list[i];
        printElement(element);
        if(i < n) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}



int main(){
    string mensaje = "esto es una prueba\n";
    try{
        // Test 1: Constructor por defecto y isEmpty
        List<int> list1;
        cout << "\n=== Test 1: Lista vacia ===" << endl;
        printList(list1, "list1");
        cout << "list1 vacia? " << (list1.isEmpty() ? "SI" : "NO") << endl;

        // Test 2: Insertar elementos
        cout << "\n=== Test 2: Inserciones ===" << endl;
        list1.insert(10, 1); printList(list1, "insertar al inicio");// Insertar en lista vacia
        list1.insert(30, list1.getSize()+1); printList(list1, "insertar al final");// Insertar al final
        list1.insert(20, list1.getSize()/2+1); printList(list1, "insertar en el medio");// Insertar en medio
        list1.insert(40, list1.getSize()+1); printList(list1, "insertar al final");// Insertar al final
        list1.insert(5, 1);  printList(list1, "insertar al inicio");// Insertar al inicio
        printList(list1, "list1 despues inserciones");
        
        
        // Test 3: Remover elementos
        cout << "\n=== Test 3: Remociones ===" << endl;
        list1.remove(1);     printList(list1, "inicio removido");// Remover inicio
        list1.remove(4);     printList(list1, "final removido");// Remover final
        list1.remove(2);     printList(list1, "centro removido");// Remover medio
        printList(list1, "list1 despues remociones");

        // Test 4: Modificar elementos
        cout << "\n=== Test 4: Modificaciones ===" << endl;
        list1.set(100, 1);  printList(list1, "modificar 1");
        list1.set(200, 2);  printList(list1, "modificar 2");
        printList(list1, "list1 despues modificaciones");
    
        // Test 5: Copiar lista
        cout << "\n=== Test 5: Constructor Copia de lista ===" << endl;
        List<int> list2(list1);
        list2.insert(300, 3);
        printList(list1, "list1 original");
        printList(list2, "list2 copia modificada");
        
        // Test 6: Operador asignación
        cout << "\n=== Test 6: Asignacion ===" << endl;
        List<int> list3;
        list3 = list1;
        list3.insert(400, 3);
        printList(list1, "list1 original");
        printList(list3, "list3 asignada modificada");

        // Test 7: Maximo y minimo
        //list1.insert(900, list1.getSize()+1);  // Insertar al final
        cout << "\n=== Test 7: Max/Min ===" << endl;
        cout << "Max list1: " << list1.getMax() << endl;
        cout << "Min list1: " << list1.getMin() << endl;


        // Test 8: Busquedas
        cout << "\n=== Test 8: Busquedas ===" << endl;
        cout << "Posicion de 200: " << list1.seek(200) << endl;
        cout << "Posicion de 999: " << list1.seek(999) << endl;
        
        // Test 9: Ordenamiento omision
        cout << "\n=== Test 9: Ordenamiento ===" << endl;
        list1.insert(150, 4);
        list1.insert(50, 2);
        cout << "Antes de ordenar: ";
        printList(list1, "list1");
        list1.sort();
        cout << "Despues de ordenar: ";
        printList(list1, "list1");
        //cout << "list1 vacia? " << (list1.isEmpty() ? "SI" : "NO") << endl;

        // Test 10: Interseccion y Union
        cout << "\n=== Test 10: Operaciones conjunto ===" << endl;
        List<int> list4;
        list4.insert(100, 1);
        list4.insert(150, 2);
        list4.insert(300, 3);
        printList(list1, "Lista 1");
        printList(list4, "Lista 4");
        
        List<int> inter = list1.getIntersection(list4);
        List<int> uni = list1.getUnion(list4);
        printList(inter, "Interseccion");
        printList(uni, "Union");

        // Test 11: SubLista
        cout << "\n=== Test 11: SubLista ===" << endl;
        List<int> sub = list1.getSubList(2, 3);
        printList(sub, "Sublista 2-3");
        cout << "Es sublista? " << (list1.isSubList(sub) ? "SI" : "NO") << endl;

        // Test 12: Inversion
        cout << "\n=== Test 12: Invertir ===" << endl;
        list1.invert();
        printList(list1, "Lista invertida");

        // Test 13: Concatenacion
        cout << "\n=== Test 13: Concatenacion ===" << endl;
        List<int> list5;
        list5.insert(8, 1);
        list5.insert(314, 2);
        list1.concat(list5);
        printList(list1, "Lista concatenada");
        printList(list5, "Lista fuente");

        // Test 14: Deconcatenacion
        cout << "\n=== Test 14: Deconcatenacion ===" << endl;
        list1.decat(3);
        printList(list1, "Lista decat(3)");

        // Test 15: Eliminar todas las instancias
        cout << "\n=== Test 15: RemoveAllInstances ===" << endl;
        list1.insert(100, 2);
        list1.insert(100, 4);
        printList(list1, "Antes de eliminar 100");
        list1.removeAllInstances(100);  
        printList(list1, "Despues de eliminar 100");

        // Test 16: Comparacion
        cout << "\n=== Test 16: Comparacion ===" << endl;
        List<int> list6 = list1;
        cout << "Iguales? " << (list1.compare(list6) ? "SI" : "NO") << endl;
        list6.set(999, 1);
        cout << "Despues modificacion, iguales? " << (list1.compare(list6) ? "SI" : "NO") << endl;

        // Test 17: Limpiar lista
        cout << "\n=== Test 17: Limpiar ===" << endl;
        list1.clean();
        printList(list1, "Lista limpia");
        cout << "list1 vacia? " << (list1.isEmpty() ? "SI" : "NO") << endl;

        // Test 18: Casos especiales
        cout << "\n=== Test 18: Casos edge ===" << endl;
        try{
            list1.getMax(); // Debe lanzar excepcion
        }catch(const exception& e){
            cout << "Excepcion esperada: " << e.what() << endl;
        }
        
        // Test 19: Lista de listas anidadas
        cout << "\n=== Test 19: Lista de listas anidadas ===" << endl;
        List<List<int>> listaDeListas;

        // Crear tres listas internas con elementos desordenados
        List<int> lista1;
        lista1.insert(3, 1);
        lista1.insert(1, 2);
        lista1.insert(2, 3);

        List<int> lista2;
        lista2.insert(5, 1);
        lista2.insert(4, 2);
        lista2.insert(6, 3);

        List<int> lista3;
        lista3.insert(9, 1);
        lista3.insert(7, 2);
        lista3.insert(8, 3);

        // Insertar las listas en la lista principal
        listaDeListas.insert(lista1, 1);
        listaDeListas.insert(lista2, 2);
        listaDeListas.insert(lista3, 3);

        // Mostrar lista de listas antes de ordenar
        printList(listaDeListas, "Lista de listas antes de ordenar");

        // Ordenar cada lista interna
        for(int i = 1; i <= listaDeListas.getSize(); ++i) {
            List<int> listaInterna = listaDeListas.query(i);
            listaInterna.sort();
            listaDeListas.set(listaInterna, i); // Actualizar la lista ordenada
        }

        // Mostrar lista de listas después de ordenar
        printList(listaDeListas, "Lista de listas después de ordenar");        



    }catch(const exception& e){
        cerr << "\n!!! Error: " << e.what() << endl;
    }

    return 0;
}