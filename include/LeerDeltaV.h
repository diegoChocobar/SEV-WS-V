#include <Arduino.h>

Tension Calculo_tension(float x[], int length);

Tension LeerDeltaV(int canal){
  //float tension = 0.0;
  float diferencia = 0.0;
  float data = 0.0;

  Tension result{0,0,0,0,0,0,0};
  float deltaV_señal[Iteraciones];
  int ret=1;

  ///*

  for (int i = 0; i < Iteraciones; i++) {

    if(canal == 1){
      diferencia = ads.readADC_Differential_0_1();
      deltaV_señal[i] = diferencia;
    }else{
      diferencia = ads.readADC_Differential_2_3();
      deltaV_señal[i] = diferencia;
    }
    data = diferencia + data;
    delay(ret);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds

  }

  if(canal == 1){
    result = Calculo_tension(deltaV_señal,Iteraciones);
    result.valor = result.valor - offset_1.valor;
  }else{
    result = Calculo_tension(deltaV_señal,Iteraciones);
    result.valor = result.valor - offset_2.valor;
  }
  //*/
  /*///////////////////////////////////////////////////////////
      El tiempo que demoramos en tomar la lectura es:
      tiempo = (Iteraciones)*(4+ret)  [=] mili segundos
  */////////////////////////////////////////////////////////
  //delay(100);
  return result;
}

Tension Calculo_tension(float x[], int length){


  float tension[length];
  float sumatoria=0;
  //float result=0;
  Tension result;
  result.valor=0;
  result.promedio=0;
  result.desvio_standar=0;

  int n=0;
  float valor=0;

//////////////Calculo de valor promerio //////////////////////////////
    for (int i = 0; i < length; i++) {
      tension[i] = float( (x[i] ) * constanteADS );
      result.promedio = result.promedio + tension[i];
    }
    result.promedio = result.promedio / length;
    result.tamaño = length;
/////////////////////////////////////////////////////////////////////////

///////////////calculo de desvio standard/////////////////////////////////  
    for (int i = 0; i < length; i++) {
        sumatoria = sumatoria + (tension[i]-result.promedio)*(tension[i]-result.promedio);
    }
    result.desvio_standar = sqrt(sumatoria/length);
/////////////////////////////////////////////////////////////////////////

//////////////Calculo del valor final ///////////////////////////////////
    for (int i = 0; i < length; i++) {
      
      tension[i] = sqrt(tension[i]*tension[i]);
      if(tension[i] <= sqrt(result.promedio*result.promedio)+2*(result.desvio_standar))
      {
        n = n+1;
        valor = valor + tension[i];
      }
      
    }
    result.n = n;
    result.valor = float(valor/n);
///////////////////////////////////////////////////////////////////

/////////////// Verificacion valores negativos ////////////////////
    if(result.promedio<0){
      result.valor = result.valor * (-1);
    }

///////////////////////////////////////////////////////////////////

    return result;
}
