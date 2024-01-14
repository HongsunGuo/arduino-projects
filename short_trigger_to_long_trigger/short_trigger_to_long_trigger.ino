volatile int gotint = 0;


int fUSi_PIN = 2;
int fUSi_PIN_converted = 4;

void quickF() {
  gotint = 1;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(fUSi_PIN_converted, OUTPUT);
  digitalWrite(fUSi_PIN_converted, LOW);
  pinMode(fUSi_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(fUSi_PIN), quickF, FALLING); // may handle pulse longer than 5 cycles (5/16MHz)
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gotint)
  {
    //gotint = 0;
    digitalWrite(fUSi_PIN_converted, HIGH);
    delay(2);
    digitalWrite(fUSi_PIN_converted, LOW);
    gotint = 0;
  }
}
