
                /*STARMICRO ELECTRONICS
DOUAL OR SINGLE TANK WLC WITH UNDER OVER VOLTAGE PROTECTION
  FLOT USE BLUE(NC)TOP SENSOR AND YELLOW(NO)BOTTOM SENSOR
                   rahulm220@gmail.com*/
////////////////////////////////////////////////////////////

 
int tank_H = A2; //OVER HEAD TANK TOP LEVEL SENSOR
int tank_L = A3; //OVER HEAD TANK BOTTOM LEVEL SENSOR
int sump_H = A5; //SUB HEAD TANK TOP LEVEL SENSOR
int sump_L = A4; //SUB HEAD TANK TOP LEVEL SENSOR
 
int motor = 3;      //MOTOR RELAY
int buz = 13;       //buzzer and low level bottom red led 
int s1; 
int s2; 
int t1; 
int t2; 
 
int led1 = 10;     // t1 green pumping status LED(BLINK)
int led3 = 11;     // t1 green full level indicate LED(GLOW)
int led2 = 5;      // t2 red LED 
int led4 = 12;     // s1 green half level LED 
int boost = 4;     // (10E resistor connect pin 4 to t2 for tank is dry) 
int i;     //voltage status flag 
int v=1020; //comparison variable(needs some adjustment) 
int u=400; 
int b=0;   //buzzer flag 
int m=0;   //motor flag 
int c=0;   //sump flag 
 
const int buttonPin = A1;// (A1 to 5v manual switch)
int buttonState = 0; 
 
int volt_sencing = A0;
int relay = 2;  //voltage control relay
int commandState;

void setup() 
{ 
 pinMode(sump_H,INPUT); 
 pinMode(sump_L,INPUT); 
 pinMode(tank_H,INPUT); 
 pinMode(tank_L,INPUT); 
 pinMode(buttonPin,INPUT); 
 pinMode(motor,OUTPUT); 
 pinMode(buz,OUTPUT); 
 pinMode(led1,OUTPUT); 
 pinMode(led2,OUTPUT); 
 pinMode(led3,OUTPUT); 
 pinMode(led4,OUTPUT); 
 pinMode(boost,OUTPUT);
 pinMode(volt_sencing,INPUT);
 pinMode(relay,OUTPUT);
 digitalWrite(buz,LOW); 
 digitalWrite(buttonPin,LOW);
 digitalWrite(motor,LOW);
 digitalWrite(relay,LOW);
    

Serial.begin(9600); 
//////////////////**************////////////////// 
            digitalWrite(buz,HIGH); 
            delay(250); 
            digitalWrite(buz,LOW); 
            delay(250); 
             
           if(t2<v) 
             { 
             digitalWrite(boost,HIGH); // IF THE POWER FAILURE 
             delay(5000); 
             digitalWrite(boost,LOW); // TANK IS DRY,
             delay(2000); 
             digitalWrite(boost,HIGH); // THE AUTO START WILL BE
             delay(500);
             digitalWrite(boost,LOW); 
             delay(100);
             } 
            
             
////////////////***************///////////////////             
} 
void loop() 
{ 
buttonState = digitalRead(buttonPin);
   commandState = analogRead(A0);
   Serial.println(commandState); 
   Serial.println(analogRead(A3)); 
   Serial.println(analogRead(A2));
   s1=analogRead(sump_H); 
   s2=analogRead(sump_L); 
   t1=analogRead(tank_H); 
   t2=analogRead(tank_L); 
   
   Serial.println("V, R, t2, t1"); 
   i = ((analogRead(A0))/218.0)*65; 
   Serial.println( i); 
   delay(50); 

 /////////////////***********///////////////// 
if(t1<v && t2>v) 
{ 
digitalWrite(motor,LOW); 
 digitalWrite(led3,HIGH); 
  delay(50); 
   digitalWrite(led2, LOW); 
    delay(50); 
m=0; 
b=0; 
} 
else if(t1>v && t2>v) 
{ 
 digitalWrite(led2, LOW); 
  delay(50); 
b=0; 
} 
else if(t1>v && t2>v && t2>u) 
{ 
digitalWrite(motor,HIGH);
 digitalWrite(led3,LOW); 
  delay(50); 
   digitalWrite(led2, HIGH); 
    delay(50); 
m=1; 
b=0; 
} 
else if(t2<u) 
{ 
  digitalWrite(motor, LOW);
b=1; 
m=0; 
///////////////*************/////////////// 
} 
 if(s1<v && s2>v && m==1)   
{ 
digitalWrite(motor,HIGH); 
} 
 if(s1>v && s2>v)            
{                           
b=0;                        
}                           
 if(s1>v && s2<v)           
{ 
digitalWrite(motor,LOW); 
 digitalWrite(led4,LOW); 
  c=0; 
} 
 if(s1<v) 
{ 
c=1; 
} 
 if(m==0) 
{ 
digitalWrite(motor,LOW); 
} 
//////////////////*************/////////////////// 
 if(b==1 || c==0 || t2<u) 
{ 
 digitalWrite(buz,HIGH); 
  delay(500); 
   digitalWrite(buz,LOW); 
    delay(500); 
} 
 else 
{ 
digitalWrite(buz,LOW); 
 digitalWrite(led4,HIGH); 
   
} 
 if(m==1 && t1>v && t2>v) 
{ 
 digitalWrite(led1,HIGH); 
  delay(250); 
   digitalWrite(led1,LOW); 
    delay(150); 
} 
 else 
{ 
digitalWrite(led1,LOW);
     ///////////////************////////////////
      }
       if(commandState < 640) //604 (180VOLT), 640 (190VOLT)
      { 
         digitalWrite(relay, LOW); 
         b=1;
      }
  else if(commandState > 680 && commandState < 885) 
      { 
         digitalWrite(relay, HIGH); 
         delay(50);
      }
  else if(commandState > 901 )//842 (250VOLT), 870 (260VOLT),901 (270V)
      { 
         digitalWrite(relay, LOW);
         b=1;
      }
     ////////////****************/////////////
       if (buttonState == HIGH&&t1>v&&t2>v){ 
        digitalWrite(motor, HIGH); 
        digitalWrite(led3,LOW); 
        delay(50); 
        m=1;
        b=0;
        delay(100); 
      } 
  else if(t1<v){ 
         digitalWrite(motor, LOW); 
         m=0;
      } 
       if (buttonState == HIGH&&t2<u){ 
        
             digitalWrite(boost,HIGH); // IF THE POWER FAILURE 
             delay(5000); 
             digitalWrite(boost,LOW); // TANK IS DRY,
             delay(2000); 
             digitalWrite(boost,HIGH); // THE AUTO START WILL BE
             delay(500);
             digitalWrite(boost,LOW); 
             delay(100);
} 
delay(10); 
}
