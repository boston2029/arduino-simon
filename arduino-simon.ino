#include <Arduino.h>

void setup() {
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(3, OUTPUT);
    randomSeed(analogRead(A5));
}

void playTone(int tone, int duration) {
  long totalMicroseconds = duration * 1000L;
  for (long i=0;i<totalMicroseconds;i+=(tone*2)) {
    digitalWrite(8, HIGH);
    delayMicroseconds(tone);
    digitalWrite(8, LOW);
    delayMicroseconds(tone);
  }
}

int length = 1;
bool hasBeenShown = false;
String code = "";
int guessIndex = 0;

void successAnimation(){
    playTone(1915, 100);
    playTone(1519, 100);
    playTone(1275, 100);
    playTone(956, 100);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(250);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    delay(250);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    delay(250);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    delay(250);
}

void loop() {
    if (hasBeenShown == false) {
        long randomNumber = random(1,5);
        code += randomNumber;
        for (int i=0;i<code.length();i++) {
            digitalWrite((code[i]-'0')+8, HIGH);
            switch (code[i]-'0') {
                case 1: playTone(956, 250);break;
                case 2: playTone(1275, 250);break;
                case 3: playTone(1519, 250);break;
                case 4: playTone(1915, 250);break;
            }
            delay(1000-(50*code.length()));
            digitalWrite((code[i]-'0')+8, LOW);
        }
        hasBeenShown=true;
    }
    
    if (digitalRead(7) == LOW) { // if you click 7 (red)
        if (code[guessIndex] == '4') { // if code matches
            digitalWrite(12, HIGH); // red light
            playTone(1915, 250); // lowest tone
            delay(500); // wait
            digitalWrite(12, LOW); // light off
            if (guessIndex+1 == code.length()) {
                successAnimation();
                guessIndex=0;
                hasBeenShown=false;
            } else {
                guessIndex++;
            }
        } else {
            playTone(1700, 250);
            playTone(1800, 250);
            playTone(1915, 250);
            playTone(2028, 500);
            delay(500);
            code = "";
            hasBeenShown=false;
        }
    }
    if (digitalRead(6) == LOW) {
        if (code[guessIndex] == '3') {
            digitalWrite(11, HIGH);
            playTone(1519, 250);
            delay(500);
            digitalWrite(11, LOW);
            if (guessIndex+1 == code.length()) {
                successAnimation();
                guessIndex=0;
                hasBeenShown=false;
            } else {
                guessIndex++;
            }
        } else {
            playTone(1700, 250);
            playTone(1800, 250);
            playTone(1915, 250);
            playTone(2028, 500);
            delay(500);
            code = "";
            hasBeenShown=false;
        }
    }
    if (digitalRead(5) == LOW) {
        if (code[guessIndex] == '2') {
            digitalWrite(10, HIGH);
            playTone(1275, 250);
            delay(500);
            digitalWrite(10, LOW);
            if (guessIndex+1 == code.length()) {
                successAnimation();
                guessIndex=0;
                hasBeenShown=false;
            } else {
                guessIndex++;
            }
        } else {
            playTone(1700, 250);
            playTone(1800, 250);
            playTone(1915, 250);
            playTone(2028, 500);
            delay(500);
            code = "";
            hasBeenShown=false;
        }
    }
    if (digitalRead(4) == LOW) {
        if (code[guessIndex] == '1') {
            digitalWrite(9, HIGH);
            playTone(956, 250);
            delay(500);
            digitalWrite(9, LOW);
            if (guessIndex+1 == code.length()) {
                successAnimation();
                guessIndex=0;
                hasBeenShown=false;
            } else {
                guessIndex++;
            }
        } else {
            playTone(1700, 250);
            playTone(1800, 250);
            playTone(1915, 250);
            playTone(2028, 500);
            delay(500);
            code = "";
            hasBeenShown=false;
        }
    }
    // if (digitalRead(6) == LOW) {
    //     digitalWrite(11, HIGH);
    //     playTone(1519, 250);
    // } else {
    //     digitalWrite(11, LOW);
    // }
    // if (digitalRead(5) == LOW) {
    //     digitalWrite(10, HIGH);
    //     playTone(1275, 250);
    // } else {
    //     digitalWrite(10, LOW);
    // }
    // if (digitalRead(4) == LOW) {
    //     digitalWrite(9, HIGH);
    //     playTone(956, 250);
    // } else {
    //     digitalWrite(9, LOW);
    // }
 }