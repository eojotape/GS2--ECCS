#include <Wire.h>
#include <MPU6050.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <EspMQTTClient.h>


MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C e dimensões do LCD

int16_t ax, ay, az;
int16_t axAnt = 0, ayAnt = 0, azAnt = 0;
int passos = 0;

int potPin = 0;      // Pino analógico ao qual o potenciômetro está conectado
int contrasteLCD;     // Variável para armazenar o valor do potenciômetro

void onConnectionEstablished() {
}

EspMQTTClient client{
  "Wokwi-GUEST",   // SSID do WiFi
  "",              // Senha do WiFi
  "mqtt.tago.io",  // Endereço do servidor
  "Default",       // Usuário
  "9c499420-0ba6-4093-a768-11dbe5272c41", // Token do dispositivo
  "esp",           // Nome do dispositivo
  1883             // Porta de comunicação
};


void setup() {
  Serial.begin(115200);


   Serial.println("Conectando WiFi");

  while (!client.isWifiConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("WiFi Conectado");
  Serial.println("Conectando com Servidor MQTT");

  while (!client.isMqttConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("MQTT Conectado");

  Wire.begin();
  mpu.initialize();


  lcd.begin(16, 2);  // Inicializa o LCD
  lcd.backlight();   // Ativa a luz de fundo
  pinMode(potPin, INPUT);  // Configuração do pino do potenciômetro
}

void loop() {
mpu.getAcceleration(&ax, &ay, &az);  // Alteração aqui para passar os endereços das variáveis

  // Leitura do valor do potenciômetro para ajustar o contraste do LCD
  contrasteLCD = analogRead(potPin);
  contrasteLCD = map(contrasteLCD, 0, 1023, 0, 255);  // Mapeia o valor para o intervalo do contraste

  // Ajusta o contraste do LCD
  lcd.setContrast(contrasteLCD);

  // Verifica se ocorreu um passo
  if (detectarPasso(ax, ay, az, axAnt, ayAnt, azAnt)) {
    passos++;
    atualizarLCD();
  }

  // Atualiza os valores anteriores
  axAnt = ax;
  ayAnt = ay;
  azAnt = az;

  delay(100);  // Atraso para estabilização
}

// Função para detectar um passo
bool detectarPasso(int16_t ax, int16_t ay, int16_t az, int16_t axAnt, int16_t ayAnt, int16_t azAnt) {
  // Aqui você pode ajustar os limiares de detecção de passo conforme necessário
  int limiar = 300;
  int dif = abs(ay - ayAnt);

  if (dif > limiar) {
    delay(500);  // Evita contar múltiplos passos por uma única ação
    return true;
  }

  return false;
}

// Função para atualizar o conteúdo do LCD
void atualizarLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Passos: ");
  lcd.print(passos);
}
