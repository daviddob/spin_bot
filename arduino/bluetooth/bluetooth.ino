int ledpin = 9;
int serialVal=0;
void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  
  // if data is available to read
  if( Serial.available() ){
    serialVal = Serial.read();         
  }

  // if 'H' was received
  if( serialVal == 'H' ){
    // turn ON the LED
    digitalWrite(ledpin, HIGH);  
  } 
  else{ 
    // otherwise turn it OFF
    digitalWrite(ledpin, LOW);   
  }
  
  delay(100);      
}
