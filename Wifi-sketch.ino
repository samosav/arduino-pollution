#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "TP-Link_92A4";          //  your network SSID (name)
char pass[] = "FIXME";   // your network password

int status = WL_IDLE_STATUS;
IPAddress server(192,168,1,142);  

// Initialize the client library
WiFiClient client;

void setup() {

  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);
  if ( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    // don't do anything else:
    while(true);    
  }
  else {
    Serial.println("Connected to wifi");
    Serial.println("\nStarting connection...");
    // if you get a connection, report back via serial:
    if (client.connect(server, 5000)) {
      Serial.println("connected");
      // Make a HTTP request:
      client.println("GET /update?d=673 HTTP/1.0");
      client.println();       
    }
  }
}

void loop() {

}
