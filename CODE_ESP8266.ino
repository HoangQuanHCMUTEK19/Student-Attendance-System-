#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"
#include <ArduinoJson.h>
#define WIFI_SSID "Phong 10"
#define WIFI_PASSWORD "hongpeoi123@"

#define FIREBASE_HOST "fir-demo-deeaf-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "laEIGSAbfgujZyEUtHKmZrDxzJrvAOfo7ZFOexNN"

FirebaseData firebaseData;
//wificlient client
String path = "/";
FirebaseJson json;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  if(!Firebase.beginStream(firebaseData,path))
  {
    Serial.println("REASON"+firebaseData.errorReason());
    Serial.println();
  }
  Serial.print("connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  while (!Serial) continue;
}
void loop() {
  // put your main code here, to run repeatedly:
  if ( Serial.available() ) {
    String data="";
    while(Serial.available()){
      data=Serial.readString();
    }
    if (data =="1")
    {
      Firebase.setString(firebaseData, path + "/Ho va ten 1"," Nguyen Dinh Nhat");
      Firebase.setString(firebaseData, path + "/Ho va ten 1" + path + "/MSSV","19146070");
      Firebase.setString(firebaseData, path + "/Ho va ten 1" + path + "/Lop","191462A");
    }
    if (data == "2")
    {
      Firebase.setString(firebaseData, path + "/Ho va ten 2","Lai Tien Quang");
      Firebase.setString(firebaseData, path + "/Ho va ten 2" + path + "/MSSV","19146376");
      Firebase.setString(firebaseData, path + "/Ho va ten 2" + path + "/Lop","191462B");
    }
    if (data == "3")
    {
      Firebase.setString(firebaseData, path + "/Ho va ten 3","Nguyen Le Hoang Quan");
      Firebase.setString(firebaseData, path + "/Ho va ten 3" + path + "/MSSV","19146378");
      Firebase.setString(firebaseData, path + "/Ho va ten 3" + path + "/Lop","191462C");
    }
  }
}
