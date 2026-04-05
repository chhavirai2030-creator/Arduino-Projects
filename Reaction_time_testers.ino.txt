// C++ code
//

int ledPin = 13;
int buttonPin = 2;
long startTime;
bool ledOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Reaction Time Tester Ready!");
  Serial.println("Wait for the LED to turn on, then press the button.");
  randomSeed(analogRead(0)); 
}

void loop() {
  
  if (!ledOn) {
    int waitTime = random(2000, 6000); 
    delay(waitTime);
    digitalWrite(ledPin, HIGH);       
    startTime = millis();              
    ledOn = true;
    Serial.println("GO! Press the button!");
  }

 
  if (ledOn && digitalRead(buttonPin) == LOW) {
    long reactionTime = millis() - startTime; 

    digitalWrite(ledPin, LOW);  
    ledOn = false;               

    
    Serial.print("Your reaction time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");


    Serial.println("--- Next round starting ---");
    delay(1000); 
  }
}