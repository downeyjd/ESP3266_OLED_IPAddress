#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ESP8266Ping.h>

#define OLED_MOSI   13
#define OLED_CLK   2
#define OLED_DC    4
#define OLED_CS    5
#define OLED_RESET 15
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
const char* ssid = "blerg";
const char* password = "VUrocks00!!";
byte mac[6];

void setup()   {
  // put your setup code here, to run once:
  WiFi.macAddress(mac);
  /*Serial.begin(9600);
  delay(2000);
  Serial.print("MAC: ");
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
  Serial.print("Connecting to Blerg: ");
  */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  //  Serial.print(".");
    delay(1000);
  }
  IPAddress myip = WiFi.localIP();
  //Serial.print(" Done! ");
  //Serial.println(myip);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("IP Address");
  display.println(myip);
  display.println();
  display.println("MAC Address");
  display.print(mac[5],HEX);
  display.print(":");
  display.print(mac[4],HEX);
  display.print(":");
  display.print(mac[3],HEX);
  display.print(":");
  display.print(mac[2],HEX);
  display.print(":");
  display.print(mac[1],HEX);
  display.print(":");
  display.println(mac[0],HEX);
  display.println();
  while (!Ping.ping("www.google.com")) {
  }
  display.println("Ping: www.google.com");
  display.print(Ping.averageTime());
  display.print(" ms");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
}
