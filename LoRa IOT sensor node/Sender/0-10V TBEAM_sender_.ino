#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>


#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

const String device_iden = "TBEAM_4...20_Sender1";





// GPIO5  -- SX1278's SCK
// GPIO19 -- SX1278's MISO
// GPIO27 -- SX1278's MOSI
// GPIO18 -- SX1278's CS
// GPIO14 -- SX1278's RESET
// GPIO26 -- SX1278's IRQ(Interrupt Request)

#define SS      18
#define RST     14
#define DI0     26
#define BAND    868000000 //Your frequency in Hz



int anA=0;
int anB=0;
int ana1[5] = {0,0,0,0,0};
int bat1[5] = {0,0,0,0,0};
float ma1 = 0;
float ma2 = 0;
uint8_t aa1=0;



String prepare_string();




void setup() {


  pinMode(0, OUTPUT);

  Serial.begin(115200);
  while (!Serial); //If just the the basic function, must connect to a computer

//  SPI.begin(5, 19, 27, 18);
//  LoRa.setPins(SS, RST, DI0);
  Serial.println("PowerON");


  SPI.begin(5, 19, 27, 18);


    LoRa.setPins(SS, RST, DI0);


    if (!LoRa.begin(BAND)) {
      Serial.println("Starting LoRa failed!");
      while (1);
    }

    //LoRa.setTxPower(10);
    

    Serial.print("LoRa Init OK, ");
        
    


}

void loop() {

    aa1++;
    Serial.print(aa1);
    if (30<aa1)
    {
      Serial.println(" ");
      Serial.print("Sending message...");
  
      delay(10);
      ana1[0] = analogRead(39);
      bat1[0] = analogRead(35);
      delay(10);
      ana1[1] = analogRead(39);
      bat1[1] = analogRead(35);
      delay(10);
      ana1[2] = analogRead(39);
      bat1[2] = analogRead(35);
      delay(10);
      ana1[3] = analogRead(39);
      bat1[3] = analogRead(35);
      delay(10);
      ana1[4] = analogRead(39);
      bat1[4] = analogRead(35);
  
      anA=(ana1[0]+ana1[1]+ana1[2]+ana1[3]+ana1[4])/5;
      ma1 = (4.86*3.44 / 2066) * anA;
      anB=(bat1[0]+bat1[1]+bat1[2]+bat1[3]+bat1[4])/5;
      ma2 = (4.86*3.44 / 2066) * anB;
      String x2=prepare_string();
      Serial.println(x2);
    
      digitalWrite(0, HIGH);
        
      // send packet
      LoRa.beginPacket();
      LoRa.print(x2);
      LoRa.endPacket();
  
      digitalWrite(0, LOW); 
        
        
      aa1=0;
    }

    delay(1000);

}










String prepare_string()
{
  String x1=device_iden;
  x1=x1+",";

  uint32_t hh = ma1 * 100;
  uint32_t j = hh / 1000;
  x1=x1+j;
  int ww = hh % 1000;
  j = ww / 100;
  x1=x1+j+".";
  ww = ww % 100;
  j = ww / 10;
  x1=x1+j;
  x1=x1+ww % 10;

  x1=x1+",";

  hh = ma2 * 100;
  j = hh / 1000;
  x1=x1+j;
  ww = hh % 1000;
  j = ww / 100;
  x1=x1+j+".";
  ww = ww % 100;
  j = ww / 10;
  x1=x1+j;
  x1=x1+ww % 10;

  x1=x1+";";

  return(x1);
}





