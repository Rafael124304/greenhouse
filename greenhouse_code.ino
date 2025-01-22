#include "dht.h" // Inclusão de biblioteca
#include <BH1750.h>
#include <U8g2lib.h>

#define sensor A2
#define molhado 450
#define seco 600

const int pinoDHT11 = 4; // Pino utilizado pelo DHT11
const int ledPin = 7; // Definindo o pino 7 como o pino do LED
const int RelayPin2 = 8; // Liga ventoinha
const int bomba = 12; //Liga o relé da bomba

dht DHT; // Variável do tipo DHT
BH1750 lightMeter; // Define o sensor como BH1750

// Inicializa o display gráfico (substitua U8G2_R0 pelo seu tipo de display)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600); // Inicializa a serial
  pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
  pinMode(RelayPin2, OUTPUT);
  lightMeter.begin(); // Inicializa o BH1750
  pinMode(12, OUTPUT); // Configura a saída digital 12 como saída
  delay(2000); // Intervalo de 2 segundos antes de iniciar
  
  u8g2.begin(); // Inicializa o display gráfico
}

void loop() {
  DHT.read11(pinoDHT11); // Lê as informações do sensor
  uint16_t lux = lightMeter.readLightLevel(); // Lê os valores do sensor de lux

  // Temperatura e Luminosidade
  if (DHT.temperature < 18 || lux < 100) { // Verifica se a temperatura é maior que 22 graus Celsius ou a luminosidade é menor que 50 lux
    digitalWrite(ledPin, HIGH); // Acende o LED na saída 7
  } else {
    digitalWrite(ledPin, LOW); // Mantém o LED na saída 7 apagado
  }

  // Verifica se a temperatura é maior que 20 graus Celsius para ligar a ventoinha
  if (DHT.temperature > 20) {
    digitalWrite(RelayPin2, HIGH); // Liga a ventoinha na saída 8
  } else {
    digitalWrite(RelayPin2, LOW); // Desliga a ventoinha na saída 8
  }

  //Verifica a umidade do solo e aciona a bomba
  if (sensor > 20) {
    digitalWrite(bomba, HIGH); // Liga a bomba na saída 12
  } else {
    digitalWrite(bomba, LOW); // Desliga a bomba na saída 12
  }

  // Umidade do Solo
  int valor = analogRead(sensor);
  int pre = map(valor, molhado, seco, 100, 0);

  // Exibe os valores no display gráfico
  u8g2.clearBuffer(); // Limpa o buffer do display
  
  u8g2.setFont(u8g2_font_ncenB08_tr); // Define a fonte
  u8g2.drawStr(0, 10, "Temperatura:");
  u8g2.setCursor(100, 10);
  u8g2.print(DHT.temperature);
  u8g2.print(" C");
  
  u8g2.drawStr(0, 25, "Umidade:");
  u8g2.setCursor(100, 25);
  u8g2.print(DHT.humidity);
  u8g2.print(" %");

  u8g2.drawStr(0, 40, "Luminosidade:");
  u8g2.setCursor(100, 40);
  u8g2.print(lux);
  u8g2.print(" lux");

  u8g2.drawStr(0, 55, "Umid. do solo:");
  u8g2.setCursor(100, 55);
  u8g2.print(pre);
  u8g2.print(" %");
  
  u8g2.sendBuffer(); // Envia o buffer para o display

  Serial.print("Umidade: ");
  Serial.print(DHT.humidity);
  Serial.print("% / Temperatura: ");
  Serial.print(DHT.temperature, 0);
  Serial.println("*C");
  Serial.print("Luminosidade: ");
  Serial.print(lux);
  Serial.println(" lux");
  Serial.println(valor);

  delay(2000); // Intervalo de 2 segundos
}
