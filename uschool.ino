// LED Pin locations
#define Player1LED 10
#define Player2LED 8
#define MiddleLED 9

// Button Pin locations
#define Player1Button 7
#define Player2Button 6
 
void setup() {
  // configure LED pins to be a digital outputs
  pinMode(Player1LED, OUTPUT);
  pinMode(Player2LED, OUTPUT);
  pinMode(MiddleLED, OUTPUT);
 
  // set button pins to INPUT and 
  // turn on internal pull up resistor 
  pinMode(Player1Button, INPUT);
  digitalWrite(Player1Button, HIGH);
  pinMode(Player2Button, INPUT);
  digitalWrite(Player2Button, HIGH);
}
// keep track of how many clicks are 
// one player increases the count, other lowers it
int PushCount = 0;
// PushCount has to be threshold far away before LED changes
int Threshold = 5;
 
void loop() {
  if ( digitalRead(Player1Button) == LOW ) {
    PushCount++;
  }
  if ( digitalRead(Player2Button) == LOW ) {
    PushCount--;
  }
 
  if ( PushCount > Threshold ) {
    digitalWrite(Player1LED, HIGH);
    digitalWrite(Player2LED, LOW);
    digitalWrite(MiddleLED, LOW);
  } else if ( PushCount < (0-Threshold) ) {
    digitalWrite(Player1LED, LOW);
    digitalWrite(Player2LED, HIGH);
    digitalWrite(MiddleLED, LOW);
  } else {
    digitalWrite(Player1LED, LOW);
    digitalWrite(Player2LED, LOW);
    digitalWrite(MiddleLED, HIGH);
  }
 
  // wait 20 ms for any button bounce to die out
  delay(20);
}