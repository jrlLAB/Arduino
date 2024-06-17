#include <EEPROM.h>

#define PH_PIN A1
int voltage = 0;
char input = 0;
boolean newData = false;
const byte numChars = 42;
char receivedChars[numChars];
char tempChars[numChars];

void setup()
{
    Serial.begin(9600);  
}

void loop()
{
    receive();
    if (newData == true) {
      strcpy(tempChars, receivedChars);
      checkpH(receivedChars);
      newData = false;
    }
}




void checkpH(String input)
{
  if(input == "pH"){                
        voltage = analogRead(PH_PIN);  // read the voltage
        Serial.println(voltage);
    }
  else{
    Serial.println("incorrect input");
  }
}

void receive() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
        if (rc == startMarker){   //new
          ndx=0;       //new
          continue;     //new
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
        else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}
