#include "definiciones.h"
#include <stdlib.h>

#include "Catedra_7.c"

#define MAX_LIST_SIZE 1000
int *read_file(char filename[], int *list_size);

void col_fil(qnode_t *primerNodo)
{
  qnode_t *current = primerNodo;
  int columnas = 0;
  while (current != NULL)
  {
    current = current->right;
    columnas++;
  }
  printf("\nHay %3d columnas\n", columnas);

  qnode_t *current2 = primerNodo; /* podria usar current */
  int filas = 0;
  while (current2 != NULL)
  {
    current2 = current2->down;
    filas++;
  }
  printf("Hay %3d filas\n", filas);
}

void imprimir_binario(int num)
{
  printf("%6d = 0b ", num);
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (num >> i) & 0b1);
    if ((i % 4) == 0)
    {
      printf(" ");
    }
  }
  printf("\n");
}

int main(void)
{
#ifdef EJ1

  int list_size = 0;
  int *list = read_file("archivo_7.bin", &list_size);

  int encontrado;
  // int lista_ejemplo = {1, 4, 5, 1, 7};

  /*
  i = 0 --> caigo en el else
  i = 1 --> lista[0] = 1 ==> encontrado = 1
            lista[1] = 4 ==> encontrado = 0
            lista[2] = 5 ==> encontrado = 0
            lista[3] = 1 ==> encontrado = 1
            lista[4] = 7 ==> encontrado = 0; //termine de recorrer el loop interno
  */

  /* 1) 3. */
  // list[0] = 1001;
  for (int i = 0; i < 101; ++i)

  { /* i va de 0 a 100 */
    for (int j = 0; j < list_size; ++j)
    {
      int num_lista = list[j];
      if (i == list[j])
      {                 /* si esto se cumple : el numero esta en la lista */
        encontrado = 1; /* si lo encuentro quiero salir */
        break;
      }
      else
      {
        encontrado = 0;
      }
    }
    if (encontrado == 0)
    {
      // printf("%3d no esta en la lista\n", i);
    }
  }

  //       segundos  primeros
  // 0b 11 1100 0011 1111 0000
  // 0b 11 1111 0000 1100 0011
  // 0xF = 0b1111 --> 0xFF = 0b1111 1111
  // 0x0 = 0b0000 --> 0x00 = 0b0000 0000
  int num = 0b11100101010110101100001111110000;
  imprimir_binario(num);

  /* aislo los 8 menos significativos y los 8 subsecuentes (el primer y segundo byte) */
  int primeros8 = num & 0xFF; /* los menos significativos */
  // imprimir_binario(primeros8);
  /* como se que el numero < 65536, el and no es necesario */
  int segundos8 = (num >> 8) & 0xFF; /* los 8 subsecuentes (2do byte menos significatvio) */
  // imprimir_binario(segundos8);
  num = num & ~0xFFFF; /* = 0b00000000000000000000000000000000 */

  int swap = (primeros8 << 8) | segundos8;
  int num1 = num | swap;
  imprimir_binario(num1);

#endif

#ifdef EJ2

  qnode_t *primerNodo = CATEDRA_CrearGrilla();

  /*
     ↓
    {9,  23, 35, 6,  11, 27, 34, 12, 36, 31, 20, 25, 26   --> NULL,
    {2,  39, 30, 5,  8,  29, 37, 13, 17, 6,  7,  36, 0    --> NULL,
    {4,  33, 9,  1,  14, 21, 11, 28, 18, 38, 22, 32, 3    --> NULL
    {35, 15, 10, 26, 12, 37, 39, 13, 19, 7,  4,  3,  30}, --> NULL
    {16, 24, 8,  27, 0,  31, 2,  18, 38, 19, 17, 15, 25}, --> NULL
    {22, 20, 1,  10, 5,  21, 23, 29, 28, 34, 14, 32, 8},  --> NULL
    {6,  36, 33, 7,  2,  11, 24, 26, 13, 12, 16, 9,  0},  --> NULL
    {4,  27, 5,  31, 23, 3,  18, 25, 21, 10, 17, 39, 29}, --> NULL
    {15, 1,  35, 20, 38, 37, 30, 19, 8,  7,  14, 22, 28}} --> NULL;
  */

  col_fil(primerNodo);

  qnode_t *actual = primerNodo;
  qnode_t *aux = actual;
  while (actual != NULL)
  {
    aux = actual; /* para mantener el puntero al primer nodo de la fila */
    while (aux != NULL)
    {
      printf("%3d ", aux->valor);
      aux = aux->right;
    }
    printf("\n");
    actual = actual->down;
  }

#endif

  return 0;
}

int *read_file(char filename[], int *list_size)
{
  int *list = (int *)malloc(MAX_LIST_SIZE * sizeof(int));
  if (list == NULL)
  {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  FILE *file;

  file = fopen(filename, "rb");
  int num;
  *list_size = 0;
  while (fread(&num, sizeof(num), 1, file))
  {
    // printf("%d - %d\n", *list_size, num);

    list[*list_size] = num;
    (*list_size)++;
  }
  fclose(file);
  list = (int *)realloc(list, *list_size * sizeof(int));
  if (list == NULL)
  {
    printf("Memory allocation failed!\n");
    return NULL;
  }
  // printf("List size = %d\n", *list_size);
  return list;
}