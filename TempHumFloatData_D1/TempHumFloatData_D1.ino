int FloatSensor = D7;
int led = D8;
int buttonState = 1;


void setup() {
  Serial.begin(9600);
  pinMode(FloatSensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);

}

void loop() {
  buttonState = digitalRead(FloatSensor);

//  digitalWrite(led, HIGH);
//  delay(500);
//  digitalWrite(led, LOW);
//  delay(500);

    if (buttonState == HIGH) {
      digitalWrite(led, LOW);
      Serial.println("WATER LEVEL - LOW");
    } else {
      digitalWrite(led, HIGH);
    }
  delay(500);

}
