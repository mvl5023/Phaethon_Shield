/*   Sample code for controlling the two latching relays
 * 
 *   Michael Lipski
 *   AOPL
 *   Summer 2016
 * 
 *   Sends digital pulse to the appropriate line to select between the transimpedance amplifier and
 *    the SMU for both the bare PV cell and the concentrator cell.
 */

int cpvSMU = 24;
int cpvTIA = 25;
int pvSMU = 28;
int pvTIA = 29;

String serialComm;

void setup() 
{
  Serial.begin(9600);

  // Initializes the proper pins as outputs and ensures that they are at logic low
  pinMode(cpvSMU, OUTPUT);
  pinMode(cpvTIA, OUTPUT);
  pinMode(pvSMU, OUTPUT);
  pinMode(pvTIA, OUTPUT);
  digitalWrite(cpvSMU, LOW);
  digitalWrite(cpvTIA, LOW);
  digitalWrite(pvSMU, LOW);
  digitalWrite(pvTIA, LOW);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    serialComm = Serial.readStringUntil('\n');
    
    if(serialComm == "cpvsmu")
    {
      digitalWrite(cpvSMU, HIGH);
      delay(5);
      digitalWrite(cpvSMU, LOW);
    }
    else if(serialComm == "cpvtia")
    {
      digitalWrite(cpvTIA, HIGH);
      delay(5);
      digitalWrite(cpvTIA, LOW);
    }
    else if(serialComm == "pvsmu")
    {
      digitalWrite(pvSMU, HIGH);
      delay(5);
      digitalWrite(pvSMU, LOW);
    }
    else if(serialComm == "pvtia")
    {
      digitalWrite(pvTIA, HIGH);
      delay(5);
      digitalWrite(pvTIA, LOW);
    }
  }
}
