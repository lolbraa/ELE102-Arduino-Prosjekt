int utsignalkort = 2;
int analogPin = A1;
uint8_t knapp = 8;

long p2;
long p3;
long produkt;
long produktSiste;
float prosentdifferanse;
unsigned char resultat;
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
  
  if (digitalRead(knapp) == HIGH) {
    for (int i = 0; i < 1000; i++) {
      for (int j = 0; j < 4; j++) {
        if (signTab2[j] == 1) {
          digitalWrite(utsignalkort, HIGH); 
        } else {
          digitalWrite(utsignalkort, LOW); 
        }

        int sensorValue = analogRead(analogPin); // Read analog pin
        p2 = signTab2[j] * sensorValue + p2;

        p3 = signTab3[j] * sensorValue + p3;
      }
    }
  }

  produktSiste = produkt;
  produkt = p2 * p2 + p3 * p3;

  //float prosentdifferanse = ((10-2)/10)*100;
  prosentdifferanse = ((float)produktSiste - (float)produkt) * 100 / (float)produktSiste;

  if (abs(prosentdifferanse) > 25) {
    resultat = 100;
  } else {
    resultat = 0;
  }
  

  Serial.print(p2);
  Serial.print(", ");
  Serial.print(p3);
  Serial.print(", ");
  Serial.print(produkt);
  Serial.print(", ");
  Serial.print(prosentdifferanse);
  Serial.print(", ");
  Serial.print(resultat);
  Serial.println("");
}



