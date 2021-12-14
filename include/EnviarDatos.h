#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float tension;

  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

    WiFiClient client;

    HTTPClient http;

    //tension = random(0,20000)/100.0;

    tension = x;

    String string_v = String(tension,2);

    String datos_a_enviar = "esp_tension=" + string_v + "&esp_status_v=1";
    
    
    //http.begin("http://10.42.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    //http.begin("http://192.0.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    
    http.begin(client,"http://10.42.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    //http.begin("http://192.0.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.POST(datos_a_enviar);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)
    
    delay(100);

    if(codigo_respuesta>0){
      //Serial.println("Código HTTP ► " + String(codigo_respuesta));   //Print return code

      if(codigo_respuesta == 200){
        //String cuerpo_respuesta = http.getString();
        //Serial.println("El servidor respondió ▼ ");
        //Serial.println(cuerpo_respuesta);
        lcd.setCursor(0, 0);
        lcd.print("Dato Enviado->Exito!");

      }else{
        lcd.setCursor(0, 0);
        lcd.print("Error-> " + String(codigo_respuesta));
      }
    }else{

     //Serial.print("Error enviando POST, código: ");
     //Serial.println(codigo_respuesta);
     lcd.setCursor(0, 0);
     //lcd.print("ERROR Envio de Dato*");
     lcd.print("Error-> " + String(codigo_respuesta));
    }

    http.end();  //libero recursos

  }



}