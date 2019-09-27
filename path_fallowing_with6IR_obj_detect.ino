 int S_A = 12;  //Enable Motor A
int M_A1 = 10; //motor a = +
int M_A2 = 9; //motor a = -
int M_B1 = 8; //motor b = -
int M_B2 = 7; //motor b = +
int S_B = 11;  //Enable Motor B

int ls1 = A0;    // for Rigth_Sensor
int ls2 = A1;    // for Left_Sensor
int ms1 = A2;    // for Rigth_Sensor
int ms2 = A3;    // for Left_Sensor
int rs1 = A4;    // for Rigth_Sensor
int rs2 = A5;    // for Left_Sensor

int led=13;

const int trigPin = 6;
const int echoPin = 5;

 
// defines variables
long duration;
int distance;
int safetyDistance;
 
void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);
pinMode(ls1, INPUT);
pinMode(ls2, INPUT);
pinMode(ms1, INPUT);
pinMode(ms2, INPUT);
pinMode(rs1, INPUT);
pinMode(rs2, INPUT);

analogWrite(S_A,130); //Here you can change the Voltage(Speed) to the motors A.
analogWrite(S_B,130); //S Here you can change the Voltage(Speed) to the motors B.

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);

}
void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(50);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
safetyDistance = distance;
if(safetyDistance<=10){
 Stop();
 delay(1000);
 forword();
 delay(100);
}
else{
  path();
}
}
void forword(){
digitalWrite(M_A1,1);
digitalWrite(M_A2,0);
digitalWrite(M_B1,1); 
digitalWrite(M_B2,0);
}
void turnLeft(){ 
digitalWrite(M_A1,0);
digitalWrite(M_A2,0);
digitalWrite(M_B1,1);
digitalWrite(M_B2,0);
}
void turnRight(){
digitalWrite(M_A1,1);
digitalWrite(M_A2,0);
digitalWrite(M_B1,0);
digitalWrite(M_B2,0);  
}
void Stop(){
digitalWrite(M_A1,0);
digitalWrite(M_A2,0);
digitalWrite(M_B1,0);
digitalWrite(M_B2,0);
}

void path(){
if ((digitalRead(ls1) == 1)&&(digitalRead(ls2) == 1)&&(digitalRead(ms1) == 1)&&(digitalRead(ms2) == 1)&&(digitalRead(rs1) == 1)&&(digitalRead(rs2) == 1)){Stop();}
if ((digitalRead(ls2) == 1)&&(digitalRead(ls1) == 1)&&(digitalRead(ms1) == 0)&&(digitalRead(ms2) == 0)&&(digitalRead(rs1) == 0)&&(digitalRead(rs2) == 0)){turnLeft();}
if ((digitalRead(ls1) == 0)&&(digitalRead(ls2) == 0)&&(digitalRead(ms1) == 0)&&(digitalRead(ms2) == 0)&&(digitalRead(rs1) == 1)&&(digitalRead(rs2) == 1)){turnRight();}
if ((digitalRead(ls1) == 0)&&(digitalRead(ls2) == 0)&&(digitalRead(ms1) == 1)&&(digitalRead(ms2) == 1)&&(digitalRead(rs1) == 0)&&(digitalRead(rs2) == 0)){forword();}
}
 

