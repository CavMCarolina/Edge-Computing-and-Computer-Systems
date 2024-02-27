int cm = 0;
int trigger = 7;
int echo = 8;

// Capacidade maior de armazenamento
long readUltrassonicDistance(int trigger, int echo){
  // Configurar trigger como output
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  // Timer para estabilizar
  delayMicroseconds(2);
  // Ligar e desligar a captação do sensor
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Configurar echo como input
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH);
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Converter o número captado pelo sensor em cm e printar na tela. Constante universal para conversão de unidades
    cm = 0.01723 * readUltrassonicDistance(trigger, echo);
    Serial.print(cm);
    Serial.println("cm");
    delay(100);
}