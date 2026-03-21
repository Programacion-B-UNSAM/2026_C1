#include <stdio.h>
#include <string.h>

struct personaStruct {
    char nombre[50];
    int edad;
    float altura;
};

union personaUnion {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    struct personaStruct persona1;
    // union personaUnion persona2;

    strcpy(persona1.nombre, "Joaquin");
    persona1.edad = 32;
    persona1.altura = 1.80;

    printf("\n\n");

    printf("Nombre: %s \n", persona1.nombre);
    printf("Altura: %f \n", persona1.altura);
    printf("Edad:   %d \n", persona1.edad);

    // printf("Struct:   %ld bytes\n", sizeof(persona1));
    // printf("Union:    %ld bytes\n", sizeof(persona2));

    printf("\n\n");
    return 0;
}

//Init con
// struct personaStruct persona2 = {"Jorge", 21, 1.65};
// struct personaStruct persona3 = {
//     .nombre = "Jorge",
//     .altura = 1.9,
//     .edad = 40,
// };

// Cambio por union
// Cambio orden de asignacion
// Tamaños
