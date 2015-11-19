int knob = A2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int myKnobData = analogRead(knob); 
  Serial.println(myKnobData); 
}
