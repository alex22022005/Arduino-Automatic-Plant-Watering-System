const int soilMoisturePin = A0;   // Analog pin for soil moisture sensor
const int motorPin = 8;           // Digital pin to control motor/relay
int soilMoistureValue = 0;        // Variable to store moisture value
int threshold = 500;              // Adjust this threshold based on your soil and sensor

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);   // Make sure motor is OFF initially
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  if (soilMoistureValue < threshold) {
    digitalWrite(motorPin, HIGH);  // Turn ON motor
    Serial.println("Soil is dry. Pump ON.");
  } else {
    digitalWrite(motorPin, LOW);   // Turn OFF motor
    Serial.println("Soil is wet. Pump OFF.");
  }

  delay(1000);  // Wait for a second before next reading
}
