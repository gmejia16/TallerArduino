// Definimos los pines de los LEDs
const int ledRojo = 8;
const int ledAmarillo = 9;
const int ledVerde = 10;

void setup() {
  // Configuramos los pines de los LEDs como salidas
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  // Encendemos el LED rojo y esperamos 5 segundos (simula semáforo en rojo)
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);

  // Encendemos el LED amarillo y esperamos 2 segundos (simula luz amarilla)
  digitalWrite(ledAmarillo, HIGH);
  delay(2000);
  digitalWrite(ledAmarillo, LOW);

  // Encendemos el LED verde y esperamos 4 segundos (simula semáforo en verde)
  digitalWrite(ledVerde, HIGH);
  delay(4000);
  digitalWrite(ledVerde, LOW);
}
