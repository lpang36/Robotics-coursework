//input from switch
int pin1 = 3;
int pin2 = 5;
//output to piezo
int pin3 = 9;
//set tempo, notes, rhythm
int tempo = 150;
int beats[] = {3,1,2,2,3,1,2,2,3,1,1,1,1,4,1,1,1,2};
char notes[] = "aacdeaGfegedcdcdec";
int length = 18;
//whether the music should play
bool on;

void setup() {
  //initialize pins
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  pinMode(pin3,OUTPUT);
}

void playTone(int tone, int duration) {
  //play tone by varying frequency
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(pin3, HIGH);
    delayMicroseconds(tone);
    digitalWrite(pin3, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  //assign note name to frequency
  char names[] = { 'g', 'a', 'b', 'c', 'd', 'e', 'f', 'G' };
  int tones[] = { 2551, 2272, 2025, 1915, 1700, 1519, 1432, 1275 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void music() {
  //loop through all notes
  for (int i=0; i<length; i++) {
    //turn off if second button pressed
    int val2 = digitalRead(pin2);
    if (val2==LOW) on=false;
    if (!on) return;
    //play note
    playNote(notes[i],beats[i]*tempo);
  }
}

void loop() {
  //switch to turn on
  int val1 = digitalRead(pin1);
  if (val1==LOW) on=true;
  //play music
  if (on) {
    music();
  }
}
