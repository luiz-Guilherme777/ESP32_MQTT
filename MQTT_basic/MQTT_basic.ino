#include <WiFi.h>
const String SSID = "iPhone";
const String PSWD = "iot_sul_123";
void conectarWiFi()


void setup() {
  Serial.begin(115200);
  conectarWiFi();  
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("tentando reconectar: aguarde");
    conectarWiFi();
  }
}

void conectarWiFi(){
  Serial.println("iniciando conexão com rede WiFi");
  WiFi.begin(SSID, PSWD);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\n Conectado!");
}
