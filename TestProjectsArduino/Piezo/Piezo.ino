/*
 Name:		Piezo.ino
 Created:	10/15/2016 6:07:56 PM
 Author:	quinten
*/
//notes to play
#define NOTE_C6 1047
#define NOTE_D6 1157
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1976
#define NOTE_C7 2093
//must be connected even when not using
#define piezo 5

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	//must be connected even when not using
	pinMode(piezo, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	tone(piezo, NOTE_A6, 500);
	delay(500);
	tone(piezo, NOTE_A6, 500);
	delay(500);
	tone(piezo, NOTE_B6, 500);
	delay(500);
	tone(piezo, NOTE_G6, 500);
	delay(500);
	tone(piezo, NOTE_A6, 500);
	delay(500);
	tone(piezo, NOTE_B6, 500);
	delay(200);
	tone(piezo, NOTE_C7, 500);
	delay(300);
	tone(piezo, NOTE_B6, 500);
	delay(500);
	tone(piezo, NOTE_G6, 500);
	delay(500);
	tone(piezo, NOTE_A6, 500);
	delay(500);
	tone(piezo, NOTE_B6, 500);
	delay(200);
	tone(piezo, NOTE_C7, 500);
	delay(300);
	tone(piezo, NOTE_B6, 500);
	delay(500);
	tone(piezo, NOTE_A6, 500);
	delay(500);
	tone(piezo, NOTE_G6, 500);
	delay(500);
	tone(piezo, NOTE_A6, 500);
	delay(500);
}
