int FloatSensor = D7;
int led = D8;
int sensorState = 1;


void setup() {
  Serial.begin(9600);
  pinMode(FloatSensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);

}

void loop() {
  sensorState = digitalRead(FloatSensor);


    if (sensorState == HIGH) {
      digitalWrite(led, LOW);
      Serial.println("WATER LEVEL - LOW");
    } else {
      digitalWrite(led, HIGH);
    }
  delay(500);

}
