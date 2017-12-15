#include <Servo.h>

int servoPin1 = 7; // pin for the servo motor
int servoPin2 = 8;
int servoPin3 = 4;
Servo myservo3;
Servo myservo1;
Servo myservo2;// create servo object to control a servo
int pos;     // the position we want to move the servo to
long randNumber;

int val;          // variable used to store data from serial port

void setup() {
  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);// attaches the servo on pin servoPin to the servo object
  Serial.begin(9600);
  Serial.println("Servo control program ready");
}

void loop() {
    //For Servo 1
    randNumber = random(1,3);
    if (randNumber == 1)
      val = 57;
    else 
      val = 53;
    val = val - '0'; // convert val from character variable to number variable
    Serial.print("val = ");Serial.println(val);
    pos = map(val, 1, 9, 0, 180); // (see https://www.arduino.cc/en/Reference/Map)    
    Serial.print("pos = ");Serial.println(pos);

      // tell the servo to go to the position
    myservo1.write(pos);


     //For Servo 2
    randNumber = random(1,3);
    if (randNumber == 1)
      val = 57;
    else 
      val = 53;
    val = val - '0'; // convert val from character variable to number variable
    Serial.print("val = ");Serial.println(val);
    pos = map(val, 1, 9, 0, 180); // (see https://www.arduino.cc/en/Reference/Map)    
    Serial.print("pos = ");Serial.println(pos);

      // tell the servo to go to the position
    myservo2.write(pos);


 //For Servo 3
    randNumber = random(1,3);
    if (randNumber == 1)
      val = 57;
    else 
      val = 53;
    val = val - '0'; // convert val from character variable to number variable
    Serial.print("val = ");Serial.println(val);
    pos = map(val, 1, 9, 0, 180); // (see https://www.arduino.cc/en/Reference/Map)    
    Serial.print("pos = ");Serial.println(pos);

      // tell the servo to go to the position
    myservo3.write(pos);
    
      // wait a few milliseconds so we don't overload the servo with too many commands all at once
    delay(500);

}



