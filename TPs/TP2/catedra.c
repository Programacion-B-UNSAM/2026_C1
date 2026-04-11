#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

/* ===== Ejercicio 1 ===== */

void testEjercicio1(void) {
    int arr[] = {1, 9, 5, 10, 11, 12, 20};
    int start, len, r;

    r = longest_streak(arr, 7, 2, &start, &len);
    if (r != 1 || start != 3 || len != 3) {
        printf("Error ej1 caso 1: r=%d start=%d len=%d (esperado: r=1 start=3 len=3)\n", r, start, len);
        return;
    }

    int arr2[] = {1, 10, 20, 30};
    r = longest_streak(arr2, 4, 2, &start, &len);
    if (r != 0) {
        printf("Error ej1 caso 2: r=%d (esperado: 0, sin subsecuencia valida)\n", r);
        return;
    }

    int arr3[] = {5, 6, 7, 8};
    r = longest_streak(arr3, 4, 1, &start, &len);
    if (r != 1 || start != 0 || len != 4) {
        printf("Error ej1 caso 3: r=%d start=%d len=%d (esperado: r=1 start=0 len=4)\n", r, start, len);
        return;
    }

    printf("Ejercicio 1: OK\n");
}

/* ===== Ejercicio 2 ===== */

void testEjercicio2(void) {
    /* Write a temp file, then read it back */
    const char* fname = "test_matrix.txt";
    FILE* f = fopen(fname, "w");
    if (!f) {
        printf("Error ej2: no se pudo crear archivo temporal\n");
        return;
    }
    fprintf(f, "2 3\n1 2 3\n4 5 6\n");
    fclose(f);

    int rows, cols;
    int** m = build_matrix_from_file(fname, &rows, &cols);
    if (!m) {
        printf("Error ej2: build_matrix_from_file devolvio NULL\n");
        return;
    }
    if (rows != 2 || cols != 3) {
        printf("Error ej2: dimensiones %dx%d (esperado: 2x3)\n", rows, cols);
        goto cleanup;
    }
    int expected[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] != expected[i][j]) {
                printf("Error ej2: m[%d][%d]=%d (esperado: %d)\n", i, j, m[i][j], expected[i][j]);
                goto cleanup;
            }
        }
    }

    printf("Ejercicio 2: OK\n");

cleanup:
    for (int i = 0; i < rows; i++) {
        free(m[i]);
    }
    free(m);
    remove(fname);
}

/* ===== Ejercicio 3 ===== */

void testEjercicio3(void) {
    int arr[] = {1, 1, 1, 2, 2, 3, 1, 1};
    int new_n = compress_array(arr, 8);

    int expected[] = {1, 2, 3, 1};
    if (new_n != 4) {
        printf("Error ej3 caso 1: new_n=%d (esperado: 4)\n", new_n);
        return;
    }
    for (int i = 0; i < new_n; i++) {
        if (arr[i] != expected[i]) {
            printf("Error ej3 caso 1: arr[%d]=%d (esperado: %d)\n", i, arr[i], expected[i]);
            return;
        }
    }

    int arr2[] = {5};
    new_n = compress_array(arr2, 1);
    if (new_n != 1 || arr2[0] != 5) {
        printf("Error ej3 caso 2: single element\n");
        return;
    }

    int arr3[] = {3, 3, 3, 3};
    new_n = compress_array(arr3, 4);
    if (new_n != 1 || arr3[0] != 3) {
        printf("Error ej3 caso 3: all same elements\n");
        return;
    }

    printf("Ejercicio 3: OK\n");
}

/* ===== Ejercicio 4 ===== */

void testEjercicio4(void) {
    int arr[] = {10, 3, 7, 7, 20, 15};

    /* target exists — must return a valid index (arr gets sorted: {3,7,7,10,15,20}) */
    int pos = binary_search_closest(arr, 6, 7);
    if (pos < 0) {
        printf("Error ej4 caso 1: pos=%d (esperado: indice valido de 7)\n", pos);
        return;
    }

    /* Duplicates: must return the smallest index */
    int arr2[] = {7, 7, 7};
    pos = binary_search_closest(arr2, 3, 7);
    if (pos != 0) {
        printf("Error ej4 caso 2: pos=%d (esperado: 0)\n", pos);
        return;
    }

    /* target not found */
    int arr3[] = {10, 3, 7, 20, 15};
    pos = binary_search_closest(arr3, 5, 8);
    if (pos != INT32_MIN) {
        printf("Error ej4 caso 3: pos=%d (esperado: INT32_MIN)\n", pos);
        return;
    }

    /* empty array */
    pos = binary_search_closest(NULL, 0, 5);
    if (pos != INT32_MIN) {
        printf("Error ej4 caso 4: pos=%d (esperado: INT32_MIN)\n", pos);
        return;
    }

    printf("Ejercicio 4: OK\n");
}