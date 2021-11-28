const int TRIGGER = 2;  //D4
const int ECHO = 0;  //D3
int value;

#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = ""; // from the blynk app

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = ""; local wifi ssid
char pass[] = "";local wifi password
void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance= duration*0.034/2;
  Serial.print(distance);
  Serial.println("Centimeter:");
  value=map(distance,0,11,0,100);
  Blynk.virtualWrite(V5,distance);
  delay(200);
  if(distance<5){
    Blynk.virtualWrite(V3,255);
    Blynk.virtualWrite(V1,0);
  }
  else{
    Blynk.virtualWrite(V1,255);
    Blynk.virtualWrite(V3,0);
  }
  Blynk.run();
}
