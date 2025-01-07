#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función de comparación genérica para void*
int compare_void_ptrs(const void *a, const void *b) {
    return memcmp(*(void **)a, *(void **)b, sizeof(void *));
}

int main() {
    // Crear un array de enteros
    int arr[] = {5, 2, 8, 1, 9};
    int num_elements = sizeof(arr) / sizeof(arr[0]);

    // Convertir el array a un array de void*
    void *elements[num_elements];
    for (int i = 0; i < num_elements; i++) {
        elements[i] = &arr[i];
    }

    // Ordenar el array de void*
    qsort(elements, num_elements, sizeof(void *), compare_void_ptrs);

    // Imprimir el array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", *(int *)elements[i]);
    }
    printf("\n");

    return 0;
}
