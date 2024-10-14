#include <Arduino.h>

void initWebSocket();
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);


void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
  void *arg, uint8_t *data, size_t len) {
    switch (type) {
      case WS_EVT_CONNECT:
        //Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
      case WS_EVT_DISCONNECT:
        //Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
      case WS_EVT_DATA:
        handleWebSocketMessage(arg, data, len);
        break;
      case WS_EVT_PONG:
      case WS_EVT_ERROR:
        break;
    }
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;

    char *data_msg;
    //int tamaño_data = sizeof(data);
    int tamaño_data = len;
    int n = 0; //posicion final del string tipo
     
    String str_data = "";

    String str_emisor = "";
    String str_receptor = "";
    String str_tipo = "";
    String str_value = "";

    for (int i=0;i<tamaño_data ;i++){
      str_data += char(data[i]);
    }

    str_emisor = str_data.substring(0,5);
    str_receptor = str_data.substring(6,11);

    n = str_data.indexOf("/",12);
    str_tipo = str_data.substring(12,n);
    str_value = str_data.substring(n+1);
  
    /*
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Emisor: ");
      lcd.print(str_emisor);

      lcd.setCursor(0, 1);
      lcd.print("Receptor: ");
      lcd.print(str_receptor);

      lcd.setCursor(0, 2);
      lcd.print("Tipo: ");
      lcd.print(str_tipo);

      lcd.setCursor(0, 3);
      lcd.print("Value: ");
      lcd.print(str_value);

    */
    if (str_receptor == "SEV_V") {
      
      if(str_emisor == "SEV_C"){//nos envio el dato la computadora
        
        if (str_tipo == "Check") {
          ws.textAll("SEV_V/SEV_C/Check/Ok");
        }
        if (str_tipo == "Hold") {
          
          if (str_value == "ON") {
              bandHoldWEB = true;
              bandHold = false;
              ws.textAll("SEV_V/SEV_C/Hold/ON");
          }
          if (str_value == "OFF") {
              bandHoldWEB = true;
              bandHold = true;
              ws.textAll("SEV_V/SEV_C/Hold/OFF");
          }
          
        }
        

      }

      if(str_emisor == "SEV_I"){//nos envio el dato la placa de corriente
        if (str_tipo == "Hold") {
            if (str_value == "ON") {
              señalhold = true;
              bandHold = false;
              ws.textAll("SEV_V/SEV_C/Hold/ON");
            }if (str_value == "OFF") {
              señalhold = true;
              bandHold = true;
              ws.textAll("SEV_V/SEV_C/Hold/OFF");
            }
        }
      }
        

    }
    else{
        ws.textAll(str_data);
    }
    
  }
  

}
