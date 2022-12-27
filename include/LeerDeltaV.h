#include <Arduino.h>

float LeerDeltaV(int canal){
  float tension = 0.0;
  float diferencia = 0.0;

  float data = 0.0;
  int Iteraciones;
  int ret;


  ///*
  Iteraciones = 15;ret=1;

  for (int i = 0; i < Iteraciones; i++) {

    if(canal == 1){
      diferencia = ads.readADC_Differential_0_1();
    }else{
      diferencia = ads.readADC_Differential_2_3();
    }
    data = diferencia + data;
    delay(ret);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds

  }

  if(canal == 1){
    tension = float( ((data / Iteraciones) * constanteADS) - offset_1);
  }else{
    tension = float( ((data / Iteraciones) * constanteADS) - offset_2);
  }
  //tension = abs(tension);
  //tension = (1.00071 * tension) + 0.1783;
  //*/
  /*///////////////////////////////////////////////////////////
      El tiempo que demoramos en tomar la lectura es:
      tiempo = (Iteraciones)*(4+ret)  [=] mili segundos
  */////////////////////////////////////////////////////////
  //delay(100);
  return tension;
}
