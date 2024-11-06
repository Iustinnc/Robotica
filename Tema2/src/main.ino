#include <Arduino.h>

#define R 6
#define G 5
#define B 4

#define Stop 2
#define Dificultate 3

volatile bool ok = false;
String text;
String cuvant;

String cuvinteOriginal[] = {
  "mar", "floare", "pian", "zebra", "masina", 
  "soare", "castel", "timp", "camp", "cafea", 
  "pahar", "zbor", "caiet", "plaja", "copac", 
  "apa", "munte", "culoare", "cuvant", "ploaie"
};
String cuvinte[20];
int numarCuvinte = sizeof(cuvinte)/sizeof(cuvinte[0]);


volatile int k = 0;

unsigned long timpJoc;
int modJoc = 500;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);

  pinMode(Stop, INPUT_PULLUP);
  pinMode(Dificultate, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(Dificultate), schimbaDificultate, FALLING);
  attachInterrupt(digitalPinToInterrupt(Stop), apasareButon, FALLING);

  Serial.begin(9600);
  randomSeed(analogRead(0));
  resetCuvinte();
}

void apasareButon() {
  ok = !ok;
}

void schimbaDificultate() {
  if (ok==false){
  k++;

  switch (k % 3 + 1) {
    case 1:
      Serial.println("Easy mode on!");
      modJoc=500;
      break;
    case 2:
      Serial.println("Medium mode on!");
      modJoc=300;
      break;
    case 3:
      Serial.println("Hard mode on!");
      modJoc=100;
      break;
  }
  }
  
}

void citire(){
  if (Serial.available() > 0) { 
    text = Serial.readStringUntil('\n');
    text.trim();

    if(text == cuvant){
      digitalWrite(R,LOW);
      digitalWrite(B,LOW);
      digitalWrite(G,HIGH);
      delay(modJoc);
    }
    else{
      digitalWrite(B,LOW);
      digitalWrite(G,LOW);
      digitalWrite(R,HIGH);
      delay(modJoc);

      afiseazaCuvantAleator();
    }

    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    
  }
}

void resetCuvinte() {
  numarCuvinte = sizeof(cuvinteOriginal) / sizeof(cuvinteOriginal[0]);
  for (int i = 0; i < numarCuvinte; i++) {
    cuvinte[i] = cuvinteOriginal[i];
  }
}

void afiseazaCuvantAleator() {
  if (numarCuvinte > 0) {  
    int indexAleator = random(numarCuvinte);  
    
    cuvant=cuvinte[indexAleator];
    Serial.println(cuvant);

    cuvinte[indexAleator] = cuvinte[numarCuvinte - 1];
    numarCuvinte--; 
  }
}

void Start(){
  for(int i=3; i>0; i--){
    if(i!=0){
      Serial.print(i);
      Serial.println("!");
    }

    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
    delay(500);
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  Serial.println("GO!");
}

void loop() {
 
 if (ok) {
    Start(); // Pornim secvența de start
    afiseazaCuvantAleator(); // Afișăm primul cuvânt aleatoriu
    timpJoc=millis();

    while (ok && numarCuvinte > 0 && (millis() - timpJoc)<=30000) {  // Atâta timp cât sunt cuvinte rămase și ok este true
      citire(); // Citim textul introdus de utilizator
      
      if(text == cuvant){
        afiseazaCuvantAleator();
      }
      text = "*";
    }
    ok = false; // Oprește jocul după ce toate cuvintele au fost afișate
    numarCuvinte = sizeof(cuvinte) / sizeof(cuvinte[0]);
    resetCuvinte();

    Serial.println("Jocul s-a terminat");
  }

  

  
}
