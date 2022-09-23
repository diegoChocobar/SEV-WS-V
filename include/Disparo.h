#include <Arduino.h>

//#include <EnviarDatos.h>

void Disparo(void){

  if(tiempo_actual > tiempo_pulsadorD + 300){
    //pasaron 100ms
    tiempo_pulsadorD = tiempo_actual;
    /////////////////////////////////////////////////////////////
    if(digitalRead(pulsador_disparo) == 0){
      
        delay(200);
        bandHold = true;
        digitalWrite(output_disparo, HIGH);
      
    }else{
      delay(200);
      digitalWrite(output_disparo, LOW);
    }

    /////////////////////////////////////////////////////////////
  }else{
    if(tiempo_actual<tiempo_pulsadorD){
      //se produjo un desbordamiento
      tiempo_pulsadorD = (4294967295-tiempo_pulsadorD) + tiempo_actual;
    }
  }

}
