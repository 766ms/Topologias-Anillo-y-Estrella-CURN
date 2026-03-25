/**
 * @file topologia_anillo.cpp
 * @author Sara C. B., Yudis F. A., José G. M., Kenderson G. R.
 * @brief Recurso educativo: Simulación física de Topología Anillo.
 * Representa el flujo circular de datos (paso de testigo o token).
 */

#include <Arduino.h>

// Definición de los pines que forman el anillo físico
const int PINES_ANILLO[] = {8, 9, 10, 11, 12};
const int CANTIDAD_NODOS = 5;

void setup() {
  // Inicialización de todos los nodos del anillo
  for (int i = 0; i < CANTIDAD_NODOS; i++) {
    pinMode(PINES_ANILLO[i], OUTPUT);
  }
}

void loop() {
  // Simulación del movimiento del "Token" a través de la red
  for (int i = 0; i < CANTIDAD_NODOS; i++) {
    // El nodo actual recibe el token y procesa la información
    digitalWrite(PINES_ANILLO[i], HIGH);
    delay(400); 
    
    // El nodo libera el token y lo pasa al vecino
    digitalWrite(PINES_ANILLO[i], LOW);
    
    // Pequeña pausa para visualizar el salto entre nodos
    delay(50); 
  }
}
