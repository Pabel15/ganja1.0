//datos Luz
#define R1 50 //Kohms
//datos Humedad
#define R2 10 //Koms

#define Nmedia 1000
double Temp();
double Luz();
double Hum();

void setup() {
  Serial.begin(115200);
}

void loop() {
  int t1=millis();
  Serial.print(Luz());Serial.print("\t");Serial.print(Temp());;Serial.print("\t");Serial.print(Hum());
  Serial.println();
  delay(1000);        // delay in between reads for stability

}

double Luz(){
  //Rluz=(5V-Vsensor)/Vsensor*R1 [Kohm] / R1=50k
  //luz=
  double s=0;
  for(int i=0;i<Nmedia;i++){
    s+=1.0*analogRead(A0)/1024;
  }
  return pow(15./(R1*(s/Nmedia)/(1.-(s/Nmedia))),1/0.6);
}
double Temp(){
  //salida Temp[ºC]=0mv+10mV/C
  double s=0;
  for(int i=0;i<Nmedia;i++){
    s+= 1.0*(analogRead(A1))/1024;
  }
  return 5.*s/Nmedia/0.01;
}
double Hum(){
  //salida Hum[ºC]=inversa de la resistencia
  double s=0;
  for(int i=0;i<Nmedia;i++){
    s+= 1.*(analogRead(A2))/1024;
  }
  ///Sw=(R0/Rt)**(1/n)  n=2, r0==resistividad Sw=1
//  return sqrt(1.7/(R2*(s/Nmedia)/(1.-s/Nmedia)));
  return 5.*(s/Nmedia);
//  return R2*(s/Nmedia)/(1.-s/Nmedia);
}
