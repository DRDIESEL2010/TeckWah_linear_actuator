/*
 * Author: Benjamin Low
 * Last updated: 5 Oct 2015
 * Description: Controls a linear actuator using yfrobot motor shield.
 * Documentation online is similar to dfrobot's shield.
 * http://www.dfrobot.com/index.php?route=product/product&product_id=69#.VYy9oe2qqko
 */
int motor1_pwmPin = 5;
int motor1_dirPin = 4;
//int motor2_pwmPin = 6;
//int motor2_dirPin = 7;

int switchForwardPin = 8;
int switchBackwardPin = 9;
int potPin = A0;

void setup() {
  pinMode(motor1_pwmPin, OUTPUT);
  //  pinMode(motor2_pwmPin, OUTPUT);
  pinMode(motor1_dirPin, OUTPUT);
  //  pinMode(motor2_dirPin, OUTPUT);
  pinMode(switchForwardPin, INPUT);
  pinMode(switchBackwardPin, INPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
  analogWrite(motor1_pwmPin, 0);
}

void loop() {

  unsigned char incomingbyte = 0;

  if (Serial.available() > 0) {
    incomingbyte = Serial.read();

    if (incomingbyte == '0') {
      analogWrite(motor1_pwmPin, 0);
    } else if (incomingbyte == '1') {
      analogWrite(motor1_pwmPin, 255); //max speed
      digitalWrite(motor1_dirPin, HIGH);
    } else if (incomingbyte == '2') {
      analogWrite(motor1_pwmPin, 255); //max speed
      digitalWrite(motor1_dirPin, LOW);
    }
  }

  //ben_test();

  delay(30);
}

void ben_test() {
  
  int speedValue = analogRead(potPin) / 4;
        
  if ( (digitalRead(switchForwardPin) == LOW) && (digitalRead(switchBackwardPin) == LOW) ) {
    //        Serial.println("low");
    analogWrite(motor1_pwmPin, 0);
  }

  else { //one of the buttons is pressed
    //write the speed
    analogWrite(motor1_pwmPin, speedValue);
    //which direction?
    if ( digitalRead(switchForwardPin) == HIGH ) {
      digitalWrite(motor1_dirPin, HIGH);
    } else if (digitalRead(switchBackwardPin) == HIGH) {
      digitalWrite(motor1_dirPin, LOW);
    }
  }
}


