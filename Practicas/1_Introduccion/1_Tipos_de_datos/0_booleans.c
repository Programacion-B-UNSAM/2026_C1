#include <stdio.h>

int main() {
    short s = 32767;
    int i = 2147483647;
    long l = 9223372036854775807;
    char c = 'A';

    printf("\n\n");

    if (l) {
        printf("======================================\n");
        printf("|| En C son consideradas True todas ||\n");
        printf("|| las variables  distintas de 0.   ||\n");
        printf("======================================\n");
    }

    printf("\n\n");
    return 0;
}

// Buenas practicas