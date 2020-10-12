// La velocidad depende del modelo de ESP-01
// siendo habituales 9600 y 115200
 
#include "SoftwareSerial.h"
#define SSID "Casa2"
#define PWD "MeadePolaris127"
#define DEBUG 1
SoftwareSerial WifiSerial(2, 3);// RX, TX
void printf(char *&toprint){
  if(DEBUG){
    Serial.print(toprint);
  }
}
void printf(char toprint){
  if(DEBUG){
    Serial.print(toprint);
  }
}

class WIFI{
  public:
    bool sendATcommand(char CMD[50], char RTA[50], int timeout);
    bool init();
    void loopfunction();
};

WIFI wifi;

void setup()
{
   Serial.begin(115200);
//   softSerial.begin(115200);
   Serial.println("arrancamos");
  wifi.init();   
   
}
void loop()
{
  wifi.loopfunction();
  
}

bool WIFI::init(){
  WifiSerial.begin(115200);  
  printf("inicia WiFi Serial\n");
  sendATcommand("ATE1","OK",2000);
    
  sendATcommand("AT+CWMODE=3","OK",2000);
  char string[50];
  sprintf(string,"AT+CWJAP=\"%s\",\"%s\"",SSID,PWD);
  sendATcommand(string,"OK",2000);
  
}

bool WIFI::sendATcommand(char CMD[50], char RTA[50], int timeout){
  WifiSerial.print(CMD);
  printf(CMD);
  int t=millis();
  int i=0;
  char string[100];
  bool encontrado=false;
  memcpy(RTA,'\0',50);
  while(millis()-t>timeout && !encontrado){
    if (WifiSerial.available())
    {
      string[i]=WifiSerial.read();
      printf(string[i]);
      i++;
    }
    if(strstr(string,RTA)!=NULL){
      encontrado=true;      
    }
  }
  while(WifiSerial.available()){
    WifiSerial.read();
  }
  return encontrado;
}

void WIFI::loopfunction(){
  if (WifiSerial.available())
  {
    Serial.print((char)WifiSerial.read());
  }
  if (Serial.available())
  {
    WifiSerial.print((char)Serial.read());
  }
}
