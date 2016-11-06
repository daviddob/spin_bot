int delayTime = 1;
int charBreak = 2;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;

int charlist[256] = {0};
int templist[256] = {0};
int chararino[256] = {0};
int charsize = 0;
int index = 0;

int incomingByte = 0;   // for incoming serial data

void setup(){
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(LED7, OUTPUT);
pinMode(LED8, OUTPUT);
pinMode(LED9, OUTPUT);
pinMode(LED10, OUTPUT);

defaultlight();
Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

int a[] = {1, 6, 26, 6, 1};
int b[] = {31, 21, 21, 10, 0};
int c[] = {14, 17, 17, 10, 0};
int d[] = {31, 17, 17, 14, 0};
int e[] = {31, 21, 21, 17, 0};
int f[] = {31, 20, 20, 16, 0};
int g[] = {14, 17, 19, 10, 0};
int h[] = {31, 4, 4, 4, 31};
int i[] = {0, 17, 31, 17, 0};
int j[] = {0, 17, 30, 16, 0};
int k[] = {31, 4, 10, 17, 0};
int l[] = {31, 1, 1, 1, 0};
int m[] = {31, 12, 3, 12, 31};
int n[] = {31, 12, 3, 31, 0};
int o[] = {14, 17, 17, 14, 0};
int p[] = {31, 20, 20, 8, 0};
int q[] = {14, 17, 19, 14, 2};
int r[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};
int t[] = {16, 16, 31, 16, 16};
int u[] = {30, 1, 1, 30, 0};
int v[] = {24, 6, 1, 6, 24};
int w[] = {28, 3, 12, 3, 28};
int x[] = {17, 10, 4, 10, 17};
int y[] = {17, 10, 4, 8, 16};
int z[] = {19, 21, 21, 25, 0};

int eos[] = {0, 1, 0, 0, 0};
int excl[] = {0, 29, 0, 0, 0};
int ques[] = {8, 19, 20, 8, 0};
int space[] = {0, 0, 0, 0, 0};
int test[] = {31, 31, 31, 31, 31};

void displayLine(int line, int row){
int myline;
myline = line;
if (row == 0){
  if (myline>=16) {digitalWrite(LED1, LOW); myline-=16;} else {digitalWrite(LED1, HIGH);}
  if (myline>=8)  {digitalWrite(LED2, LOW); myline-=8;}  else {digitalWrite(LED2, HIGH);}
  if (myline>=4)  {digitalWrite(LED3, LOW); myline-=4;}  else {digitalWrite(LED3, HIGH);}
  if (myline>=2)  {digitalWrite(LED4, LOW); myline-=2;}  else {digitalWrite(LED4, HIGH);}
  if (myline>=1)  {digitalWrite(LED5, LOW); myline-=1;}  else {digitalWrite(LED5, HIGH);}
}
if (row == 1){
  if (myline>=16) {digitalWrite(LED6, LOW); myline-=16;} else {digitalWrite(LED6, HIGH);}
  if (myline>=8)  {digitalWrite(LED7, LOW); myline-=8;}  else {digitalWrite(LED7, HIGH);}
  if (myline>=4)  {digitalWrite(LED8, LOW); myline-=4;}  else {digitalWrite(LED8, HIGH);}
  if (myline>=2)  {digitalWrite(LED9, LOW); myline-=2;}  else {digitalWrite(LED9, HIGH);}
  if (myline>=1)  {digitalWrite(LED10, LOW); myline-=1;}  else {digitalWrite(LED10, HIGH);}
}
}

void displayChar(int let, int row){
if (let == 65){for (int i = 0; i <5; i++){displayLine(a[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 66){for (int i = 0; i <5; i++){displayLine(b[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 67){for (int i = 0; i <5; i++){displayLine(c[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 68){for (int i = 0; i <5; i++){displayLine(d[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 69){for (int i = 0; i <5; i++){displayLine(e[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 70){for (int i = 0; i <5; i++){displayLine(f[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 71){for (int i = 0; i <5; i++){displayLine(g[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 72){for (int i = 0; i <5; i++){displayLine(h[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 73){for (int it = 0; it <5; it++){displayLine(i[it], row);delay(delayTime);}displayLine(0, row);}
if (let == 74){for (int i = 0; i <5; i++){displayLine(j[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 75){for (int i = 0; i <5; i++){displayLine(k[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 76){for (int i = 0; i <5; i++){displayLine(l[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 77){for (int i = 0; i <5; i++){displayLine(m[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 78){for (int i = 0; i <5; i++){displayLine(n[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 79){for (int i = 0; i <5; i++){displayLine(o[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 80){for (int i = 0; i <5; i++){displayLine(p[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 81){for (int i = 0; i <5; i++){displayLine(q[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 82){for (int i = 0; i <5; i++){displayLine(r[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 83){for (int i = 0; i <5; i++){displayLine(s[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 84){for (int i = 0; i <5; i++){displayLine(t[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 85){for (int i = 0; i <5; i++){displayLine(u[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 86){for (int i = 0; i <5; i++){displayLine(v[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 87){for (int i = 0; i <5; i++){displayLine(w[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 88){for (int i = 0; i <5; i++){displayLine(x[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 89){for (int i = 0; i <5; i++){displayLine(y[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 90){for (int i = 0; i <5; i++){displayLine(z[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 33){for (int i = 0; i <5; i++){displayLine(excl[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 63){for (int i = 0; i <5; i++){displayLine(ques[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 39){for (int i = 0; i <5; i++){displayLine(eos[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 32){for (int i = 0; i <5; i++){displayLine(space[i], row);delay(delayTime);}displayLine(0, row);}
if (let == 116){for (int i = 0; i <5; i++){displayLine(test[i], row);delay(delayTime);}displayLine(0, row);}
delay(charBreak);
}

void displayString(int len){

  // change chararino to charlist
  int row = 0;
  if (chararino[0] == 103) { // if first letter is 'g' send to green
    Serial.print("set to green");
    row = 1;
  }
  for (int i = 1; i < len; i++){
    
    displayChar(chararino[i], row);
}
defaultlight();
}

void defaultlight(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  digitalWrite(LED7, HIGH);
  digitalWrite(LED8, HIGH);
  digitalWrite(LED9, HIGH);
  digitalWrite(LED10, HIGH);
}


void loop(){
        
        
//        char character;
//  
//        // send data only when you receive data:
//        if (Serial.available() > 0) {
//                // read the incoming byte:
//                incomingByte = Serial.read();
//                character = incomingByte;
//                if(index < 256){
//                  templist[index] = incomingByte;
//                  index++;
//                }
//
//                if(character == 'z') {        // if character is 'z', denotes end of string
//                  for(int i = 0; i < 256; i++) {
//                    charlist[i] = templist[i];
//                }
//                  charsize = index;
//                  index = 0;
//                  Serial.println("Updating");
// 
//                }     
//                
//        }else {
//        for(int j = 0; j < charsize; j++) {
//            char temp = charlist[j];
//            Serial.print(temp);
//        }

        int hullo[12] = {98, 72, 85, 76, 76, 79, 32, 87, 79, 82, 76, 68};
        for(int i = 0; i < 12; i++) {
          chararino[i] = hullo[i];
        }
        //displayString(charsize);
        displayString(12);
        defaultlight();
        delay(10);
//        }
}



