/*
Name:		Led.ino
Created:	10/14/2016 8:34:17 PM
Author:	quinten
*/

#define led 4
//must be connected even when not using
#define piezo 5

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(led, OUTPUT);
	//must be connected even when not using
	pinMode(piezo, OUTPUT);
}

bool ledState = LOW;
// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(led, ledState);
	ledState = !ledState;
	Serial.println(ledState);
	delay(1000);
}
