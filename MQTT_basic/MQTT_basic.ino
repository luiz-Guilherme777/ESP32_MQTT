#include <WiFi.h>
#include <PubSubClient.h>

const String SSID = "iPhone";
const String PSWD = "iot_sul_123";

const String BrokerUrl = "test.mosquitto.org";  //URl do broker   (servidor)
const int port = 1883;     //porta do broker (servidor)

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void conectarWiFi();


void setup() {
  Serial.begin(115200);
  conectarWiFi();
  Serial.println("conectando ao broker...");
  mqttClient.setServer(BrokerUrl.c_str(),port);
  String userId = "tocomfome";
  mqttClient.connect(userId.c_str());
  while(!mqttClient.connected()){
    Serial.println("erro de conexão");
    delay(500);
  }
  Serial.println("conectado ao Broker!");
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("tentando reconectar: aguarde");
    conectarWiFi();
  }
  mqttClient.loop();
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
