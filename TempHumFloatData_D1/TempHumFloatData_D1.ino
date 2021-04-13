#include <LiquidCrystal.h>
#include "DHT.h"

// F sensor
const int FloatSensor = D8;

// Display
const int RS = D1, EN = D2, d3 = D3, d4 = D4, d6 = D6, d7 = D7;
const int buttonPin = D0;

LiquidCrystal lcd(RS, EN, d3, d4, d6, d7); 

// Temp and hum. sensor
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
/* DHT11 module, has pullup resistor already: 
 *  pin 1 (left) = data, to arduino. 
 *  pin 2 (center) to 5V
 *  pin 3 (right) ground

*/
int sensorState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(FloatSensor, INPUT);
  
  // On/Off switch for display?
  // pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  dht.begin();
  //Serial.println("Booting sensors!");
  lcd.print("Booting system!");
}

void loop() {
  sensorState = digitalRead(FloatSensor);

  //Serial.print("Current temp and humidity: ");

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    //Serial.println(F("Failed to read from DHT sensor!"));
    lcd.clear();
    lcd.print("Failed to read from DHT Sensor!");
    return;
  }

  /*
  // Write temp.humidity to console. Will go on lcd display
  Serial.print(F("humidity: "));
  Serial.print(h);
  Serial.print(F("%. Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

  */

  lcd.clear();
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print("% ");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("C ");
  


  /* Write to lcd display
  if (sensorState == HIGH) {
    digitalWrite(led, LOW);
    Serial.println("WATER LEVEL - LOW");
  } else {
    digitalWrite(led, HIGH);
  }
  */

  // Read every 3 seconds
  delay(3000);

}
