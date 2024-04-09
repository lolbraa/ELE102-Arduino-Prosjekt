int utsignalkort = 2;
int analogPin = A1;
long p2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(utsignalkort, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  p2=0;
  for (int i = 0; i < 5000; i++) { // Loop 10 times
    digitalWrite(utsignalkort, HIGH); // Set digital pin HIGH
    //delay(1); // Wait for stabilization
    int sensorValue = analogRead(analogPin); // Read analog pin
    p2=p2+sensorValue;
    //Serial.print("Sensor value when HIGH: ");
    //Serial.println(sensorValue);
  
    digitalWrite(utsignalkort, LOW); // Set digital pin LOW
    //delay(1); // Wait for stabilization
    int sensorValue2 = analogRead(analogPin); // Read analog pin
    p2=p2-sensorValue2;
    //Serial.print("Sensor value when LOW: ");
    //Serial.println(sensorValue2);
  }
Serial.println(p2);
delay(1);
}

