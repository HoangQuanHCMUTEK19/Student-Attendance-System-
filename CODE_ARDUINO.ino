#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#define SS_PIN 10
#define RST_PIN 9
int loa = 8;
LiquidCrystal_I2C lcd(0X27,16,2); //SCL A5 SDA A4
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial ser(2,3); // RX, TX 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  ser.begin (9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  delay(10);
  lcd.init();                    
  lcd.backlight(); 
  lcd.setCursor(3,0);
  lcd.print("HELLO CLASS");
  pinMode(loa, OUTPUT);
  Serial.println("Dat the diem danh cua ban vao");
  Serial.println();
 
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Ho va Ten va MSSV :");
  content.toUpperCase();
  if (content.substring(1) == "E1 79 31 02" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("1-Nguyen Dinh Nhat - 19146070");
    ser.print("1");
    Serial.println();
    lcd.setCursor(0,1);
    lcd.print(" NG  DINH   NHAT");
    digitalWrite(loa,HIGH);
    delay(500);
    digitalWrite(loa,LOW);
  }
   if (content.substring(1) ==  "D1 91 E1 21" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("2-Lai Tien Quang 191463");
    ser.print("2");
    Serial.println();
    lcd.setCursor(0,1);
    lcd.print(" LAI TIEN QUANG ");
    digitalWrite(loa,HIGH);
    delay(500);
    digitalWrite(loa,LOW);
  }
   if (content.substring(1) == "F3 85 BB 16" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("3-Nguyen Le Hoang Quan - 19146378");
    ser.print("3");
    Serial.println();
    lcd.setCursor(0,1);
    lcd.print("NG LE HOANG QUAN");
    digitalWrite(loa,HIGH);
    delay(500);
    digitalWrite(loa,LOW);
  }
}
