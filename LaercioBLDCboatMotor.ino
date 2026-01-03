//import libraries
#include <Servo.h>


// Joystick pins (ANALOG pins)
#define JOY_THROTTLE_PIN A0
#define JOY_STEER_PIN    A1


#define ESC_PIN   5
#define SERVO_PIN 6


Servo esc;
Servo fin;


void setup() {
  Serial.begin(9600);


  esc.attach(ESC_PIN, 1000, 2000);
  fin.attach(SERVO_PIN);


  // // Arm ESC
  // esc.writeMicroseconds(1000);
  // delay(3000);


  //initialize servos 
  for(int i = 180; i > 0; i--) { 
    fin.write(i); 
    delay(5); 
  } 
  for (int i = 0; i < 180; i++) {
    fin.write(i); 
    delay(5);
  }



  Serial.println("System ready");
  delay(2000);
}


void loop() {
  int throttleRaw = analogRead(JOY_THROTTLE_PIN); // 0?1023
  int steerRaw    = analogRead(JOY_STEER_PIN);    // 0?1023


  int throttlePWM = map(throttleRaw, 600, 1023, 1000, 2000);
  int steerAngle  = map(steerRaw,    0, 1023, 135,    45);


  esc.writeMicroseconds(throttlePWM);
  fin.write(steerAngle);


  Serial.print("Throttle PWM: ");
  Serial.print(throttlePWM);
  Serial.print(" | Steering angle: ");
  Serial.println(steerAngle);


  delay(50);
}

