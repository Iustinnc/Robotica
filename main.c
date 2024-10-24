#include <Arduino.h>

#define R 6 // Pin pentru LED roșu
#define G 5 // Pin pentru LED verde
#define B 4 // Pin pentru LED albastru

#define L1 10
#define L2 9
#define L3 8
#define L4 7

#define START 3
#define STOP 2

bool ok = false; // Variabilă pentru a controla execuția animației

// Variabile pentru debounce buton START
unsigned long lastDebounceTimeStart = 0; // Ultima dată când butonul a fost apăsat
const unsigned long debounceDelay = 50;    // Timp de debounce în milisecunde

// Variabile pentru delayCheck
unsigned long lastDelayTime = 0; // Ultima dată când a fost apelată delayCheck
unsigned long delayDuration = 0;  // Durata delay-ului

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  pinMode(START, INPUT_PULLUP);
  pinMode(STOP, INPUT_PULLUP);
  
  digitalWrite(G, HIGH); // Aprinde LED verde la început
}

void delayCheck(unsigned long duration) {
  lastDelayTime = millis(); // Setează timpul curent
  delayDuration = duration; // Salvează durata delay-ului
  while (millis() - lastDelayTime < delayDuration) {
    verificaStop(); // Verifică butonul de stop în timpul delay-ului
  }
}

void verificaStop() {
  // Verifică starea butonului de oprire
  if (digitalRead(STOP) == LOW) {
    ok = false; // Oprește animația
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW); // Stinge toate LED-urile

    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
  }
}

void turnOffAllLeds() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
}

void animatie() {
  digitalWrite(G, LOW); // Stinge LED verde
  digitalWrite(R, HIGH); // Aprinde LED roșu

  // Animația LED-urilor
  verificaStop();
  digitalWrite(L1, HIGH);
  delayCheck(2500);  // Folosește delayCheck
  digitalWrite(L1, LOW);
  verificaStop();
  delayCheck(500);   // Folosește delayCheck
  digitalWrite(L1, HIGH);
  verificaStop();
  
  for (int i = 0; i < 3; i++) {
    verificaStop();
    if (!ok) {
      turnOffAllLeds(); // Stinge toate LED-urile la oprire
      return; // Oprește execuția dacă animația este oprită
    }

    digitalWrite(L2, HIGH);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L2, LOW);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L2, HIGH);
  }
  
  for (int i = 0; i < 3; i++) {
    verificaStop();
    if (!ok) {
      turnOffAllLeds(); // Stinge toate LED-urile la oprire
      return;
    }

    digitalWrite(L3, HIGH);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L3, LOW);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L3, HIGH);
  }
  
  for (int i = 0; i < 3; i++) {
    verificaStop();
    if (!ok) {
      turnOffAllLeds(); // Stinge toate LED-urile la oprire
      return;
    }

    digitalWrite(L4, HIGH);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L4, LOW);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L4, HIGH);
  }

  for (int i = 0; i < 3; i++) {
    verificaStop();
    if (!ok) {
      turnOffAllLeds(); // Stinge toate LED-urile la oprire
      return;
    }

    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    delayCheck(500); // Folosește delayCheck
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
    digitalWrite(L3, LOW);
    digitalWrite(L4, LOW);
    delayCheck(500); // Folosește delayCheck
  }

  delayCheck(500); // Folosește delayCheck
  digitalWrite(R, LOW); // Stinge LED roșu
  digitalWrite(G, HIGH); // Aprinde LED verde din nou
}




void loop() {
  // Citirea stării butonului START
  int reading = digitalRead(START);

  // Verificăm dacă butonul a fost apăsat
  if (reading == LOW) {
    // Verificăm dacă timpul de debounce a trecut
    if (millis() - lastDebounceTimeStart > debounceDelay) {
      ok = true; // Pornește animația
    }
  } else {
    lastDebounceTimeStart = millis(); // Resetăm timpul de debounce când butonul nu este apăsat
  }

  verificaStop(); // Verifică butonul de oprire în fiecare iterație

  if (ok) {
    animatie(); // Execută animația dacă este activă
    ok = false; // Resetează ok după execuția animației
  }
}
