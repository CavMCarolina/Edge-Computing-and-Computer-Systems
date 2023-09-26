#define LP 2
#define LA 4
#define LV 8
#define buzzer 12
#define LDR A0

void setup(){
  pinMode(LV,OUTPUT);
  pinMode(LA,OUTPUT);
  pinMode(LP,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  Serial.begin(9600);
  int VLDR = analogRead(LDR);
  Serial.println(VLDR);
  delay(500);

  if(VLDR<500){
    noTone(buzzer);
    digitalWrite(LP,HIGH);
    digitalWrite(LA,LOW);
    digitalWrite(LV,LOW);
 }
  else if(VLDR < 949){
    digitalWrite(LP,LOW);
    digitalWrite(LA,HIGH);
    digitalWrite(LV,LOW);
    tone(buzzer,1000);
    delay(3000);
    noTone(buzzer);
    delay(3000);
    tone(buzzer,1000);
  }
  if(VLDR>=950){
    digitalWrite(LP,LOW);
    digitalWrite(LA,LOW);
    digitalWrite(LV,HIGH);
    tone(buzzer,1000);
  } 
}