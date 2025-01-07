#include "listas.h"
typedef struct prueba
{
    int a;
    char b;
}prueba;

void mostrar_prueba(void *dato){
    prueba algo = *(prueba*)dato;
    printf("%d %c\n",algo.a,algo.b);
}

int main(){
    // probando lista de enteros
    lista l = crear_lista(INT,sizeof(int),NULL);

    for (int i = 1; i <= 5; i++){
        agregar(&l,&i,INT);
    }
    
    printf("Lista: ");
    printf("%d\n",l.total);
    mostrar_lista(l);
    quitar(&l, 3);
        
    printf("Lista: ");
    printf("%d\n",l.total);

    mostrar_lista(l);
    
    eliminar_lista(&l);
    printf("\n");

// probando lista de estructuras------------------
    lista l2 = crear_lista(STRUCT,sizeof(prueba),&mostrar_prueba);
    prueba n_1;
    n_1.a = 0;
    n_1.b = 'a';
    for (int i = 0; i <= 4; i++){
        n_1.a = n_1.a+i;
        n_1.b = n_1.b+i;
        
        agregar(&l2,&n_1,STRUCT);
    }
    
    printf("Lista: ");
    printf("%d\n",l2.total);
    mostrar_lista(l2);
    quitar(&l2, 3);
        
    printf("Lista: ");
    printf("%d\n",l2.total);

    mostrar_lista(l2);
    
    eliminar_lista(&l2);

    return 0;

}
