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
    String str_data = "";

    String str_emisor = "";
    String str_receptor = "";
    String str_tipo = "";
    String str_value = "";

    for (int i=0;i<tamaño_data ;i++){
      str_data += char(data[i]);
    }

    str_emisor = str_data.substring(0,'/');
    str_receptor = str_data.substring(6,'/');
    str_tipo = str_data.substring(12,'/');

    //ws.textAll(str_data);

    if(str_receptor.compareTo("SEV_V")>0){
      if(str_tipo.compareTo("Check")>0){
        ws.textAll("SEV_V/SEV_C/Check/Ok");
      }
    }else{
      ws.textAll(str_data);
    }
    
    

    

  }
}
