const int mq7Pin = A0;
const int heaterPin = 3;

unsigned long previousMillis = 0;
const long intervalHigh = 90000; // 90 seconds
const long intervalLow = 60000; // 60 seconds

void setup() {
  Serial.begin(9600);
  pinMode(heaterPin, OUTPUT);
  digitalWrite(heaterPin, HIGH);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= intervalHigh) {
    previousMillis = currentMillis;
    digitalWrite(heaterPin, LOW);
  } else if (currentMillis - previousMillis >= intervalLow) {
    previousMillis = currentMillis;
    digitalWrite(heaterPin, HIGH);
  }

  int sensorValue = analogRead(mq7Pin);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(" Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Convert the analog value to CO concentration using your calibration curve
  float CO_concentration = convertToCO(sensorValue);
  Serial.print("CO Concentration: ");
  Serial.print(CO_concentration);
  Serial.println(" ppm");

  delay(2000);
}

float convertToCO(int sensorValue) {
  // Placeholder function for converting sensor value to CO concentration
  // Replace with your calibration data
  return (sensorValue / 1023.0) * 1000; // Example conversion
}

