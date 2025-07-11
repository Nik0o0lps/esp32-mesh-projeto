#include <WiFi.h>

// Dados da rede do ESP Pai
const char* ssid_ap = "ESP_PAI";
const char* password_ap = "12345678";

// IP fixo do ESP Pai no modo AP (padrão: 192.168.4.1)
const char* esp_pai_ip = "192.168.4.1";
const int esp_pai_porta = 5000;

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid_ap, password_ap);
  Serial.print("Conectando ao ESP Pai");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n[✓] Conectado ao ESP Pai!");
  Serial.print("IP do ESP Filho: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (client.connect(esp_pai_ip, esp_pai_porta)) {
    String msg = "Olá do ESP Filho!\n";
    client.print(msg);
    Serial.println("[->] Mensagem enviada ao ESP Pai.");

    // Recebe resposta (opcional)
    if (client.available()) {
      String resposta = client.readStringUntil('\n');
      Serial.print("[<-] Resposta: ");
      Serial.println(resposta);
    }

    client.stop();
  } else {
    Serial.println("[X] Falha na conexão com o ESP Pai");
  }

  delay(5000); // envia a cada 5 segundos
}
