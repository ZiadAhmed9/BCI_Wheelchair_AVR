#include <SPI.h>

#define ENCA 3
#define ENCB 5
#define ENCA2 2
#define ENCB2 4
#define inputbutton 1
int R_PWM = 10;
int L_PWM = 11;
int R_PWM2 = 6;
int L_PWM2 = 9;
// globals
long prevT = 0;
int posPrev = 0;
int posPrev1 = 0;
// Use the "volatile" directive for variables
// used in an interrupt
volatile int pos_i = 0;
volatile int pos_i1 = 0;
volatile long prevT_i = 0;
volatile float vt = 50;
float Long_press = 0;
const int push_button = A5;
float v1Filt = 0;
float v1Prev = 0;
float v2Filt = 0;
float v2Prev = 0;
float eintegral = 0;
float eintegral2 = 0;
double velocity1 = 0;
double velocity2 = 0;
int speed1_button;

volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;

void setup() {
 Serial.begin(115200);

  pinMode(ENCA, INPUT_PULLUP);
pinMode(ENCB, INPUT);
pinMode(R_PWM, OUTPUT);
pinMode(L_PWM, OUTPUT);
pinMode(ENCA2, INPUT_PULLUP);
pinMode(ENCB2, INPUT);  
pinMode(R_PWM2, OUTPUT);
pinMode(L_PWM2, OUTPUT);
attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
attachInterrupt(digitalPinToInterrupt(ENCA2), readEncoder_2, RISING);   
pinMode(push_button, INPUT_PULLUP);                
 pinMode(MISO,OUTPUT); 
Serial.println("Press button");                  

  SPCR |= _BV(SPE);                  
  received = false;

  SPI.attachInterrupt(); 

}
ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR;         
  received = true;                        
}
void loop() {
int pos = 0;
int pos1 = 0;
noInterrupts(); // disable interrupts temporarily while reading
pos = pos_i; // 1st encoder position readings
pos1 = pos_i1; // 2nd encoder position readings
interrupts(); // turn interrupts back on
long currT = millis();
double deltaT;
if (currT < prevT) {
 deltaT = (4294967295 + currT - prevT) / 1.0e3;
 prevT = 4294967295 - prevT + currT;
}
else {
 deltaT = (currT - prevT) / 1.0e3;
 prevT = currT;
}
if (deltaT != 0.00) {
 velocity1 = (pos - posPrev) / deltaT;
 velocity2 = (pos1 - posPrev1) / deltaT;
}
if (digitalRead(push_button) == LOW) {
 vt = 30;
}
else {
 vt = 50;
}
Long_press = Long_press + deltaT;
if (Long_press > 7  && digitalRead(push_button) == HIGH) {
 vt = 150;
}
posPrev = pos;
posPrev1 = pos1;
// Convert count/s to RPM
float v1 = velocity1 / 600.0 * 60.0;
float v2 = velocity2 / 600.0 * 60.0;
// Low-pass filter (25 Hz cutoff)
v1Filt = 0.854 * v1Filt + 0.0728 * v1 + 0.0728 * v1Prev;
v1Prev = v1;
v2Filt = 0.854 * v2Filt + 0.0728 * v2 + 0.0728 * v2Prev;
v2Prev = v2;
float kp = 0.5;
float ki = 0.4; //integral term reduces steady state error
float kp2 = 0.5;
float ki2 = 0.4; //integral term reduces steady state error
float e = vt - v1Filt;
float e2 = vt - v2Filt;
eintegral = eintegral + e * deltaT;
eintegral2 = eintegral2 + e2 * deltaT;
float u = kp * e + ki * eintegral;
float u2 = kp2 * e2 + ki2 * eintegral2;
// Set the motor speed and direction
int dir = 1;
if (u < 0) {
 dir = -1;
}
int pwr = (int) fabs(u);
if (pwr > 255) {
 pwr = 255;
}
//set motor 2 speed and direction
int dir2 = 1;
if (u2 < 0) {
 dir2 = -1;
}
int pwr2 = (int) fabs(u2);
if (pwr2 > 255) {
 pwr2 = 255;
}


  if(received)                           
   {
      if (Slavereceived==1) 
      {
        //moves Forwards 
        setMotor(dir, pwr, R_PWM, L_PWM);
        setMotor_2(dir2, pwr2, R_PWM2, L_PWM2);
      }else
      {
         //moves Backwards   
        setMotor(-1, pwr, R_PWM, L_PWM);
        setMotor_2(-1, pwr2, R_PWM2, L_PWM2);       
      }
      
      buttonvalue = digitalRead(inputbutton);  //el slave byb3at lel master
      
      if (buttonvalue == HIGH)           
      {
        x=1;
        
      }else
      {
        x=0;
      }
      
  Slavesend=x;                             
  SPDR = Slavesend;                       
  delay(1000);
}
}


 
void setMotor(int dir, int pwmVal, int R_PWM, int L_PWM) {
if (dir == 1) {
 // Turn one way
 analogWrite(R_PWM, pwmVal);
 analogWrite(L_PWM, 0);
}
else if (dir == -1) {
 // Turn the other way
 analogWrite(R_PWM, 0);
 analogWrite(L_PWM, pwmVal);
}
else {
 // Or dont turn
 analogWrite(R_PWM, 0);
 analogWrite(L_PWM, 0);
}
}
void setMotor_2(int dir, int pwmVal, int R_PWM, int L_PWM) {
if (dir == 1) {
 // Turn one way
 analogWrite(R_PWM, pwmVal);
 analogWrite(L_PWM, 0);
}
else if (dir == -1) {
 // Turn the other way
 analogWrite(R_PWM, 0);
 analogWrite(L_PWM, pwmVal);
}
else {
 // Or dont turn
 analogWrite(R_PWM, 0);
 analogWrite(L_PWM, 0);
}
}

void readEncoder() {
// Read encoder B when ENCA rises
int b = digitalRead(ENCB);
if (b > 0) {
 // If B is high, increment forward
 pos_i--;
}
else {
 // Otherwise, increment backward
 pos_i++;
}
}
void readEncoder_2() {
// Read encoder B1 when ENCA2 rises
int x = digitalRead(ENCB2);
if (x > 0) {
 // If X is high, increment forward
 pos_i1--;
}
else {
 // Otherwise, increment backward
 pos_i1++;
}
}
