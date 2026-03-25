/**
 * @file topologia_estrella.cpp
 * @author Sara C. B., Yudis F. A., José G. M., Kenderson G. R.
 * @brief Recurso educativo: Simulación física de Topología Estrella.
 * El Arduino actúa como el nodo central (Hub/Switch) gestionando la red.
 */

#include <Arduino.h>

// Definición de pines para los nodos periféricos
const int NODO_CENTRAL = 2; 
const int NODOS_PERIFERICOS[] = {3, 4, 5, 6}; 
const int TOTAL_NODOS = 4;

void setup() {
  // Configuración de pines como salida
  pinMode(NODO_CENTRAL, OUTPUT);
  for (int i = 0; i < TOTAL_NODOS; i++) {
    pinMode(NODOS_PERIFERICOS[i], OUTPUT);
  }
}

void loop() {
  // 1. El nodo central inicia la transmisión (Broadcast)
  digitalWrite(NODO_CENTRAL, HIGH);
  delay(500); // Tiempo de procesamiento del Switch

  // 2. Envío secuencial de datos a cada terminal
  for (int i = 0; i < TOTAL_NODOS; i++) {
    digitalWrite(NODOS_PERIFERICOS[i], HIGH);
    delay(200);
    digitalWrite(NODOS_PERIFERICOS[i], LOW);
  }

  // 3. Fin del ciclo de transmisión
  digitalWrite(NODO_CENTRAL, LOW);
  delay(1500);
}
