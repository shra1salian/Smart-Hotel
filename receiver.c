#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

String name1="SMART RESTORENT ";  
String name2="    SYSTEM      ";

unsigned int data ,i;

void setup() {


  pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    
  pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
     pinMode(13,OUTPUT);
    

   Serial.begin(9600);
    // initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  for(i=0;i<=16;i++){
   lcd.print(name1[i]);
   delay(100);
  }
 
  lcd.setCursor(0, 1);
  for(i=0;i<=16;i++){
   lcd.print(name2[i]);
   delay(100); 
  }
 
 
 
    
}

// the loop function runs over and over again forever
void loop() 
{
  if((digitalRead(2)==HIGH)&&(digitalRead(3)==LOW)&&(digitalRead(4)==LOW)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("TEA");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("TEA ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==LOW)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==LOW)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("COFFEE");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("dish 2 ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==HIGH)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==LOW)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("DOSA");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("dish 3 ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==LOW)&&(digitalRead(3)==LOW)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("IDLY");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("dish 4 ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==HIGH)&&(digitalRead(3)==LOW)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("SAMBAR");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("dish 5 ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==LOW)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("PULAO");
    
    lcd.setCursor(0,1);
   lcd.print("ORDERED");
   Serial.println("dish 6 ordered");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==HIGH)&&(digitalRead(3)==HIGH)&&(digitalRead(4)==HIGH)&&(digitalRead(5)==LOW))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("CALL WAITER");
    
   Serial.println("CALL WAITER");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
  if((digitalRead(2)==LOW)&&(digitalRead(3)==LOW)&&(digitalRead(4)==LOW)&&(digitalRead(5)==HIGH))
  
 {
  lcd.clear();
    lcd.setCursor(0, 0);
   lcd.print("BILL REQUEST");
    
   Serial.println("BILL REQUEST");
   digitalWrite(13,HIGH);
   delay(1000); 
   digitalWrite(13,LOW);
 }
    
}
