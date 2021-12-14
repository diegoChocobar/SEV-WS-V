#include <Arduino.h>

#include <EnviarDatos.h>

void HoldSet(void){

  if(tiempo_actual > tiempo_pulsadorH + 25){
    //pasaron 100ms
    tiempo_pulsadorH = tiempo_actual;
    

    if(digitalRead(pulsador_hold) == 0){
      if (bandHold == false) {//debemos congelar la señal actual
        bandHold = true;
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);

        lcd.setCursor(0, 3);
        lcd.print("*HOLD ON --> MEDIDA*");

        /////////////////////////////////////////////////////// 
        /////enviamos datos al software///////////////////////
        EnviarDatos(deltaV);
        /////////////////////////////////////////////////////
        
        while(digitalRead(pulsador_hold) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        //digitalWrite(output_hold, LOW);
        delay(100);
        digitalWrite(output_zumbador, LOW);
        ///////////////////////////////////////////////////////////////////////////

      }else{//debemos seguir midiendo

        bandHold = false;
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, HIGH);

        lcd.setCursor(0, 3);
        lcd.print("*HOLD OFF -> MEDIDA*");

        while(digitalRead(pulsador_hold) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        //digitalWrite(output_hold, LOW);
        delay(100);
        digitalWrite(output_zumbador, LOW);
        /////////////////////////////////////////////////////

      }
    }

  }else{
    if(tiempo_actual<tiempo_pulsadorH){
      //se produjo un desbordamiento
      tiempo_pulsadorH = (4294967295-tiempo_pulsadorH) + tiempo_actual;
    }
  }

}
