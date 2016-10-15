/*
 Name:		TestProjectsArduino.ino
 Created:	10/14/2016 8:34:17 PM
 Author:	quinten
*/
#define magnet 3
//must be connected even when not using
#define piezo 5

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(magnet, INPUT_PULLUP);
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.print("magnet: ");
	Serial.println(digitalRead(magnet));
	delay(1000);
}
