#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

WiFiClient client;
WiFiServer server(80); 

#define WIFI_SSID "Moto M 3321" 
#define WIFI_PASSWORD "futuristik"

String data = "";

//#define led1 D5
//#define led2 D6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
   // Print ESP8266 Local IP Address
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP address: http://");
  Serial.println(WiFi.localIP());//Membaca Alamat IP Board
  server.begin();

//  pinMode(led1,OUTPUT);
//  pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();
  if(!client) return;
  data = checkClient();
  Serial.print(data);

  if(data=="led1ON"){
    Serial.println("Led1 ON");
    
  }
 if(data=="led1OFF"){
  Serial.println("Led1 OFF");
 }
 if(data=="led2ON"){
    Serial.println("Led2 ON");
    
  }
 if(data=="led2OFF"){
  Serial.println("Led2 OFF");
 }
 
}

String checkClient(void){
  while(!client.available()) delay(1);
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
