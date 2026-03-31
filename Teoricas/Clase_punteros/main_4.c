#include <stdio.h>

// #define PRINT_MEMORY
// #define POINTER_OPERATORS
#define POINTER_and_ARRAYS
// #define POINTER_ARITHMETIC
// #define BONUS_TRACK

#define LEN 3

double jim_global = 99999999;

int main(void)
{

#ifdef PRINT_MEMORY
    char is_jim_smart = 0; /* Es un booleano */
    long long jims_birth = 1111999;
    char jims_initial = 'j';
    float jims_height = 1.81;

    printf("Memory (pile) \t\t Computer Address \t Variable Name\n");

    printf("|-------|\n");
    printf("|1 byte | \t\t %p \t char is_smart\n", &is_jim_smart);
    printf("|-------|\n");
    printf("|1 byte | \t\t %p \t char initial\n", &jims_initial);
    printf("|-------|\n");
    printf("|       | \t\t %p \t float height\n", &jims_height);
    printf("|       |\n");
    printf("|4 bytes|\n");
    printf("|       |\n");
    printf("|-------|\n");
    printf("|       | \t\t %p \t long long birth\n", &jims_birth);
    printf("|8 bytes|\n");
    printf("|       |\n");
    printf("|       |\n");

    printf("\n\n");
    printf("This is the data segment\n");
    printf("|-------|\n");
    printf("|       | \t\t %p \t double jim_global\n", (void *)&jim_global);
    printf("|-------|\n");
#endif

#ifdef POINTER_OPERATORS

    int var = 10;
    int var2 = 30;

    int *ptr;
    ptr = &var;

    /* Imprimen lo mismo */
    printf("\nptr vs &var\n");
    printf(" ptr = \t %p\n", ptr); /* lo que esta adentro de ptr */
    printf("&var = %p\n", &var);
    ;
    /*      Lo que esta 'adentro' de ptr es la direccion de memoria de var
     *      (*) me devuelve lo que esta adentro de la direccion de memoria
     *      a la que apunta su operando
     *      *ptr --> me devuelve lo que esta adentro de &var
     *      *(&var)
     */

    /* Imprimen lo mismo*/

    *ptr = 20;

    printf("\n*ptr vs var\n");
    printf("*ptr = \t %d\n", *ptr);
    printf(" var = \t %d\n", var);

    int var = 10;
    *(&var) =

    /* var --> se donde esta var, y puedo modificarla
     * ptr --> se donde esta var, y puedo modificarla. Pero tambine puedo hacer
     *         que ptr apunte a otra variable (var2) y modificarla
     */

    /* Conociendo el valor de ptr puedo:
     *    --> por un lado saber donde esta guardada la informacion de var (ptr) y, ademas,
     *    --> puedo acceder y modificar la informacion que esta guardada en var
     */

#endif

#ifdef POINTER_and_ARRAYS

        double arr[LEN] = {1E8, 3.8E6, 5E5};
    double *p_arr;

    p_arr = arr; /* arr es un puntero constante que apunta siempre a &(arr[0])*/
    printf("double *p_arr = arr =\t\t %p\n", p_arr);
    p_arr = &arr[0];
    printf("double *p_arr = &arr[0] =\t %p\n", p_arr);

    printf("\n--------------------------------------------\n");

    /* Going through the vector */
    for (int i = 0; i < LEN; i++)
    {
        printf("arr[%d] = \t %lf\n", i, arr[i]); /* Imprime el vallor de arr[i]*/
        /* 1) 1E8     ->  2)  3.8E6   -> 3) 5*/
        /* Imprime el valor de la variable a la que apunta el puntero */

        printf("arr[%d] = \t %lf\t\t (p_arr = %p)\n\n", i, *p_arr, p_arr);
        p_arr++;
        /* 1)arr[0] = 1E8 (p_arr = 0xAA0)     ->  2)arr[2] = 3.8E6 (p_arr = 0xAA8)
           -> 3)arr[3] = 5 (p_arr = 0xAB0) */
    }
#endif

#ifdef POINTER_ARITHMETIC

    short a, b, add = 2, aux;
    short *ptr_a = &a, *ptr_b = &b;

    printf("Original pointers: ptr_a = %p | ptr_b = %p\n", ptr_a, ptr_b);
    printf("They are both shorts (2 bytes)\n");

    printf("\n1. Increment/Decrement\n");
    ptr_a++;
    printf("ptr_a++ = %p\n", ptr_a--); /* uso el -- para recuperar la direc original */
    ptr_b--;
    printf("ptr_b-- = %p\n", ptr_b++); /* uso el ++ para recuperar direc original */

    printf("\n2. Addition / Substraction of integer to pointer\n");
    ptr_a = ptr_a + add; /* ptr_a = ptr_a + sizeof(short) * value(add)*/
    printf("ptr_a + %d = \t\t %p\n", add, ptr_a);
    ptr_a = ptr_a - add;
    printf("(ptr_a + %d) - %d =\t %p  (recupero original)\n", add, add, ptr_a);

    printf("\n3. Substracting 2 pointers of the same type\n");
    aux = ptr_a - ptr_b;
    printf("ptr_a - ptr_b = %d\n", aux);

    printf("\n4. Pointer Comparisson\n");
    if (ptr_a >= ptr_b)
        printf("ptra >= ptr_b\n\n");
    else
        printf("ptr_a < ptr_b\n\n");

#endif

#ifdef BONUS_TRACK
    /* Punteros a structs / unions */
    struct myStruct
    {
        int a;
        char b;
    } s1;
    struct myStruct *ps1 = &s1;
    ps1->a = 50;
    s1.b = 'h';

    printf("s1.a   = \t%d \t | s1.b   = \t%c\n", s1.a, s1.b);
    printf("ps1->a = \t%d \t | ps1->b = \t%c\n", ps1->a, ps1->b);

    printf("\n\n");
    /* Punteros a punteros */
    printf("\n\n");

    int var = 10;
    int *ptr = &var;
    int **ptr2 = &ptr;

    printf("Direcciones de memoria: \n");
    printf("var  = \t%d\t\t[en %p]\n", var, &var);
    printf("ptr  = \t%p \t[en %p]\n", ptr, &ptr);
    printf("ptr2 = \t%p \t[en %p]\n", ptr2, &ptr2);

    printf("\nDes-referenciando ptr2: \n");
    printf("  ptr2 = \t%p\n", ptr2);
    printf(" *ptr2 = \t%p\n", *ptr2);
    printf("**ptr2 = \t%d\n", **ptr2);

#endif

    return 0;
}