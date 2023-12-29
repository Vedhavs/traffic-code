#include <Wire.h>
#include <LiquidCrystal_I2C.h> LiquidCrystal_I2C lcd(0x27, 16, 2);
int b; int C; int D; int i; int x; int y; int z; int ig=0; //char password[8];
int count=0; char input[15]; //char str[15];
int voice1=4; int voice2=5; int voice3=3;//int irPin = A0; int gasAPin = A1; int sw1=2; int sw2=6; int sw3=7; //int M1=A0;
int lim1=8; int lim2=9; int lim3=10; int wheel1=12; int wheel2=13;
int en1=3; int en2=6; int alcoholThres = 500; void setup()
{ lcd.init(); lcd.backlight(); lcd.clear(); Serial.begin(9600); // Serial1.begin(9600);
pinMode(voice1,OUTPUT); pinMode(voice2,OUTPUT); pinMode(voice3,OUTPUT);
// pinMode(v4,OUTPUT);
// pinMode(v5,OUTPUT);
// pinMode(v6,OUTPUT);
// pinMode(v7,OUTPUT);
// pinMode(M1,OUTPUT); pinMode(lim1,INPUT); pinMode(lim2,INPUT); pinMode(lim3,INPUT); pinMode(gasAPin,INPUT);
pinMode(sw1,INPUT); pinMode(sw2,INPUT); pinMode(sw3,INPUT); digitalWrite(sw1,1); digitalWrite(sw2,1); digitalWrite(sw3,1); digitalWrite(lim1,1);
digitalWrite(lim2,1); digitalWrite(lim3,1); pinMode(wheel1, OUTPUT);// motor 1 pinMode(wheel2, OUTPUT); // motor 2
digitalWrite(voice1,HIGH); digitalWrite(voice2,HIGH); digitalWrite(voice3,HIGH);
//	Serial.print(digitalRead(sw2));
 
// digitalWrite(v4,1); // digitalWrite(v5,1); // digitalWrite(v6,1); // digitalWrite(v7,1);
// digitalWrite(voice4,HIGH);
//	analogWrite(M1,LOW);	// lcd.begin(16,2); lcd.clear();
lcd.print("TRAFFIC VIOLATION");
lcd.setCursor(0,1); lcd.print("MONITORING SYSTM");
delay(2000);
x=digitalRead(sw1); y=digitalRead(sw2); z=digitalRead(sw3);
}
//=========================main=======================//
void loop()
{
Serial.println(digitalRead(gasAPin)); Serial.print(digitalRead(lim1)); Serial.print(digitalRead(lim2)); Serial.println(digitalRead(lim3)); lcd.clear();
lcd.print("TRAFFIC VIOLATION");
lcd.setCursor(1,1); lcd.print("MONITORING"); delay(2500); if(ig==1)
{
helmet_Alcohol_Check();
}
}
//===============================HELMET=====================//
void helmet_Alcohol_Check()
{
if((digitalRead(lim1) == 0 || digitalRead(lim2)==0 || digitalRead(lim3)==0)&& (digitalRead(gasAPin)== 1))
{
lcd.setCursor(0,0); lcd.print("Helmet Worn,");
 
lcd.setCursor(0,1);
lcd.print("Thank You !"); delay(2000); lcd.clear();
lcd.setCursor(0,0); lcd.print("NO Alcohol "); lcd.setCursor(0,1);
lcd.print("CAN DRIVE."); delay(2000); lcd.clear();
lcd.print("IGNITION ON"); delay(1500); ig=1;
digitalWrite(wheel1,1); digitalWrite(wheel2,0); analogWrite(en1,80); analogWrite(en2,80); lcd.clear();
}
else if((digitalRead(lim1) == 1 || digitalRead(lim2)==1 || digitalRead(lim3)==1)&& (digitalRead(gasAPin)==1))
{ lcd.clear();
lcd.print("WEAR	HELMET!");	lcd.setCursor(0,1);	lcd.print("FOR	SAFE	DRIVE"); delay(2000); digitalWrite(wheel1,0); digitalWrite(wheel2,0);
lcd.clear();
}
else if(digitalRead(gasAPin)==0)
{ lcd.clear();
//	lcd.print(gasAPin);	delay(1500);	lcd.clear();	lcd.setCursor(0,0);	lcd.print("ALCOHOL PRESENT"); lcd.setCursor(0,1); lcd.print("DON'T DRIVE ."); delay(3000); digitalWrite(wheel1,0); digitalWrite(wheel2,0);
lcd.clear();
}
}
//=================ALCOHOL DETECTION==========================//
void alcoholDetect()
{ digitalWrite(1,0); delay(50); digitalWrite(1,1); lcd.setCursor(0,0);
 
lcd.print("Please Blow "); lcd.setCursor(0,1); lcd.print("In The Sensor."); delay(2000); lcd.clear(); delay(3000); int analogSensor = analogRead(gasAPin);
lcd.setCursor(0,0); lcd.print("Your Breath is :"); lcd.setCursor(0,1); lcd.print(analogSensor); delay(3000); lcd.clear();
if(analogSensor > alcoholThres)
{
digitalWrite(2,0); delay(50); digitalWrite(2,1);
lcd.setCursor(0,0); lcd.print("Alcohol present"); lcd.setCursor(0,1); lcd.print("DON'T DRIVE
."); delay(3000); lcd.clear();
}
else
{ digitalWrite(3,0); delay(50); Serial.print("no alcohol"); digitalWrite(3,1);
lcd.setCursor(0,0); lcd.print("NO Alcohol "); lcd.setCursor(0,1); lcd.print("CAN DRIVE."); delay(3000); lcd.clear();
}
delay(3000);
}
//	CLEARING RFID FUNTION	//
void rfid_clear()
{ int s;
for ( int s = 0; s < 13; ++s ) input[s] = (char)0;
}
void passd_clear()
{
}
void gsm_send()
{ lcd.clear(); lcd.print(" SENDING SMS	"); delay(5000); Serial.begin(9600); delay(500);
Serial.println("sms "); Serial.println("AT");
delay(1000); delay(1000); Serial.println("AT+CMGF=1"); delay(1000); delay(1000); Serial.println("AT+CMGS=\"8088138621\" \r\n"); delay(1000); delay(1000); lcd.clear();
 
}
void sms()
{
{
gsm_send();
Serial.println("vehical KA-19 A-1995 in no parking area,please vacate it soon to avoid penalty"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
}
}
void sms11()
{
{
gsm_send();
Serial.println("vehical KA-19 A-1995 in no parking area,penalty-750/-"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
}
}
void sms2()
{
{
gsm_send();
Serial.println("vehical KA-14 A-8081 is in no parking area,please vacate it soon to avoid penalty"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
}}
void sms22()
{{
gsm_send();
Serial.println("vehical no KA-14 A-8081 in no parking area,penaty 750/-"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
} }
void sms3()
{ {
 
gsm_send();
Serial.println("Vehicle no-KA 17 15A 9513, insurence is expired penalty 500/-"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
} }
void sms4()
{ {
gsm_send();
Serial.println("Vehicle no KA-26 F-5151,invalid emmision testing certificate penalty 200/-"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
} }
void sms33()
{ {
gsm_send();
Serial.println("Vehicle no-KA 17 15A 9513, insurence is expired penalty 500/-"); delay(1000); delay(1000); Serial.println(char(26)); delay(1000); delay(1000);
} }
//======================rfid operation====================//
void serialEvent()
{
if(Serial.available()>0)
{
while(count<=11)
{
while(Serial.available()>0)
{
char inChar=Serial.read(); input[count++]=inChar;
} }
Serial.println(input);
}
no_parking_with_doc();
// speed_control_mode();
 
}
//================no parking WITH document verification ============// void no_parking_with_doc()
{
if((input[8]=='2')&&(input[9]=='C')&&(input[10]=='D')&&(input[11]=='C')&&(digitalRead(sw 1)==0))
{ lcd.clear(); lcd.print("INVALID LICENCE");
delay(1000); lcd.clear(); passd_clear(); count=0; rfid_clear();
}
else if((input[8]=='2')&&(input[9]=='C')&&(input[10]=='D')&&(input[11]=='C')&&(b==0))
{ b=1;
digitalWrite(voice1,LOW); delay(50); digitalWrite(voice1,HIGH); lcd.clear(); lcd.print("NOPARKING AREA");
lcd.setCursor(0,1);
lcd.print("VACATE UR VEHICLE"); delay(2000); lcd.clear();
rfid_clear(); passd_clear(); count=0;
}
//=	FIRST CARD SMS SENT	//
else if((input[8]=='2')&&(input[9]=='C')&&(input[10]=='D')&&(input[11]=='C')&&(b==1))
{
b=2; lcd.clear(); lcd.print("NOPARKING AREA");
lcd.setCursor(0,1);
lcd.print("ALERT SMS SENDING"); delay(3000); lcd.clear(); digitalWrite(voice1,LOW); delay(50);
digitalWrite(voice1,HIGH); sms2(); rfid_clear(); passd_clear(); count=0;
}
 
//-----------------------------SENDING SMS TO CONTROL ROOM	//
else if((input[8]=='2')&&(input[9]=='C')&&(input[10]=='D')&&(input[11]=='C')&&(b==2))
{ b=0;
lcd.clear(); lcd.print("sending sms to control room"); lcd.clear(); lcd.print("NOPARKING AREA");
lcd.setCursor(0,1);
lcd.print("PENALTY SMS SENDING"); delay(3000);
digitalWrite(voice1,LOW); delay(50); digitalWrite(voice1,HIGH); lcd.clear(); sms22(); rfid_clear();
passd_clear(); count=0;
}
//	SECOND CARD NO PARKING	//
if((input[8]=='2')&&(input[9]=='2')&&(input[10]=='A')&&(input[11]=='4')&&(digitalRead(sw1
)==0))
{ lcd.clear(); lcd.print("LICENCE IS VALID"); delay(2000); lcd.clear(); lcd.print("CHECKING FOR");
lcd.setCursor(0,1); lcd.print("ALCOHOL & HELMET"); helmet_Alcohol_Check(); delay(3000); rfid_clear();
passd_clear(); count=0;
}
else if((input[8]=='2')&&(input[9]=='2')&&(input[10]=='A')&&(input[11]=='4')&&(C==0))
{ C=1;
lcd.clear(); lcd.print("NO parking");
digitalWrite(voice2,LOW); delay(50); digitalWrite(voice2,HIGH); Serial.println("voice1: "); lcd.clear(); lcd.print("NOPARKING AREA-2"); lcd.setCursor(0,1); lcd.print("VACATE UR VEHICLE"); delay(4000);
rfid_clear();
 
passd_clear(); count=0;
}
//=	SECOND CRD FOR SENDING SMS	//
else if((input[8]=='2')&&(input[9]=='2')&&(input[10]=='A')&&(input[11]=='4')&&(C==1))
{ C=2;
lcd.clear(); lcd.print("NOPARKING AREA");
lcd.setCursor(0,1);
lcd.print("ALERT SMS SENDING"); delay(1000); digitalWrite(voice2,LOW); delay(50); digitalWrite(voice2,HIGH); delay(3000); lcd.clear(); sms();
rfid_clear(); passd_clear(); count=0;;
}
//=-----------SECOND CARD SENDING SMS TO CONTROL ROOM	//
else if((input[8]=='2')&&(input[9]=='2')&&(input[10]=='A')&&(input[11]=='4')&&(C==2))
{ C=0;
lcd.clear(); lcd.print("sending sms to control room"); digitalWrite(voice2,LOW); delay(50);
digitalWrite(voice2,HIGH); Serial.println("voice2: "); lcd.clear(); lcd.print("NOPARKING AREA");
lcd.setCursor(0,1);
lcd.print("PENALTY SMS SENDING");
delay(4000); lcd.clear(); sms11(); rfid_clear(); passd_clear(); count=0;
}
if((input[8]=='A')&&(input[9]=='3')&&(input[10]=='2')&&(input[11]=='A'))
{ lcd.clear();
lcd.print("NOPARKING AREA"); delay(1500); lcd.setCursor(0,0); lcd.print("KA 17 15A 9513"); lcd.setCursor(0,1); lcd.print("VACATE UR VEHICLE"); delay(1500); lcd.clear(); lcd.print("INSURANCE
 
EXPIRED"); delay(1500);
lcd.clear();
lcd.print(" RENEWAL YOUR"); lcd.setCursor(0,1); lcd.print(" INSURANCE"); delay(2000); lcd.clear(); sms33();
rfid_clear(); passd_clear(); count=0;
}
if((input[8]=='4')&&(input[9]=='7')&&(input[10]=='7')&&(input[11]=='D'))
{ lcd.clear();
lcd.print("NOPARKING AREA"); delay(1500); lcd.setCursor(0,0); lcd.print("KA 12 5E 7070"); lcd.setCursor(0,1); lcd.print("VACATE UR VEHICLE"); delay(1500); lcd.clear(); lcd.print("EMISIION EXPIRED"); delay(1500); lcd.clear(); lcd.print("TAKE A EMMISSION"); lcd.setCursor(0,1); lcd.print("	TEST"); delay(3000); lcd.clear(); sms4();
rfid_clear(); passd_clear(); count=0;
}
if((input[8]=='D')&&(input[9]=='E')&&(input[10]=='1')&&(input[11]=='9')&&(ig==1))
{ lcd.clear(); lcd.print("SCHOOL ZONE");
lcd.setCursor(0,1); lcd.print("SPEED LMT-60KMPH");
// Serial.println("SCHOOL ZONE SPEED LMT-60KMPH, AUTO SPEED BREAK ");
digitalWrite(wheel1,1); digitalWrite(wheel2,0); analogWrite(en1,60); analogWrite(en2,60); delay(3000); analogWrite(en1,80); analogWrite(en2,80); lcd.clear(); lcd.setCursor(0,0); lcd.print("SCHOOL ZONE END");
analogWrite(10,500); delay(3000); rfid_clear();
passd_clear(); count=0;
}
if((input[8]=='F')&&(input[9]=='8')&&(input[10]=='5')&&(input[11]=='E'))
{
analogWrite(10,500); lcd.clear(); lcd.print("HOSPITAL ZONE");
 
lcd.setCursor(0,1);
lcd.print("DONT BLOW HORN"); lcd.clear();
// Serial.println("HOSPITAL ZONE SPEED LMT-60KMPH, DONT BLOW HORN ");
delay(2000);	digitalWrite(wheel1,1);	digitalWrite(wheel2,0);	analogWrite(en1,60); analogWrite(en2,60);	delay(3000);	analogWrite(en1,80);	analogWrite(en2,80);	lcd.clear(); lcd.setCursor(0,0); lcd.print(" HOSPITAL ZONE"); lcd.setCursor(0,1); lcd.print(" END"); analogWrite(10,500); delay(3000); rfid_clear(); passd_clear();
count=0;
}
}
