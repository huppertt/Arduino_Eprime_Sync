/*
  This is a simple code for triggering analog outputs from USB to BNC off the Arduino UNO Board
  BNC pins are connected to Digital lines 2,3,4,& 5 and tied to the common ground
  
  In Eprime:
      Create a Serial device (named "serial" in this example) in the expertiment/deivces menu
      Set the baudrate to 9600.  All else defaults
      In the Eprime code, create an inline object and add the lines 
      serial.WriteString A0  - turn port 1 (A) on  [leaves all others untouched]
      serial.WriteString A1    turn port 1 (A) off 

      serial.WriteString B0 / B1 [Port 2] , C0/C1  [Port 3], D0/D1  [port 4] 
  
*/

// pins for the LEDs:
const int Pin1 = 2;
const int Pin2 = 3;
const int Pin3 = 4;
const int Pin4 = 5;
const int LED = LED_BUILTIN;

String content;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
  content = "";
}

void loop() {
  // if there's any serial available, read it:
  digitalWrite(LED, LOW);
  while (Serial.available() > 0) {
    delay(3);
    char c = Serial.read();
    content += c;
  }
  if (content.length() > 0) {
    Serial.println(content);
    if (content.indexOf("A1") >= 0) {
      digitalWrite(Pin1, HIGH);
      digitalWrite(LED, HIGH);
      Serial.print("A-on\n");
    }
    if (content.indexOf("A0") >= 0) {
      digitalWrite(Pin1, LOW);
      digitalWrite(LED, LOW);
      Serial.print("A-off\n");
    }
    if (content.indexOf("B1") >= 0) {
      digitalWrite(Pin2, HIGH);
      Serial.print("B-on\n");
    }
    if (content.indexOf("B0") >= 0) {
      digitalWrite(Pin2, LOW);
      Serial.print("B-off\n");
    }
    if (content.indexOf("C1") >= 0) {
      digitalWrite(Pin3, HIGH);
      Serial.print("C-on\n");
    }
    if (content.indexOf("C0") >= 0) {
      digitalWrite(Pin3, LOW);
      Serial.print("C-off\n");
    }
    if (content.indexOf("D1") >= 0) {
      digitalWrite(Pin4, HIGH);
      Serial.print("D-on\n");
    }
    if (content.indexOf("D0") >= 0) {
      digitalWrite(Pin4, LOW);
      Serial.print("D-off\n");
    }
    content = "";
  }
}








