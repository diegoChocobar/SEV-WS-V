#include <Arduino.h>

//si usas esp32
//#include <HTTPClient.h>
//#include <WiFi.h>

//si usas esp8266
#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>

void Conectar_WiFi(){

    IPAddress local_IP(192,168,1,1);
    IPAddress gateway(192,168,1,255);
    IPAddress subnet(255,255,255,0);

    int channel = 6;
    boolean hidden = false;
    int max_connection = 8;
    
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(local_IP, gateway, subnet);
    
    //Serial.print("Conectando...");
    lcd.clear();lcd.setCursor(0, 0);
    lcd.print("Creando WiFi...");

   while(!WiFi.softAP(ssid, password, channel, hidden, max_connection))
    {
        lcd.print(".");
        delay(200);
    }
    delay(1000);
    lcd.clear();lcd.setCursor(0, 0);
    lcd.print(ssid);lcd.print(" Creado.");

    IPAddress IP = WiFi.softAPIP();

    lcd.setCursor(0, 1);
    lcd.print("IP: ");
    lcd.print(IP);

    delay(2500);


    initWebSocket();

    // Start server
    server.begin();
}