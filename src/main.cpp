#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRremote.h>
#include <WS2812FX.h>
#include "Fita.h"

#define R D4
#define G D2
#define B D1
#define LED_COUNT 60
#define LED_PIN D5

const int IRsend_PIN = D6;
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
IRsend irsend(IRsend_PIN);
unsigned long valor;
decode_results res;
decode_type_t tipo;

#define SSID ""
#define SENHA ""

ESP8266WebServer servidor;

void ledazul() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0, 0, 255);
  ws2812fx.start();
  valor = 0xF7609F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;;
}
void ledverdin() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0x00FFFF);
  ws2812fx.start();
  valor = 0xF78877;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledon() {
  ws2812fx.start();
  valor = 0xF7C03F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledverde() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0, 255, 0);
  ws2812fx.start();
  valor = 0xF7A05F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledroxo() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0xA020F0);
  ws2812fx.start();
  valor = 0xF748B7;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledroxao() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0x4B0082);
  ws2812fx.start();
  valor = 0xF7708F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledrosa() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(0xFF00FF);
  ws2812fx.start();
  valor = 0xF76897;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledoff() {
  ws2812fx.stop();
  valor = 0xF740BF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledvermelho() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(255, 0, 0);
  ws2812fx.start();
  valor = 0xF720DF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledbranco() {
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setColor(255, 255, 255);
  ws2812fx.start();
  valor = 0xF7E01F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledbrilho() {
  valor = 0xF700FF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void ledfesta() {
  ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
  ws2812fx.start();
  valor = 0xF7D02F;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}

void quadroon() {
  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
}
void quadrooff() {
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
void quadroazul() {
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
}
void quadroroxo() {
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
}
void quadrovermelho() {
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
void quadroverde() {
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(B, LOW);
}
void rele1on() {

  valor = 0xFF30CF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele1off() {

  valor = 0xFF30CF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele2on() {

  valor = 0xFF18E7;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele2off() {

  valor = 0xFF18E7;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele3on() {

  valor = 0xFF7A85;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele3off() {

  valor = 0xFF7A85;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele4on() {

  valor = 0xFF10EF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void rele4off() {

  valor = 0xFF10EF;
  irsend.sendNEC(valor, 32);
  Serial.println(valor, HEX);
  tipo = res.decode_type;
}
void setup() {
  WiFi.begin(SSID, SENHA);
  Serial.begin(9600);
  ws2812fx.setBrightness(50);
  ws2812fx.setSpeed(100);
  ws2812fx.init();
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(IRsend_PIN, LOW);

  while (WiFi.status() != WL_CONNECTED) //Enquanto a conexão não é realizada
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); //Ip onde tenho que me conectar
  servidor.on("/ledazul", ledazul);
  servidor.on("/ledverdin", ledverdin);
  servidor.on("/ledon", ledon);
  servidor.on("/ledverde", ledverde);
  servidor.on("/ledroxo", ledroxo);
  servidor.on("/ledroxao", ledroxao);
  servidor.on("/ledrosa", ledrosa);
  servidor.on("/ledoff", ledoff);
  servidor.on("/ledvermelho", ledvermelho);
  servidor.on("/ledbranco", ledbranco);
  servidor.on("/ledbrilho", ledbrilho);
  servidor.on("/ledfesta", ledfesta);
  servidor.on("/quadroon", quadroon);
  servidor.on("/quadrooff", quadrooff);
  servidor.on("/quadroazul", quadroazul);
  servidor.on("/quadroroxo", quadroroxo);
  servidor.on("/quadrovermelho", quadrovermelho);
  servidor.on("/quadroverde", quadroverde);
  servidor.on("/rele1on", rele1on);
  servidor.on("/rele1off", rele1off);
  servidor.on("/rele2on", rele2on);
  servidor.on("/rele2off", rele2off);
  servidor.on("/rele3on", rele3on);
  servidor.on("/rele3off", rele3off);
  servidor.on("/rele4on", rele4on);
  servidor.on("/rele4off", rele4off);
  servidor.on("/", []() {
    server.send(200, "text/html", Fita);
  });
  servidor.begin();
}

void loop() {
  servidor.handleClient();
  ws2812fx.service();
}