#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
void connect_wifi(char* ssid,char* password)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}