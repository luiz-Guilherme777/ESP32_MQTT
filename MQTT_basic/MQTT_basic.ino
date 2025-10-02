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
  conectarBroker();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("tentando reconectar wifi: aguarde");
    conectarWiFi();
  }
  if(!mqttClient.connected()){
    Serial.println("tentando reconectar ao broker: aguarde");
    conectarBroker();
  }
  mqttClient.publish("AulaIoTSul/Chat","o horario nao permite ");
  delay(1000);


  mqttClient.loop();
}


void conectarBroker(){
    Serial.println("conectando ao broker...");
  mqttClient.setServer(BrokerUrl.c_str(),port);
  String userId = "tocomfome";
  while(!mqttClient.connected()){
    mqttClient.connect(userId.c_str());
    Serial.println(".");
    delay(500);
  }
  Serial.println("conectado ao Broker!");
}

void conectarWiFi(){
  Serial.println("iniciando conexão com rede WiFi");
  while(WiFi.status() != WL_CONNECTED){
    WiFi.begin(SSID, PSWD);
    Serial.print(".");
    delay(2000);
  }
  Serial.println("\n Conectado!");
}
