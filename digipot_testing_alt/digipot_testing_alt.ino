/*   Sample code for controlling the AD5272 Digital Potentiometer over I2C
 *    Using "word" datatype instead of an array of two bytes
 * 
 *   Michael Lipski
 *   AOPL
 *   Summer 2016
 * 
 *   Controls the two digital potentiometers which in turn control the gain settings of the transimpedance amplifiers
 *   for the two PV cells.
 *   
 *   CPV Cell: I2C Address = 0b0101111 (0x2F), reset = pin 26
 *   Bare PV Cell: I2C Address = 0b0101100 (0x2C), reset = pin 27
 */

#include <Wire.h>

int resetCPV = 26;
int resetPV = 27;

unsigned int dpData;

word dpCommand;

String serialComm;
String comm1;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  // Set reset pins for the digipots high if reset function is not used
  pinMode(resetCPV, OUTPUT);
  pinMode(resetPV, OUTPUT);
  digitalWrite(resetCPV, HIGH);
  digitalWrite(resetPV, HIGH);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    serialComm = Serial.readStringUntil('\n');
    if(serialComm.substring(0, 5) == "setpv")
    {      
      comm1 = serialComm.substring(6);
      dpData = comm1.toInt();

      // Generating two bytes to be sent to the digipot shift register, MSByte first
      dpCommand = 1024 + dpData;      
  
      Wire.beginTransmission(0x2C);
      Wire.write(highByte(dpCommand));
      Wire.write(lowByte(dpCommand));
      Wire.endTransmission();

      
      Serial.print("PV  ");
      Serial.print(highByte(dpCommand), BIN);
      Serial.print(' ');
      Serial.println(lowByte(dpCommand), BIN);
      
    }
    if(serialComm.substring(0, 6) == "setcpv")
    {
      comm1 = serialComm.substring(7);
      dpData = comm1.toInt();

      // Generating two bytes to be sent to the digipot shift register, MSByte first
      dpCommand = 1024 + dpData;      
  
      Wire.beginTransmission(0x2C);
      Wire.write(highByte(dpCommand));
      Wire.write(lowByte(dpCommand));
      Wire.endTransmission();

      
      Serial.print("PV  ");
      Serial.print(highByte(dpCommand), BIN);
      Serial.print(' ');
      Serial.println(lowByte(dpCommand), BIN);
      
    }
  }
}
