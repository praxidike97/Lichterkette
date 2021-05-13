#include <Arduino.h>
#include <IRremote.h>
#include "HomeSpan.h"
#include "extras/PwmPin.h"
 
#define UPDATES_PER_SECOND 100

IRsend irsend;

struct FAIRY_LIGHTS : Service::LightBulb { 

  int ledPin;                                       
  SpanCharacteristic *power;                       
  
  FAIRY_LIGHTS() : Service::LightBulb(){
    power=new Characteristic::On();
  }

  boolean update(){            

    Serial.println(power->getNewVal());
    bool isOn = power->getNewVal();

    if (isOn){
      // Send it three times, just in case
      irsend.sendNEC(0xFFA25D, 32);
      delay(100);
      irsend.sendNEC(0xFFA25D, 32);
      delay(100);
      irsend.sendNEC(0xFFA25D, 32);
    }else{
      // Send it three times, just in case
      irsend.sendNEC(0xFFE21D, 32);
      delay(100);
      irsend.sendNEC(0xFFE21D, 32);
      delay(100);
      irsend.sendNEC(0xFFE21D, 32);
    }
   
    return(true);
  
  }
};
 
void setup(){
    Serial.begin(115200);
    
    delay(3000); // power-up safety delay

    homeSpan.begin(Category::Lighting,"Lichterkette");

    new SpanAccessory();
     
    new Service::AccessoryInformation();
       new Characteristic::Name("Lichterkette");                                                 
       new Characteristic::Manufacturer("Piglet Inc.");
       new Characteristic::SerialNumber("Für mein sayang :-x");
       new Characteristic::Model("Novi edition"); 
       new Characteristic::FirmwareRevision("3.14159");
       new Characteristic::Identify();
    
    new Service::HAPProtocolInformation();
       new Characteristic::Version("1.1.0"); 
        
    new FAIRY_LIGHTS();
}
 
void loop(){
  homeSpan.poll();
}
