#include <Arduino.h>
#include "AsyncUDP.h"
#include "WiFi.h"
#include "WiFiClient.h"

AsyncUDP _udp;

// WiFi credentials
char _ssid[] = "";
char _pw[] = "";

// User given uuid should be unique for each mcu.
const char uuid[] = "57cc3ea1-8b39-42d6-befd-07e110dff74d";

void listenUdp();

void setup() {
  Serial.begin(115200);
  // Set up wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(_ssid,_pw);
  
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(_ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  listenUdp();
  sleep(5);
}

// Listen on the given UDP port to check for calls.
void listenUdp() {
  if (_udp.listen(43770)) {
      
      Serial.print("UDP auto detect running at: ");
      Serial.print(WiFi.localIP());
      Serial.println(":43770");

      _udp.onPacket([](AsyncUDPPacket packet) {
      
        String str = (const char*)packet.data();
        Serial.println(str);
        
        if (str.equals("iue")) {
          // If the recieved data is the "iue" string than return the uuid
          // the reciever can get the ip from the response.
          packet.printf("ESP32_%s",uuid);
        } else {
          Serial.println("notIdentCall");
        }
        
      });
  }
}