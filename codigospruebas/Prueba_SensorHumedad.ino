#include <DHT.h>

#define DHTPIN 2     // Pin digital donde está conectado el sensor
#define DHTTYPE DHT11   // Definimos que usamos el sensor DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Inicializamos la comunicación serial
  dht.begin();          // Inicializamos el sensor DHT
}

void loop() {
  // Esperamos 2 segundos entre mediciones (el DHT11 es lento)
  delay(2000);

  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados Celsius
  float t = dht.readTemperature();

  // Comprobamos si hubo un error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("¡Error al leer del sensor DHT!");
    return;
  }

  // Mostramos los resultados en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%  |  ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");
}