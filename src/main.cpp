#include <Arduino.h>
#include <wifi_connect.h>
#include <update_firmware_github.h>
#include <ESP8266httpUpdate.h>
#include <WiFiClientSecure.h>
#include <CertStoreBearSSL.h>
#include <time.h>
#include <ct1642.h>

const String FirmwareVer = {"2.1"};
// #define URL_fw_Version "/programmer131/otaFiles/master/version.txt"
#define URL_fw_Version "/ledixonbs1234/otaesp8266/main/version.txt"
#define URL_fw_Bin "https://raw.githubusercontent.com/ledixonbs1234/otaesp8266/main/firmware.bin"
 char *ssid = "Huong -2.4G";
 char *password = "0348759205";


void setup()
{
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Start");
  connect_wifi(ssid,password);
  Serial.println("Dang chay version");
  Serial.println(FirmwareVer);
  installCT1642(D5,D6);
  
  pinMode(LED_BUILTIN, OUTPUT);
}
unsigned long prevousMillis = 0;
void loop()
{
  unsigned long currentMillis = millis();
  if ((currentMillis - prevousMillis) >= 30000)
  {
    // save the last time you blinked the LED
    prevousMillis = currentMillis;
    setClock();
  FirmwareUpdate(URL_fw_Bin,URL_fw_Version,FirmwareVer);
  }
  // repeatedCall();
  showNumber(21);
}
