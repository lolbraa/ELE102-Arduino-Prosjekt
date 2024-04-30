int utsignalkort = 2;
int analogPin = A1;
uint8_t knapp = 8;

long p2;
long p3;
long produkt;
int signTab2[] = {1,1,-1,-1};
int signTab3[] = {1,-1,-1,1};

#define MAX_SIZE 3 // Define the maximum size of your data array
long produktArray[MAX_SIZE]; // Array to store produkt values
int index = 0; // Index to keep track of where to store the next value
float resultat = 0;
float y[MAX_SIZE]; // Output array

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

  produkt = p2 * p2 + p3 * p3;

  produktArray[index] = produkt; // Store produkt in the array
  
  lavpassfilter(produktArray, MAX_SIZE, 0.1, 10);

  if (index >= MAX_SIZE) {
    resultat = y[MAX_SIZE-1];
    index = 0;
  } else {
    index++;
  }

  Serial.print(p2);
  Serial.print(", ");
  Serial.print(p3);
  Serial.print(", ");
  Serial.print(produkt);
  Serial.print(", ");
  Serial.print(resultat);
  Serial.print(", ");
  Serial.print(index);
  Serial.println("");
}



void lavpassfilter(long* x, int n, float dt, float RC) {
  // Digital RC low pass filter
  // Variables:
  // input data - x
  // time interval - dt
  // time constant RC

  float alfa = dt / (RC + dt);
  y[0] = x[0];

  for (int i = 1; i < n; i++) {
    y[i] = alfa * x[i] + (1 - alfa) * y[i - 1];
  }
}