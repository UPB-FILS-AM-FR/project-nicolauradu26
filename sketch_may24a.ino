#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT22
#define SOILPIN A0
#define LIGHTPIN A1
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  delay(3000);
  dht.begin();
}
void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int soilValue = analogRead(SOILPIN);
  int lightValue = analogRead(LIGHTPIN);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.print("Air Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);
  if (soilValue > 800) {
    Serial.println("Soil is DRY");
  }
  else if (soilValue > 500) {
    Serial.println("Soil is OK");
  }
  else {
    Serial.println("Soil is WET");
  }
  Serial.print("Light Level: ");
  Serial.println(lightValue);
  if (lightValue < 300) {
    Serial.println("It is DARK");
  }
  else if (lightValue < 700) {
    Serial.println("Normal LIGHT");
  }
  else {
    Serial.println("It is VERY BRIGHT");
  }
  Serial.println("--------------------------");
  delay(3000);
}