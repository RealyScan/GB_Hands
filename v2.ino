/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 16.11.2020 20:10:18
 Project     :
 Libraries   :
 Author      :
 Description :
******************************************************************/
#define hand1 A0
#define hand2 A1
#define hand3 A2
#define hand4 A3
#define hand5 A4
#define hand6 A5

#define woof 8

#define winrar 7

bool relayOn=HIGH;
bool relayOff=LOW;


int touched = 30;
int holding=0;

byte stage=0;

int handshake1 = 0;
int handshake2 = 0;
int handshake3 = 0;
int handshake4 = 0;
int handshake5 = 0;
int handshake6 = 0;

bool ready2go=true;


void setup()
{
Serial.begin(9600);
pinMode(winrar, OUTPUT);
pinMode(woof, OUTPUT);
digitalWrite(winrar, relayOff);
digitalWrite(woof, LOW);

//pinMode(hand1, INPUT);
//pinMode(hand2, INPUT);
//pinMode(hand3, INPUT);
//pinMode(hand4, INPUT);
//pinMode(hand5, INPUT);
//pinMode(hand6, INPUT);


}

void loop(){
  Serial.print("Stage= "); Serial.print(stage); Serial.print(" "); Serial.print("R2G= "); Serial.println(ready2go);
  
  handsfree();

  checkin();

  if(holding<0){
    holding=0;
  }

  if(handshake1>40 and handshake2>40 and handshake3>40 and handshake4>40 and handshake5>40 and handshake6>40){
    ready2go=true;
    
  }


  if(stage==0){
    holding--; delay(20);
    while(ready2go==true and handshake1<touched and handshake4<touched and handshake5<touched and handshake2>touched and handshake3>touched and handshake6>touched){
      handsfree();
      holding++;delay(10);
      Serial.println(holding);
      if(holding==200){
        stage=6;
        holding=0;
        Serial.println("DONE"); boo();
        ready2go=false;
        break;
      }
    }
  }
  
  

  
  
  
  
  
  
  
  if(stage==6){
    digitalWrite(winrar, relayOn);
    delay(50000);
    stage=0;
  }
  
  
  
  
  
  
  
  

}

void checkin(){
Serial.println("******************");
Serial.print("h1");
Serial.print("   ");
Serial.print("h2");
Serial.print("   ");
Serial.print("h3");
Serial.print("   ");
Serial.print("h4");
Serial.print("   ");
Serial.print("h5");
Serial.print("   ");
Serial.println("h6");
//Serial.println("******************");
//Serial.println("******************");
Serial.print(handshake1);
Serial.print("  ");
Serial.print(handshake2);
Serial.print("  ");
Serial.print(handshake3);
Serial.print("  ");
Serial.print(handshake4);
Serial.print("  ");
Serial.print(handshake5);
Serial.print("  ");
Serial.println(handshake6);
Serial.println("******************");
delay(300);
}

void handsfree(){
  handshake1 = analogRead(hand1);
  handshake2 = analogRead(hand2);
  handshake3 = analogRead(hand3);
  handshake4 = analogRead(hand4);
  handshake5 = analogRead(hand5);
  handshake6 = analogRead(hand6);
}

void boo(){
digitalWrite(woof, HIGH);
delay(150);
digitalWrite(woof, LOW);
Serial.println("woof");
}


