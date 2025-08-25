#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
#define SW1_PIN 11
#define SW2_PIN 12
#define SW3_PIN 13
#define BUTTON_PIN 2
#define EN_PIN 5
#define IN1_PIN 4
#define IN2_PIN 3
int check_SW1 = 1;
int check_SW2 = 1;
int check_SW3 = 1;
int IN11 = 1;
int IN12 = 1;
//int exp = 1;
int count;
int count1;
int X;
int Y;
#define POTENTIOMETER_PIN 21
int potentiometerValue;
float result;
float result1;
float result2;
void setup()
{
  delay(250); 
  display.begin(0x3C, true);
  delay(1000);
  display.clearDisplay();
  display.display();
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SW1_PIN, INPUT);
  pinMode(SW2_PIN, INPUT);
  pinMode(SW3_PIN, INPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
}

void loop()
{
  display.setRotation(3);
  display.setTextSize(1); 
  display.setTextColor(SH110X_WHITE);
    check_SW1 = digitalRead(SW1_PIN);
    check_SW2 = digitalRead(SW2_PIN);
    check_SW3 = digitalRead(SW3_PIN);
    IN11 = digitalRead(IN1_PIN);
    IN12 = digitalRead(IN2_PIN);
  if (check_SW1 == 0){
    up();
  }
  else if (check_SW2 == 0){
    down();
  }
  else if (check_SW3 == 0){
    reset();
 }
 potentiometerValue= analogRead(POTENTIOMETER_PIN);
 result = potentiometerValue * (0.00677966);
result1 = result - 0.6;
result2 = result1*9.81;
  display.setCursor(0, 30);
  display.print(result1);
  display.setCursor(32, 30);
  display.print("Kg");
  display.setCursor(0, 50);
  display.print(result2);
  display.setCursor(34, 50);
  display.print("Newtons");
  display.setCursor(0, 40);
  display.print(count);
  display.setCursor(15, 40);
  display.print("turns");
  display.setCursor(0, 0);
  display.print("Group 3 Team 5A");
  if (IN11 == 0){
  count1++;}
  if (IN12 == 0){
  count1--;}
  count = 0.2*count1;
  display.display();
  delay(100);
  display.clearDisplay(); 
}
void up(){
 // attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_ISR, FALLING);
  
  analogWrite(EN_PIN,127);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  check_SW2 = 1;
  check_SW3 = 1;
  Serial.println("up");
 // display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Direction:");
  display.setCursor(60, 10);
  display.println("Up");
  display.display();
  delay(800);
}
/*void exp1(){
  if (check_SW1 == 0){
    int exp = 0;
     if int exp = 0; {
       Serial.println("up");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Direction:");
  display.setCursor(0, 8);
  display.println("up");
  display.display();
     }}
}
*/
void timeall(){
  if (check_SW2 == 0){
  count++;}
  if (check_SW1 == 0){
  count--;}
}

void down(){
  // attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonR_ISR, FALLING);
  analogWrite(EN_PIN,127);
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  check_SW1 = 1;
  check_SW3 = 1;
   Serial.println("down");
    display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Direction:");
  display.setCursor(60, 10);
  display.println("Down");
  display.display();
   delay(800);
}
void reset(){
  analogWrite(EN_PIN,0);
   digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  check_SW1 = 1;
  check_SW2 = 1;
  Serial.println("Stopped");
  delay(1);
   display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Direction:");
  display.setCursor(60, 10);
  display.println("Stopped");
  display.display();
   delay(800);
}
void button_ISR() {
Serial.println(count);
 display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Direction:");
  display.setCursor(60, 0);
  display.print("up");
   display.setCursor(36, 16);
   display.print(count);
  display.setCursor(0, 16);
  display.print("Turns:");
  display.display();
}
void buttonR_ISR() {
Serial.println(count);
display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Direction:");
  display.setCursor(60, 0);
  display.println("down");
  display.setCursor(36, 16);
  display.print(count);
  display.setCursor(0, 16);
  display.print("Turns:");
  display.display();
}
