int ledPin = 8;
char serialVal;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
   
  // if data is available to read
  if( Serial.available() ){
    serialVal = Serial.read();         
  }

  // if 'H' was received
  if( serialVal == 'H' ){
    // turn ON the LED
    digitalWrite(ledPin, HIGH);  
  } 
  else{ 
    // otherwise turn it OFF
    digitalWrite(ledPin, LOW);   
  }
  
  delay(1000);      
}
