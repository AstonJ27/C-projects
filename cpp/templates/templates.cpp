#include <iostream>
#include <string.h>
#include "../../proyecto uno/librerias/colores/colores.h"
//#include <typeinfo>

using namespace std;


void pause(){
    cout <<"Presione Enter para continuar..."<< endl;
    getchar();
}

template <class tipo1, class tipo2>
void sumarOconcatenar(tipo1 dato1, tipo2 dato2){
    if(string(typeid(dato1).name())== "c" || string(typeid(dato2).name()) == "c"){
        cout << "concatenacion: "<<dato1<<dato2<<endl;
    }else{
        cout << "suma: "<<dato1+dato2<<endl;
    }


}

int main(){
    
    int a = 5;
    char b = 'c';
    string palabra = "hola ";
    string palabra2 = "hola";
    sumarOconcatenar(a,b);
    // el operador + concatena los objetos strings, sin embargo no concatena el tipo char* ojo pelao
    cout << string("a")+string("b")<<endl;

    pause();
    return 0;
}