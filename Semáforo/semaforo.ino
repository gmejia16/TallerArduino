#define LED_ROJO 2
#define LED_AMARILLO 3
#define LED_VERDE 4

void setup() {
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
}

void loop() {
    digitalWrite(LED_ROJO, HIGH);  
    delay(3000);  
    digitalWrite(LED_ROJO, LOW);

    digitalWrite(LED_AMARILLO, HIGH);  
    delay(1000);  
    digitalWrite(LED_AMARILLO, LOW);

    digitalWrite(LED_VERDE, HIGH);  
    delay(3000);  
    digitalWrite(LED_VERDE, LOW);
}
