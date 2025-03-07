#include <SoftwareSerial.h>
#include <SoftwareSerial.h> 

Servo motor;       // Servo motor object
int pos = 0;
// Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); // SIM800L Tx & Rx is connected to Arduino pins 3 & 2

const int led1 = 7; // Pin for LED1
const int led2 = 8; // Pin for LED2
const int led3 = 9;

void setup() {
  // Initialize communication
  Serial.begin(9600);        // For communication with Python
  mySerial.begin(9600);      // For communication with SIM800L
  Serial.println("Ready .");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Attach the servo motor to pin 9
  motor.attach(6);

}

void loop() {
  if (Serial.available() > 0) {  // If any data is received from Python
    Serial.read();               // Read the incoming byte (not needed further)
    sendSMS();

    String command = Serial.readStringUntil('\n'); // Read the incoming command
    command.trim();
    if (command.startsWith("MOTOR:")) {
      for (pos = 0; pos <= 180; pos += 1) { 
        motor.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
      for (pos = 180; pos >= 0; pos -= 1) { 
        delay(1000);
        motor.write(pos);             
        delay(15);                      
      }
    }
    if (command.startsWith("1")) { // LED1 control
      digitalWrite(led1, command.charAt(1) == '1' ? HIGH : LOW);
      Serial.println("LED1 updated.");
    } else if (command.startsWith("2")) { // LED2 control
      digitalWrite(led2, command.charAt(1) == '1' ? HIGH : LOW);
      Serial.println("LED2 updated.");
    } else if (command.startsWith("3")) { // LED3 control
      digitalWrite(led3, command.charAt(1) == '1' ? HIGH : LOW);
      Serial.println("LED3 updated.");
    }       
  }
}

void sendSMS() {
  mySerial.println("AT"); 
  delay(1000);
  
  mySerial.println("AT+CMGF=1"); 
  delay(1000);
  
  mySerial.println("AT+CMGS=\"+254700000000\""); // Replace with your phone number
  delay(1000);
  
  mySerial.print("Alert:triggered!"); // SMS content
  mySerial.write(26); // ASCII code for CTRL+Z to send the SMS
  delay(3000); // Wait for the SMS to be sent
  
  Serial.println("SMS Sent."); // Feedback for Python


}
