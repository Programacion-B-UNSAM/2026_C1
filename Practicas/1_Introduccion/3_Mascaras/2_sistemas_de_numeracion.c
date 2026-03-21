/*
  1) Pida al usuario ingresar un número entero decimal
  2) Convierta y muestre el número en sus representaciones:
        Binaria
        Hexadecimal
        BCD
*/

#include <stdio.h>
#include <string.h>

int main() {
    int numOriginal, aux;
    int i, j, cantDigitos = 0;

    printf("\n\nNúmero original: ");
    scanf("%d", &numOriginal);
    while (getchar() != '\n')
        ; /* Limpia el buffer de entrada para evitar problemas con fgets */

    //La contra de este metodo es que tengo que definir la cantidad de digitos antes
    //Cuento la cantidad de digitos
    aux = numOriginal;
    while (aux != 0) {
        aux /= 10;
        cantDigitos++;
    }

    // Pasaje a binario
    printf("\nNúmero binario:\t\t");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (numOriginal >> i) & 1);
        if (i % 4 == 0) {
            printf(" ");
        }
    }

    // Pasaje a BCD
    aux = numOriginal;
    printf("\nNúmero BCD:\t\t");

    for (j = cantDigitos - 1; j >= 0; j--) {
        aux = numOriginal;
        for (i = 0; i < j; i++) {
            aux /= 10;
        }

        for (i = 3; i >= 0; i--) {
            printf("%d", ((aux %= 10) >> i) & 1);
        }
        printf(" ");
    }

    // Pasaje a hexadecimal
    aux = numOriginal;
    printf("\nNúmero hexadecimal:\t");
    for (j = cantDigitos - 1; j >= 0; j--) {
        aux = numOriginal;
        for (i = 0; i < j; i++) {
            aux /= 16;
        }
        if (aux == 0) {
            continue; //para no imprimir ceros a la izquierda
        }

        if ((aux % 16) < 10) {
            printf("%d", (aux % 16));
        } else {
            printf("%c", ((aux % 16) - 10 + 'A')); //Para pasar de int a char
        }
    }

    return 0;
}
