#include <SPI.h>
#include <Wire.h>



char input = 0;
boolean newData = false;
const byte numChars = 42;
char receivedChars[numChars];
char tempChars[numChars];
int n = 0;

// Push button pins
const int pin5 = 5; //short enabled
const int pin6 = 6; //e1 IDA4 W1
const int pin7 = 7; //e2 IDA3 W1
const int pin8 = 8; //e3 IDA2 W1
const int pin9 = 9; //e4 IDA1 W1
const int pin10 = 10; //e5 IDA1 W2
const int pin11 = 11; //e6 IDA2 W2
const int pin12 = 12; //e7 IDA3 W2
const int pin13 = 13; //e8 IDA4 W2


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void loop()
{
    receive();
    if (newData == true) {
      strcpy(tempChars, receivedChars);
      writeIDA(receivedChars);
      newData = false;
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


void writeIDA(String input) {
  n = input.toInt();
  if (n == 1) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    Serial.println("Changed to IDA1");
  } else if (n == 2) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    Serial.println("Changed to IDA2");
  } else if (n == 3) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(12, HIGH);
    Serial.println("Changed to IDA3");
  } else if (n == 4) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("Changed to IDA4");
  } else if (n == 5) {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("All electrodes active");
  } else if (n == 11) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    Serial.println("Changed to Electrode 1");
  } else if (n == 12) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    Serial.println("Changed to Electrode 2");
  } else if (n == 13) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    Serial.println("Changed to Electrode 3");
  } else if (n == 14) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    Serial.println("Changed to Electrode 4");
  } else if (n == 15) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(10, HIGH);
    Serial.println("Changed to Electrode 5");
  } else if (n == 16) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(11, HIGH);
    Serial.println("Changed to Electrode 6");
  } else if (n == 17) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(12, HIGH);
    Serial.println("Changed to Electrode 7");
  } else if (n == 18) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("Changed to Electrode 8");
  } else if (n == 20) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("All collector electrodes on WE1");
  } else if (n == 30) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    Serial.println("All generator electrodes on WE1");
  } else if (n == 40) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    Serial.println("All generator/collector electrodes on WE1/WE2");
  }
  
}
