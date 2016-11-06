int pin = 10;
double high_noon = 1.2;
double period = 20;
int speed;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  speed = 179;
  if(speed > 174) {
    analogWrite(pin, speed);
  }
}
