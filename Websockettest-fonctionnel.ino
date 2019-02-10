#include <ESP8266WiFi.h>
#include <WebSocketServer.h>
 
WiFiServer server(80);
WebSocketServer webSocketServer;
 
const char *ssid = "SuperMaison";
const char *password = "*1965GP1964";
String test;
int ledPin = 13;

IPAddress ip(192, 168, 1, 50); // where xx is the desired IP Address
IPAddress gateway(192, 168, 1, 1); // set gateway to match your network
IPAddress subnet(255, 255, 255, 0); 
 
void setup() {

pinMode(ledPin,OUTPUT);
digitalWrite(ledPin,LOW);

Serial.begin(9600);
  
Serial.print(F("Setting static ip to : "));
Serial.println(ip);

Serial.println();
Serial.print("Wifi connecting to ");
Serial.println( ssid );
  
WiFi.config(ip, gateway, subnet);
WiFi.begin(ssid,password);
  server.begin();
  delay(100);
}
 
void loop() {
 
  WiFiClient client = server.available();
 
  if (client.connected() && webSocketServer.handshake(client)) {
 
    String data;      
    while (client.connected()) {
 
      data = webSocketServer.getData();
 
      if (data.length() > 0) {
         Serial.println(data);
      }
      
      if (Serial.available() > 0) {
        test = Serial.readString();
        Serial.println(test);
        webSocketServer.sendData(test);
      }

      if (data.length() > 0 && data == "1"){ Serial.println("Allumage de la led"); digitalWrite(ledPin,HIGH);  }
      else if (data.length() > 0 && data == "0") { Serial.println("Eteindre les led"); digitalWrite(ledPin,LOW);  }
      delay(10); // Delay needed for receiving the data correctly
   }
 
   Serial.println("The client disconnected");
   delay(100);
  }
 
  delay(100);
}
