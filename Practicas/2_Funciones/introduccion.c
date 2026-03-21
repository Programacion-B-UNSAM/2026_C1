#include <stdio.h>
#include <string.h>

void funcion(void);

int main() {
    funcion();
    funcion();
    funcion();
    funcion();
    funcion();

    return 0;
}

void funcion(void) {
    static int a = 0;
    a++; // a = a+1

    printf("%d \n", a);
}