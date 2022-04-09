#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String ssid     = "Simulator Wifi";   
String password = ""; 
String host     = "api.thingspeak.com";
const int httpPort   = 80; 
String uri1     = "/update?api_key=&field1="; //keep your API key for Temperature 
String uri2  ="/update?api_key=&field1=";//keep your API key for Moisture
String uri3 = "/update?api_key=&field1=";//keep your API key for Humidity
int setupESP8266(void) { 
  
 // Serial.begin(115200);    
  Serial.println("AT");   
  delay(1000);        
  if (!Serial.find("OK")) return 1; 
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\""); 
  delay(1000);         
  if (!Serial.find("OK")) return 2; 
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort); 
  delay(1000);        
  if (!Serial.find("OK")) return 3; 
  return 0; 
} 


void setup() {
  setupESP8266();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  int a0=analogRead(A0);
 
  

  int a1=analogRead(A1);

  int a2 = analogRead(A2);
  delay(100);
  
  String httpPacket1 = "GET " + uri1 + String(a0) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length1 = httpPacket1.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length1); 
  delay(1000);
  Serial.print(httpPacket1); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  delay(1000);
  
  //////////////////////
  String httpPacket2 = "GET " + uri2 + String(a1) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length2 = httpPacket2.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length2); 
  delay(1000);
  Serial.print(httpPacket2); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  
  ////////////////////////////////
  String httpPacket3 = "GET " + uri3 + String(a2) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length3 = httpPacket3.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length3); 
  delay(1000);
  Serial.print(httpPacket3); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  
  /////////////////////
  
  Serial.print( "Temp Reading = ");
  Serial.println( analogRead(A0));
  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A0));
  delay(1000);
  lcd.clear();
  if( analogRead(A0)>300)
 {
 
   digitalWrite(9,1);
   delay(1000);   
 }
 digitalWrite(9,0);
  delay(1000);
  
Serial.print( "Moisture Reading = ");
Serial.println( analogRead(A1));
lcd.setCursor(0, 0);
  lcd.print("Moisture");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A1));
  delay(1000);
  lcd.clear();
if( analogRead(A1)<300)
 {
 
   digitalWrite(8,1);
   delay(1000);
 }
digitalWrite(8,0);
  delay(1000);
  
Serial.print( "Humidity Reading = ");
Serial.println( analogRead(A2));
lcd.setCursor(0, 0);
  lcd.print("Humidity");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A2));
  delay(1000);
  lcd.clear();
  delay(1000);
}#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String ssid     = "Simulator Wifi";   
String password = ""; 
String host     = "api.thingspeak.com";
const int httpPort   = 80; 
String uri1     = "/update?api_key=MRBW6M8EOQCZBFEC&field1=";  
String uri2  ="/update?api_key=MRBW6M8EOQCZBFEC&field1=";
String uri3 = "/update?api_key=MRBW6M8EOQCZBFEC&field1=";
int setupESP8266(void) { 
  
 // Serial.begin(115200);    
  Serial.println("AT");   
  delay(1000);        
  if (!Serial.find("OK")) return 1; 
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\""); 
  delay(1000);         
  if (!Serial.find("OK")) return 2; 
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort); 
  delay(1000);        
  if (!Serial.find("OK")) return 3; 
  return 0; 
} 


void setup() {
  setupESP8266();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  int a0=analogRead(A0);
 
  

  int a1=analogRead(A1);

  int a2 = analogRead(A2);
  delay(100);
  
  String httpPacket1 = "GET " + uri1 + String(a0) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length1 = httpPacket1.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length1); 
  delay(1000);
  Serial.print(httpPacket1); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  delay(1000);
  
  //////////////////////
  String httpPacket2 = "GET " + uri2 + String(a1) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length2 = httpPacket2.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length2); 
  delay(1000);
  Serial.print(httpPacket2); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  
  ////////////////////////////////
  String httpPacket3 = "GET " + uri3 + String(a2) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"; 
  int length3 = httpPacket3.length(); 
  Serial.print("AT+CIPSEND="); 
  Serial.println(length3); 
  delay(1000);
  Serial.print(httpPacket3); 
  delay(1000);  
  if (!Serial.find("SEND OK\r\n")) return; 
  
  /////////////////////
  
  Serial.print( "Temp Reading = ");
  Serial.println( analogRead(A0));
  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A0));
  delay(1000);
  lcd.clear();
  if( analogRead(A0)>300)
 {
 
   digitalWrite(9,1);
   delay(1000);   
 }
 digitalWrite(9,0);
  delay(1000);
  
Serial.print( "Moisture Reading = ");
Serial.println( analogRead(A1));
lcd.setCursor(0, 0);
  lcd.print("Moisture");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A1));
  delay(1000);
  lcd.clear();
if( analogRead(A1)<300)
 {
 
   digitalWrite(8,1);
   delay(1000);
 }
digitalWrite(8,0);
  delay(1000);
  
Serial.print( "Humidity Reading = ");
Serial.println( analogRead(A2));
lcd.setCursor(0, 0);
  lcd.print("Humidity");
  lcd.setCursor(0, 1);
  lcd.print(analogRead(A2));
  delay(1000);
  lcd.clear();
  delay(1000);
}
