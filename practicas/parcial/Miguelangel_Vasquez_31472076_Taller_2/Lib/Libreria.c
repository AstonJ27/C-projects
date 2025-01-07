#include "Libreria.h"

/*----------------------------------------LISTAS SIMPLEMENTE ENLAZADAS-------------------------------------------*/

nodo *createList()
{
    nodo *prime;
    prime = (nodo *)malloc(sizeof(nodo));

    prime->info = 0;
    prime->prox = NULL;

    return (prime);
}
//inicia el primer elemento de la lista como una cabecera

nodo *addEndList(nodo *pointer, int data)
{
    nodo *elem, *ant, *sig;
    elem = (nodo *)malloc(sizeof(nodo));

    elem->info = data;
    elem->prox = NULL;

    sig = pointer->prox;
    ant = pointer;

    while (sig != NULL)
    {
        sig = sig->prox;
        ant = ant->prox;
    }
    ant->prox = elem;

    return (pointer);
}
//agrega un elemento al final de la lista

nodo *addStartList(nodo *pointer, int data)
{
    nodo *elem, *aux, *sig;
    elem = (nodo *)malloc(sizeof(nodo));

    aux = pointer->prox;

    elem->info = data;
    elem->prox = aux;

    pointer = createList();
    pointer->prox = elem;
    return (pointer);
}
//agrega un elemento al principio de la lista

nodo *ElementList(nodo *pointer, int position)
{
    nodo *elem, *sig, *ant, *aux;
    int count = 0, val = 0;

    elem = createList();
    elem->prox = (nodo *)malloc(sizeof(nodo));

    sig = pointer->prox;
    ant = pointer;

    while (sig != NULL && val != 1)
    {
        if (count == position)
        {
            val = 1;
        }
        else
        {
            ant = ant->prox;
            sig = sig->prox;
        }
        count++;
    }
    aux = elem->prox;
    aux->prox = NULL;
    aux->info = ant->info;
    return (elem);
}
//extrae en un nodo con cabecera el elemento indicado de la lista

int lenghtList(nodo *pointer)
{
    nodo *aux = NULL;
    int count = 0;

    if (pointer != NULL)
    {
        aux = pointer->prox;
    }

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }
    return count;
}
//muestra la longitud de la lista

nodo *deleteElementList(nodo *pointer, int pos)
{
    nodo *act, *ant;
    int count = 1;

    ant = pointer;
    act = pointer->prox;

    while (act != NULL)
    {
        if (count == pos)
        {
            ant->prox = act->prox;
            act->prox = NULL;
        }
        count++;
        ant = ant->prox;
        act = act->prox;
    }
    free(act);
    act = NULL;
    return (pointer);
}
//elimina en base a la posicion un elemento de la lista

nodo *deleteList(nodo *pointer)
{
    while (pointer->prox != NULL)
    {
        pointer = deleteElementList(pointer, lenghtList(pointer));
    }
    free(pointer);
    pointer = NULL;
    return (pointer);
}
//elimina completamente la lista dada

void showList(nodo *pointer)
{
    nodo *aux;
    int count = 1;

    if (pointer != NULL)
    {
        aux = pointer->prox;
    }

    if (lenghtList(pointer) == 0)
    {
        printf("No tiene elementos esta lista\n");
    }
    else
    {
        while (aux != NULL)
        {
            printf("Elemento %d: %d\n", count, aux->info);
            count++;
            aux = aux->prox;
        }
    }
}
//muestra todos los elementos de la lista

nodo *mergeList(nodo *lista1, nodo *lista2)
{
    nodo *newlist, *aux, *ant;

    newlist = createList();

    aux = lista1->prox;
    ant = lista1;

    while (aux != NULL)
    {
        aux = aux->prox;
        ant = ant->prox;
    }

    ant->prox = lista2->prox;
    newlist = lista1;

    return (newlist);
}
//le agrega a la lista1 la lista2 en secuencia para funcionarlas

