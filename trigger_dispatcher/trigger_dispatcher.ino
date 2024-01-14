//Pin layout
const int PINs[8] = {22, 24, 26, 28, 31, 33, 35, 37};

String cmdString = "";         // a String to hold incoming data
bool isNewCmd = false;  // whether the string is complete
bool isTriggering = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  Serial.print("setup\n");

  Serial2.begin(9600);
  for(int i = 0; i < 8; i++){
    pinMode(PINs[i], OUTPUT);
    digitalWrite(PINs[i], LOW);
  }

  // reserve 200 bytes for the inputString:
  cmdString.reserve(200);
  cmdString = "";
}

void loop() {
  while (Serial2.available()) {
    // get the new byte:
    char inChar = (char)Serial2.read();
    // add it to the inputString:
    cmdString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      isNewCmd = true;
      Serial2.print("ack\n");
    }
  }

  if (isNewCmd) {
    int trigPin = checkCMD();
    if (trigPin > 0){
      digitalWrite(trigPin, HIGH);
      delay(2);
      digitalWrite(trigPin, LOW);
    }
    cmdString = "";
    isNewCmd = false;
  }
}

int checkCMD()
{
  int trigPin = -1;
  if (cmdString.startsWith("PIN0"))
    trigPin = PINs[0];
  else if (cmdString.startsWith("PIN1"))
    trigPin = PINs[1];
  else if (cmdString.startsWith("PIN2"))
    trigPin = PINs[2];
  else if (cmdString.startsWith("PIN3"))
    trigPin = PINs[3];
  else if (cmdString.startsWith("PIN4"))
    trigPin = PINs[4];
  else if (cmdString.startsWith("PIN5"))
    trigPin = PINs[5];
  else if (cmdString.startsWith("PIN6"))
    trigPin = PINs[6];
  else if (cmdString.startsWith("PIN7"))
    trigPin = PINs[7];
  else
    return trigPin;
  
  return trigPin;
}
