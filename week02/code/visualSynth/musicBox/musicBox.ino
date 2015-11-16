//#include "musicBox.h" //this is for our tones and is for reference. 
int knob = A4; //analog pin for the potentiometer 

int btn = 12; //pin for the button 

void setup() {
Serial.begin(57600); //start printing out to the serial port for processing to read from
pinMode(knob, INPUT);//add a input for your potentiometer  	
pinMode(btn, INPUT_PULLUP);//add an input for the button. We're using input pull up because otherwise, there'd be a short
//you can also do this in hardware. I often do. See pull up resistor  
}

void loop() {
	int data = analogRead(knob); //take an analog read on the knob to read resistance(0 to 1024)
	int btnState = digitalRead(btn); //digitally read the button (0 or 1) 
	//Serial.println(btnState); //optional print line for testing 
	data = map(data, 0, 1024, 65, 800);//using the map function, transform the range of the 
//tone that the resistor is in, 0 to 1024 to the range of tones we want to play. 

	if(btnState==0) // the button is pushed down 
	{
		int pauseBetweenNotes = 2 * 1.30;//make a little pause to not overwhelm arduino
		tone(8, data,500); // play a tone on pin 8, at the mapped sound frequency for 500ms
		delay(pauseBetweenNotes); // a little pause 
		Serial.println(data); // print it out 
		noTone(8);//turn off the pad  
	}else{ //the button is not pushed 
		noTone(8); //make no noise  
	}
}
