int ldrPin=2;
int pirPin=8;
int led1=13;
int led2=5;
int relay=A3;
int gas=11;
int buzzer=2;

void setup(){
  pinMode(ldrPin,INPUT);
  pinMode(pirPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(gas,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  light();
  gasSensor();
}

void light(){
  int ldrStatus=digitalRead(ldrPin);
  if (ldrStatus==1){
    Serial.print("Darkness");
    Serial.println(ldrStatus);
    digitalWrite(led1,HIGH);
  }else{
    Serial.print("Enough Light");
    Serial.println(ldrStatus);
    digitalWrite(led1,LOW);
  }
}
void gasSensor(){
  int gasStatus=digitalRead(gas);
  if (gasStatus==1){
    digitalWrite(led2,HIGH);
  }else{
    digitalWrite(led2,LOW);
  }
}

void motion(){
  int motionStatus=digitalRead(pirPin);
  if (motionStatus==1){
    digitalWrite(buzzer,HIGH);
    delay(5000);
  }else{
    digitalWrite(buzzer,LOW);
    delay(100);
  }
}