// Incluir biblioteca
#include <ArduinoJson.h>

// Mesmo código da aula passada, só que com json
int cm = 0;
int trigger = 7;
int echo = 8;

long readUltrassonicDistance(int trigger, int echo){
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
  cm = 0.01723 * readUltrassonicDistance(trigger, echo);

  // Criar um objeto JSON
  StaticJsonDocument<200> doc;
  doc["distance_cm"] = cm; // Adicionar a variável cm ao JSON

  // Serializar o objeto JSON para enviar pela porta serial
  serializeJson(doc, Serial);
  Serial.println(); // Adicionar uma quebra de linha para separar os dados

  delay(3000); 
}