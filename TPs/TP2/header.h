#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define EJ1
#define EJ2
#define EJ3
#define EJ4

/* Ejercicio 1 */
int longest_streak(int* arr, int n, int max_diff, int* start_idx, int* length);

/* Ejercicio 2 */
int** build_matrix_from_file(const char* filename, int* rows, int* cols);

/* Ejercicio 3 */
int compress_array(int* arr, int n);

/* Ejercicio 4 */
int binary_search_closest(int* arr, int n, int target);

/* Test functions */
void testEjercicio1(void);
void testEjercicio2(void);
void testEjercicio3(void);
void testEjercicio4(void);

#endif /* HEADER_H */