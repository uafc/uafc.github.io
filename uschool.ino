#define Player1FirstPin 10
#define Player1SecondPin 9
#define MiddlePin 8
#define Player2FirstPin 6
#define Player2SecondPin 7
#define Player1ButtonPin 11
#define Player2ButtonPin 12

int Player1Counter = 0, Player2Counter = 0;
 
void setup() {
  // configure LED pins to be digital outputs
  pinMode(Player1FirstPin, OUTPUT);
  pinMode(Player2FirstPin, OUTPUT);
  pinMode(Player1SecondPin, OUTPUT);
  pinMode(Player2SecondPin, OUTPUT);
  pinMode(MiddlePin, OUTPUT);
 
  // set button pins to INPUT and 
  // turn on internal pull up resistor 
  pinMode(Player1ButtonPin, INPUT);
  digitalWrite(Player1ButtonPin, HIGH);
  pinMode(Player2ButtonPin, INPUT);
  digitalWrite(Player2ButtonPin, HIGH);
}

void Player1Pushed(){
  if (Player2Counter == 0){
    Player1Counter--;
  }
  else{
    Player2Counter--;
  }
  LightUpLEDS(Player1FirstPin, -1, Player1Counter);
}

void Player2Pushed(){
  if (Player1Counter == 0){
    Player2Counter++;
  }
  else{
    Player1Counter--;
  }
  LightUpLEDS(Player2FirstPin, 1, Player2Counter);
  
}

void LightUpLEDS(int startLocation, int counter, int playerCounter){
  for(int i = startLocation; i != startLocation + counter*3; i + counter){
    
  }
  
}


 
void loop() {
  if ( digitalRead(Player1ButtonPin) == LOW ) {
    Player1Pushed();
  }
  if ( digitalRead(Player2ButtonPin) == LOW ) {
    Player2Pushed();
  }
  // wait 50 ms for any button bounce to die out
  delay(50);
}
