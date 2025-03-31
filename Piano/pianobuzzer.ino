#include <Arduino.h>

#define BUZZER_PIN 9

const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 10}; // Pines de los botones
const int tones[] = {262, 294, 330, 349, 392, 440, 494, 523}; // Notas (DO, RE, MI, FA, SOL, LA, SI, DO')
const int numButtons = 8;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    for (int i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

void loop() {
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            tone(BUZZER_PIN, tones[i]); // Reproducir la nota
        }
    }
    if (allButtonsReleased()) {
        noTone(BUZZER_PIN); // Detener el sonido si no hay botones presionados
    }
}

bool allButtonsReleased() {
    for (int i = 0; i < numButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            return false;
        }
    }
    return true;
}
