#include <stdio.h>
#include <string.h>
int main(){
    char hola[20] = "hola.sql";
    printf("antes: %s\n",hola);
    char *split = strrchr(hola, '.');
    printf("parte a eliminar: %s\n",split);
    
    int a = strlen(hola);
    printf("tamaño: %d\n",a);
    *split = '\0';

    // Llenar el resto de la cadena con ceros
    memset(split + 1, 0, strlen(split + 1)); // Establecer el resto a cero
    
   // snprintf(split, strlen(split)+1, "");
    /*int b = strlen(hola) - strlen(split);
    while(hola[b] != '\0'){
        hola[a - 1] = '\0';
        a--;
    }*/
    a = strlen(hola);
    printf("despues: %s\n",hola);
    printf("tamaño: %d\n",a);
    return 0;
}
