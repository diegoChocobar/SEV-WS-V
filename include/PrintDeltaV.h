#include <Arduino.h>

void PrintDeltaVLCD(float x, int y);

void PrintDeltaV(){

  //float deltaV = 0;
  float x;

  if(tiempo_actual > tiempo_LCD + 300){
      //pasaron 500ms
      tiempo_LCD = tiempo_actual;

      if(bandHold == false){
          deltaV = LeerDeltaV(1);
          x = Calibrar(deltaV,escala);
          EnviarDatos(x);
          PrintDeltaVLCD(x,escala);
      }

  }else{
    if(tiempo_actual<tiempo_LCD){
      //se produjo un desbordamiento
      tiempo_LCD = (4294967295-tiempo_LCD) + tiempo_actual;
    }
  }

}


void PrintDeltaVLCD(float x, int y){//x:tension y:escala


  unsigned long unidad,decena,centena,mil,diezmil;
  boolean negativo = false;
  //x = abs(x);//abs redondea el numero a entero (no usar en este caso)

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    if(x<=2000){
      //debemos mostrar 4 numero con un punto decimal
      x = x*10.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("***TENSION  M-N  (-)");}else{lcd.print("***TENSION  M-N  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 2000mV***");
      mostranumero(pos1_unidad,unidad);
      mostranumero(pos1_decena,decena);
      mostranumero(pos1_centena,centena);
      mostranumero(pos1_mil,mil);
      mostranumero(pos1_diezmil,diezmil);
      lcd.setCursor(15,2);
      lcd.print("*");

    }else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***TENSION  M-N  ***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 2000mV***");
      mostranumero(pos1_unidad,8);
      mostranumero(pos1_decena,8);
      mostranumero(pos1_centena,8);
      mostranumero(pos1_mil,8);
      mostranumero(pos1_diezmil,8);
      lcd.setCursor(15,2);
      lcd.print("*");

    }
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    if(x<=1000){

      //debemos mostrar 4 numero con un punto decimal
      x = x*100.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("***TENSION  M-N  (-)");}else{lcd.print("***TENSION  M-N  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 1000mV***");
      mostranumero(pos2_unidad,unidad);
      mostranumero(pos2_decena,decena);
      mostranumero(pos2_centena,centena);
      mostranumero(pos2_mil,mil);
      mostranumero(pos2_diezmil,diezmil);
      lcd.setCursor(11,2);
      lcd.print("*");
    }
    else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***TENSION  M-N  ***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 1000mV***");
      mostranumero(pos2_unidad,8);
      mostranumero(pos2_decena,8);
      mostranumero(pos2_centena,8);
      mostranumero(pos2_mil,8);
      mostranumero(pos2_diezmil,8);
      lcd.setCursor(11,2);
      lcd.print("*");
    }
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    if(x<=250){
      //debemos mostrar 4 numero con un punto decimal
      x = x*100.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("***TENSION  M-N  (-)");}else{lcd.print("***TENSION  M-N  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 250mV***");
      mostranumero(pos2_unidad,unidad);
      mostranumero(pos2_decena,decena);
      mostranumero(pos2_centena,centena);
      mostranumero(pos2_mil,mil);
      mostranumero(pos2_diezmil,diezmil);
      lcd.setCursor(11,2);
      lcd.print("*");

    }
    else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***TENSION  M-N  ***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 250mV***");
      mostranumero(pos2_unidad,8);
      mostranumero(pos2_decena,8);
      mostranumero(pos2_centena,8);
      lcd.setCursor(11,2);
      lcd.print("*");
      mostranumero(pos2_mil,8);
      mostranumero(pos2_diezmil,8);
      lcd.setCursor(11,2);
      lcd.print("*");
    }
  }


}
