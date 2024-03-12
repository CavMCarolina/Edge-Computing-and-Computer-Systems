#include <ArduinoJson.h>
#include "DHT.h"

// DHT
const int tamanho = 5;

#define DHTPIN  A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Ultrassônico
int cm = 0;
int trigger = 7;
int echo = 8;

// LDR
int ldr = A0;

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

    pinMode(ldr, INPUT);
    dht.begin();
}

void loop() {
    StaticJsonDocument<tamanho> doc;

    // Faz a leitura da temperatura  
    float temp = dht.readTemperature();
    // faz a leitura da humidade
    float umi = dht.readHumidity();

    cm = 0.01723 * readUltrassonicDistance(trigger, echo);

    int leitura = analogRead(ldr);

    doc["umidade"] = umi;
    doc["temperatura"] = temp;
    doc["distance_cm"] = cm;
    doc["luminosidade"] = leitura;

    serializeJson(doc, Serial);
    Serial.println(); 

    delay(4000);
}