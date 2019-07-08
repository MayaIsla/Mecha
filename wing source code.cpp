

#include <Servo.h>
int button = 5; //button pin, connect to ground to move servo
int press = 0;
Servo myservo; // initializing servos
Servo myservo1;
int i; // used for - for loop 20 times
int RedLed = 2; // red led
int GreenLed = 3;// green led
int ledState1 = LOW;             // ledState used to set the LED
unsigned long previousMillis1 = 0;        // will store last time LED was updated
long OnTime1 = 250;           // milliseconds of on-time
long OffTime1 = 750;          // milliseconds of off-time
int ledState2 = LOW;             // ledState used to set the LED
unsigned long previousMillis2 = 0;        // will store last time LED was updated
long OnTime2 = 330;           // milliseconds of on-time
long OffTime2 = 400;          // milliseconds of off-time

boolean toggle = true;

void setup()
{
  pinMode(button, INPUT); //arduino monitor pin state
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  myservo.attach(9); //pin for servo control signal
  myservo1.attach(10); //pin for servo control signal
  digitalWrite(5, HIGH); //enable pullups to make pin high
}

void loop()
{
  press = digitalRead(button);
  if (press == LOW)
  {
    if(toggle)
    {

/*
      myservo.write(90);
      myservo1.write(90);
      delay(2000);
      
 */
      /*
      myservo.write(170);
      myservo1.write(80);
      delay(50); 
      */

   // for servo one sweeping 
   int servpos=170;
   int servpos1=80;
   int pos =80; //variable to store the servo position
   int pos1 =170; // variable to store the servo position
   
   while(pos <= servpos && pos1 >= servpos1)
     {         // in steps of 1 degree

        pos++;
        pos1--;
        myservo.write(pos);    // tell servo to go to position in
          // variable 'pos'
        myservo1.write(pos1);    // tell servo to go to position in
        delay(15);      // waits 15ms for the servo to reach
          // the position
          
     }   
     
      
      for(i=0; i <=10; i++) {
        digitalWrite(RedLed, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100); 
        digitalWrite(RedLed, LOW);    // turn the LED off by making the voltage LOW
        delay(100);              // wait for a second
      }
      
      toggle = !toggle;
      
    
    }
    else
    {

// to go down more slowly put in for loop'

     /*
      myservo.write(90);
      myservo1.write(90);
      delay(2000);
   */
      
     myservo.write(100);
     myservo1.write(170);
     delay(15);

     for(i=0; i <=10; i++) {
        digitalWrite(GreenLed, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100); 
        digitalWrite(GreenLed, LOW);    // turn the LED off by making the voltage LOW
        delay(100);              // wait for a second
      }

      toggle = !toggle;
      
    }
  }
  delay(500);  //delay for debounce

  unsigned long currentMillis = millis();
 
  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;  // Turn it off
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(RedLed, ledState1);  // Update the actual LED
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;  // turn it on
    previousMillis1 = currentMillis;   // Remember the time
    digitalWrite(RedLed, ledState1);   // Update the actual LED
  }
  
  if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    ledState2 = LOW;  // Turn it off
    previousMillis2 = currentMillis;  // Remember the time
    digitalWrite(GreenLed, ledState2);  // Update the actual LED
  }
  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    ledState2 = HIGH;  // turn it on
    previousMillis2 = currentMillis;   // Remember the time
    digitalWrite(GreenLed, ledState2);   // Update the actual LED
  } 

 
}


