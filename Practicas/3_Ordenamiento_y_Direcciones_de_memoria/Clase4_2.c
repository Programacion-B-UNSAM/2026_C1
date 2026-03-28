/*
Escribir una función en C que calcule el valor máximo, el valor mínimo y el promedio
de los elementos en un array de enteros.

La funcion debe recibir los siguientes parámetros:
-Un puntero a un array de enteros (arr).
-Un entero que representa el tamaño del array (largo).
-Dos punteros a enteros (max y min) para almacenar el valor máximo y el valor mínimo, respectivamente.
-Un puntero a un flotante (promedio) para almacenar el promedio de los elementos del array.
*/

#include <stdio.h>
#include "vectores.h"

void MaxMinProm(int* arr, int largo, int* max, int* min, float* prom);

int main() {
    int max, min;
    float prom;
    int largo = sizeof(shortVector) / sizeof(shortVector[0]);

    MaxMinProm(shortVector, largo, &max, &min, &prom);

    printf("Maximo:   %d\n", max);
    printf("Minimo:   %d\n", min);
    printf("Promedio: %f\n", prom);

    return 0;
}

void MaxMinProm(int* arr, int largo, int* max, int* min, float* prom) {
    int suma = 0;
    *max = arr[0];
    *min = arr[0];

    for (int i = 0; i < largo; i++) {
        suma += arr[i];
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }

    *prom = (float)suma / largo;
}