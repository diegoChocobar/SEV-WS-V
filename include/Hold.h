#include <Arduino.h>


void Hold(void){


    if(señalhold == true){
      if (bandHold == false) {//debemos congelar la señal actual
        bandHold = true;

        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        lcd.setCursor(0, 3);
        lcd.print("*HOLD ON --> MEDIDA*");

        /////////////////////////////////////////////////////////////////////////////////////////
        ///////////////Enviamos datos al software///////////////////////////////////////////////
        EnviarDatos(deltaV.valor);
        ////////////////////////////////////////////////////////////////////////////////////////
        
        delay(150);//retardo de antirrebote (debido a que es una señal de otra placa que simula un pulsador)

        señalhold = false;

        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, LOW);

      }else{//debemos seguir midiendo
        bandHold = false;
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, HIGH);
        lcd.setCursor(0, 3);
        lcd.print("*HOLD OFF -> MEDIDA*");
        delay(150);//retardo de antirrebote (debido a que es una señal de otra placa que simula un pulsador)
        señalhold = false;
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
      }
    

  }

}


void Hold_Button(void){

  if(tiempo_actual > tiempo_pulsadorH + 25){
    //pasaron 100ms
    tiempo_pulsadorH = tiempo_actual;
    

    if(digitalRead(pulsador_hold) == 0 || bandHoldWEB == true){
      
      if (bandHold == false) {//debemos congelar la señal actual
        bandHold = true;
        if (bandHoldWEB == false) { EnviarHold("ON"); } //cuando la señal de hold no proviene de la web debemos enviar señal de hold a placa de corriente
        delay(100);//este delay es de antirrebote del pulsados
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);

        lcd.setCursor(0, 3);
        lcd.print("*HOLD ON --> MEDIDA*");
        /////////////////////////////////////////////////////// 
        /////enviamos datos al software///////////////////////
        EnviarDatos(deltaV.valor);
        /////////////////////////////////////////////////////
        
        while(digitalRead(pulsador_hold) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        //digitalWrite(output_hold, LOW);
        delay(100);
        digitalWrite(output_zumbador, LOW);
        ///////////////////////////////////////////////////////////////////////////

      }else{//debemos seguir midiendo

        bandHold = false;
        if (bandHoldWEB == false) { EnviarHold("OFF"); } //cuando la señal de hold no proviene de la web debemos enviar señal de hold a placa de corriente
        delay(100);//este delay es el antirrebote del pulsador
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, HIGH);

        lcd.setCursor(0, 3);
        lcd.print("*HOLD OFF -> MEDIDA*");
        

        while(digitalRead(pulsador_hold) == 0){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        
        delay(100);
        digitalWrite(output_zumbador, LOW);
        /////////////////////////////////////////////////////

      }
      
      bandHoldWEB = false;
    }

  }else{
    if(tiempo_actual<tiempo_pulsadorH){
      //se produjo un desbordamiento
      tiempo_pulsadorH = (4294967295-tiempo_pulsadorH) + tiempo_actual;
    }
  }

}