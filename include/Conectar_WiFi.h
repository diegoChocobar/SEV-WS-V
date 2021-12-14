#include <Arduino.h>

//si usas esp32
//#include <HTTPClient.h>
//#include <WiFi.h>

//si usas esp8266
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

void Conectar_WiFi(){

    int cont_conexion = 0;
    
    const char* ssid = "WiFi_CDC";
    const char* password = "12345678";

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    //WiFi.begin(ssid);
    
    //Serial.print("Conectando...");
    lcd.clear();lcd.setCursor(0, 0);
    lcd.print("Conectando...");

  while (WiFi.status() != WL_CONNECTED  and cont_conexion <50) { //Check for the connection
    cont_conexion = cont_conexion +1;
    delay(500);
    //Serial.print(".");
    lcd.print(".");
    if(WiFi.status() == WL_CONNECT_FAILED){
      //contraseña incorrecta, salimos del bucle
      cont_conexion = 100;
    }
    if (digitalRead(pulsador) == 0 || digitalRead(input_zero) == 0){
      /* no deseamos conectarnos con software */
      cont_conexion = 100;
      delay(100);//retardo de antirrebote
      while(digitalRead(pulsador) == 0){delay(10);}//mientras tenemos presionado el pulsador
      while(digitalRead(input_zero) == 0){delay(10);}//mientras tenemos presionado el pulsador

    }
    

  }

  //Serial.print("Conectado con éxito, mi IP es: ");
  //Serial.println(WiFi.localIP());
  if(WiFi.status()== WL_CONNECTED){
      ///Nos conectamos satisfactoriamente con el soft
    lcd.setCursor(0, 0);
    lcd.print("*SEV-V4.0 -> GIT-1.0");
    lcd.setCursor(0, 1);
    lcd.print("********************");
    lcd.setCursor(0, 2);
    lcd.print("**Conexion Exitosa**");
    lcd.setCursor(0, 3);
    lcd.print("********************");

    delay(5500);

  }else{
      //No nos pudimos conectar al software
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Equipo NO Conectado!");
        lcd.setCursor(0, 1);
        lcd.print("Error: ");

        ///*
        if(WiFi.status() == WL_NO_SSID_AVAIL){
          lcd.setCursor(0, 2);
          lcd.print("SSID no encontrado");
          lcd.setCursor(0, 3);
          lcd.print("********************");
        }
        if(WiFi.status() == WL_CONNECT_FAILED){
          lcd.setCursor(0, 2);
          lcd.print("Pass faild");
          lcd.setCursor(0, 3);
          lcd.print("********************");
        }
        if(WiFi.status() == WL_DISCONNECTED){
          lcd.setCursor(0, 2);
          lcd.print("Modulo STA faild");
          lcd.setCursor(0, 3);
          lcd.print("Pass faild");
        }
        //*/

        delay(2500);
  }

}