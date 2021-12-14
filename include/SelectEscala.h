#include <Arduino.h>

void SelectEscala(void){

  if(tiempo_actual > tiempo_pulsadorE + 50){
    //pasaron 100ms
    tiempo_pulsadorE = tiempo_actual;
    ///*
    if(digitalRead(pulsador) == 0  && bandHold == false){
      digitalWrite(output_led, HIGH);
      digitalWrite(output_zumbador, HIGH);
      delay(100);//retardo de antirrebote

      //Serial.print("Cambio de escada.. --> ");
      lcd.setCursor(0, 3);
      lcd.print("Cambio de escala -->");
      while(digitalRead(pulsador) == 0){delay(10);}//mientras tenemos presionado el pulsador

        switch (escala) {
          case 2:
            ads.setGain(GAIN_SIXTEEN);constanteADS=0.0078125;escala =16;
            //Serial.println("Escala 250mV");
            lcd.setCursor(0, 3);
            lcd.print("***Escala: 250mV***");
          break;
          case 4:
            ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;
            //Serial.println("Escala 2000mV");
            lcd.setCursor(0, 3);
            lcd.print("***Escala: 2000mV***");
          break;
          case 16:
            ads.setGain(GAIN_FOUR);constanteADS=0.03125;escala =4;
            //Serial.println("Escala 1000mV");
            lcd.setCursor(0, 3);
            lcd.print("***Escala: 1000mV***");
          break;

          default:
            ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;
            //Serial.println("Escala 2000mV");
            lcd.setCursor(0, 3);
            lcd.print("***Escala: 2000mV***");
          break;
        }
      delay(250);
      digitalWrite(output_led, LOW);
      digitalWrite(output_zumbador, LOW);
    }
    //*/
  }else{
    if(tiempo_actual<tiempo_pulsadorE){
      //se produjo un desbordamiento
      tiempo_pulsadorE = (4294967295-tiempo_pulsadorE) + tiempo_actual;
    }
  }

}
