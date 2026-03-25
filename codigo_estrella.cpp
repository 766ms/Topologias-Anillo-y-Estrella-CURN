// --- Recurso Educativo: Topología Estrella ---
// Nodo Central: Arduino UNO
// Nodos Periféricos: LEDs Azules

const int centro = 2; // Pin que simula el envío desde el Switch
const int nodos[] = {3, 4, 5, 6}; // Pines de los nodos receptores

void setup() {
  pinMode(centro, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(nodos[i], OUTPUT);
  }
}

void loop() {
  // Simulación de difusión (Broadcast) desde el centro
  digitalWrite(centro, HIGH); 
  delay(200);
  
  // Los nodos reciben la señal del centro secuencialmente
  for (int i = 0; i < 4; i++) {
    digitalWrite(nodos[i], HIGH);
    delay(150);
    digitalWrite(nodos[i], LOW);
  }
  
  digitalWrite(centro, LOW);
  delay(1000);
}
