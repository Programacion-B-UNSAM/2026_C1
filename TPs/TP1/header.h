#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdio.h>

#define EJ1
#define EJ2
#define EJ3

#define MASK_SENSOR
#define MASK_ALARMA
#define MASK_LOW_PWR
#define MASK_LED

typedef struct {
} datosSensor_t;

typedef enum {
    ESTADO_NORMAL,
    ESTADO_ALERTA_TEMP,
    ESTADO_ALERTA_HUM,
    ESTADO_ERROR,
} estado_t;

datosSensor_t obtenerDatos(uint16_t dato);

uint8_t activarBit(uint8_t registro, uint8_t mascara);
uint8_t desactivarBit(uint8_t registro, uint8_t mascara);
uint8_t leerBit(uint8_t registro, uint8_t mascara);
uint8_t toggleBit(uint8_t registro, uint8_t mascara);

estado_t evaluarEstado(int8_t temp, uint8_t hum);
void imprimirEstado(estado_t estado);

#endif /* HEADER_H */
