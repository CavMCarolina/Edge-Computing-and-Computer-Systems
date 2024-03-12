// Adicionando bibliotecas
#include <ArduinoJson.h>
#include "DHT.h"

// variável para objeto Json
const int tamanho = 5;

// DHT
#define DHTPIN  A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Ultrassônico
int cm = 0;
int trigger = 7;
int echo = 8;

// LDR
int ldr = A0;

// Ler Ultrassônico
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
    // Criando objeto Json
    StaticJsonDocument<tamanho> doc;

    // leitura da temperatura  
    float temp = dht.readTemperature();
    // leitura da umidade
    float umi = dht.readHumidity();

    // leitura ldr
    int leitura = analogRead(ldr);

    // Transformando distância em cm
    cm = 0.01723 * readUltrassonicDistance(trigger, echo);

    // Adicionando variáveis no objeto
    doc["umidade"] = umi;
    doc["temperatura"] = temp;
    doc["distance_cm"] = cm;
    doc["luminosidade"] = leitura;

    // Printando tudo
    serializeJson(doc, Serial);
    Serial.println(); 
    
    // Delay de 4 segundos para printar novamente
    delay(4000);
}