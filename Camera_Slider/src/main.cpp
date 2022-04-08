#include <Arduino.h>

#include <AFMotor.h>
AF_Stepper motor1(200, 1); // A la puerta M1 M2
AF_Stepper motor2(200, 2);

int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int velx;
int vely;

void setup()
{
   Serial.begin(9600);
   Serial.println("Stepper test!");
   motor1.setSpeed(100);
   motor2.setSpeed(100);

   pinMode(xPin, INPUT);
   pinMode(yPin, INPUT);
}
void loop()
{
   xPosition = analogRead(xPin);
   yPosition = analogRead(yPin);

   if (xPosition > 515)
   {
      motor1.step(1, FORWARD, DOUBLE);
      if (yPosition > 530)
      {
         motor2.step(1, FORWARD, DOUBLE);
      }
      if (yPosition < 520)
      {
         motor2.step(1, BACKWARD, DOUBLE);
      }
   }

   if (xPosition < 500)
   {
      motor1.step(1, BACKWARD, DOUBLE);
      if (yPosition > 530)
      {
         motor2.step(1, FORWARD, DOUBLE);
      }
      if (yPosition < 520)
      {
         motor2.step(1, BACKWARD, DOUBLE);
      }
   }

   if (yPosition > 530)
   {
      motor2.step(1, FORWARD, DOUBLE);
   }

   if (yPosition < 520)
   {
      motor2.step(1, BACKWARD, DOUBLE);
   }

   Serial.print("X: ");
   Serial.print(xPosition);
   Serial.print(" | Y: ");
   Serial.println(yPosition);
   /*Serial.println("Interleave coil steps");
   motor1.step(2000, FORWARD, INTERLEAVE);
   motor1.step(1000, BACKWARD, INTERLEAVE);
   motor2.step(2000, FORWARD, INTERLEAVE);
   motor2.step(1000, BACKWARD, INTERLEAVE);
   delay(1000);*/

   /*Serial.println("Micrsostep steps");
   motor1.step(2000, FORWARD, MICROSTEP);
   motor1.step(1000, BACKWARD, MICROSTEP);
   motor2.step(2000, FORWARD, MICROSTEP);
   motor2.step(1000, BACKWARD, MICROSTEP);
   delay(1000);*/
}