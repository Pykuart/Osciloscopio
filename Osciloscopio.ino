//#include <SPI.h>

#define AREF 5.0
#define ADC_MAX 1023.0


float ratio = AREF / ADC_MAX;

void setup() {

  Serial.begin(115200);
 
}

void loop() {
  //read system time
  unsigned long time_a = micros();
 
  // read the analog value  and convert to voltage:
  float voltageChannel0 = analogRead(A0) * ratio;
  float voltageChannel1 = analogRead(A1) * ratio;
  float voltageChannel2 = analogRead(A2) * ratio;
  float voltageChannel3 = analogRead(A3) * ratio;
  float voltageChannel4 = analogRead(A4) * ratio;
  float voltageChannel5 = analogRead(A5) * ratio;

  // send system time first
  Serial.print(time_a);
  Serial.print(" ");

  // send value of each channel, seperated by " " or "\t".
  Serial.print(voltageChannel0);
  Serial.print(" ");
  Serial.print(voltageChannel1);
  Serial.print(" ");
  Serial.print(voltageChannel2);
  Serial.print(" ");
  //Serial.print(voltageChannel3);
  //Serial.print(" ");
  Serial.print(voltageChannel4);
  Serial.print(" ");
  //the last channel must send with new line charaters
  Serial.println(voltageChannel5);
}
