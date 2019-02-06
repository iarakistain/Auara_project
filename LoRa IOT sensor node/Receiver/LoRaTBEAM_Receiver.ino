
#include <SPI.h>
#include <LoRa.h>


// GPIO5  -- SX1278's SCK
// GPIO19 -- SX1278's MISO
// GPIO27 -- SX1278's MOSI
// GPIO18 -- SX1278's CS
// GPIO14 -- SX1278's RESET
// GPIO26 -- SX1278's IRQ(Interrupt Request)

#define SS      18
#define RST     14
#define DI0     26
#define BAND    868000000
long cl1=0;
int dl1=1000;
int aa1=0;
int led=14;


void setup() {

  
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  while (!Serial); //if just the the basic function, must connect to a computer
  delay(1000);
  
  Serial.println("LoRa Receiver"); 
  
  SPI.begin(5,19,27,18);
  LoRa.setPins(SS,RST,DI0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSpreadingFactor(7);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);  
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    aa1=0;
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  }




//block1begin---------------------------------------------
//
  if (cl1+dl1<millis())
  {
    cl1=millis();

    aa1++;
    Serial.print(aa1);
    if (60<aa1)
    {
        Serial.println(" ");
      aa1=0;
    }
}
//block1end---------------------------------------------

}


