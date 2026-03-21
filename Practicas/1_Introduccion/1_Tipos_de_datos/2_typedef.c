#include <stdint.h>
#include <stdio.h>

typedef enum {
    falso = 0,
    verdadero = 1,
} boolean_t;

typedef enum {
    Mostrar = 0,
    Editar = 1,
    Borrar = 2,
    Agregar = 3,
    Salir = 4,
} opciones_t;

// int main() {
//     boolean_t esAlumno = falso;

//     if (esAlumno) {
//         printf("\n\nSe cumple la condicion\n\n");
//     }

//     return 0;
// }

int main() {
    opciones_t opcionSeleccionada = Salir;

    printf("\n\nSe selecciono la opcion:\n\t");

    switch (opcionSeleccionada) {
        case Mostrar: {
            printf("Mostrar");
            break;
        }
        case Editar: {
            printf("Editar");
            break;
        }
        case Borrar: {
            printf("Borrar");
            break;
        }
        case Agregar: {
            printf("Agregar");
            break;
        }
        case Salir: {
            printf("Salir");
            break;
        }

        default: {
            printf("No valido");
            break;
        }
    }

    printf("\n\n");

    return 0;
}