void splitList(nodo *lista, nodo *split1, nodo *split2, int divide)
{
    nodo *aux;
    int count = 0;

    aux = lista->prox;

    while (aux != NULL)
    {
        if (count < divide)
        {
            split1 = addEndList(split1, aux->info);
        }
        else
        {
            split2 = addEndList(split2, aux->info);
        }
        count++;
        aux = aux->prox;
    }
}
//divide la lista original en dos splits en base a la posicion mitad indicada

nodo *quickSortList(nodo *pointer)
{
    nodo *iter, *list1, *list2, *last;
    int pivote;

    if (lenghtList(pointer) <= 1)
    {
        return (pointer);
    }

    last = ElementList(pointer, lenghtList(pointer));

    pivote = last->prox->info;

    pointer = deleteElementList (pointer, lenghtList(pointer));

    iter = pointer->prox;
    list1 = createList();
    list2 = createList();

    while (iter != NULL)
    {
        if (iter->info < pivote)
        {
            list1 = addEndList(list1, iter->info);
        }
        else
        {
            list2 = addEndList(list2, iter->info);
        }
        iter = iter->prox;
    }

    list1 = quickSortList(list1);
    list2 = quickSortList(list2);

    pointer = createList();
    pointer = mergeList(pointer, list1);
    pointer = addEndList(pointer, pivote);
    pointer = mergeList(pointer, list2);

    return (pointer);
}
//ordena los elementos de la lista

int searchList(nodo *pointer, int num, int pos)
{
    int halfNumber, lenghtHalf;
    nodo *halfNode, *l1, *l2;

    lenghtHalf = lenghtList(pointer) / 2;

    l1 = createList();
    l2 = createList();

    if (lenghtHalf == 0)
    {
        lenghtHalf = 1;
    }
    

    halfNode = ElementList(pointer, lenghtHalf);
    halfNumber = halfNode->prox->info;

    if (num == halfNumber)
    {
        if (pos < lenghtHalf)
        {
            return(lenghtHalf);
        }
        else
        {
            if (lenghtHalf > 1)
            {
                return(pos + 1);
            }
            else
            {
                return(pos);
            }
            
        }
        
    }
    else if (lenghtList(pointer) <= 1 && halfNumber != num) 
    {
        return(-1);
    }
    else
    {
        splitList(pointer, l1, l2, lenghtHalf);

        if (halfNumber > num)
        {
            return(searchList(l1, num, pos));
        }
        else
        {
            return(searchList(l2, num, pos + lenghtHalf));
        }
    }
}
//busca un elemento en una lista obligatoriamente ordenada

void uniqueList(nodo *pointer)
{
    nodo *aux, *new;
    int verify, pos = 1, count = 1;

    aux = pointer->prox;

    while (aux != NULL)
    {
        verify = aux->info;
        pos = searchList(pointer, verify, pos);

        if (pos != count)
        {
            pointer = deleteElementList(pointer, pos);
            count--;
        }
        aux = aux->prox;
        pos = 1;
        count++;
    }
    
}
//elimina los elementos repetidos de una lista

/*----------------------------------------PILAS---------------------------------------------------------*/

nodo *createPill(int data)
{
    nodo *prime;
    prime = (nodo *)malloc(sizeof(nodo));

    prime->info = data;
    prime->prox = NULL;

    return(prime);
}
//crea una pila

nodo *addEndPill(nodo *pill, int data)
{
    nodo *elem, *ant, *sig = NULL;
    elem = (nodo *)malloc(sizeof(nodo));

    elem->info = data;
    elem->prox = NULL;

    sig = pill->prox;
    ant = pill;

    while (sig != NULL)
    {
        sig = sig->prox;
        ant = ant->prox;
    }
    ant->prox = elem;

    return (pill);
}
//añade un valor al final de la pila

nodo *deleteEndPill(nodo *pill)
{
    nodo *ant, *sig;

    sig = pill->prox;
    ant = pill;

    while (sig->prox != NULL)
    {
        sig = sig->prox;
        ant = ant->prox;
    }
    ant->prox = NULL;
    
    return (pill);
}
//elimina el ultimo elemento de la Pila

