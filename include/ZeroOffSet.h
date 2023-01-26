#include <Arduino.h>


void ZeroOffSet(void){

  if(tiempo_actual > tiempo_pulsadorZ + 50){
    //pasaron 100ms
    tiempo_pulsadorZ = tiempo_actual;

    if(digitalRead(input_zero) == 0 && bandHold == false){
      if (bandZero == true) {
        bandZero = false;
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        delay(100);//retardo de antirrebote
        //Serial.println("Puesta a CERO OFF-SET la medion...");
        lcd.setCursor(0, 3);
        lcd.print("****OFF-SET = xx****");//Print en LCD que estamos poniento a cero off-set la medicion
        offset_1 = LeerDeltaV(1);
        while(digitalRead(input_zero) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        delay(50);
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
      }else{
        bandZero = true;
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        delay(100);//retardo de antirrebote
        //Serial.println("Puesta a CERO-CERO la medion...");
        lcd.setCursor(0, 3);
        lcd.print("***OFF-SET = 0.0 ***");
        //Print en LCD que estamos poniento a cero-cero la medicion
        while(digitalRead(input_zero) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        offset_1 ={0,0,0,0,0,0,0};
        offset_2 ={0,0,0,0,0,0,0};
        delay(50);
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
      }
    }

  }else{
    if(tiempo_actual<tiempo_pulsadorZ){
      //se produjo un desbordamiento
      tiempo_pulsadorZ = (4294967295-tiempo_pulsadorZ) + tiempo_actual;
    }
  }

}
