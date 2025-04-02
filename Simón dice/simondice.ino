// Definición de pines para LEDs y botones
const int ledPins[] = {6, 7, 8, 9};  // LEDs conectados a estos pines
const int buttonPins[] = {2, 3, 4, 5}; // Botones conectados a estos pines

const int sequenceLength = 10; // Longitud máxima de la secuencia
int gameSequence[sequenceLength]; // Almacena la secuencia generada
int userInput[sequenceLength]; // Almacena la secuencia ingresada por el usuario

int currentRound = 1; // Número de elementos a recordar en la ronda actual

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0)); // Inicializar aleatoriedad con una lectura analógica

    // Configurar pines de LEDs y botones
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    delay(1000); // Pequeña pausa antes de comenzar el juego
}

void loop() {
    generateSequence(); // Crear la secuencia del juego

    while (true) {
        playSequence(); // Mostrar la secuencia con LEDs

        if (!getUserInput()) { // Capturar y verificar la entrada del usuario
            Serial.println("Juego terminado. Inténtalo de nuevo.");
            delay(2000);
            currentRound = 1; // Reiniciar el juego
        } else {
            Serial.println("¡Bien hecho! Pasando a la siguiente ronda.");
            currentRound++; // Avanzar a la siguiente ronda
            if (currentRound > sequenceLength) {
                Serial.println("¡Felicidades! Completaste el juego.");
                currentRound = 1; // Reiniciar si gana
            }
        }

        delay(1000); // Pequeña pausa antes de la siguiente ronda
    }
}

// Genera la secuencia aleatoria para el juego
void generateSequence() {
    for (int i = 0; i < sequenceLength; i++) {
        gameSequence[i] = random(0, 4); // Valores entre 0 y 3 (correspondientes a los LEDs)
    }
}

// Muestra la secuencia de LEDs hasta la ronda actual
void playSequence() {
    Serial.print("Mostrando secuencia: ");
    for (int i = 0; i < currentRound; i++) {
        int led = gameSequence[i];
        digitalWrite(ledPins[led], HIGH);
        Serial.print(led);
        Serial.print(" ");
        delay(500);
        digitalWrite(ledPins[led], LOW);
        delay(250);
    }
    Serial.println();
}

// Captura la entrada del usuario y la compara con la secuencia generada
bool getUserInput() {
    Serial.println("Introduce la secuencia:");

    for (int i = 0; i < currentRound; i++) {
        bool buttonPressed = false;
        int pressedButton = -1;

        while (!buttonPressed) { // Esperar a que el usuario presione un botón válido
            for (int j = 0; j < 4; j++) {
                if (digitalRead(buttonPins[j]) == LOW) { // Botón presionado
                    buttonPressed = true;
                    pressedButton = j;
                    while (digitalRead(buttonPins[j]) == LOW); // Esperar a que suelte el botón
                    delay(100); // Evitar rebotes
                }
            }
        }

        Serial.print("Botón presionado: ");
        Serial.println(pressedButton);

        userInput[i] = pressedButton;

        if (userInput[i] != gameSequence[i]) { // Comparar con la secuencia correcta
            Serial.println("Secuencia incorrecta.");
            return false; // Fin del juego si hay error
        }
    }

    return true; // Si completó la secuencia correctamente
}
