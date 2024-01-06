#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int coinAcceptorPin = 3;  // Connect the coin acceptor signal wire to pin 2

volatile unsigned long coinPulseCount = 0;

int totalCredits = 0;

void setup() {
  Serial.begin(9600);
    lcd.init();
  pinMode(coinAcceptorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(coinAcceptorPin), coinInserted, FALLING);
  lcd.setCursor(0, 0); // Set cursor to the first line
  lcd.print("Insert Coin/Bill");
    lcd.backlight();
}

void loop() {
  // Your main loop code here
  // You can perform other tasks while waiting for coin pulses
  
  lcd.setCursor(0, 1);  // Set cursor to the second line
  lcd.print("Credits: ");
  lcd.print(coinPulseCount);
   lcd.backlight();
   delay(1500); 
}

void coinInserted() {
  // This function will be called whenever a falling edge is detected on pin 2
  coinPulseCount++;
  delay(599);
  Serial.println("Coin inserted!");
  Serial.print("Total Coin Pulses: ");
  Serial.println(coinPulseCount);
}
