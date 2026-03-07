/*
COMPILAR Y CORRER MANUALMENTE (unico archivo)

Windows (MinGW / gcc):
    gcc archivo_1.c -o archivo_1.exe
    archivo_1.exe

Linux / macOS (gcc):
    gcc archivo_1.c -o archivo_1
    ./archivo_1

*/

#include <stdio.h>

int main() {

    long num = 16;
    printf("Un numero = %ld\n", num);

    FILE *archivo = fopen("archivo_1.bin", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura\n");
        return 1;
    }

    fwrite(&num, sizeof(num), 1, archivo);
    fclose(archivo);

    archivo = fopen("archivo_1.bin", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura\n");
        return 1;
    }

    long num1;
    fread(&num1, sizeof(num1), 1, archivo);
    fclose(archivo);

    printf("Numero guardado = %ld\n", num1);

    return 0;
}