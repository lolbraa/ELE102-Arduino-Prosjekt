int utsignalkort = 2;
int analogPin = A1;
uint8_t knapp = 8;

long p2;
long p3;
int signTab2[] = {1,1,-1,-1};
int signTab3[] = {1,-1,-1,1};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(utsignalkort, OUTPUT);
  pinMode(knapp, INPUT_PULLUP);
}

void loop() {
  p2=0;
  p3=0;
  
  if (digitalRead(knapp) == LOW) {
    Serial.println("Knapp trykket");  
    for (int i = 0; i < 1000; i++) { // Loop 10 times
      for (int j = 0; j < 4; j++) {
        if (signTab2[j] == 1) {
          digitalWrite(utsignalkort, HIGH); 
        } else {
          digitalWrite(utsignalkort, LOW); 
        }

        int sensorValue = analogRead(analogPin); // Read analog pin
        p2 = signTab2[j] * sensorValue + p2;

        //int sensorValue2 = analogRead(analogPin); // Read analog pin
        p3 = signTab3[j] * sensorValue + p3;
      }
    }
  }

  long produkt = p2 * p2 + p3 * p3;

  Serial.print(p2);
  Serial.print(", ");
  Serial.println(p3);
  // Serial.println(produkt);
}

