/*
Name:		Keyboard.ino
Created:	10/14/2016 8:34:17 PM
Author:	quinten
*/

#define col0 11
#define col1 10
#define col2 9
#define row0 6
#define row1 7
#define row2 8
#define row3 2
//must be connected even when not using
#define piezo 5

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(col0, OUTPUT);
	digitalWrite(col0, HIGH);
	pinMode(col1, OUTPUT);
	digitalWrite(col1, HIGH);
	pinMode(col2, OUTPUT);
	digitalWrite(col2, HIGH);
	pinMode(row0, INPUT_PULLUP);
	pinMode(row1, INPUT_PULLUP);
	pinMode(row2, INPUT_PULLUP);
	pinMode(row3, INPUT_PULLUP);
	//must be connected even when not using
	pinMode(piezo, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	int readKey = readKeypad();
	//Serial.println(readKey);
	/*switch (readKey)
	{
	case 1: Serial.println(1); break;
	case 2: Serial.println(2); break;
	case 3: Serial.println(3); break;
	default:
	break;
	}*/
	delay(100);
}

byte cols[] = { col0, col1, col2, NULL };
byte rows[] = { row0, row1, row2, row3 };

int readKeypad() {
	int currentKeyPressed = 0;
	for (int i = 0; i < sizeof(cols); i++)
	{
		if (cols[i] != NULL) {
			digitalWrite(cols[i], LOW);
			for (int j = 0; j < sizeof(rows); j++)
			{
				if (!digitalRead(rows[j])) {
					currentKeyPressed = i + 3 * j + 1;
					Serial.println(currentKeyPressed);
				}
			}
			digitalWrite(cols[i], HIGH);
		}
		else if (cols[i] == NULL) {
			if (!digitalRead(row3)) {
				currentKeyPressed = 13;
				Serial.println(currentKeyPressed);
			}
		}
	}
	return currentKeyPressed;
}
