



#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
// inicializando os pinos do sensor_de_ultrason
const int TRIG = 3;
const int ECHO = 2;
const int distancia_obstaculo = 20;
int altura;
int distancia;
String alturaStr = "";

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas

  // Limpa o LCD
  lcd.clear();
  
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop(){
  // guardando o valor da distancia entre o sensor e o objeto ou pessoa
  int distancia = medir_distancia(TRIG,ECHO);

  if(distancia > 80) {
    lcd.clear();
    lcd.setCursor(0, 0); // (coluna 0, linha 0)
    lcd.print("Aguardando"); // Imprime mensagem

    
  } else {
    //posicionando em um lugar de 180cm de altura o sensor podemos calcular a altura de varios objetos
    altura = 180 - distancia;
    alturaStr = String(altura, DEC) + "cm";
    lcd.clear();
    lcd.setCursor(0, 0); // (coluna 0, linha 0)
    lcd.print(alturaStr); // Imprime mensagem
  }

 delay(1000);

}

int medir_distancia(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
