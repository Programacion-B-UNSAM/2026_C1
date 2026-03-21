#include <math.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void Saludo(void) {
    char nombre[20];

    printf("\nIngrese el nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("\nHola, %s! ", nombre);
}

int Multiplo(int Start, int Stop, int Base) {
    for (int i = Start; i <= Stop; i++) {
        if ((i % Base) == 0) {
            // printf("%d ", i);
            return i;
        }
    }
    return -1;
}

void Armstrong(int Start, int Stop) {
    int nrDigitos, suma, aux;

    for (int i = Start; i <= Stop; i++) {
        nrDigitos = 0;
        suma = 0;

        aux = i;
        while (aux > 0) {
            aux /= 10;
            nrDigitos++;
        }

        aux = i;
        while (aux > 0) {
            suma += pow(aux % 10, nrDigitos);
            aux /= 10;
        }

        if (suma == i) {
            printf("%d\n", i);
        }
    }
}

unsigned long long Fibonacci(int n) {
    nroRecurrenciasFibonacci++;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return (Fibonacci(n - 2) + Fibonacci(n - 1));
}
