#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_ADS1X15.h>
#include <LiquidCrystal_I2C.h>


#include <Variables.h>
#include <function.h>
#include <Setup.h>
#include <EnviarDatos.h>
#include <Calibracion.h>
#include <LeerDeltaV.h>
#include <SelectEscala.h>
#include <ZeroOffSet.h>
#include <Hold.h>
#include <PrintDeltaV.h>
#include <Disparo.h>

//Esta en una primera version subida a GITHUB --> 23-02-2021

void loop(void)
{

  tiempo_LCD = millis();
  tiempo_pulsadorZ = millis();
  tiempo_pulsadorE = millis();
  tiempo_pulsadorD = millis();
  tiempo_pulsadorH = millis();


  while (1){

    tiempo_actual = millis();

    PrintDeltaV();

    SelectEscala();

    ZeroOffSet();

    Hold();

    //SelectPotencia();
    //Disparo();

    delay(10);

  }


}
