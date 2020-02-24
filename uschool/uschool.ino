int P1LEDLowPin = 10;
int P2LEDLowPin = 8;
int LEDEvenPin = 9;
 
int P1ButtonPin = 7;
int P2ButtonPin = 6;
 
void setup() {
  // configure LED pins to be a digital outputs
  pinMode(P1LEDLowPin, OUTPUT);
  pinMode(P2LEDLowPin, OUTPUT);
  pinMode(LEDEvenPin, OUTPUT);
 
  // set button pins to INPUT and 
  // turn on internal pull up resistor 
  pinMode(P1ButtonPin, INPUT);
  digitalWrite(P1ButtonPin, HIGH);
  pinMode(P2ButtonPin, INPUT);
  digitalWrite(P2ButtonPin, HIGH);
}
 
/* PushCount is incremented when player 1 pushes their
   button, and decremented when player 2 pushes their 
   button.  So if it is > 0 player 1 has made more pushes
   and if it is < 0 player 2 has made more pushes.
*/
 
int PushCount = 0;
 
/* PushCount has to be Threshold far away from zero before a
   player is considered to be winning.
*/
 
int Threshold = 5;
 
void loop() {
  if ( digitalRead(P1ButtonPin) == LOW ) {
    PushCount++;
  }
  if ( digitalRead(P2ButtonPin) == LOW ) {
    PushCount--;
  }
 
  if ( PushCount > Threshold ) {
    digitalWrite(P1LEDLowPin, HIGH);
    digitalWrite(P2LEDLowPin, LOW);
    digitalWrite(LEDEvenPin, LOW);
  } else if ( PushCount < (0-Threshold) ) {
    digitalWrite(P1LEDLowPin, LOW);
    digitalWrite(P2LEDLowPin, HIGH);
    digitalWrite(LEDEvenPin, LOW);
  } else {
    digitalWrite(P1LEDLowPin, LOW);
    digitalWrite(P2LEDLowPin, LOW);
    digitalWrite(LEDEvenPin, HIGH);
  }
 
  // wait 50 mS for any button bounce to die out
  delay(50);
}
