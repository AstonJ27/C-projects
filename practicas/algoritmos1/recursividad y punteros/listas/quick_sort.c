#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void qs_asc(int lista[], int limite_izq, int limite_der) {
    int izq, der, temporal, pivote;

    izq = limite_izq;
    der = limite_der;
    pivote = lista[(izq + der) / 2];

    do {
        while (lista[izq] < pivote && izq < limite_der) izq++;
        while (pivote < lista[der] && der > limite_izq) der--;
        if (izq <= der) {
            temporal = lista[izq];
            lista[izq] = lista[der];
            lista[der] = temporal;
            izq++;
            der--;
        }

    } while (izq <= der);
    if (limite_izq < der) { qs_asc(lista, limite_izq, der); }
    if (limite_der > izq) { qs_asc(lista, izq, limite_der); }
}

void quicksort_asc(int lista[], int n) {
    qs_asc(lista, 0, n - 1);
}

void qs_desc(int lista[], int limite_izq, int limite_der) {
    int izq, der, temporal, pivote;

    izq = limite_izq;
    der = limite_der;
    pivote = lista[(izq + der) / 2];

    do {
        while (lista[izq] > pivote && izq < limite_der) izq++;
        while (pivote > lista[der] && der > limite_izq) der--;
        if (izq <= der) {
            temporal = lista[izq];
            lista[izq] = lista[der];
            lista[der] = temporal;
            izq++;
            der--;
        }

    } while (izq <= der);
    if (limite_izq < der) { qs_desc(lista, limite_izq, der); }
    if (limite_der > izq) { qs_desc(lista, izq, limite_der); }
}

void quicksort_desc(int lista[], int n) {
    qs_desc(lista, 0, n - 1);
}

void llenar_random(int lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        lista[i] = (rand() % 100) + 1;
    }
}

void escribir_archivo(FILE *archivo, int lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        fprintf(archivo, "%d", lista[i]);
        if (i < tam - 1)
            fprintf(archivo, " ");
    }
    fprintf(archivo, "\n");
}

int main() {
    FILE* listas;
    int lista1[MAX], lista2[MAX];
    srand(time(0));
    int size1 = (rand() % 6) + 5;
    int size2 = (rand() % 6) + 5;

    llenar_random(lista1, size1);
    llenar_random(lista2, size2);

    printf("Lista 1 Desordenada \n");
    for (int i = 0; i < size1; i++) {
        printf("%d", lista1[i]);
        if (i < size1 - 1)
            printf(",");
    }
    printf("\n\nLista 2 Desordenada \n");
    for (int i = 0; i < size2; i++) {
        printf("%d", lista2[i]);
        if (i < size2 - 1)
            printf(",");
    }
    printf("\n\n");

    quicksort_asc(lista1, size1);
    quicksort_desc(lista2, size2);

    printf("Lista 1 Ordenada \n");
    for (int i = 0; i < size1; i++) {
        printf("%d", lista1[i]);
        if (i < size1 - 1)
            printf(",");
    }
    printf("\n\n");

    printf("Lista 2 Ordenada \n");
    for (int i = 0; i < size2; i++) {
        printf("%d", lista2[i]);
        if (i < size2 - 1)
            printf(",");
    }
    printf("\n");

    listas = fopen("listas.txt", "w");

    fprintf(listas, "%d\n", size1);
    escribir_archivo(listas, lista1, size1);

    fprintf(listas, "%d\n", size2);
    escribir_archivo(listas, lista2, size2);

    fclose(listas);
    return 0;
}