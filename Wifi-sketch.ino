#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "fixme";          //  your network SSID (name)
char pass[] = "fixme";          // your network password

int sensorValue;

int status = WL_IDLE_STATUS;
IPAddress server(192,168,1,69); //use ifconfig to get correct ip

WiFiClient client;

void setup() {

  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  status = WiFi.begin(ssid, pass);
  if ( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while(true);    
  }
  
  else {
    Serial.println("Connected to wifi");
  }     
        
}

void loop() {

  sensorValue = analogRead(0);
  Serial.print(sensorValue, DEC); 
  delay(1000);
  
  if (client.connect(server, 5000)) {
    Serial.println("connected");
    client.println("GET /update?d="+String(sensorValue)+" HTTP/1.0");
    client.println();       
    
  }    
  
}
