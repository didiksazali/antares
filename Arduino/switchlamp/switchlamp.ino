#include "DHT.h"
#include <ArduinoJson.h>
#include "AntaresESP8266HTTP.h"
//IO Define
#define DHTTYPE DHT11
#define SENSOR_DHT D3
#define LEDPIN D4
#define RELAY D5
//ANTARES & Wifi Data
#define ACCESSKEY "7b1348e3956238ad:613f238b5604e1e5"
#define WIFISSID "A1601"
#define PASSWORD "hammer25"

StaticJsonBuffer<10000> jsonBuffer;
String projectName = "AIoT";
String deviceNameStatus = "SmartSwitchStatus";

String deviceNameControl = "SmartSwitchControl";
String Value,Unit,Label;
unsigned long intervalSend=10000; // the time we need to wait
unsigned long previousMillis=0;
int statusSwitch=0;
DHT dht(SENSOR_DHT, DHTTYPE);
AntaresESP8266HTTP antares(ACCESSKEY);
void ledOn()
{
digitalWrite(LEDPIN,LOW);
}
void ledOff()
{
digitalWrite(LEDPIN,HIGH);
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
pinMode(RELAY,OUTPUT);
pinMode(LEDPIN,OUTPUT);
dht.begin();
antares.setDebug(true);
antares.wifiConnection(WIFISSID,PASSWORD);
Serial.println("Test Hardware Workshop Antares ...");

}
void loop() {
unsigned long currentMillis = millis();
if (antares.checkWifiConnection())
{
if ((unsigned long)(currentMillis - previousMillis) >= intervalSend) {
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();
int sizeData = 3;
String dataName[sizeData],dataValue[sizeData];
dataName[0]= "temperature";
dataName[1]= "humidity";
dataName[2]= "status";
dataValue[0]= (String)humidity;
dataValue[1]= (String)temperature;
dataValue[2]= (String)statusSwitch;
String responseCode = antares.storeData(projectName, deviceNameStatus, dataName, dataValue, sizeData);
if (responseCode=="201")
{
Serial.println("SENDING SUCCESS");
ledOn();
delay(1000);
ledOn();
}
else
{
Serial.println("SENDING FAILED");
ledOff();
delay(1000);
ledOff();
}
previousMillis = millis();
}

String dataFromAntares = antares.retrieveLatestData(projectName,deviceNameControl);
if (dataFromAntares != "")
{
dataFromAntares.replace(" ","");
dataFromAntares.replace("\n","");
dataFromAntares.replace("\r","");
dataFromAntares.replace("\\\""," ");
dataFromAntares.replace("[","");
dataFromAntares.replace("]","");
Serial.println(dataFromAntares);
JsonObject& root = jsonBuffer.parseObject(dataFromAntares);
JsonObject& root4 = jsonBuffer.parseObject(root["m2m:cin"].as<String>());
Label = root4["pi"].as<String>();
String con = root4["con"].as<String>();
con.replace(" ","\"");
JsonObject& contentAntares = jsonBuffer.parseObject(con);
String statusSwitchs = contentAntares["status"].as<String>();
Serial.println(Label);
//if (Label == URI_PROJECT_CONTROL)
//{
if (statusSwitchs == "1")
{
digitalWrite(RELAY,HIGH);
statusSwitch=0;
}
else
{
digitalWrite(RELAY,LOW);
statusSwitch=1;
}
//}
jsonBuffer.clear();
dataFromAntares="";
}
}
delay(1000);
}
