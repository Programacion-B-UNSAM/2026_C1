#include <stdint.h>
#include <stdio.h>

/*
1- Piense una estructura para guardar los datos bancarios de una persona, estos son:
    - Nombre (max 20 caracteres)
    - nroCuenta  (4 numeros)
    - En caso de ser Argentino D.N.I. (10 digitos)
    - En caso de no ser Argentino Pasaporte (12 digitos    alfanumericos) 
Utilize la menor cantidad de memoria posible

2- Inicalize los datos e imprima los valores

*/

typedef struct {
    char nombre[20];
    short nroCuenta;
    short esArg;

    union id {
        char pasaporte[12];
        int dni;
    } id;
} datos_bancarios_t;

int main() {
    datos_bancarios_t persona1 = {
        .nombre = "Juan",
        .nroCuenta = 1230,
        .esArg = 1,
        .id.dni = 40085741,
    };
    printf("\nNombre:           %s\n", persona1.nombre);
    printf("Numero de Cuenta: %d\n", persona1.nroCuenta);
    if (persona1.esArg) {

        printf("DNI:              %d\n", persona1.id.dni);
    } else {
        printf("Pasaporte:        %s \n", persona1.id.pasaporte);
    }

    persona1.esArg = 0;
    strcpy(persona1.id.pasaporte, "ABC678901234");

    printf("\nNombre:           %s\n", persona1.nombre);
    printf("Numero de Cuenta: %d\n", persona1.nroCuenta);
    if (persona1.esArg) {

        printf("DNI:              %d\n", persona1.id.dni);
    } else {
        printf("Pasaporte:        %s \n", persona1.id.pasaporte);
    }
}