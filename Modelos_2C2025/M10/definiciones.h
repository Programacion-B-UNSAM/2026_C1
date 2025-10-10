#ifndef definiciones
#define definiciones

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

typedef struct file_struct_t
{
    int num1;
    int num2;
    unsigned int num3;
} file_struct_t;

typedef struct data_t
{
    int num;
    char let;
} data_t;

typedef struct dnode_t
{
    struct data_t *data;
    struct dnode_t *prev;
    struct dnode_t *next;
} dnode_t;

/* Puede comentar o des-comentar los siguientes define a medida que lo necesite*/
#define EJ1
#define EJ2

/* ============= Comienzo de sus prototipos ============= */

/* ===============  Fin de sus prototipos =============== */

/* Prototipos de Catedra_4.c (NO USAR) */
dnode_t *CATEDRA_CrearLista(void);

#endif