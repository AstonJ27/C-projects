#include "listas.h"

// implementacion de los tipos de datos
//---------------------------------LISTAS SIMPLEMENTE ENLAZADAS-------------------------------
lista crearS(){ //check
    NodoSimple *a=NULL;
    return a;
}

lista crearNS(item x) { //check
    NodoSimple *a = malloc(sizeof(NodoSimple));
    if (a != NULL) {
        a->elem = x;
        a->prox = NULL;
    }
    return a;
}

int isvoidS(lista list){
    return(list == NULL);
}

void insertarIniS(lista *list, item x){ //check
    lista aux = crearNS(x);;
    if(*list == NULL){
        *list = aux;
    }else{
        aux->prox = *list;
        *list = aux;
    }
}

void insertarS(lista *list, item x, int pos){ //check
    lista aux = *list, nuevo = crearNS(x);
    if(pos <= 0){
        return;
    }
    if(*list == NULL){
        *list = nuevo;
    }else{
        int i=1;
        while(aux->prox!=NULL && i != pos-1){
            aux=aux->prox;
            i++;
        }

        if(pos <= tamanioS(*list)+1){
            nuevo->prox = aux->prox;
            aux->prox=nuevo;
        }
    }
}

lista recorrerS(lista list, int pos){ //check
    lista aux = list;
    if(list == NULL || pos <= 0){
        return NULL;
    }
    
    int i=1;
    while(aux != NULL && i != pos){
        aux = aux->prox;
        i++;
    }
    return aux;
}

void imprimirS(lista list, char* type){ //check
    if(list == NULL){
        printf("lista vacia");
        return;
    }
    
    lista aux = list;
    while(aux != NULL){
        printf(type,aux->elem);
        printf(" ");
        aux = aux->prox;
    }
    printf("\n");
}

int existeS(lista list, item x){ //check
    lista aux = list;
    int i=1;

    while(aux->prox != NULL){
        if(aux->elem == x){
            return i;
        }
        aux = aux->prox;
        i++;
    }
    
    return 0;
}


int tamanioS(lista list){ //check
    lista aux=list;
    int i=0;
    while (aux != NULL){
        aux=aux->prox;
        i++;
    }
    return i;
}
void eliminarS(lista *list){ //check
    lista temp;
    while (*list != NULL){
        temp = *list;
        *list = (*list)->prox;
        free(temp);
    }
}
lista eliminarPosS(lista list, int pos){ //check
    if(list == NULL){
        return NULL;
    }
    lista aux = recorrerS(list, pos-1);
    lista aux2 = recorrerS(list, pos);
    
    aux->prox=aux2->prox;
    free(aux2);
    aux = list;
    return aux;
}

int comparar_ptr(const void *a, const void *b){ //check
    
    stringS //return strcmp(*(item *)a, *(item *)b);
    return *(item *)a - *(item *)b;
}

void ordenarS(lista list){ //check
    if(list == NULL || list->prox == NULL){
        return; // Lista vacía o un solo elemento
    }
    
    lista aux = list;
    int tam = tamanioS(list);
    item vect[tam];
    int i=0;
    while(aux != NULL){
        vect[i] = aux->elem;
        aux = aux->prox;
        i++;
    }
    qsort(vect,tam,sizeof(item),comparar_ptr);
    i=0;
    aux = list;
    while(aux != NULL){
        aux->elem = vect[i];
        aux = aux->prox;
        i++;
    }
}

//---------------------------------LISTAS DOBLEMENTE ENLAZADAS-------------------------------

listaD crearD(){ // Crear lista doblemente enlazada vacía
    return NULL;
}

listaD crearND(itemD x) { // Crear nodo doblemente enlazado
    listaD a = malloc(sizeof(NodoDoble));
    if (a != NULL) {
        a->elem = x;
        a->prox = NULL;
        a->ant = NULL;
    }
    return a;
}

int isvoidD(listaD list){ // Verificar si la lista está vacía
    return (list == NULL);
}

void insertarIniD(listaD *list, itemD x){ // Insertar al inicio de la lista
    listaD nuevo = crearND(x);
    if (*list != NULL) {
        nuevo->prox = *list;
        (*list)->ant = nuevo;
    }
    *list = nuevo;
}

void insertarD(listaD *list, itemD x, int pos){ // Insertar en posición específica
    listaD aux = *list, nuevo = NULL;
    if(pos <= 0){
        return;
    }else if(*list == NULL){
        *list = nuevo;
    }
    else{
    
        int i = 1;
        while (aux != NULL && i != pos - 1) {
            aux = aux->prox;
            i++;
        }
        if (pos <= tamanioD(*list) + 1) {
            nuevo = crearND(x);
            if (aux->prox != NULL) {
                nuevo->prox = aux->prox;
                aux->prox->ant = nuevo;
            }
            aux->prox = nuevo;
            nuevo->ant = aux;
        }
    }
}

