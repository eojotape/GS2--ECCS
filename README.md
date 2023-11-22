# GS2--ECCS]

# Projeto Pedômetro com ESP32, MP5060, Display LCD I2C e Potenciômetro Integrado ao Tago.io

## Descrição do Projeto

Este é um projeto de um pedômetro que utiliza o sensor MP5060 para medir passos, um display LCD I2C para exibir informações, e um potenciômetro para ajuste do brilho do LCD. O dispositivo é baseado na plataforma ESP32 e está integrado à plataforma Tago.io para implementação de IoT, permitindo monitorar e analisar dados em tempo real.

## Componentes Utilizados

- Microcontrolador: ESP32
- Cabos jumpers : Conectores
- Sensor de passos: MP5060
- Display LCD: I2C
- Potenciômetro: Controle de brilho do LCD
- Plataforma IoT: Tago.io

## Instruções de Montagem

1. **Conexão dos Componentes:**
   - Conecte o sensor MP5060 para medição de passos.
   - Conecte o display LCD I2C para exibição de informações.
   - Conecte o potenciômetro para ajuste de brilho do LCD.
   - Certifique-se de conectar o ESP32 aos componentes de acordo com o esquema elétrico.

2. **Configuração do Tago.io:**
   - Crie uma conta no Tago.io, se ainda não tiver uma.
   - Crie um novo dispositivo para o seu pedômetro.
   - Anote as chaves de API geradas para autenticação.

3. **Configuração do Código:**
   - Abra o arquivo do código-fonte (ex: `pedometro.ino`) no seu ambiente de desenvolvimento Arduino.
   - Substitua as chaves de API do Tago.io no código.
   - Certifique-se de que as bibliotecas necessárias para o sensor MP5060, LCD I2C e ESP32 estejam instaladas.

4. **Upload do Código:**
   - Faça o upload do código para o ESP32.

5. **Teste do Dispositivo:**
   - Alimente o dispositivo e verifique se o display LCD exibe as informações corretas.
   - Certifique-se de que o sensor MP5060 está registrando corretamente os passos.

6. **Integração com o Tago.io:**
   - Acesse o dashboard do seu dispositivo no Tago.io.
   - Configure os widgets desejados para visualização dos dados.
   - Explore as opções de análise e notificações disponíveis na plataforma.

## Contribuições e Problemas

Se encontrar problemas ou tiver sugestões para melhorias, sinta-se à vontade para abrir uma issue neste repositório. Contribuições através de pull requests são bem-vindas!

---

Esperamos que este README ajude na implementação do seu projeto! Se precisar de mais assistência, sinta-se à vontade para entrar em contato.
