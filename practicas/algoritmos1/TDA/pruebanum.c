#include <stdio.h>
#include <stdlib.h>

// Función de comparación para enteros
int compare_ints(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingresa los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare_ints);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
