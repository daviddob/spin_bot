int pin = 10;
double high_noon = 1.2;
double period = 20;
int speed;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  //SPEEDS THAT WORK FROM LOW TO HIGH: starts quick around 5, 
  //slows down until 60 which is a complete stop, 
  //at 75 starts again and speeds up until about 130 ish which is max speed
  speed = 50;
  analogWrite(pin, speed);
}
