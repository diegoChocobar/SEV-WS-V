#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float tension;

    //tension = random(0,20000)/100.0;
    if(x<0){x=x*-1;}
    tension = x;

    String string_v = String(tension,2);
    String str_final = "Tension:" + string_v;
    
    ws.textAll(str_final);

}