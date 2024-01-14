#define LED_on_time 80

const byte LED1 = 4;
const byte interruptPin = 2;

volatile bool isNewTrigComming = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), inComingTrigISR, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isNewTrigComming)
  {    
    digitalWrite(LED1, HIGH);
    delay(LED_on_time);
    //turn off the leds
    digitalWrite(LED1, LOW);
    isNewTrigComming = false;
  }
}

void inComingTrigISR()
{
  isNewTrigComming = true;
}
