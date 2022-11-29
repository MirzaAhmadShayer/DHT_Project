
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11 



DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600); 
  Serial.println("DHT Final");
 
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hif = dht.computeHeatIndex(f, h);
  //Compute heat index in Celcius(isFahrenheit = false)
  float hic = dht.computeHeatIndex(t,h,false);

Serial.println(t);
Serial.println(h);
}
