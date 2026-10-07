const int LM35_PIN = A0;
const int LED_R = 2;
const int LED_G = 3;
const int LED_Y = 4;

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
}

double getTemperature(){
  return (analogRead(LM35_PIN) * 5.0 / 1024.0) * 100.0;
}

void loop(){

  if(getTemperature()>23 && getTemperature()<=25){
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_Y,HIGH);
  } else if(getTemperature()>25 && getTemperature()<=27){
    digitalWrite(LED_Y,LOW);
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,HIGH);
  } else{
    digitalWrite(LED_Y,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,HIGH);
  }

  Serial.print("{");
  Serial.print("\"temperature\":");
  Serial.print(getTemperature());
  Serial.println("}");
  delay(5000); // Esperar 5 segundos antes de la siguiente lectura
}