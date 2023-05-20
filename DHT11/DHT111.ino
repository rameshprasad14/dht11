#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<DHT.h>
#define BLYNK_TEMPLATE_ID "TMPL3xzqQeG67"
#define BLYNK_TEMPLATE_NAME "dht11"
#define BLYNK_AUTH_TOKEN "n5IOAf2LaeKpp-39qB94MCudeoiyPmLU"
#define BLYNK_PRINT Serial
char ssid[]= "    ";
char  pass[]="    ";
#define DHTPIN  D3
#define DHTTYPE  DHT11
DHT  dht(DHTPIN,DHTTYPE);
BlynkTimer  timer;
void  sendsensor(){
  float  h=dht.readHumidity();
  float  t=dht.readTemperature();
  Serial.print("Humidity  :-");
  Serial.print(h);
  Serial.print("    ");
  Serial.print("Temperature  :-");
  Serial.print(t);
  Serial.println("    ");
  Blynk.v irtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  }
void setup() {
 Serial.begin(115200);
 Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
 dht.begin();
 timer.setInterval(1000L,sendsensor);
}

void loop() {
 Blynk.run();
 timer.run();
}
