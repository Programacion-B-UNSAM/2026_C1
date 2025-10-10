#ifndef definiciones
#define definiciones

/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct dNode {
    int data;
    struct dNode *next;
    struct dNode *prev;
} dNode;

/* Puede comentar o des-comentar los siguientes define a medida que lo necesite*/
#define EJ1
#define EJ2
#define EJ3

#endif