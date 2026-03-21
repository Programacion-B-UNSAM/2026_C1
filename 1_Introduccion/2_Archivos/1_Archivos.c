/*
  Gestión de Empleados en una Empresa

  Escriba un programa que gestione los empleados de una empresa.
  Los datos deben manejarse a través de archivos binarios.
  Este debe constar de las siguientes opciones:

  1) Agregar nombre:
  Pida al usuario el nombre del empleado.
  Guarde el nombre en un archivo nombres.bin como un registro único.

  2) Mostrar nombres:
  Lea todos los nombres del archivo y muéstrelos en un formato legible.

  3) Buscar nombre:
  Pida al usuario el nombre del empleado.
  Si este esta en la lista imprima el nombre y la posicion.

*/

#include <stdio.h>
#include <string.h>

void main() {
    int opcion, encontrado, posicion;
    char nombre[20], nombre2[20];
    FILE* file;
    file = fopen("nombres.bin", "wb+");
    if (file == NULL) {
        perror("Error, no exisiste el archivo");
        return;
    }

    do {
        printf("\n--------------------------");
        printf("\nSeleccione una opcion\n");
        printf("\t1: Agregar nombre\n");
        printf("\t2: Mostrar nombres\n");
        printf("\t3: Buscar nombre\n");
        printf("\t0: Cerrar programa\n");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n')
            ;

        switch (opcion) {
            case 1:
                printf("\nIngrese el nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0; //limpiar el buffer

                fseek(file, 0, SEEK_END); /* Mover el puntero al final del archivo */
                fwrite(&nombre, sizeof(nombre), 1, file);

                printf("Nombre agregado correctamente.\n");

                break;

            case 2:
                rewind(file);
                while (fread(&nombre, sizeof(nombre), 1, file) != 0) {
                    printf("%s \n", nombre);
                }
                break;

            case 3:
                encontrado = 0;
                posicion = 0;
                rewind(file);

                printf("\nIngrese el nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0; //limpiar el buffer

                while (fread(&nombre2, sizeof(nombre2), 1, file) != 0) {
                    if (strstr(nombre2, nombre) != NULL) {
                        printf("Se encontro el nombre $s, en la pos %d", nombre, posicion);
                        encontrado = 1;
                        break;
                    }
                    posicion++;
                }
                if (encontrado != 1) {
                    printf("No se encontro el nombre\n");
                }

                break;

            default: printf("opcion no valida"); break;
        }

    } while (opcion != 0);

    fclose(file);
    return;
}
