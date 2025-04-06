#include <iostream>
#include <stdexcept>
#include "stack.h"

using namespace std;

int main() {
    // Test 1: Constructor vacío
    cout << "=== Test 1: Constructor vacio ===" << endl;
    Stack<int> s1;
    cout << "Tamano: " << s1.getSize() 
         << " (Esperado 0), Vacio?: " << (s1.isEmpty() ? "SI" : "NO")
         << " (Esperado SI)\n" << endl;

    // Test 2: Constructor con elemento
    cout << "=== Test 2: Constructor con elemento ===" << endl;
    Stack<int> s2(5);
    cout << "Tamano: " << s2.getSize() 
        <<  " (Esperado 1), Vacio?: " << (s2.isEmpty() ? "SI" :"NO")
        << " (Esperado NO)\n" << endl;

    // Test 3: Push y tamaño
    cout << "=== Test 3: Push ===" << endl;
    Stack<char> s3;
    s3.push('a');
    s3.push('b');
    cout << "Tamano: " << s3.getSize() << " (Esperado 2)" << endl;
    cout << "Peek: " << s3.peek() << " (Esperado b)\n" << endl;

    // Test 4: Pop
    cout << "=== Test 4: Pop ===" << endl;
    cout << "desapilar" << endl;
    s3.pop();
    cout << "Peek despues de pop: " << s3.peek() 
         << " (Esperado a)" << endl;
    cout << "desapilar" << endl;
    
    s3.pop();
    cout << "Vacio?: " << (s3.isEmpty() ? "SI" : "NO") << " (Esperado SI)\n" << endl;

    // Test 5: Copiar pila
    cout << "=== Test 5: Copiar pila ===" << endl;
    Stack<int> original;
    original.push(10);
    original.push(20);
    Stack<int> copia;
    Stack<int> copia2(original);
    copia.copy(original);
    cout << "Compare metodo copia: " << (original.compare(copia) ? "SI" : "NO") 
        << " (Esperado SI)\n" << endl;
    cout << "Compare constructor copia: " << (original.compare(copia2) ? "SI" : "NO")
        << " (Esperado SI)\n" << endl;
    
    // Test 6: Merge (requiere quitar const del parámetro)
    cout << "=== Test 7: Merge ===" << endl;
    Stack<int> s7a;
    s7a.push(1);
    s7a.push(2);
    
    Stack<int> s7b;
    s7b.push(3);
    s7b.push(4);
    s7a.merge(s7b);
    cout << "Tamano s7a: " << s7a.getSize() 
        << " (Esperado 4), Peek: " << s7a.peek() 
        << " (Esperado 4)\n" << endl;

    cout << "=== Test 7: reverse ===" << endl;
    Stack<int> s7c;
    s7c.push(1);
    s7c.push(2);
    s7c.push(3);
    s7c.push(4);
    s7c.push(5);
    s7c.push(6);
    s7c.push(7);
    s7c.push(8);
    s7c.push(9);
    s7c.push(10);

    cout << "Antes de reversa (Esperado 10), Peek: " << s7c.peek()<<endl;
    s7c.reverse(); 
    cout << "Tamano s7c: " << s7c.getSize()
    << "\nDespues de reversa (Esperado 1), Peek: " << s7c.peek()
    << " (Esperado 3)" << endl;
    cout << "Vacio?: " << (s7c.isEmpty() ? "SI" :"NO") << " (Esperado NO)\n" << endl;

    // Test 6: Peek en pila vacía (excepción)
    cout << "=== Test 6: Peek en pila vacia ===" << endl;
    Stack<double> s6;
    try {
        s6.peek();
    } catch (const exception& e) {
        cout << "Excepcion: " << e.what() << endl;
    }

    return 0;
}