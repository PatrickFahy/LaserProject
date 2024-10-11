//This is the arduino code for this project, should be directly uploaded to your arduino.
//This code will interpret the serial data and tell your arduino what signals to send to each servo motor to correctly orient the laser in the right direction.

#include<Servo.h>

Servo serX;
Servo serY;

String serialData;

void setup() {
  serX.attach(10);
  serY.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // going to stay empty as use causes program to freeze

}


void serialEvent(){

  serialData = Serial.readString();

  serX.write(parseDataX(serialData));
  serY.write(parseDataY(serialData));

}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}

int parseDataY(String data){
  data.remove(0, data.indexOf("Y")+ 1);

  return data.toInt();
}
