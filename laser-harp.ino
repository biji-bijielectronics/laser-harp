// Laser Synthesizers 10 notes
// 14/09/2016
//

//int ldr_Sensor[12] = { 30, 28, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41 };

int Time = 0;
unsigned long lastTimer = 0;

// 15 secs timeout
#define TIMEOUT 15000000

#define P1 300
#define P2 300
#define P3 300
#define P4 300
#define P5 300
#define P6 300
#define P7 300
#define P8 300
#define P9 300
#define P10 300

// Notes to send to midi
#define N1 51
#define N2 52
#define N3 53
#define N4 54
#define N5 55
#define N6 56
#define N7 57
#define N8 58
#define N9 59
#define N10 60


int velOn = 100;//velocity of MIDI notes, must be between 0 and 127
int velOff = 0;
int noteON = 144;//144 = 10010000 in binary, note on command
int noteOFF = 128;//128 = 10000000 in binary, note off command

// Keep the last states, default is HIGH
bool lastS1, lastS2, lastS3, lastS4, lastS5, lastS6, lastS7, lastS8, lastS9,
     lastS10 = 1;

// Run once counter
bool cS1, cS2, cS3, cS4, cS5, cS6, cS7, cS8, cS9, cS10 = 0;

void setup() {

  // For Serial Monitor
  Serial.begin(115200);

  // For MIDI
  Serial1.begin(31250);


  for ( int i = 0; i < 129; i++) {
    // Off all 128 notes
    MIDImessage(noteOFF, i, velOff);
  }

  int a = 150;
  int b =  0;

  MIDImessage(noteON, N1, velOn);
  delay(a);
  MIDImessage(noteOFF, N1, velOff);
  delay(b);

  MIDImessage(noteON, N2, velOn);
  delay(a);
  MIDImessage(noteOFF, N2, velOff);
  delay(b);

  MIDImessage(noteON, N3, velOn);
  delay(a);
  MIDImessage(noteOFF, N3, velOff);
  delay(b);

  MIDImessage(noteON, N4, velOn);
  delay(a);
  MIDImessage(noteOFF, N4, velOff);
  delay(b);

  MIDImessage(noteON, N5, velOn);
  delay(a);
  MIDImessage(noteOFF, N5, velOff);
  delay(b);

  MIDImessage(noteON, N6, velOn);
  delay(a);
  MIDImessage(noteOFF, N6, velOff);
  delay(b);

  MIDImessage(noteON, N7, velOn);
  delay(a);
  MIDImessage(noteOFF, N7, velOff);
  delay(b);

  MIDImessage(noteON, N8, velOn);
  delay(a);
  MIDImessage(noteOFF, N8, velOff);
  delay(b);

  MIDImessage(noteON, N9, velOn);
  delay(a);
  MIDImessage(noteOFF, N9, velOff);
  delay(b);

  MIDImessage(noteON, N10, velOn);
  delay(a);
  MIDImessage(noteOFF, N10, velOff);
  delay(b);

  delay(2000);

  /*
    MIDImessage(noteOFF, N1, velOff);
    MIDImessage(noteOFF, N2, velOff);
    MIDImessage(noteOFF, N3, velOff);
    MIDImessage(noteOFF, N4, velOff);
    MIDImessage(noteOFF, N5, velOff);
    MIDImessage(noteOFF, N6, velOff);
    MIDImessage(noteOFF, N7, velOff);
    MIDImessage(noteOFF, N8, velOff);
    MIDImessage(noteOFF, N9, velOff);
    MIDImessage(noteOFF, N10, velOff);
    MIDImessage(noteOFF, N11, velOff);
    MIDImessage(noteOFF, N12, velOff);
  */
  // Store the first millis()
  lastTimer = millis();

}

