#include <Arduino.h>
#include <Servo.h>
#include <BasicStepperDriver.h>
#include <MultiDriver.h>
#include <SyncDriver.h>

#define STEP1 3
#define DIRE1 2
#define STEP2 5
#define DIRE2 4

BasicStepperDriver stepper1(200, DIRE1, STEP1);
BasicStepperDriver stepper2(200, DIRE2, STEP2);

SyncDriver controller(stepper1, stepper2);

Servo myservo;

void setup()
{
  Serial.begin(115200);
  myservo.attach(11);
  stepper1.begin(200);
  stepper2.begin(200);
  myservo.write(-20);
}

void frev(int n)
{
  for (int i = 0; i < n; i++)
  {
    controller.rotate(360, 360);
    delay(10);
  }
}

void brev(int n)
{
  for (int i = 0; i < n; i++)
  {
    controller.rotate(-360, -360);
    delay(10);
  }
}

void bin1()
{
  frev(4);
  controller.rotate(300, 300);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
  brev(4);
  controller.rotate(-300, -300);
}

void bin2()
{
  frev(2);
  controller.rotate(200, 200);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
  brev(2);
  controller.rotate(-200, -200);
}

void bin3()
{
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
}

void bin4()
{
  brev(2);
  controller.rotate(-200, -200);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
  frev(2);
  controller.rotate(200, 200);
}

void bin5()
{
  brev(4);
  controller.rotate(-300, -300);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(0);
  delay(500);
  frev(4);
  controller.rotate(300, 300);
}

void loop()
{
  String input = Serial.readString();

  if (input == "1")
  {
    bin1();
  }

  if (input == "2")
  {
    bin2();
  }

  if (input == "3")
  {
    bin3();
  }

  if (input == "4")
  {
    bin4();
  }

  if (input == "5")
  {
    bin5();
  }
}