listaD recorrerD(listaD list, int pos){ // Recorrer hasta posición específica
    listaD aux = list;
    int i = 1;
    while (aux != NULL && i != pos) {
        aux = aux->prox;
        i++;
    }
    return aux;
}

void imprimirD(listaD list, char *type){ // Imprimir todos los elementos de la lista
    if(list == NULL){
        printf("lista vacia");
        return;
    }
    listaD aux = list;
    while (aux != NULL){
        printf(type,aux->elem);
        printf(" ");
        aux = aux->prox;
    }
    printf("\n");
}

int existeD(listaD list, itemD x){ // Verificar si un elemento existe en la lista
    listaD aux = list;
    int i = 1;
    while (aux != NULL) {
        if(aux->elem == x){
            return i;
        }
        aux = aux->prox;
        i++;
    }
    
    return 0;
}

int tamanioD(listaD list){ // Obtener el tamaño de la lista
    listaD aux = list;
    int i = 0;
    while (aux != NULL){
        aux = aux->prox;
        i++;
    }
    return i;
}

void eliminarD(listaD *list){ // Eliminar toda la lista
    listaD temp;
    while (*list != NULL){
        temp = *list;
        *list = (*list)->prox;
        free(temp);
    }
}

listaD eliminarPosD(listaD list, int pos){ // Eliminar nodo en posición específica
    if(list == NULL){
        return NULL;
    }
    listaD aux = recorrerD(list, pos-1);
    listaD aux2 = recorrerD(list, pos);
    
    aux->prox = aux2->prox;
    if (aux2->prox != NULL) {
        aux2->prox->ant = aux;
    }
    free(aux2);
    aux = list;
    return aux;
}
int comparar_ptrD(const void *a, const void *b) { //check
    
    stringD //return strcmp(*(item *)a, *(item *)b); //para strings
    return *(itemD *)a - *(itemD *)b;
}
void ordenarD(listaD list){ // Ordenar la lista
    if(list == NULL || list->prox == NULL){
        return; // Lista vacía o un solo elemento
    }
    
    listaD aux = list;
    int tam = tamanioD(list);
    itemD vect[tam];
    int i = 0;
    while (aux != NULL){
        vect[i] = aux->elem;
        aux = aux->prox;
        i++;
    }
    qsort(vect, tam, sizeof(itemD), comparar_ptrD);
    i = 0;
    aux = list;
    while (aux != NULL){
        aux->elem = vect[i];
        aux = aux->prox;
        i++;
    }
}

//---------------------------------LISTAS SIMPLEMENTE ENLAZADAS CIRCULARMENTE-------------------------------

listaSC crearSC(){ //check
    return NULL;
}

listaSC crearNSC(itemSC x){ //check
    listaSC a = malloc(sizeof(NodoSimpleC));
    if(a != NULL){
        a->elem = x;
        a->prox = a; // Apunta a sí mismo para indicar lista vacía
    }
    return a;
}

int isvoidSC(listaSC list){ //check
    return (list == NULL);
}

void insertarIniSC(listaSC *list, itemSC x, listaSC ult){ //necesita un puntero que guarde la posicion final
    listaSC aux = crearNSC(x);
    if(*list == NULL){
        *list = aux;
    }else{
        aux->prox = *list;
        (*list)= aux;
        ult->prox = *list; 
    }
}

void insertarSC(listaSC *list, itemSC x, int pos){ //inserta el elemento en la posicion pos%(tamaño+1)
    listaSC nuevo = crearNSC(x); //nodo que se apunta a si mismo
    if(pos <= 0){
        return;
    }else if(pos > (tamanioSC(*list)+1)){
        pos = pos%(tamanioSC(*list)+1)+1;
    }
    
    if(*list == NULL){
        *list = nuevo;
    }else{
        listaSC aux = *list;

        int i = 1;

        while (i < pos-1 && aux->prox != *list){
            aux = aux->prox;
            i++;
        }
        nuevo->prox = aux->prox;
        aux->prox = nuevo;
    }
}


listaSC recorrerSC(listaSC list, int pos){
    listaSC aux = list;
    if(pos > tamanioSC(list)){
        pos = pos % (tamanioSC(list)+1)+1;
    }
    int i = 1;
    while ( i < pos && aux->prox != list) {
        aux = aux->prox;
        i++;
    }
    return aux;
}

void imprimirSC(listaSC list, char *type){ //check
    
    if(list == NULL){
        printf("Lista vacía\n");
        return;
    }
    listaSC aux = list;
    do{
        printf(type, aux->elem);
        printf(" ");
        aux = aux->prox;
    }while(aux != list);
    printf("\n");
}

