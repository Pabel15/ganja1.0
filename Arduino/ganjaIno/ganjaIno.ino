#define R1 50 //Kohms
#define Nmedia 100
double Temp();
double Luz();
void setup() {
  Serial.begin(115200);
}

void loop() {
  
  int t1=millis();
  Serial.print(Luz());Serial.print("\t");Serial.print(Temp());;Serial.print("\t");Serial.print(millis()-t1);
  Serial.println();
  delay(500);        // delay in between reads for stability

}

double Luz(){
  //Rluz=(5V-Vsensor)/Vsensor*R1 [Kohm] / R1=50k
  double s=0;
  for(int i=0;i<Nmedia;i++){
    s+=1.0*(1024-analogRead(A0))/analogRead(A0)*R1;
  }
  return s;
}
double Temp(){
  //salida Temp[ºC]=0mv+10mV/C
  double s=0;
  for(int i=0;i<Nmedia;i++){
    s= 5.*(analogRead(A1))/1024/(0.01);
  }
  return s;
}