void loop() {

  int X1, X2, X3, X4, X5, X6, X7, X8, X9, X10;
  bool S1, S2, S3, S4, S5, S6, S7, S8, S9, S10 = 0;
  unsigned int delayTime = 0;


  X1 = analogRead(A1);
  delay(delayTime);
  X2 = analogRead(A12);
  delay(delayTime);
  X3 = analogRead(A13);
  delay(delayTime);
  X4 = analogRead(A4);
  delay(delayTime);
  X5 = analogRead(A14);
  delay(delayTime);
  X6 = analogRead(A6);
  delay(delayTime);
  X7 = analogRead(A15);
  delay(delayTime);
  X8 = analogRead(A9);
  delay(delayTime);
  X9 = analogRead(A8);
  delay(delayTime);
  X10 = analogRead(A10);
  delay(delayTime);

  /*
    Serial.print("X1:");
    Serial.print(X1);
    Serial.print(" X2:");
    Serial.print(X2);
    Serial.print(" X3:");
    Serial.print(X3);
    Serial.print(" X4:");
    Serial.print(X4);
    Serial.print(" X5:");
    Serial.print(X5);
    Serial.print(" X6:");
    Serial.print(X6);
    Serial.print(" X7:");
    Serial.print(X7);
    Serial.print(" X8:");
    Serial.print(X8);
    Serial.print(" X9:");
    Serial.print(X9);
    Serial.print(" X10:");
    Serial.print(X10);

    Serial.println();
  */

  if ( X1 > P1 ) {
    S1 = HIGH;
  } else {
    S1 = LOW;
  }


  if ( X2 > P2 ) {
    S2 = HIGH;
  } else {
    S2 = LOW;
  }


  if ( X3 > P3 ) {
    S3 = HIGH;
  } else {
    S3 = LOW;
  }


  if ( X4 > P4 ) {
    S4 = HIGH;
  } else {
    S4 = LOW;
  }

  if ( X5 > P5 ) {
    S5 = HIGH;
  } else {
    S5 = LOW;
  }

  if ( X6 > P6 ) {
    S6 = HIGH;
  } else {
    S6 = LOW;
  }


  if ( X7 > P7 ) {
    S7 = HIGH;
  } else {
    S7 = LOW;
  }


  if ( X8 > P8 ) {
    S8 = HIGH;
  } else {
    S8 = LOW;
  }

  if ( X9 > P9 ) {
    S9 = HIGH;
  } else {
    S9 = LOW;
  }


  if ( X10 > P10 ) {
    S10 = HIGH;
  } else {
    S10 = LOW;
  }

  //Sensor 1

  if ( S1 == HIGH && lastS1 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('A');
    MIDImessage(noteON, N1, velOn);
    lastS1 = 1;
  } else if ( S1 == HIGH && lastS1 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S1 == LOW && lastS1 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S1 off ");
    Serial.println('a');
    MIDImessage(noteOFF, N1, velOff);
    lastS1 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor 2

  if ( S2 == HIGH && lastS2 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('B');
    MIDImessage(noteON, N2, velOn);
    lastS2 = 1;
  } else if ( S2 == HIGH && lastS2 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S2 == LOW && lastS2 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S2 off ");
    Serial.println('b');
    MIDImessage(noteOFF, N2, velOff);
    lastS2 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S3
  if ( S3 == HIGH && lastS3 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('C');
    MIDImessage(noteON, N3, velOn);
    lastS3 = 1;
  } else if ( S3 == HIGH && lastS3 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S3 == LOW && lastS3 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S3 off ");
    Serial.println('c');
    MIDImessage(noteOFF, N3, velOff);
    lastS3 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S4
  if ( S4 == HIGH && lastS4 == LOW ) {
    // state changed from LOW to HIGH
    Serial.println('D');
    MIDImessage(noteON, N4, velOn);
    lastS4 = 1;
  } else if ( S4 == HIGH && lastS4 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S4 == LOW && lastS4 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S4 off ");
    Serial.println('d');
    MIDImessage(noteOFF, N4, velOff);
    lastS4 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }

  //Sensor S5

  if ( S5 == HIGH && lastS5 == LOW ) {
    // state changed from LOW to HIGH
    Serial.println('E');
    MIDImessage(noteON, N5, velOn);
    lastS5 = 1;
  } else if ( S5 == HIGH && lastS5 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S5 == LOW && lastS5 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S5 off ");
    Serial.println('e');
    MIDImessage(noteOFF, N5, velOff);
    lastS5 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S6
  if ( S6 == HIGH && lastS6 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('F');
    MIDImessage(noteON, N6, velOn);
    lastS6 = 1;
  } else if ( S6 == HIGH && lastS6 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S6 == LOW && lastS6 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S6 off ");
    Serial.println('f');
    MIDImessage(noteOFF, N6, velOff);
    lastS6 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S7
  if ( S7 == HIGH && lastS7 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('G');
    MIDImessage(noteON, N7, velOn);
    lastS7 = 1;
  } else if ( S7 == HIGH && lastS7 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S7 == LOW && lastS7 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S7 off ");
    Serial.println('g');
    MIDImessage(noteOFF, N7, velOff);
    lastS7 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }

  //Sensor S8
  if ( S8 == HIGH && lastS8 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('H');
    MIDImessage(noteON, N8, velOn);
    lastS8 = 1;
  } else if ( S8 == HIGH && lastS8 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S8 == LOW && lastS8 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S8 off ");
    Serial.println('h');
    MIDImessage(noteOFF, N8, velOff);
    lastS8 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S9
  if ( S9 == HIGH && lastS9 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('I');
    MIDImessage(noteON, N9, velOn);
    lastS9 = 1;
  } else if ( S9 == HIGH && lastS9 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S9 == LOW && lastS9 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S9 off ");
    Serial.println('i');
    MIDImessage(noteOFF, N9, velOff);
    lastS9 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  //Sensor S10
  if ( S10 == HIGH && lastS10 == LOW  ) {
    // state changed from LOW to HIGH
    Serial.println('J');
    MIDImessage(noteON, N10, velOn);
    lastS10 = 1;
  } else if ( S10 == HIGH && lastS10 == HIGH ) {
    // State still HIGH, do thing
  } else if ( S10 == LOW && lastS10 == HIGH ) {
    // state change from HIGH TO LOW
    //Serial.print("S10 off ");
    Serial.println('j');
    MIDImessage(noteOFF, N10, velOff);
    lastS10 = 0;
  } else {
    // State is LOW, lastState is LOW ,do nothing
  }


  Time = millis();

  //   Failsafe TIMER off all notes
  if ( millis() - lastTimer > TIMEOUT ) {
    //Serial.println("*** OFF all notes ***");
    for ( int i = 0; i < 129; i++) {
      // Off all 128 notes
      MIDImessage(noteOFF, i, velOff);
    }


    lastTimer = millis();
  }


}


void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial1.write(command);//send note on or note off command
  Serial1.write(MIDInote);//send pitch data
  Serial1.write(MIDIvelocity);//send velocity data
}


