#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"

#include "Catedra_M12.c"
#include "funciones.c"

int main(void) {

#ifdef EJ1
    /* (Q | 2) - ( | 10) - (W | 2) - ( | 10) - (F | 7) - (E | 2) - (R | 2) - ( | 11) - (x | 2) - (y | 2) - ( | 10) - (z | 2) - (C | 2) - (  | 2) - (F | 7) - (n | 2) - ( | 3) - (e | 2) - (  | 2) - (n | 2) - ( | 3) - (o | 2) - (F | 7) - (i | 2) - (c | 2) - (a | 2) - ( | 10) - (m | 2) - (a | 2) - (F | 7) - (r | 2) - ( | 3) - (g | 2) - (o | 2) - (r | 2) - (P | 2) -  */
    
    printf("\n=== EJERCICIO 1 ===\n");
    char file[] = "M12.dat";
    FILE *fp = fopen(file, "rb"); /* Siempre cuando solo queremos leer usamos rb! */
    node_t *lfirst = NULL;
    M12_t aux;

    while(fread(&aux, sizeof(M12_t), 1, fp)){
        // printf("(%c | %hu) - ", aux.dato, aux.mask);
        uint16_t op = aux.mask;
        switch(op){ 
            case 10:  /* Toggle circular */
                toggle_circ(&lfirst);
                break;

            case 11:  /* Liberar lista */
                free_list(&lfirst);
                break;

            case 0b10: /* Insertar first */
                ins_first(&lfirst, aux.dato);
                break;

            case 0b11: /* Eliminar ultimo */
                del_last(&lfirst);
                break;

            default:
                continue;

        }
        print_list(lfirst);
    }
    free_list(&lfirst);
    fclose(fp);

#endif

#ifdef EJ2
    printf("\n=== EJERCICIO 2 ===\n");
    qnode_t* first = CATEDRA_CrearGrilla();
    showGrilla(first);
    printMinas(first);
    findMina(first, 1, 5);
#endif

    return 0;
}