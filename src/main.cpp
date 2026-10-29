
#include <Arduino.h>
#include <stdio.h>
#include <FastAccelStepper.h>

constexpr uint8_t PIN_STEP = 5;
constexpr uint8_t PIN_DIR = 6;
constexpr uint8_t PIN_EN = 4;

constexpr uint32_t SLOW_SPEED = 80000;
constexpr uint32_t MEDIUM_SPEED = 120000;
constexpr uint32_t FAST_SPEED = 200000;

constexpr uint32_t PAUSE_MS = 3000;

FastAccelStepperEngine engine;
FastAccelStepper *motor = nullptr;

void pauseBetweenTests()
{
  printf("Pause: 3 seconds...\n\n");
  fflush(stdout);
  delay(PAUSE_MS);
}

void moveForTime(uint32_t speed, uint32_t durationMs)
{
  motor->setSpeedInHz(speed);
  motor->runForward();

  printf("Speed: %lu pulses/sec, duration: %lu ms\n",
         (unsigned long)speed,
         (unsigned long)durationMs);
  fflush(stdout);

  delay(durationMs);

  motor->stopMove();

  while (motor->isRunning())
  {
    delay(2);
  }
}

void testSlowSpeed()
{
  printf("\n=== TEST 1: SLOW SPEED ===\n");
  fflush(stdout);

  motor->setAcceleration(200);
  moveForTime(SLOW_SPEED, 4000);

  pauseBetweenTests();
}

void testMediumSpeed()
{
  printf("\n=== TEST 2: MEDIUM SPEED ===\n");
  fflush(stdout);

  motor->setAcceleration(300);
  moveForTime(MEDIUM_SPEED, 4000);

  pauseBetweenTests();
}

void testFastSpeed()
{
  printf("\n=== TEST 3: FAST SPEED ===\n");
  fflush(stdout);

  motor->setAcceleration(400);
  moveForTime(FAST_SPEED, 4000);

  pauseBetweenTests();
}

void testAcceleration()
{
  printf("\n=== TEST 4: ACCELERATION / DECELERATION ===\n");
  fflush(stdout);

  motor->setAcceleration(100);
  motor->setSpeedInHz(1000);

  motor->move(3200);

  while (motor->isRunning())
  {
    delay(2);
  }

  printf("Forward movement completed.\n");
  fflush(stdout);

  motor->move(-3200);

  while (motor->isRunning())
  {
    delay(2);
  }

  printf("Return movement completed.\n");
  fflush(stdout);

  pauseBetweenTests();
}

void testForwardBackward()
{
  printf("\n=== TEST 5: FORWARD / BACKWARD ===\n");
  fflush(stdout);

  motor->setAcceleration(250);
  motor->setSpeedInHz(400);

  for (int i = 0; i < 3; i++)
  {
    printf("Cycle %d/3: forward\n", i + 1);
    fflush(stdout);

    motor->move(1600);

    while (motor->isRunning())
    {
      delay(2);
    }

    delay(500);

    printf("Cycle %d/3: backward\n", i + 1);
    fflush(stdout);

    motor->move(-1600);

    while (motor->isRunning())
    {
      delay(2);
    }

    delay(500);
  }

  printf("Forward/backward test completed.\n");
  fflush(stdout);

  pauseBetweenTests();
}

void setup()
{
  Serial.begin(115200);
  delay(1500);

  printf("\n\n====================================\n");
  printf("ESP32-S3 + MKS SERVO42C AUTO TEST\n");
  printf("====================================\n");
  fflush(stdout);

  engine.init();

  motor = engine.stepperConnectToPin(PIN_STEP);

  if (motor == nullptr)
  {
    printf("ERROR: Failed to initialize STEP pin.\n");
    fflush(stdout);
    return;
  }

  motor->setDirectionPin(PIN_DIR);
  motor->setEnablePin(PIN_EN, true);

  motor->setAcceleration(200);
  motor->setSpeedInHz(SLOW_SPEED);
  motor->enableOutputs();

  printf("Motor initialized successfully.\n");
  printf("Automatic test sequence starts in 3 seconds.\n");
  fflush(stdout);

  delay(PAUSE_MS);
}

void loop()
{
  if (motor == nullptr)
  {
    delay(1000);
    return;
  }

  testSlowSpeed();
  testMediumSpeed();
  testFastSpeed();
  testAcceleration();
  testForwardBackward();

  printf("\n=== ALL TESTS COMPLETED. REPEATING ===\n");
  fflush(stdout);

  pauseBetweenTests();
}
