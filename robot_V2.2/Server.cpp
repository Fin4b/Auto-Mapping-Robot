#include <WiFi.h>
#include <WebServer.h>
#include "Server.h"
#include "ServoControl.h"
#include "Imu.h"

const char* ssid = "Franciss_IoT";
const char* password = "123abc123";

WebServer server(80);

void setupServer()
{
  WiFi.begin(ssid,password);
  Serial.print("Connecting...");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  

  Serial.println();
  Serial.println("Connected!");

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server started successfully!");
}

void updateServer()
{
  server.handleClient();
}

void handleRoot()
{
  String data = "{";

  data += "\"heading\":";
  data += heading;
  data += ",\"measurements\":[";
  for(int i=0;i<7;i++)
  {
    data += "{";
    data += "\"angle\":";
    data += getAngles(i);

    data += ",";
    data += "\"distance\":";
    data += getMeasurements(i);

     data += "}";

     if(i<6)
     {
      data += ",";
     }

  }
  data +="]}";
  server.send(200,"application/json", data);
  
}