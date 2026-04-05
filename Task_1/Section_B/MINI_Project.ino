int ldrPin = A0;
int potPin = A1;   
int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);   
  int threshold  = analogRead(potPin);   

  Serial.print("Light: "); 
  Serial.print(lightValue);
  Serial.print("  Threshold: "); 
  Serial.println(threshold);

  if (lightValue < threshold) {
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);   
  }

  delay(100);
}