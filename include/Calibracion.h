#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    /*
      if(x>100 && x<=500){
        x = (x*1.0004)-0.0205;
      }
      if(x>500){
        x = (x*1.0007)-0.2339;
      }
      */

  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    /*
    if(x>5 && x<=100){
      x = (x*1.0006)-0.0054;
    }
    if(x>100){
      x = (x*1.0009)-0.0732;
    }
    */

  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    /*
    if(x>0.2 && x<=5){
      x = (x*0.9996)-0.007;
    }
    if(x>5 && x<=25){
      x = (x*1.0008)-0.0131;
    }
    if(x>25){
      x = (x*1.0019)-0.03099;
    }
    */

  }

    if(negativo == true){
        x = x*-1;
    }

    return x;
}