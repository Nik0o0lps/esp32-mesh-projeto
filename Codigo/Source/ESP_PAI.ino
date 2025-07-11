#include <WiFi.h>

// Dados da sua rede Wi-Fi (roteador)
const char* ssid_router = "SEU_WIFI";
const char* password_router = "SENHA_WIFI";

// Dados da rede criada para o ESP Filho
const char* ssid_ap = "ESP_PAI";
const char* password_ap = "12345678";

// Servidor na porta 5000
WiFiServer server(5000);

void setup() {
  Serial.begin(115200);

  // Configura modo AP + STA
  WiFi.mode(WIFI_AP_STA);

  // Conecta ao roteador
  WiFi.begin(ssid_router, password_router);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n[✓] Conectado ao Wi-Fi do roteador!");
  Serial.print("IP do ESP Pai (roteador): ");
  Serial.println(WiFi.localIP());

  // Cria o Access Point para o Filho
  WiFi.softAP(ssid_ap, password_ap);
  Serial.print("[✓] AP iniciado: ");
  Serial.println(ssid_ap);
  Serial.print("IP do ESP Pai (AP): ");
  Serial.println(WiFi.softAPIP());

  // Inicia o servidor
  server.begin();
  Serial.println("[✓] Servidor TCP iniciado na porta 5000");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("[+] Cliente conectado");
    while (client.connected()) {
      if (client.available()) {
        String msg = client.readStringUntil('\n');
        Serial.print("[MSG recebida do Filho]: ");
        Serial.println(msg);
        client.print("Recebido!\n"); // resposta opcional
      }
    }
    client.stop();
    Serial.println("[-] Cliente desconectado");
  }
}
