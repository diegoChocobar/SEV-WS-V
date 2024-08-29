#include <Arduino.h>
#include <Wire.h>
//#include <Adafruit_ADS1015.h>
#include <Adafruit_ADS1X15.h>
#include <LiquidCrystal_I2C.h>

#include <WebSocketsServer.h>
#include <ESPAsyncWebServer.h>

struct  Tension
{
    float promedio;
    float desvio_standar;
    float valor;
    int tamaño;//tamño del numero de iteraciones para la obtencion de una medida
    int n;//tamaño del valor que queda despues de tratar la señal
    float tiempo_individual;
    float tiempo_total;
};

////////////////VARIABLES PARA MANEJO DEL LCD //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 o 0x20 o 0x3F

const int pos1_unidad=17,pos1_decena=12,pos1_centena=8,pos1_mil=4,pos1_diezmil=0;
const int pos2_unidad=17,pos2_decena=13,pos2_centena=8,pos2_mil=4,pos2_diezmil=0;

//Vector formador de los segmentos para el LCD
byte LT[8] ={B01111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111};
byte UB[8] ={B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000};
byte RT[8] ={B11110,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111};
byte LL[8] ={B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01111};
byte LB[8] ={B00000,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111,  B11111};
byte LR[8] ={B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11110};
byte UMB[8] ={B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B11111,  B11111};
byte LMB[8] ={B11111,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111,  B11111};
/////////////////////////////////////////////////////////////////////////////////////


 //Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */ /*Dir I2C 0x48 (gnd) */
 Adafruit_ADS1115 ads;
//Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */

float constanteADS;
int escala;
boolean bandZero=true;
boolean bandHold=false;
boolean señalhold = false;
boolean bandDisparo=true;
boolean bandDisparoWEB=false;
boolean bandDisparoWEBAnt=false;

Tension offset_1 ={0,0,0,0,0,0,0};
Tension offset_2={0,0,0,0,0,0,0};
Tension deltaV;
int Iteraciones=40;


int pulsador = 16;      //pin utilizado para el pulsador de cambio de escala
int input_zero = 14;    //pin utilizado para pulsador de puesta a cero la medicion
int pulsador_disparo = 180;  //pin utilizado para pulsador selector de potencia de salida
int pulsador_hold = 181;    //pin utilizado para pulsador dedicado a congenlar la señal medida

int output_led = 2;     //pin de salida led indicador
int output_zumbador = 3; //pin de salida zumbador

int output_pwm = 183;   //pin de salida pwm
unsigned int ValorPwm=20;
boolean band_potencia = false;


unsigned long tiempo_actual = 0;
unsigned long tiempo_LCD = 0;
unsigned long tiempo_pulsadorZ = 0;  //pulsador de puesta a caro la medicion
unsigned long tiempo_pulsadorE = 0;  //pulsador de selector de escala
unsigned long tiempo_pulsadorH = 0;  //pulsador para congelar la señal

unsigned long tiempo_medida_total = 0;  //pulsador para congelar la señal
unsigned long tiempo_medida_indiv = 0;  //pulsador para congelar la señal
////////////////INCIALIZAR wifi /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////    
const char* ssid = "SEV_WiFi";
const char* password = "ChDi1088";

AsyncWebServer server(80); // server port 80
AsyncWebSocket ws("/ws");
WebSocketsServer websockets(81);

int Num_Dispositivos = 0;
int Num_Disp_Check = 0;


bool isValidsendMessage = true;
bool isRecivedPhone = false;


////////////////////////////////////////////////////////////////////////////////
