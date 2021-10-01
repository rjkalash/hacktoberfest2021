// Assistant Gauntlet using Arduino - Nishant Giri

int callDoctorPin = 13; 
int happyPin = 12;
int sadPin = 8;    
int eatPin = 7;
int drinkPin = 4;
int toiletPin = 2;
int delayTime = 500;
void setup() 
{  
	Serial.begin(9600);
  	pinMode(callDoctorPin, INPUT);
  	pinMode(happyPin, INPUT);
  	pinMode(sadPin, INPUT);
	pinMode(eatPin, INPUT);
  	pinMode(drinkPin, INPUT);
  	pinMode(toiletPin, INPUT);
  	digitalWrite(callDoctorPin, HIGH);
  	digitalWrite(happyPin, HIGH);
  	digitalWrite(sadPin, HIGH);
	digitalWrite(eatPin, HIGH);
  	digitalWrite(drinkPin, HIGH);
  	digitalWrite(toiletPin, HIGH);
}
void loop() 
{
	if(digitalRead(callDoctorPin) == LOW)
	{
    		Serial.println(1);
 	}
  	if(digitalRead(happyPin) == LOW)
	{
   		Serial.println(2);
 	}
  	if(digitalRead(sadPin) == LOW)
	{
    		Serial.println(3);
 	}
  	if(digitalRead(eatPin) == LOW)
	{
    		Serial.println(4);
 	}
  	if(digitalRead(drinkPin) == LOW)
	{
    		Serial.println(5);
 	}
  	if(digitalRead(toiletPin) == LOW)
	{
    		Serial.println(6);
 	}
 	delay(delayTime);
}