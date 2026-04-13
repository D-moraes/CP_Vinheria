#include <LiquidCrystal.h> // Importa a biblioteca para controlar o LCD

// Define os pinos de conexão do LCD 
LiquidCrystal lcd(8, 7, 6, 5, 4, 3, 2);

// Definição dos pinos para os LEDs e o Buzzer
int ldOk = 12;      // LED Verde (Tudo ok)
int ldAlert = 11;   // LED Amarelo (Alerta)
int ldProb = 10;    // LED Vermelho (Problema)
int alertRing = 9;  // Buzzer para alerta 

// --- Blocos dos Desenhos Customizados (letra A e a Taça de vinho) ---
// Cada 'byte' define uma matriz 5x8 de pixels para criar ícones no LCD.
// Foram criados desenhos para a taça em 3 estados: cheia, média e vazia.
// Também há blocos para formar uma "Letra A" grande usando 4 espaços do 
//LCD para representar a inicial da Vinheria Agnello.


byte wine1Baixa[8] = 
{B00111,
 B01000,
 B01000,
 B11111,
 B11111,
 B11111,
 B11111,
 B01111};

byte wine2Baixa[8] = 
{B11100,
 B00010,
 B00010,
 B11111,
 B11111,
 B11111,
 B11111,
 B11110};
byte wine3[8] = 
{B00111,
 B00011,
 B00001,
 B00001,
 B00001,
 B00001,
 B00011,
 B01111};

byte wine4[8] = 
{B11100,
 B11000,
 B10000,
 B10000,
 B10000,
 B10000,
 B11000,
 B11110};

byte wine1Medio[8] = 
{B00111,
 B01000,
 B01000,
 B10000,
 B10000,
 B11111,
 B11111,
 B01111};

byte wine2Medio[8] = 
{B11100,
 B00010,
 B00010,
 B00001,
 B00001,
 B11111,
 B11111,
 B11110};



byte wine1Alta[8] = 
{B00111,
 B01000,
 B01000,
 B10000,
 B10000,
 B10000,
 B10000,
 B01111};

byte wine2Alta[8] = 
{B11100,
 B00010,
 B00010,
 B00001,
 B00001,
 B00001,
 B00001,
 B11110};



byte letra1[8] = 
{B00000,
 B00000,
 B00000,
 B00001,
 B00001,
 B00001,
 B00001,
 B00011};


byte letra2[8] = 
{B00000,
 B01000,
 B11000,
 B11100,
 B11100,
 B01110,
 B00110,
 B00110};

byte letra3[8] = 
{B00010,
 B00011,
 B00010,
 B00100,
 B00100,
 B01100,
 B11111,
 B00000};

byte letra4[8] = 
{B00110,
 B11110,
 B00110,
 B00110,
 B00110,
 B01111,
 B11111,
 B00000};

//---------------------

void setup()
{
  Serial.begin(9600); // Inicia o monitor serial

  // Configura os pinos como saída
  pinMode(ldOk, OUTPUT);
  pinMode(ldAlert, OUTPUT);
  pinMode(ldProb, OUTPUT);
  pinMode(alertRing, OUTPUT);

  lcd.begin(16,2); // Inicializa o LCD de 16 colunas e 2 linhas
  lcd.clear();     // Limpa a tela
  
  lcd.setCursor(0,0); //Define o posicionamento da frase ou figura
  lcd.print("Bem-vindo!"); // Printa o "Bem-vindo!" no LCD

  // Cria os caracteres customizados na memória do LCD (suporta até 8)
 
  lcd.createChar(0, wine1Baixa);
  lcd.createChar(1, wine2Baixa);
  lcd.createChar(2, wine3);
  lcd.createChar(3, wine4);
  
  lcd.createChar(0, wine1Medio); // Aqui sobrescreve os IDs 0 e 1 para no 
   								// loop decidir se vai exibir a taça cheia ou vazia
  lcd.createChar(1, wine2Medio);

  lcd.createChar(0, wine1Alta);
  lcd.createChar(1, wine2Alta);

  
  lcd.createChar(4, letra1);
  lcd.createChar(5, letra2);
  lcd.createChar(6, letra3);
  lcd.createChar(7, letra4);

 
 
}

void loop()
{
  int luz = analogRead(A0); // Lê o valor do sensor LDR no pino analógico A0
  int nivel = map(luz, 0, 1023, 0, 100); // Converte o valor (0 a 1023) para uma escala de 0 a 100%

  Serial.println(nivel);// Exibe o valor no monitor serial


  // --------- Printa o nível de luminosidade no LCD ---------
  lcd.setCursor(0,1);
  lcd.print("Nivel: ");
  lcd.print(nivel);
  lcd.print("%   ");
  
  // --------- Letra A ---------
  lcd.setCursor(11, 0);
  lcd.write(byte(4));
  lcd.setCursor(12, 0);
  lcd.write(byte(5));
  lcd.setCursor(11, 1);
  lcd.write(byte(6));
  lcd.setCursor(12, 1);
  lcd.write(byte(7));
  
    // --- Lógica dos níveis ---

  // --------- Nível baixa luminosidade---------
  if(nivel >= 0 && nivel <=69){
    digitalWrite(ldAlert, LOW);
    digitalWrite(ldProb, LOW);
    digitalWrite(ldOk, HIGH);
    noTone(alertRing);
    
    lcd.createChar(0, wine1Baixa); // Altera a taça para cheia
  	lcd.createChar(1, wine2Baixa);
    
    lcd.setCursor(13, 0); // Exibe a taça
  	lcd.write(byte(0));
  	lcd.setCursor(14, 0);
  	lcd.write(byte(1));
    lcd.setCursor(13, 1);
  	lcd.write(byte(2));
  	lcd.setCursor(14, 1);
  	lcd.write(byte(3));
    
    
  }

  
  // --------- Nível de luminosidade média ---------
  if(nivel >= 70 && nivel <=89){
    digitalWrite(ldAlert, HIGH);
    digitalWrite(ldOk, LOW);
    digitalWrite(ldProb, LOW); 
    lcd.createChar(0, wine1Medio); // Altera a taça para meio cheia
  	lcd.createChar(1, wine2Medio);

    lcd.setCursor(13, 0); // Exibe a taça
  	lcd.write(byte(0));
  	lcd.setCursor(14, 0);
  	lcd.write(byte(1));
    lcd.setCursor(13, 1);
  	lcd.write(byte(2));
  	lcd.setCursor(14, 1);
  	lcd.write(byte(3));
    
    // Toca o buzzer por 3 segundos e se o nível
    // continuar em estado de alerta por 5 segundos
    // ele volta a tocar
    tone(alertRing, 50); 
    delay(3000);
    noTone(alertRing); 
    delay(5000);
 
    
  }

  // --------- Nível de alta luminosidade  ---------
  if(nivel >= 90 && nivel <=100){
    digitalWrite(ldProb, HIGH);
    digitalWrite(ldOk, LOW);
    digitalWrite(ldAlert, LOW);
    noTone(alertRing);
    lcd.createChar(0, wine1Alta); // Altera a taça para vazia
  	lcd.createChar(1, wine2Alta);
    lcd.setCursor(13, 0);
  	lcd.write(byte(0));
  	lcd.setCursor(14, 0);
  	lcd.write(byte(1));
    lcd.setCursor(13, 1);
  	lcd.write(byte(2));
  	lcd.setCursor(14, 1);
  	lcd.write(byte(3));
  

  }

}