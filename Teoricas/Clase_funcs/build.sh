# Este archivo sirve para correr proyectos en Linux (WSL)
#!/bin/bash
set -e   # hace que el script se detenga si algún comando falla

gcc -c main.c -o main.o
gcc -c funciones.c -o funciones.o
gcc main.o funciones.o -o ejemplo_proyecto

echo "Ejecutando ejemplo_proyecto..."
./ejemplo_proyecto