int existeSC(listaSC list, itemSC x){
    listaSC aux = list;
    int i=1;
    while(aux->prox != list){
        if(aux->elem == x){
            return i;
        }
        aux = aux->prox;
        i++;
    }
    
    return 0;
}

int tamanioSC(listaSC list){
    if(list == NULL){ 
        return 0;
    }
    listaSC aux = list;
    int i = 1;
    while(aux->prox != list){
        aux = aux->prox;
        i++;
    }
    return i;
}

void eliminarSC(listaSC *list) {
    if (*list == NULL) return;
    listaSC temp;
    while(*list != (*list)->prox){
        temp = (*list)->prox;
        (*list)->prox = temp->prox;
        free(temp);
    }
    free(*list);
    *list = NULL;
}

listaSC eliminarPosSC(listaSC list, int pos){
    if(list == NULL){ 
        return NULL;
    }
    listaSC aux = recorrerSC(list, pos - 1);
    listaSC aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return list;
}

int comparar_ptrSC(const void *a, const void *b){
    
    stringSC //return strcmp(*(item *)a, *(item *)b); //para strings
    return *(itemSC *)a - *(itemSC *)b;
}

void ordenarSC(listaSC list){
    if (list == NULL || list->prox == list){
        return; // Lista vacía o un solo elemento
    }
    int tam = tamanioSC(list);
    itemSC vect[tam];
    listaSC aux = list;
    int i = 0;
    do{
        vect[i] = aux->elem;
        aux = aux->prox;
        i++;
    }while(aux != list);
    qsort(vect, tam, sizeof(itemSC), comparar_ptrSC);
    aux = list;
    i = 0;
    do{
        aux->elem = vect[i];
        aux = aux->prox;
        i++;
    }while(aux != list);
}


//---------------------------------LISTAS DOBLEMENTE ENLAZADAS CIRCULARMENTE-------------------------------

listaDC crearDC(){ //check
    return NULL;
}

listaDC crearNDC(itemDC x){ //check
    listaDC a = malloc(sizeof(NodoDobleC));
    if(a != NULL){
        a->elem = x;
        a->ant = a; 
        a->prox = a; 
    }
    return a;
}

int isvoidDC(listaDC list){ //check
    return (list == NULL);
}

void insertarIniDC(listaDC *list, itemDC x){ //check
    listaDC nuevo = crearNDC(x);
    if(*list == NULL){
        *list = nuevo;
    }
    else{
        nuevo->prox = *list;
        nuevo->ant = (*list)->ant;
        (*list)->ant->prox = nuevo;
        (*list)->ant = nuevo;
        *list = nuevo;
    }
}

void insertarDC(listaDC *list, itemDC x, int pos){ //check
    listaDC nuevo = crearNDC(x);
    if(*list == NULL){
        *list = nuevo;
        return;
    }else if(pos == 0){
        return;
    }else if(pos > (tamanioDC(*list)+1)){
        pos = pos%(tamanioDC(*list)+1)+1;
    }

    listaDC aux = *list;
    int i = 1;
    while(i < pos - 1 && aux->prox != *list){
        aux = aux->prox;
        i++;
    }
    
    nuevo->prox = aux->prox;
    nuevo->ant = aux;
    aux->prox->ant = nuevo;
    aux->prox = nuevo;
    
}

void imprimirDC(listaDC list, char *type){ //check puesto de primero para cambiar el tipo de dato a imprimir
    if(list == NULL){
        printf("Lista vacía\n");
        return;
    }
    listaDC aux = list;
    do{
        printf(type, aux->elem);
        printf(" ");
        aux = aux->prox;
    }while(aux != list);
    printf("\n");
}

listaDC recorrerDC(listaDC list, int pos){ //check
    listaDC aux = list;
    if(pos > tamanioDC(list)){
        pos = pos % (tamanioDC(list)+1)+1;
    }
    int i = 1;
    while(i < pos && aux->prox != list){
        aux = aux->prox;
        i++;
    }
    return aux;
}


int existeDC(listaDC list, itemDC x){ //check
    listaDC aux = list;
    int i = 1;
    do{
        if(aux->elem == x){
            return i;
        }
        aux = aux->prox;
        i++;
    }while(aux != list);
    return 0;
}

int tamanioDC(listaDC list){ //check
    if(list == NULL){
        return 0;
    }
    
    listaDC aux = list;
    int i = 1;
    while(aux->prox != list){
        aux = aux->prox;
        i++;
    }
    return i;
}

