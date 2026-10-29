#include <FastAccelStepper.h>

constexpr uint8_t PIN_STEP = 5;
constexpr uint8_t PIN_DIR = 6;
constexpr uint8_t PIN_EN = 4;

FastAccelStepperEngine engine;
FastAccelStepper *motor = nullptr;

void setup()
{
  Serial.begin(115200);

  pinMode(PIN_EN, OUTPUT);
  digitalWrite(PIN_EN, HIGH);

  engine.init();
  motor = engine.stepperConnectToPin(PIN_STEP);

  if (motor == nullptr)
  {
    Serial.println("Не вдалося ініціалізувати STEP");
    return;
  }

  motor->setDirectionPin(PIN_DIR);
  motor->setEnablePin(PIN_EN, false);
  motor->setSpeedInHz(200);
  motor->setAcceleration(100);

  motor->enableOutputs();
  motor->move(800);
}

void loop()
{
  // FastAccelStepper 
}