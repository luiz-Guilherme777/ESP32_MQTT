#include <WiFi.h>
const String SSID = "iPhone";
const String PSWD = "iot_sul_123";

 void setup() {
  Serial.begin(115200);
  void scanLocalNetworks();
  Serial.println("iniciando coneXão com rede WiFi");
  WiFi.begin(SSID, PSWD);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\n Conectado!");
}

void loop() {


}

void scanLocalNetworks(){
  Serial.println("iniciando scan de redes Wi-Fi");
  int number = WiFi.scanNetworks();
  delay(500);
  if(number == -1){
    Serial.println("ERRO!. Não deu bom");
  }
  else{
    Serial.printf("Numero das redes encontradas : %d\n", number);
    for(int net = 0; net < number; net++){
      Serial.printf("%d - %s | %d db\n", net, WiFi. SSID(net), WiFi.RSSI(net));
    }
  }
}
