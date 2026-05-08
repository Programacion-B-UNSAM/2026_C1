# Trabajo Práctico

## Ejercicio 1

1. Implemente la función createTree que reciba un arreglo de enteros y construya un Árbol Binario de Búsqueda insertando los elementos en el orden en que aparecen en el arreglo.
```c
void createTree(int *arr, int size, Node **root);
```

2. Implemente la función findNode que, dado un valor entero, realice lo siguiente:
    - Imprima el camino recorrido desde la raíz como una secuencia de direcciones ```R```(derecha) o ```L```(izquierda). 
    - Devuelva ```1``` si el nodo fue encontrado, o ```0``` en caso contrario.
```c

int findNode(Node *root, int value);
```

Ejemplo:
```c
int arr[]= {10, 8, 5, 11, 12, 13, 9};
Node * root;

createTree(arr, 7, &root);

/* Arbol creado:
    10
   / \
  8   11
 / \    \
5    9   12
          \
           13
*/

int found 
found = findNode(root, 11);
// R -> R
// found = 1;

found = findNode(root, 9);
// L -> R
// found = 1;
```

## Ejercicio 2

1. A partir de una lista de structs del tipo 
```c
typedef struct tnode_info_t {
	char nombre_padre;
	char nombre_propio;
	int  dist_a_padre;
} tnode_info_t;
```
construya un grafo dirigido y con pesos que conecte todos los nodos según la relación padre–hijo indicada.

2. Implemente una función que, dado el nodo raíz y un número de nivel, imprima la distancia mínima acumulada para alcanzar cualquier nodo que se encuentre en ese nivel. La raíz corresponde al nivel 0.
```c
void minDistAtLevel(Node *root, int level);
```

```c
tnode_info_t nodos[] = {
    {'\0', 'A',  0},  // A es la raíz
    { 'A', 'B',  4},
    { 'A', 'C',  2},
    { 'B', 'D',  5},
    { 'B', 'E',  1},
    { 'C', 'F',  8},
};

/*  Grafo:
         A (nivel 0)
        / \
      4/   \2
      B     C  (nivel 1)
     / \     \
   5/   \1   8\
   D     E     F  (nivel 2)
*/

minDistAtLevel(root, 0);  // min. dis: 0  (nodo A)
minDistAtLevel(root, 1);  // min. dis: 2  (A→C)
minDistAtLevel(root, 2);  // min. dis: 5  (A→B→E)
```