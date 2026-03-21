#include <stdint.h>
#include <stdio.h>

#include "header.h"

static void testEjercicio1() {
    uint16_t registros[] = {
        0b0001000110011010,
        0b0011010101101100,
        0b1010011000110110,
    };

    uint8_t nro_esperado[] = {1, 3, 10};
    uint8_t hum_esperada[] = {1, 5, 6};
    int8_t temp_esperada[] = {-102, 108, 54};

    int n = sizeof(registros) / sizeof(registros[0]);

    for (int i = 0; i < n; i++) {
        datosSensor_t d = obtenerDatos(registros[i]);

        if (d.nroMedicion != nro_esperado[i]) {
            printf("Error ej1[%d]: nroMedicion: %u  (esperado: %u)\n", i, d.nroMedicion, nro_esperado[i]);
            return;
        }
        if (d.humedad != hum_esperada[i]) {
            printf("Error ej1[%d]: humedad: %u  (esperado: %u)\n", i, d.humedad, hum_esperada[i]);
            return;
        }
        if (d.temperatura != temp_esperada[i]) {
            printf("Error ej1[%d]: temperatura: %d  (esperado: %d)\n", i, d.temperatura, temp_esperada[i]);
            return;
        }
    }
    printf("Ejercicio 1: OK\n");
}

static void testEjercicio2() {
    uint8_t config = 0x00;
    uint8_t esperado;

    /* Paso 1 — activar SENSOR + LED */
    config = activarBit(config, MASK_SENSOR);
    config = activarBit(config, MASK_LED);
    esperado = 0x81;
    if (config != esperado) {
        printf("Error ej2 paso 1: 0x%02X  (esperado: 0x%02X)\n", config, esperado);
        return;
    }

    /* Paso 2 — activar ALARMA */
    config = activarBit(config, MASK_ALARMA);
    esperado = 0xC1;
    if (config != esperado) {
        printf("Error ej2 paso 2: 0x%02X  (esperado: 0x%02X)\n", config, esperado);
        return;
    }

    /* Paso 3 — desactivar LED */
    config = desactivarBit(config, MASK_LED);
    esperado = 0xC0;
    if (config != esperado) {
        printf("Error ej2 paso 3: 0x%02X  (esperado: 0x%02X)\n", config, esperado);
        return;
    }

    /* Paso 4 — toggle LOW_PWR off->on */
    config = toggleBit(config, MASK_LOW_PWR);
    esperado = 0xE0;
    if (config != esperado) {
        printf("Error ej2 paso 4: 0x%02X  (esperado: 0x%02X)\n", config, esperado);
        return;
    }

    /* Paso 5 — toggle LOW_PWR on->off */
    config = toggleBit(config, MASK_LOW_PWR);
    esperado = 0xC0;
    if (config != esperado) {
        printf("Error ej2 paso 5: 0x%02X  (esperado: 0x%02X)\n", config, esperado);
        return;
    }

    /* Paso 6 — leerBit ALARMA debe ser 1 */
    uint8_t bit = leerBit(config, MASK_ALARMA);
    if (bit != 1) {
        printf("Error ej2 paso 6: leerBit(ALARMA) = %u  (esperado: 1)\n", bit);
        return;
    }

    /* Paso 7 — leerBit LED debe ser 0 */
    bit = leerBit(config, MASK_LED);
    if (bit != 0) {
        printf("Error ej2 paso 7: leerBit(LED) = %u  (esperado: 0)\n", bit);
        return;
    }

    printf("Ejercicio 2: OK\n");
}

static void testEjercicio3() {
    typedef struct {
        int8_t temp;
        uint8_t hum;
        estado_t esperado;
    } caso_t;

    caso_t casos[] = {
        {25, 60, ESTADO_NORMAL},
        {45, 50, ESTADO_ALERTA_TEMP},
        {30, 95, ESTADO_ALERTA_HUM},
        {0, 0, ESTADO_ERROR},
    };

    const char* nombres[] = {"ESTADO_NORMAL", "ESTADO_ALERTA_TEMP", "ESTADO_ALERTA_HUM", "ESTADO_ERROR"};

    int n = sizeof(casos) / sizeof(casos[0]);

    for (int i = 0; i < n; i++) {
        estado_t resultado = evaluarEstado(casos[i].temp, casos[i].hum);
        if (resultado != casos[i].esperado) {
            printf("Error ej3[%d]: temp=%d hum=%u -> %s  (esperado: %s)\n", i, casos[i].temp, casos[i].hum,
                   nombres[resultado], nombres[casos[i].esperado]);
            return;
        }
    }
    printf("Ejercicio 3: OK\n");
}