const int TRIG = 7;
const int ECHO = 2;
const int SEGURO = 200;
const int CUIDADO = 100;
const int PERIGO = 50;


const int LEDRGB1 = 13;
const int LEDRGB2 = 12;
const int LEDRGB3 = 11;
  
const int PIEZO = 8;
  
  
void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(PIEZO, OUTPUT);
  pinMode(LEDRGB1, OUTPUT);
  pinMode(LEDRGB2, OUTPUT);
  pinMode(LEDRGB3, OUTPUT);

}

void loop() {
  int distancia = sensorDistancia(TRIG,ECHO);
  
  if(distancia <= SEGURO && distancia > CUIDADO){
    Serial.print("Distancia Segura! - ");
    Serial.print(distancia);
    Serial.print("cm");
    digitalWrite(LEDRGB1, LOW);
    digitalWrite(LEDRGB2, LOW);
    digitalWrite(LEDRGB3, HIGH);
    noTone(PIEZO);

  }
  
  if(distancia <= CUIDADO && distancia > PERIGO){
    Serial.print("Cuidado! Chegando Perto! - ");
    Serial.print(distancia);
    Serial.print("cm");
    digitalWrite(LEDRGB1, LOW);
    digitalWrite(LEDRGB2, HIGH);
    digitalWrite(LEDRGB3, LOW);
    tone(PIEZO, 1000);
    delay(200);
    noTone(PIEZO);
    delay(200);
  }
  
  if(distancia <= PERIGO){
    Serial.print("Distancia Perigosa! - ");
    Serial.print(distancia);
    Serial.print("cm");
    digitalWrite(LEDRGB1, HIGH);
    digitalWrite(LEDRGB2, LOW);
    digitalWrite(LEDRGB3, LOW);
    tone(PIEZO, 2000);
      
  }

  delay(100);
}

int sensorDistancia(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}