#include <Arduino.h>
#include <IRremote.h>
 
/*int IR_PIN = 23;

const int RECV_PIN = 22;
IRrecv irrecv(RECV_PIN);
decode_results results;*/

IRsend irsend;
 
void setup()
{
  Serial.begin(9600);
  //IrSender.begin(IR_PIN, true);
  //irrecv.enableIRIn();
}
 
void loop(){
  irsend.sendNEC(0xFFA25D, 32);
  //Serial.println("An");
  delay(3000);
  //IrSender.sendNECRaw(0xFFE21D, 0);
  //Serial.println("Aus");
  //delay(3000);*/

  /*if (irrecv.decode()){
        Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
        irrecv.resume();
  }*/
  irsend.sendNEC(0xFFE21D, 32);

  delay(3000);
  
}
