
            /*////////UPDATED CODE//////////////
                STARMICRO ELECTRONICS
DOUAL OR SINGLE TANK WLC WIT
 
int tank_H = A2; //OVER HEAD TANK TOP LEVEL SENSOR
int tank_L = A3; //OVER HEAD TANK BOTTOM LEVEL SENSOR

 
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
in
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
; 
 pinMode(boost,OUTPUT);
 pinMode(volt_sencing,INPUT);
 pinMode(relay,OUTPUT);

 
Serial.begin(9600); 
//////////////////**************////////////////// 
            digitalWrite(buz,HIGH); 
            delay(250); 
            digitalWrite(buz,LOW); 
            delay(250); 
          
         
             
////////////////***************///////////////////             
} 
void loop() 
{ 
buttonState = digitalRead(buttonPin);
   commandState = analogRead(A0);
 
   s2=analogRead(sump_L); 
   t1=analogRead(tank_H); 
   t2=analogRead(tank_L); 
   
   Serial.println("V, R, t2, t1"); 
   i = ((analogRead(A0))/218.0)*65; 
   Serial.println( i); 
   delay(50); 

 /////////////////***********///////////////// 

m=0; 
///////////////*************/////////////// 
} 
 if(s1>v && s2>v && m==1)   
{ 
digitalWrite(motor,HIGH);
digitalWrite(led4,HIGH);
b=0;
} 
 if(s1<v && s2>v )            
{  
                           
b=0;                        
}                           
 if(s1<v && s2<v)           
{ 
digitalWrite(motor,LOW); 
 digitalWrite(led4,LOW); 
  c=1; 
} 
 if(s1>v) 
{ 
c=0; 
} 

         b=1;
      }
  else if(commandState > 656 && commandState < 873) //656 (195), 873 (260)
      { 
         digitalWrite(relay, HIGH); 
         delay(50);
      }
  else if(commandState > 901 )// 873 (260VOLT),901 (270V)
      { 
         digitalWrite(relay, LOW);
         b=1;
      }
     ////////////****************/////////////
       if (buttonState == HIGH && t2>v){ 
        digitalWrite(motor, HIGH); 
        digitalWrite(led3,LOW); 
        delay(50); 
       
