#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#define CAPTURE_BUF 256

static void capture_call(void (*fn)(GraphNode *, int), GraphNode *root, int arg, char *buf, int buf_size)
{
    /* Use temporary file for cross-platform stdout capture */
    const char *temp_filename = "catedra_output.tmp";

    /* Redirect stdout to temporary file */
    if (freopen(temp_filename, "w", stdout) == NULL)
    {
        perror("freopen");
        exit(1);
    }

    /* Call the function */
    fn(root, arg);
    fflush(stdout);

    /* Restore stdout to console */
#ifdef _WIN32
    freopen("CON", "w", stdout);
#else
    freopen("/dev/stdout", "w", stdout);
#endif

    /* Read captured output from temporary file */
    FILE *temp_file = fopen(temp_filename, "r");
    if (temp_file == NULL)
    {
        perror("fopen");
        exit(1);
    }

    int n = fread(buf, 1, buf_size - 1, temp_file);
    buf[n] = '\0';
    fclose(temp_file);

    /* Delete temporary file */
    remove(temp_filename);

    /* Strip trailing newline */
    int len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
    }
}

/* ===== Ejercicio 1 ===== */

void testEjercicio1(void)
{
    BSTNode *root;
    int found;

    /* caso 1: árbol del enunciado */
    int arr1[] = {1, 8, 5, 10, 11, 12, 20, 9};
    createTree(arr1, 8, &root);

    found = findNode(root, 11);
    if (found != 1)
    {
        printf("\nError ej1 caso 1a: findNode(11) = %d (esperado 1)\n", found);
        return;
    }

    found = findNode(root, 9);
    if (found != 1)
    {
        printf("\nError ej1 caso 1b: findNode(9) = %d (esperado 1)\n", found);
        return;
    }

    found = findNode(root, 7);
    if (found != 0)
    {
        printf("\nError ej1 caso 1c: findNode(7) = %d (esperado 0)\n", found);
        return;
    }

    /* caso 2: buscar la raíz */
    found = findNode(root, 1);
    if (found != 1)
    {
        printf("\nError ej1 caso 2: findNode(1) = %d (esperado 1)\n", found);
        return;
    }

    /* caso 3: árbol de un solo elemento */
    int arr2[] = {42};
    createTree(arr2, 1, &root);

    found = findNode(root, 42);
    if (found != 1)
    {
        printf("\nError ej1 caso 3a: findNode(42) = %d (esperado 1)\n", found);
        return;
    }

    found = findNode(root, 0);
    if (found != 0)
    {
        printf("\nError ej1 caso 3b: findNode(0) = %d (esperado 0)\n", found);
        return;
    }

    /* caso 4: degenerado a la derecha */
    int arr3[] = {1, 2, 3, 4, 5};
    createTree(arr3, 5, &root);

    found = findNode(root, 5);
    if (found != 1)
    {
        printf("\nError ej1 caso 4: findNode(5) = %d (esperado 1)\n", found);
        return;
    }

    /* caso 5: degenerado a la izquierda */
    int arr4[] = {5, 4, 3, 2, 1};
    createTree(arr4, 5, &root);

    found = findNode(root, 1);
    if (found != 1)
    {
        printf("\nError ej1 caso 5: findNode(1) = %d (esperado 1)\n", found);
        return;
    }

    printf("Ejercicio 1: OK\n");
}

/* ===== Ejercicio 2 ===== */

static int check_min_dist(GraphNode *root, int level, const char *expected_str, const char *caso_label)
{
    char buf[CAPTURE_BUF];
    capture_call(minDistAtLevel, root, level, buf, CAPTURE_BUF);

    if (strcmp(buf, expected_str) != 0)
    {
        printf("\nError ej2 %s: nivel %d\n"
               "  obtenido:  \"%s\"\n"
               "  esperado:  \"%s\"\n",
               caso_label, level, buf, expected_str);
        return 0;
    }
    return 1;
}

void testEjercicio2(void)
{
    GraphNode *root = NULL;

    /* caso 1: grafo del enunciado
     *
     *      A (nivel 0)
     *     / \
     *   4/   \2
     *   B     C  (nivel 1)
     *  / \     \
     * 5/  \1   8\
     * D    E     F  (nivel 2)
     *
     * nivel 0 -> 0, nivel 1 -> 2 (A->C), nivel 2 -> 5 (A->B->E)
     */
    tnode_info_t g1[] = {
        {'\0', 'A', 0},
        {'A', 'B', 4},
        {'A', 'C', 2},
        {'B', 'D', 5},
        {'B', 'E', 1},
        {'C', 'F', 8},
    };
    createGraph(g1, 6, &root);

    if (root == NULL || root->nombre != 'A')
    {
        printf("\nError seg fault\n");
        return;
    }
    // if (root->nombre != 'A')
    // {
    //     printf("\nError --> raiz incorrecta");
    //     return;
    // }
    if (root->num_children != 2)
    {
        printf("\nError ej2 caso 1: A deberia tener 2 hijos, tiene %d\n", root->num_children);
        return;
    }

    if (!check_min_dist(root, 0, "Min distance to level 0: 0", "caso 1"))
    {
        return;
    }
    if (!check_min_dist(root, 1, "Min distance to level 1: 2", "caso 1"))
    {
        return;
    }
    if (!check_min_dist(root, 2, "Min distance to level 2: 5", "caso 1"))
    {
        return;
    }

    /* caso 2: un solo nodo */
    tnode_info_t g2[] = {
        {'\0', 'Z', 0},
    };
    createGraph(g2, 1, &root);

    if (!root || root->nombre != 'Z')
    {
        printf("\nError ej2 caso 2: raiz incorrecta\n");
        return;
    }
    if (!check_min_dist(root, 0, "Min distance to level 0: 0", "caso 2"))
    {
        return;
    }

    /* caso 3: camino lineal A -10-> B -1-> C -1-> D
     * nivel 3 -> 12
     */
    tnode_info_t g3[] = {
        {'\0', 'A', 0},
        {'A', 'B', 10},
        {'B', 'C', 1},
        {'C', 'D', 1},
    };
    createGraph(g3, 4, &root);
    if (!check_min_dist(root, 3, "Min distance to level 3: 12", "caso 3"))
    {
        return;
    }

    /* caso 4: raíz con 3 hijos de distintos pesos
     * R -> A(1), B(5), C(3)  ->  nivel 1 minima = 1
     */
    tnode_info_t g4[] = {
        {'\0', 'R', 0},
        {'R', 'A', 1},
        {'R', 'B', 5},
        {'R', 'C', 3},
    };
    createGraph(g4, 4, &root);
    if (!check_min_dist(root, 1, "Min distance to level 1: 1", "caso 4"))
    {
        return;
    }

    /* caso 5: minimo no es el primer hijo
     *
     *         R (nivel 0)
     *        / \
     *      10/   \1
     *       X     Y  (nivel 1)
     *      / \     \
     *    1/   \1   1\
     *    P     Q     S  (nivel 2)
     *
     * nivel 2: R->X->P=11, R->X->Q=11, R->Y->S=2  ->  minima = 2
     */
    tnode_info_t g5[] = {
        {'\0', 'R', 0},
        {'R', 'X', 10},
        {'R', 'Y', 1},
        {'X', 'P', 1},
        {'X', 'Q', 1},
        {'Y', 'S', 1},
    };
    createGraph(g5, 6, &root);
    if (!check_min_dist(root, 2, "Min distance to level 2: 2", "caso 5"))
    {
        return;
    }

    printf("Ejercicio 2: OK\n");
}
