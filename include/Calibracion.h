#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado=0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=25.00){
      resultado = (x*1.0009)-0.0122;
    }
    if(x>25.00 && x<=250.00){
      resultado = (x*1.0005)-0.0250;
    }
    if(x>250.0){
      resultado = (x*1.0006)-0.0697;
    }
    //*/

  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=5.00){
      resultado = (x*1.0066)-0.0263;
    }
    if(x>5.00 && x<=25.00){
      resultado = (x*1.0006)-0.004;
    }
    if(x>25.00 && x<=250.00){
      resultado = (x*1.0008)-0.0261;
    }
    if(x>250.0){
      resultado = (x*1.0009)-0.0897;
    }
    //*/

  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=25.00){
      resultado = (x*1.0016)-0.0153;
    }
    if(x>25.0){
      resultado = (x*1.0014)-0.0342;
    }
    //*/

  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}