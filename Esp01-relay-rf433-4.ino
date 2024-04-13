#include <RCSwitch.h>
int pinSW = 15;//Our Swith ESP D7
int pinSW1 = 4;
int pinSW2 = 0;


RCSwitch mySwitch = RCSwitch();


void setup() {
  pinMode(pinSW, OUTPUT);
  pinMode(pinSW1, OUTPUT);
  pinMode(pinSW2, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Welcome");
  mySwitch.enableReceive(2);  // Receiver on interrupt 0 => that is D3 or GPIO pin #0
  
}

void loop() {
    
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
      if(mySwitch.getReceivedValue() == 90968){
        Serial.println("Unlock");
        digitalWrite(pinSW, !digitalRead(pinSW));
        delay(500);
        
      } else { if (mySwitch.getReceivedValue() == 90965){
        Serial.println("Unlock");
        digitalWrite(pinSW1, !digitalRead(pinSW1));
        delay(500);
        
      } else { if (mySwitch.getReceivedValue() == 90961){
        Serial.println("Unlock");
        digitalWrite(pinSW2, !digitalRead(pinSW2));
        delay(500);
               
      }
    }

    mySwitch.resetAvailable();
  }
}
}