int lenghtPill(nodo *pointer)
{
    nodo *aux = NULL;
    int count = 0;

    aux = pointer;

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }
    return(count);
}
//muestra la longitud de la Pila

nodo *deletePill(nodo *pill)
{
    while (pill->prox != NULL)
    {
        pill = deleteEndPill(pill);
    }
    free(pill);
    pill = NULL;
    return (pill);
}
//elimina la pila

int climbElementPill(nodo *pill)
{
    nodo *ant, *sig;
    int aux;

    sig = pill->prox;
    ant = pill;

    while (sig != NULL)
    {
        sig = sig->prox;
        ant = ant->prox;
    }
    aux = ant->info;

    return(aux);
}
//explusa el ultimo elemento de la pila

int extratClimbPill(nodo *pill)
{
    int aux;

    aux = climbElementPill(pill);
    pill = deleteEndPill(pill);

    return(aux);
}
//extrae el ultimo elemento de la pila y lo elimina

void showPill(nodo *pill)
{
    nodo *aux;
    int count = 1;
    
    aux = pill;

    if (lenghtPill(pill) == 0)
    {
        printf("No tiene elementos esta pila\n");
    }
    else
    {
        while (aux != NULL)
        {
            printf("Elemento %d: %d\n", count, aux->info);
            count++;
            aux = aux->prox;
        }
    }
}
//muestra todos los elementos de la Pila

/*----------------------------------------COLAS--------------------------------------------------------*/

nodo *createTail(int data)
{
    nodo *prime;
    prime = (nodo *)malloc(sizeof(nodo));

    prime->info = data;
    prime->prox = NULL;

    return(prime);
}
//crea una Cola

int lenghtTail(nodo *pointer)
{
    nodo *aux = NULL;
    int count = 0;

    aux = pointer;

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }
    return(count);
}
//muestra la longitud de la Cola

nodo *addEndTail(nodo *tail, int data)
{
    nodo *elem, *ant, *sig = NULL;
    elem = (nodo *)malloc(sizeof(nodo));

    elem->info = data;
    elem->prox = NULL;

    sig = tail->prox;
    ant = tail;

    while (sig != NULL)
    {
        sig = sig->prox;
        ant = ant->prox;
    }
    ant->prox = elem;

    return (tail);
}
//añade un valor al final de la Cola

nodo *addStartTail(nodo *pill, int data)
{
    nodo *elem, *aux, *new;

    new = createPill(data);
    new->prox = pill;

    return (new);
}
//añade un valor al principio de la Cola

nodo *deleteStartTail(nodo *tail)
{
    nodo *ant, *sig;

    sig = tail->prox;
    ant = tail;

    if (lenghtTail(tail) == 0)
    {
        printf("Cola vacia\n");
    }
    else
    {
        ant->info = sig->info;
        ant->prox = sig->prox;
    }
    return (tail);
}
//elimina el ultimo elemento de la Cola

nodo *deleteTail(nodo *tail)
{
    while (tail->prox != NULL)
    {
        tail = deleteStartTail(tail);
    }
    free(tail);
    tail = NULL;
    return (tail);
}
//elimina la Cola

int climbElementTail(nodo *tail)
{
    if (lenghtTail(tail) == 0)
    {
        printf("Cola vacia\n");
        return(-1);
    }
    else
    {
        return(tail->info);
    }
    
}
//explusa el primer elemento de la Cola

int extratClimbTail(nodo *tail)
{
    int aux;

    aux = climbElementTail(tail);
    tail = deleteStartTail(tail);

    return(aux);
}
//extrae el primer elemento de la cola y lo elimina de la misma 

void showTail(nodo *tail)
{
    nodo *aux;
    int count = 1;
    
    aux = tail;

    if (lenghtTail(tail) == 0)
    {
        printf("No tiene elementos esta Cola\n");
    }
    else
    {
        while (aux != NULL)
        {
            printf("Elemento %d: %d\n", count, aux->info);
            count++;
            aux = aux->prox;
        }
    }
}
//muestra todos los elementos de la Cola