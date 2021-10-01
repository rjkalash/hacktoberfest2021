// Burglar Alarm using Arduino - Sharoni Bose

int sensor = 9;
int buzzer = 11;
int led = 10;
void setup()
{
	Serial.begin(9600);
  	pinMode(buzzer, OUTPUT);
 	pinMode(led, OUTPUT);
  	pinMode(sensor, INPUT);
}
void loop()
{
	if(digitalRead(sensor) == HIGH)
  	{
    		digitalWrite(buzzer, HIGH);
    		digitalWrite(led, HIGH);
  	}
  	else
  	{
    		digitalWrite(buzzer, LOW);
    		digitalWrite(led, LOW);
  	} 
}