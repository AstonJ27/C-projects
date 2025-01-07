#include <stdio.h>
#include <stdlib.h>

struct nodo //nodo para listas doblemente enlazadas
{
    int info;
    struct nodo *prox;
    struct nodo *ant;
};
typedef struct nodo nodo;

//los apuntadores a nodos son listas
//crea una lista vacia
nodo *new(){
   nodo *l = NULL;
    return l;
}

// agregar elementos
nodo *agregar(nodo *l, int x)
{
    
    nodo *generador, *iterador;
    
    generador = (nodo*)malloc(sizeof(nodo));
    generador->info = x;
    generador->ant = NULL;
    generador->prox = NULL;
    if(l == NULL){
        return generador;
    }
    else{
        iterador = l;
        while (iterador->prox != NULL)
        {
            iterador = iterador->prox;
        }
        iterador->prox = generador;
        generador->ant = iterador;
        
        return l;
    }
}

void llenar_rand(nodo **lr,FILE *arch){ // x es el numero de elementos que tendra mi lista, para hacerlo interesante, mas adelante se usaran numeros aleatorios
    int size1, n;
    fscanf(arch,"%d",&size1);

    for(int i=1;i<=size1;i++){
        fscanf(arch,"%d",&n);
        *lr = agregar(*lr,n);
    }

}



void imprimir_lista(nodo *l)
{
    nodo *iterador = l;
    while (iterador != NULL)
    {
        printf("%d ", iterador->info);
        iterador = iterador->prox;
    }
    printf("\n");
}

void liberar_lista(nodo *l)
{
    nodo *temp;
    while (l != NULL)
    {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

int main()
{
    nodo *l1 , *l2 , *l3; //listas
    FILE *ent;
    ent = fopen("listas.txt","r");
    
    l1 = new();
    l2 = new();
    l3 = new();

    //lenar listas con numeros ramdom
    llenar_rand(&l1,ent);
    llenar_rand(&l2,ent);
    fclose(ent);
    //mover el puntero de l2 a la ultima posicion
    nodo *p1 = l1, *p2=l2; // punteros auxiliares
    
    while (p2->prox != NULL)
    {
        p2 = p2->prox;
    }
    

    //llenar l3
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info <= p2->info)
        {
            l3 = agregar(l3, p1->info);
            p1 = p1->prox;
        }
        else
        {
            l3 = agregar(l3, p2->info);
            p2 = p2->ant;
        }
    }
    
    while (p1 != NULL){
        l3 = agregar(l3, p1->info);
        p1 = p1->prox;
    }
    
    while (p2 != NULL){
        l3 = agregar(l3, p2->info);
        p2 = p2->ant;
    }
    //p1 = l1;
    //p2 = l2;
    //prin_fin(p1,1);
    //prin_fin(p2,1);
    //---------------------------------------------------TESTING----------------------------------------------------------------------//
    //imprimir_lista(p1);
    //imprimir_lista(p2);
    //---------------------------------------------------TESTING----------------------------------------------------------------------//
    //escribir todos los valores de l3
   imprimir_lista(l3);

    //liberar memoria
    liberar_lista(l1);  
    liberar_lista(l2);    
    liberar_lista(l3);
    return 0;
}
