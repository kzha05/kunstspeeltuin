// Include the servo library:
#include "Servo.h"
#define SERVO_NUM 6

//create a new servo object 
Servo servoArray[SERVO_NUM]; //create array of servo object

//assign button to pin 7
#define BUTTON_PIN 7

//make buttonstate variable
int lastButtonState;

//connect pin to led
int LED_PIN0 = 1;
int LED_PIN1 = 2;
int LED_PIN2 = 3;
int LED_PIN3 = 4;

byte ledInArray[] = { LED_PIN0,
                      LED_PIN1,
                      LED_PIN2,
                      LED_PIN3 };

void setup() {
  //start serial monitor
  Serial.begin(115200);

 //servo
  // attach the servo variable to a pin:
  servoArray[1].attach(9);
  servoArray[2].attach(10);
  servoArray[3].attach(11);
  servoArray[4].attach(8);
  servoArray[5].attach(12);
  servoArray[6].attach(13);

  //button
  //enable internal pullup resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastButtonState = digitalRead(BUTTON_PIN);
  
  //LED
  //set pin output mode
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
}

void loop() {
  //button
  //read the value of the button
  int buttonState = digitalRead(BUTTON_PIN);

  //led
  if(lastButtonState != buttonState){ //state change
    delay(50); // debounce time

    if(buttonState == LOW){
      Serial.println("button pressed");
      //random
      for(int i = 0; i < 3; i++){
         int randomNumber = random(0,4);
         Serial.println(randomNumber);
         digitalWrite(ledInArray[randomNumber], HIGH);
      }
      delay(3000);
      for(int i = 0; i < ledInArray[i]; i++){
        digitalWrite(ledInArray[i], LOW);
      }  
    }
    lastButtonState = buttonState;
  }

}