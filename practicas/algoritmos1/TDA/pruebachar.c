#include <stdio.h>
#include <stdlib.h>

// Función de comparación para caracteres
int compare_chars(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int main() {
    int n;
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", &n);

    char arr[n];
    printf("Ingresa los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    qsort(arr, n, sizeof(char), compare_chars);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}
