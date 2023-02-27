#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include "env.h"

char const * endpoint = "https://ecse-three-led-api.onrender.com";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(WIFI_NAME, WIFI_PW);

  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println(" ");
  Serial.println("Connected Successful to WiFi");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    String httpResponse;

    http.begin(endpoint);

    int httpResponseCode = http.GET();
    if (httpResponseCode>0)
    {
      Serial.println("Response Code is:");
      Serial.println(httpResponseCode);
      httpResponse = http.getString();
    }
    else 
    {
      Serial.print("ERROR CODE: ");
      Serial.println(httpResponseCode);
    }

    http.end();
    
  }
}