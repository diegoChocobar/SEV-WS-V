#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float tension;

    //tension = random(0,20000)/100.0;
    if(x<0){x=x*-1;}
    tension = x;

    String string_v = String(tension,2);
    String str_final = "SEV_V/Tension/" + string_v;
    
    ws.textAll(str_final);

}

void EnviarHold(int hold){

    String string_h = String(hold);

    String str_final = "SEV_V/SEV_WEB/Hold/" + string_h;
    ws.textAll(str_final);

}