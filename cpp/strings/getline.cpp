#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void pause(){
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

int main(){
    char nombre[40];
    cout << "cual es tu nombre" << endl;
    cin.getline(nombre,40,'\n');
    cout << "hola " << nombre << "! " <<endl;
    int size = strlen(nombre);
    cout << "tamaño: "<<size<<endl;
    //reversa
    //str
    cout << "nombre reversa: "<<nombre<<endl;
    pause();
    
    //getchar();
    return 0;
}