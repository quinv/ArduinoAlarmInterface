/*
 Name:		SerialCommunicationArduino.ino
 Created:	10/15/2016 6:50:31 PM
 Author:	quinten
*/

//requires SerialCommunicationCS after uploading

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

String receivedCommands;
bool playNote = false;
bool changeLedstate = false;
bool ledState = LOW;
int pulseDelay = 0;
int repetitions = 0;
int frequency = 0;
long duration = 0;

// the loop function runs over and over again until power down or reset
void loop() {
	do {
		receivedCommands = Serial.readStringUntil(',');
		if (contains(receivedCommands, "led")) {
			String state;
			state = Serial.readStringUntil(';');
			if (contains(state, "on")) {
				digitalWrite(led, HIGH);
				Serial.println("1");
			}
			else if (contains(state, "off")) {
				digitalWrite(led, LOW);
       Serial.println("1");
			}
			else {
				Serial.println("error: no ledstate given");
				Serial.println("1");
			}
		}
		else if (contains(receivedCommands, "pulse")) {
			//reads frequency
			String strPulseFrequency;
			strPulseFrequency = Serial.readStringUntil(',');
			pulseDelay = 1000/(2*strPulseFrequency.toInt());
			//reads duration
			String strRepetitions;
			strRepetitions = Serial.readStringUntil(';');
			repetitions = strRepetitions.toInt()*2;
			for (int i = 0; i < repetitions; i++)
			{
				ledState = !ledState;
				digitalWrite(led, ledState);
				delay(pulseDelay);
			}
			Serial.println("1");
		}
		else if(contains(receivedCommands, "play")){
		//reads frequency
			String strFrequency;
			strFrequency = Serial.readStringUntil(',');
			frequency = strFrequency.toInt();
		//reads duration
			String strDuration;
			strDuration = Serial.readStringUntil(';');
			duration = strDuration.toInt();
			tone(piezo, frequency, duration);
			delay(duration);
			Serial.println("1");
		}
		else
		{
			Serial.flush();
			Serial.println("error: invalid command");
		}
		delay(10);
	}while(!(contains(receivedCommands, "led")||contains(receivedCommands, "play")||contains(receivedCommands, "pulse")));
	
}



bool contains(String s, String search) {
	int max = s.length() - search.length();

	for (int i = 0; i <= max; i++) {
		if (s.substring(i) == search) return true;
	}

	return false;
}
