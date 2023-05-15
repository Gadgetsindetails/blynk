#define BLYNK_TEMPLATE_ID "TMPL32mUpMp2K"
#define BLYNK_TEMPLATE_NAME "OTA DHT11"
#define BLYNK_FIRMWARE_VERSION      "0.1.0"

#define BLYNK_PRINT Serial

#include "BlynkEdgent.h"
#include <DHT.h>

#define DHTPIN 4          // DHT11 sensor pin
#define DHTTYPE DHT11     // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, hum);
  delay(2000);
}
