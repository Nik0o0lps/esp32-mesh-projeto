# Código-Fonte do Projeto ESP32

Este diretório contém os códigos-fonte para os dois dispositivos ESP32 usados no projeto: o **ESP Pai** e o **ESP Filho**.

---

## Arquivos

- `esp_pai.ino` — Código do ESP que se conecta ao roteador Wi-Fi e cria o ponto de acesso.
- `esp_filho.ino` — Código do ESP que conecta ao ponto de acesso do ESP Pai e envia mensagens via TCP.

---

## Como Compilar e Rodar

### Requisitos

- Arduino IDE instalada (versão 2.0 ou superior recomendada)
- Placa ESP32 configurada na IDE (via Boards Manager)

### Passos

1. Abra a Arduino IDE.
2. Conecte o ESP32 ao computador via cabo USB.
3. Selecione a placa:  
   `Ferramentas > Placa > ESP32 Dev Module`
4. Selecione a porta correta onde o ESP32 está conectado:  
   `Ferramentas > Porta`
5. Abra o arquivo `.ino` correspondente:
   - Para o ESP Pai: abra `esp_pai.ino`
   - Para o ESP Filho: abra `esp_filho.ino`
6. Clique no botão **Verificar/Compilar** para compilar o código.
7. Clique no botão **Enviar** para gravar o código no ESP32.
8. Abra o **Monitor Serial** (`Ferramentas > Monitor Serial`) para visualizar os logs de execução.

---

## Observações

- Certifique-se de carregar o código correto em cada dispositivo.
- O ESP Pai precisa estar conectado ao roteador Wi-Fi para funcionar corretamente.
- O ESP Filho só funciona se estiver conectado à rede Wi-Fi criada pelo ESP Pai.
- Para interromper ou reiniciar a conexão, pressione o botão de reset do ESP.

---

Se precisar de ajuda, consulte os arquivos `.ino` para detalhes do código.
