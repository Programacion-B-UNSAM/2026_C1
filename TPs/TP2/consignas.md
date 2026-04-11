# Trabajo Práctico

## Ejercicio 1

Escriba una función para el siguiente prototipo:

```c
bool_t longest_streak(int* arr,int n, int max_diff, int* start_idx, int* length);
```

La función debe encontrar la subsecuencia contigua más larga tal que la diferencia absoluta entre elementos consecutivos sea menor o igual a `max_diff`.

- La función debe devolver:
    - `1` si encuentra al menos una subsecuencia válida de longitud mayor o igual a 2
    - `0` en caso contrario
- En caso de éxito:
    - `start_idx` debe contener el índice donde comienza la subsecuencia
    - `length` debe contener la longitud de la subsecuencia

Ejemplo:

```c
intarr[]= {1,9,5,10,11,12,20};
intstart,len;

bool_tr = longest_streak(arr, 7, 2, &start, &len);

/*
Resultado esperado:
start = 3
len = 3
r = 1
*/
```

---

## Ejercicio 2

Escriba una función para el siguiente prototipo:

```c
int** build_matrix_from_file(const char* filename, int* rows, int* cols);
```

La función debe:

1. Leer un archivo de texto cuyo formato sea:

```c
filas columnas
dato dato dato ...
...
```

1. Reservar memoria dinámica para una matriz de enteros de tamaño `filas x columnas`.
2. Cargar los datos del archivo en la matriz.
3. Devolver un puntero a la matriz creada.
4. Modificar los valores de `rows` y `cols` con las dimensiones leídas.

En caso de error (archivo inexistente, formato inválido, problemas de memoria), la función debe devolver `NULL`.

---

## Ejercicio 3

Escriba una función para el siguiente prototipo:

```c
int compress_array(int* arr, int n);
```

La función debe eliminar los elementos consecutivos repetidos de un arreglo, trabajando sobre el mismo arreglo (in-place).

Debe devolver el nuevo tamaño lógico del arreglo.

Ejemplo:

```c
intarr[] = {1,1,1,2,2,3,1,1};

intnew_n = compress_array(arr, 8);

/*
Resultado esperado:
arr = {1, 2, 3, 1}
new_n = 4
*/
```

---

## Ejercicio 4

Escriba una función para el siguiente prototipo:

```c
int binary_search_closest(int* arr,int n, int target);
```

La función debe:

1. Ordenar el arreglo utilizando el algoritmo **Bubble Sort** (de menor a mayor).
2. Aplicar **Binary Search** sobre el arreglo ordenado.
3. Buscar la posición del valor `target`.

### Consideraciones:

- Si el valor `target` se encuentra en el arreglo:
    - Debe devolver el índice de alguna de sus ocurrencias.
    - La función debe funcionar correctamente aun si existen elementos duplicados.
- Si el número aparece más de una vez en la lista, la función debe devolver el índice más chico.
- Si el valor `target` **no se encuentra o s**i el arreglo está vacío (`n == 0`):
    - Debe devolver `INT32_MIN`.
- En caso de no poder determinar un valor válido:
    - Debe devolver `INT32_MIN`.

### Ejemplos:

```c
int arr[]= {10,3,7,7,20,15};

int pos_a = binary_search_closest(arr,6,7);
/*
Resultado esperado:
pos_a = índice válido donde haya un 7
*/

int pos_b = binary_search_closest(arr, 6, 8);
/*
Resultado esperado:
pos_b = índice de 7 o 10 (el más cercano)
*/

int pos_c = binary_search_closest(arr, 6, 100);
/*
Resultado esperado:
pos_c = índice de 20
*/

int pos_d = binary_search_closest(arr, 0, 5);
/*
Resultado esperado:
pos_d = INT32_MIN
*/
```