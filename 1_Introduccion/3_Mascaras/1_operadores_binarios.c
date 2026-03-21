/*
  Escribe un programa en C que
  1) Pida al usuario ingresar un número entero decimal
  2) Pida al usuario una mascara (número entero decimal)
  3) Muestre las represantaciones binarias de ambos
  4) Aplique al numero original las operaciones (AND, OR, NOT y módulo) 
  y muestre el resultado en binario
*/

#include <stdio.h>
#include <string.h>

int main() {
    long numOriginal, numMascara;

    /* Ejercicio 1 */
    printf("\n\nNúmero original: \t\t");
    scanf("%ld", &numOriginal);
    while (getchar() != '\n')
        ;

    /* Ejercicio 2 */
    printf("\nNúmero mascara: \t\t");
    scanf("%ld", &numMascara);
    while (getchar() != '\n')
        ;

    /* Ejercicio 3 */
    printf("\nNúmero original:  \t\t");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numOriginal >> i) & 1);
    }

    printf("\nNúmero mascara:   \t\t");
    for (int i = 15; i >= 0; i--) {
        printf("%ld", (numMascara >> i) & 1);
    }

    printf("\n----------------------------------------------------------------");

    /* Ejercicio 4 */
    printf("\nAND:\t\t %ld \t\t", numOriginal & numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((numOriginal & numMascara) >> i) & 1);
    }

    printf("\nOR:\t\t %ld \t\t", numOriginal | numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((numOriginal | numMascara) >> i) & 1);
    }

    printf("\nNOT orig:\t %ld \t\t", ~numOriginal);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((~numOriginal) >> i) & 1);
    }

    printf("\nNOT masc:\t %ld \t\t", ~numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((~numMascara) >> i) & 1);
    }

    printf("\nMÓDULO:\t\t %ld \t\t", numOriginal % numMascara);
    for (int i = 15; i >= 0; i--) {
        printf("%ld", ((numOriginal % numMascara) >> i) & 1);
    }

    printf("\n\n\n");

    return 0;
}
