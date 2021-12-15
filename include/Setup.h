#include <Arduino.h>


#include <PrintNumber.h>

#include <Conectar_WiFi.h>

void SaludoInicial();

void setup(void)
{
  pinMode(pulsador, INPUT_PULLUP);//Configuramos el pin como entrada pullup
  digitalWrite(pulsador, HIGH);

  pinMode(input_zero, INPUT_PULLUP);//Configuramos el pin como entrada pullup
  digitalWrite(input_zero, HIGH);

  pinMode(pulsador_select, INPUT_PULLUP);//Configuramos el pin como entrada pullup
  digitalWrite(pulsador_select, HIGH);

  pinMode(pulsador_hold, INPUT_PULLUP);//Configuramos el pin como entrada pullup
  digitalWrite(pulsador_hold, HIGH);

  pinMode(output_led, OUTPUT);
  digitalWrite(output_led, LOW);

   pinMode(output_zumbador, OUTPUT);
  digitalWrite(output_zumbador, LOW);
  delay(10);
  
  //pinMode(output_pwm, OUTPUT);
  //analogWrite(output_pwm, 0);//valores de 0 a 1023

  //Serial.begin(9600);

//////////////////////CONFIGURACION DE ADS1115 ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  //ads.setGain(GAIN_TWOTHIRDS);constanteADS=0.1875;escala =0;  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  //ads.setGain(GAIN_ONE);constanteADS=0.125;escala =1;        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads.setGain(GAIN_TWO);constanteADS=0.0625;escala =2;        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  //ads.setGain(GAIN_FOUR);constanteADS=0.03125;escala =4;       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  //ads.setGain(GAIN_EIGHT);constanteADS=0.015625;escala =8;      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  //ads.setGain(GAIN_SIXTEEN);constanteADS=0.0078125;escala =16;    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  ads.setDataRate(RATE_ADS1015_490SPS);
  
  ads.begin();
///////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////CONFIGURACION DEL LCD ////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
  lcd.init();      //Inicializa o LCD
  lcd.display();         //Enciende el muestreo de las Letras
  lcd.setBacklight(1); //Enciende la luz de fondo (0:off;1:on)


  //Associa cada segmento criado, a um número
  lcd.createChar(0,LT);
  lcd.createChar(1,UB);
  lcd.createChar(2,RT);
  lcd.createChar(3,LL);
  lcd.createChar(4,LB);
  lcd.createChar(5,LR);
  lcd.createChar(6,UMB);
  lcd.createChar(7,LMB);

  SaludoInicial();

  Conectar_WiFi();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

void SaludoInicial(){

    lcd.setCursor(0, 0);
    lcd.print("***CDC Elctronics***");
    lcd.setCursor(0, 1);
    lcd.print("*SEV-WS-V -> GIT-0.1");
    lcd.setCursor(0, 2);
    lcd.print("cel:+54-0387-5312963");
    lcd.setCursor(0, 3);
    lcd.print("cel:+54-0387-4466066");
    
    ///*
      for (size_t i = 0; i < 9; i++)
      {
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        delay(250);
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
        delay(250);
      }
    
    //*/
    //delay(2500);

}
