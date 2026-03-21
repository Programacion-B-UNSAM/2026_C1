#include <stdio.h>

int main() {
    short s = 92233720368575780732767;
    int i = 2147483647;
    long l = 922337203685757807;
    char c = 'A';
    __uint8_t u8 = 255;
    // Unsigned 8-bit int

    printf("\nshort: \t(%ld Bytes)", sizeof(s));
    printf("\n\tvalue: %d  ", s);

    printf("\nint: \t(%ld Bytes)", sizeof(i));
    printf("\n\tvalue: %d  ", i);

    printf("\nlong: \t(%ld Bytes)", sizeof(l));
    printf("\n\tvalue: %ld ", l);

    printf("\nchar: \t(%ld Bytes)", sizeof(c));
    printf("\n\tvalue: %c  ", c);

    printf("\n\n");
    return 0;
}

// Overflow
// Asignacion incorrecta
// Asignacion estilo __uint8_t