void eliminarDC(listaDC *list){ //check
    if(*list == NULL){
        return;
    }    
    listaDC temp;
    while((*list)->prox != *list){
        temp = (*list)->prox;
        (*list)->prox = temp->prox;
        temp->prox->ant = *list;
        free(temp);
    }
    free(*list);
    *list = NULL;
}

listaDC eliminarPosDC(listaDC list, int pos){ //check
    if(list == NULL || pos <= 0){
        return NULL;
    }else if(pos > tamanioDC(list)){
        pos = pos % (tamanioDC(list)+1)+1;
    }
    
    
    listaDC aux = recorrerDC(list, pos - 1);
    listaDC aux2 = aux->prox;
    aux->prox = aux2->prox;
    aux2->prox->ant = aux;
    free(aux2);
    return list;
}

int comparar_ptrDC(const void *a, const void *b){ //check
    
    stringDC //return strcmp(*(itemDC *)a, *(itemDC *)b); //para strings 
    return *(itemDC *)a - *(itemDC *)b;
}

void ordenarDC(listaDC list){ //check
    if(list == NULL || list->prox == list){
        return; // Lista vacía o un solo elemento
    }
    
    int tam = tamanioDC(list);
    itemDC vect[tam];
    listaDC aux = list;
    int i = 0;
    
    do{
        vect[i] = aux->elem;
        aux = aux->prox;
        i++;
    }while(aux != list);
    
    qsort(vect, tam, sizeof(itemDC), comparar_ptrDC);
    aux = list;
    i = 0;
    
    do{
        aux->elem = vect[i];
        aux = aux->prox;
        i++;
    }while(aux != list);
}

//---------------------------------PILAS-------------------------------

pila crearPila(){
    return NULL;
}

int isvoidP(pila pil){
    return pil == NULL;
}

itemP cima(pila pil){
    if(isvoidP(pil)){
        exit(EXIT_FAILURE);
    }
    return pil->elem;
}
//para trabajar strings
char *prepare(char buff[]){
    char *w = (char *)malloc(strlen(buff)+1);
    if(w == NULL){
        exit(EXIT_FAILURE);
    }
    strcpy(w,buff);
    return w;
}


void insertarCima(pila *pil, itemP x){ 
    pila nuevo;
    nuevo = (pila)malloc(sizeof(NodoP)); 
    nuevo->elem = x; 
    nuevo->sig = *pil; 
    *pil = nuevo;
}

void eliminarCima(pila *pil){
    if(!isvoidP(*pil)){
        pila aux = *pil;
        *pil = (*pil)->sig;
        free(aux);
    }
}

itemP quitarCima(pila *pil){
    if(isvoidP(*pil)){
        exit(EXIT_FAILURE);
    }
    itemP cima = (*pil)->elem;
    eliminarCima(pil);
    return cima;
}

void vaciarPila(pila *pil){
    while(!isvoidP(*pil)){
        eliminarCima(pil);
    }
}

int tamanioPila(pila pil){
    pila aux;
    int tam = 1;
    while(aux != NULL){
        aux = aux->sig;
        tam++;
    }
    return tam;
}

//---------------------------------COLAS-------------------------------

void crearCola(cola *col){ //check
    col->ini = NULL;
    col->fin = NULL;
}

int isvoidC(cola col){ //check
    return col.ini == NULL;
}


NodoC *crearNCola(itemC x){ //check
    NodoC *nuevo;
    nuevo = (NodoC*)malloc(sizeof(NodoC));
    nuevo->elem = x;
    nuevo->sig = NULL;
    return nuevo;
}

void insertarACola(cola *col, itemC x){ //check
    NodoC *nuevo = crearNCola(x);
    if(isvoidC(*col)){
        col->ini = nuevo;
        col->fin = nuevo;
    }else{
        col->fin->sig = nuevo;
        col->fin = nuevo;
    }
}

itemC frenteCola(cola col){ //check
    if(isvoidC(col)){
        exit(EXIT_FAILURE);
    }
    return col.ini->elem;
}

void eliminarDeCola(cola *col){ //check
    if(!isvoidC(*col)){
        NodoC *aux = col->ini;
        col->ini = aux->sig;
        free(aux);
    }
}

itemC quitarDeCola(cola *col){ //check
    if(isvoidC(*col)){
        exit(EXIT_FAILURE);
    }
    itemC temp = col->ini->elem;
    eliminarDeCola(col);
    return temp;
}

void vaciarCola(cola *col){ //check
    while(!isvoidC(*col)){
        eliminarDeCola(col);
    }
}

int tamanioCola(cola col){ //check
    if(isvoidC(col)){
        return 0;
    }
    int tam = 0;
    NodoC *aux = col.ini;
    while(aux != NULL){
        tam++;
        aux = aux->sig;
    }
    return tam;
}
