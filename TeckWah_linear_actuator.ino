/*
 * Author: Benjamin Low
 * Last updated: 18 Nov 2015
 * Description: Controls up to two linear actuators using yfrobot motor shield.
 * Documentation online is similar to dfrobot's shield.
 * http://www.dfrobot.com/index.php?route=product/product&product_id=69#.VYy9oe2qqko
 */
int motor1_pwmPin = 5; //speed
int motor1_dirPin = 4; //direction
int motor2_pwmPin = 6;
int motor2_dirPin = 7;

void setup() {
  pinMode(motor1_pwmPin, OUTPUT);
  pinMode(motor1_dirPin, OUTPUT);
  pinMode(motor2_pwmPin, OUTPUT);
  pinMode(motor2_dirPin, OUTPUT);
  
  Serial.begin(9600);
  analogWrite(motor1_pwmPin, 0);
  analogWrite(motor2_pwmPin, 0);
}

void loop() {

  unsigned char incomingbyte = 0;

  if (Serial.available() > 0) {
        
    incomingbyte = Serial.read();

    if (incomingbyte == '0') {
      
      analogWrite(motor1_pwmPin, 0);//stop
      analogWrite(motor2_pwmPin, 0);//stop
      Serial.println("stopping");
      
    } else if (incomingbyte == '1') {
      
      analogWrite(motor1_pwmPin, 255); //max speed
      digitalWrite(motor1_dirPin, HIGH); //extend
      analogWrite(motor2_pwmPin, 255); //max speed
      digitalWrite(motor2_dirPin, HIGH); //extend
      Serial.println("extending");
      
    } else if (incomingbyte == '2') {
      
      analogWrite(motor1_pwmPin, 255); //max speed
      digitalWrite(motor1_dirPin, LOW); //retract
      analogWrite(motor2_pwmPin, 255); //max speed
      digitalWrite(motor2_dirPin, LOW); //retract
      Serial.println("retracting");
    }
  }
  
  delay(20);
}




