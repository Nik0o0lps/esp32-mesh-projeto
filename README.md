# Projeto de Comunicação Wi-Fi entre ESP32

Este projeto implementa uma rede ponto-a-ponto entre dois microcontroladores ESP32, onde o **ESP Pai** conecta-se ao roteador Wi-Fi e atua como Access Point para o **ESP Filho**. O ESP Filho conecta-se ao ESP Pai para troca de mensagens via protocolo TCP, permitindo comunicação entre os dispositivos.

---

## Estrutura do Repositório

seu-repositorio-projeto-redes/

├── README.md ← Este arquivo

├── relatorio/

│ └── relatorio_final.pdf ← Relatório técnico completo

├── apresentacao/

│ └── slides_apresentacao.pdf ← Slides da apresentação

└── codigo/

├── src/

│ ├── esp_pai.ino ← Código do ESP Pai

│ └── esp_filho.ino ← Código do ESP Filho

├── lib/ ← Bibliotecas externas (se houver)

└── README.md ← Como compilar e rodar o código

---

## Objetivo

Desenvolver e validar a comunicação Wi-Fi entre dois ESP32, utilizando o ESP Pai como gateway conectado à internet e ponto de acesso local para o ESP Filho, que se conecta para enviar dados via TCP.

---

## Tecnologias Utilizadas

- ESP32 DevKit V1  
- Arduino IDE  
- Biblioteca WiFi.h nativa do ESP32  
- Protocolo TCP/IP para comunicação  

---

## Como Usar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio-projeto-redes.git
Abra a pasta codigo/src/ na Arduino IDE.

Carregue esp_pai.ino no ESP Pai.

Carregue esp_filho.ino no ESP Filho.

Abra os monitores seriais para acompanhar a comunicação.

Autor
Nikolas Lopes
