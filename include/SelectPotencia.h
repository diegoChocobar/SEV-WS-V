#include <Arduino.h>

void RestaurarEscala();

void SelectPotencia(){

  if(tiempo_actual > tiempo_pulsadorS + 50){
    //pasaron 100ms
    tiempo_pulsadorS = tiempo_actual;
    /////////////////////////////////////////////////////////////
    if(digitalRead(pulsador_select) == 0){

      delay(100);//retardo de antirrebote
      lcd.setCursor(0, 3);
      lcd.print("Setup Potencia  -->");
      while(digitalRead(pulsador_select) == 0){delay(10);}//mientras tenemos presionado el pulsador
      delay(100);//retardo de antirrebote


      while(digitalRead(pulsador_select) == 1){
        float tension_2 = 0;
        ValorPwm = analogRead(A0);
        analogWrite(output_pwm, ValorPwm);//lavores de 0 a 1023
        ads.setGain(GAIN_TWOTHIRDS);constanteADS=0.1875;//Seleccionamos escala de 6000mV
        tension_2 = LeerDeltaV(2);
        lcd.home();lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("***CDC Elctronics***");
        lcd.setCursor(0, 1);
        lcd.print("Tension = ");
        lcd.print(tension_2, 1);
        lcd.setCursor(19, 1);
        lcd.print("V");
        lcd.setCursor(0, 2);
        lcd.print("PWM = ");
        lcd.print(ValorPwm);
        lcd.setCursor(15, 2);
        lcd.print((ValorPwm*100)/1023.0,1);
        lcd.setCursor(19, 2);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("***Escala: 600 V***");
        delay(500);
      }

      lcd.setCursor(0, 3);
      lcd.print("Panel Principal -->");
      while(digitalRead(pulsador_select) == 0){delay(10);}//mientras tenemos presionado el pulsador
      RestaurarEscala();
      delay(500);
    }

    /////////////////////////////////////////////////////////////
  }else{
    if(tiempo_actual<tiempo_pulsadorS){
      //se produjo un desbordamiento
      tiempo_pulsadorS = (4294967295-tiempo_pulsadorS) + tiempo_actual;
    }
  }

}

void RestaurarEscala(){

  switch (escala) {
    case 2:
      ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;
    break;
    case 4:
      ads.setGain(GAIN_FOUR);constanteADS=0.03125;escala =4;
    break;
    case 16:
      ads.setGain(GAIN_SIXTEEN);constanteADS=0.0078125;escala =16;
    break;

    default:
      ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;
      //Serial.println("Escala 2000mV");
    break;
  }

}
