/*
* Receiver Code
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* Code updates: Arilson Jr.
*/
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(7, 8); // CE, CSN

const uint64_t rAddress[] = {0x7878787878, 0xB3B4B5B6F1, 0xB3B4B5B6CD, 0xB3B4B5B6A3, 0xB3B4B5B60F, 0xB3B4B5B605};
double ta[6]; //vector of air temperature
double tg[6]; //vector of black-globe temperature
double ur[6]; //vector of relative himidity
double num[4]; //vector of data sent by ptx_transmitter

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);  // "short range setting" - increase if you want more range AND have a good power supply
  radio.setChannel(108);          // the higher channels tend to be more "open"
  radio.openReadingPipe(0, rAddress[0]);
  radio.openReadingPipe(1, rAddress[1]);
  radio.openReadingPipe(2, rAddress[2]);
  radio.openReadingPipe(3, rAddress[3]);
  radio.openReadingPipe(4, rAddress[4]);
  radio.openReadingPipe(5, rAddress[5]);
  radio.startListening();
  
  for (int i = 0; i < 6; i++){
    ta[i] = 0;
    tg[i] = 0;
    ur[i] = 0;
    num[0] = 0;
  }
  
}

void loop() {
  byte pipeNum = 0; //variable to hold which reading pipe sent data
  int sensor = 0;
  
  for (int q = 0; q < 4; q++) {
      num [q] = 0;
  }
  
  while(radio.available(&pipeNum)) { //Check if received data
     radio.read(&num, sizeof(num));
     sensor = (int) num[3];
     
     switch (sensor){
      case 1:
      ta[0] = num[0];
      tg[0] = num[1];
      ur[0] = num[2];
      break;
      case 2:
      ta[1] = num[0];
      tg[1] = num[1];
      ur[1] = num[2];
      break;
      case 3:
      ta[2] = num[0];
      tg[2] = num[1];
      ur[2] = num[2];
      break;
      case 4:
      ta[3] = num[0];
      tg[3] = num[1];
      ur[3] = num[2];
      break;
      case 5:
      ta[4] = num[0];
      tg[4] = num[1];
      ur[4] = num[2];
      break;
      case 6:
      ta[5] = num[0];
      tg[5] = num[1];
      ur[5] = num[2];
      break;
     }
  }
    
    //Real
    Serial.print(1);
    Serial.print(ta[0]);
    Serial.print(tg[0]);
    Serial.print(ur[0]);
    Serial.print(2);
    Serial.print(ta[1]);
    Serial.print(tg[1]);
    Serial.print(ur[1]);
    Serial.print(3);
    Serial.print(ta[2]);
    Serial.print(tg[2]);
    Serial.print(ur[2]);
    Serial.print(4);
    Serial.print(ta[3]);
    Serial.print(tg[3]);
    Serial.print(ur[3]);
    Serial.print(5);
    Serial.print(ta[4]);
    Serial.print(tg[4]);
    Serial.print(ur[4]);
    Serial.print(6);
    Serial.print(ta[5]);
    Serial.print(tg[5]);
    Serial.print(ur[5]);
    
    //Monitor 
    /*
    Serial.println(1);
    Serial.println(ta[0]);
    Serial.println(tg[0]);
    Serial.println(ur[0]);
    Serial.println(2);
    Serial.println(ta[1]);
    Serial.println(tg[1]);
    Serial.println(ur[1]);
    Serial.println(3);
    Serial.println(ta[2]);
    Serial.println(tg[2]);
    Serial.println(ur[2]);
    Serial.println(4);
    Serial.println(ta[3]);
    Serial.println(tg[3]);
    Serial.println(ur[3]);
    Serial.println(5);
    Serial.println(ta[4]);
    Serial.println(tg[4]);
    Serial.println(ur[4]);
    Serial.println(6);
    Serial.println(ta[5]);
    Serial.println(tg[5]);
    Serial.println(ur[5]);
    */

    //Teste
    /*
    Serial.print(1);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    Serial.print(2);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    Serial.print(3);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    Serial.print(4);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    Serial.print(5);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    Serial.print(6);
    Serial.print(50.50);
    Serial.print(51.50);
    Serial.print(50.50);
    */
    

    delay(6000);
}

