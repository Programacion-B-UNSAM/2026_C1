/*
Se tiene un sensor que mide temperatura y humedad

    int datosSensor = 0b1001010111100010;
    los 8 bits mas significativos corresponden a los datos de Humedad
    los 8 bits menos significativos corresponden a los datos de Temperatura

    Imprima los datos en pantalla

 */

#include <stdio.h>

int main() {
    int Humedad, Temperatura;
    int datosSensor = 0b1001010111100010;
                    
    Humedad = datosSensor >> 8;
    Temperatura = datosSensor & 0xFF; // 0b0000000011111111;

    printf("Temperatura : \t %d\n", Temperatura);
    printf("Humedad : \t %d\n", Humedad);
   

    return 0;
}