#define NUM_LEDS 4
int leds[NUM_LEDS] = {2, 3, 4, 5};  
int botones[NUM_LEDS] = {6, 7, 8, 9};  
int secuencia[10];  
int nivel = 0;

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        pinMode(botones[i], INPUT_PULLUP);
    }
    iniciarJuego();
}

void loop() {
    mostrarSecuencia();
    if (!verificarEntrada()) {
        Serial.println("Juego terminado");
        iniciarJuego();
    } else {
        nivel++;
        if (nivel == 10) {
            Serial.println("¡Ganaste!");
            iniciarJuego();
        }
    }
}

void iniciarJuego() {
    nivel = 0;
    for (int i = 0; i < 10; i++) {
        secuencia[i] = random(NUM_LEDS);
    }
    delay(1000);
}

void mostrarSecuencia() {
    Serial.println("Memoriza esta secuencia:");
    for (int i = 0; i <= nivel; i++) {
        digitalWrite(leds[secuencia[i]], HIGH);
        delay(500);
        digitalWrite(leds[secuencia[i]], LOW);
        delay(250);
    }
}

bool verificarEntrada() {
    for (int i = 0; i <= nivel; i++) {
        bool presionado = false;
        while (!presionado) {
            for (int j = 0; j < NUM_LEDS; j++) {
                if (digitalRead(botones[j]) == LOW) {
                    presionado = true;
                    if (j != secuencia[i]) return false;
                    digitalWrite(leds[j], HIGH);
                    delay(300);
                    digitalWrite(leds[j], LOW);
                }
            }
        }
    }
    return true;
}
