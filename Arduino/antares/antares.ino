#include "DHT.h"
#define DHTTYPE DHT11
#define SENSOR_DHT D3
#define LEDPIN D4
#define RELAY D5
DHT dht(SENSOR_DHT, DHTTYPE);
void relayOn()
{
digitalWrite(RELAY,HIGH);
}

void relayOff()
{
digitalWrite(RELAY,LOW);
}
float getTemperature()
{
float t = dht.readTemperature();
if (isnan(t)) return 0;
return t;
}
float getHumidity()
{
float h = dht.readHumidity();
if (isnan(h)) return 0;
return h;
}
void setup() {
Serial.begin(115200);
pinMode(LEDPIN,OUTPUT);
pinMode(RELAY,OUTPUT);
dht.begin();
Serial.println("Test Hardware Workshop Antares ...");
}
void loop() {
Serial.println("==================TESTING=================");
Serial.println("Temperature : " + (String)getTemperature()+" *C");
Serial.println("Humidity : " + (String)getHumidity()+" %");
delay(1000);
Serial.println("LED : ON");
digitalWrite(LEDPIN,LOW);
delay(1000);
Serial.println("LED : OFF");
digitalWrite(LEDPIN,HIGH);
delay(1000);
Serial.println("RELAY : ON");
relayOn();
delay(1000);
Serial.println("RELAY : OFF\n");
relayOff();
delay(2000);
}
