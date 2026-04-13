#  Monitor de Luminosidade Agnello

Este projeto foi desenvolvido para monitorar a incidência de luz em ambientes de armazenamento de vinho. Através de um sensor LDR e um display LCD, o sistema fornece feedback visual e sonoro sobre as condições do ambiente, garantindo a conservação ideal dos produtos.

##  Demonstração Visual
O grande diferencial deste projeto é a interface gráfica no LCD 16x2. Criamos uma logo personalizada (letra 'A') e uma animação de uma taça que reage aos níveis de luz:
* **Luz Baixa (0-69%):** Taça Cheia (Ideal).
* **Luz Média (70-89%):** Taça Meio Cheia (Alerta).
* **Luz Alta (90-100%):** Taça Vazia (Crítico).


## Componentes Utilizados
•	Arduino Uno
•	Display LCD 16x2
•	Sensor de Luz LDR
•	LEDs (Verde, Amarelo e Vermelho)
•	Buzzer
•	Resistor 330 Ohm
•	Resistor 150 Ohm
•	Resistor 10K Ohm
•	Protoboard


##  Pinagem
| Componente | Pino Arduino |
| :--- | :--- |
| LCD (RS, E, D4-D7) | 8, 7, 6, 5, 4, 3, 2 |
| LED Verde | 12 |
| LED Amarelo | 11 |
| LED Vermelho | 10 |
| Buzzer | 9 |
| Sensor LDR | A0 |

##  Como usar
1. Conecte os componentes conforme a tabela de pinagem.
2. Certifique-se de ter a biblioteca `LiquidCrystal.h` instalada na sua Arduino IDE.
3. Faça o upload do código disponível neste repositório.
4. Monitore os níveis através do Serial Monitor (9600 baud) ou diretamente no LCD.

---