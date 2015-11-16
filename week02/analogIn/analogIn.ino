int pinIn=A2; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(pinIn, INPUT_PULLUP); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int value = analogRead(pinIn); 
  Serial.println(value); 
  delay(1); 
}


