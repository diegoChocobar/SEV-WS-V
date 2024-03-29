#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float tension;

    //tension = random(0,20000)/100.0;
    if(x<0){x=x*-1;}
    tension = x;

    String string_v = String(tension,2);
    String str_final = "SEV_V/SEV_C/Tension/" + string_v;
    
    ws.textAll(str_final);

}

void EnviarHold(String hold){

    //String string_h = String(hold);

    String str_final = "SEV_V/SEV_I/Hold/" + hold;
    ws.textAll(str_final);

}

void EnviarDisparo(String hold){

    //String string_h = String(hold);

    String str_final = "SEV_V/SEV_C/Disparo/" + hold;
    ws.textAll(str_final);

}