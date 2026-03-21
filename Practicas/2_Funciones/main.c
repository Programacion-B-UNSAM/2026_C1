#include <stdio.h>
#include <string.h>

#include "funciones.c"
#include "header.h"

/*
=========================== Ej 1 ===========================
Crear una funcion dentro de la cual, se le pida el nombre al usuario y se imprima "Hola {nombre}!"

=========================== Ej 2 ===========================
Crear una funcion que tome 3 numeros (a, b, c) como entrada y devuelva el primer numero dentro del intervalo [a, b] que sean multiplo de c.

=========================== Ej 3 ===========================
Crear una funcion que tome 2 numeros como entrada e imprima todos los numeros dentro de ese intervalo, cuya suma de los de los digitos elevado a la cantidad de digitos sea igual al numero original.

ej: 153 = 1^3 + 5^3 + 3^3
ej 8028 = 8^4 + 0^4 + 2^4 + 8^4

=========================== Ej 4 ===========================
Crear una funcion que tome 1 numero (n) como entrada y devuelva el termino n de la secuencia de fiboacci.

Serie de Fibonacci:
Serie de numeros donde el proximo termino esta dado por la suma de los 2 terminos anteriores. 
n = (n-1 + n-2)
Ej: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, … 
*/

unsigned long long nroRecurrenciasFibonacci;

int main(void) {
#ifdef Ej1
    Saludo();
#endif
#ifdef Ej2
    int Start = 10;
    int Stop = 100;
    int Base = 7;

    Multiplo(Start, Stop, Base);
#endif
#ifdef Ej3
    int start, stop;
    printf("\nComienzo del intervalo: \t");
    scanf("%d", &start);
    printf("\nFin del intervalo: \t");
    scanf("%d", &stop);
    Armstrong(start, stop);

#endif
#ifdef Ej4
    nroRecurrenciasFibonacci = 0;
    int nroIter;
    printf("\nIngrese el numero de iteraciones: \t");
    scanf("%d", &nroIter);
    printf("El %d de la secuencia de Fibonacci es : \t%lld", nroIter, Fibonacci(nroIter));
    printf("\nPara esta sucecion se llamo a la funcion %lld veces", nroRecurrenciasFibonacci);
#endif
    printf("\n\n");
    return 0;
}
