// C++ code
//
int potPin= A0;
int redPin= 11;
int bluePin= 10;
int greenPin= 9;
int ledPin= 13;

int potValue=0;
unsigned long previousMillis =0;
bool ledState= false;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  potValue= analogRead(potPin);
  
  if (potValue<341){
    int r= map(potValue, 0,340,255,0);
    int g= map(potValue, 0,340,0,255);
    int b= 0;
    
    analogWrite(redPin, r);
    analogWrite(bluePin, b);
    analogWrite(greenPin, g);
  }
  
  else if(potValue <682){
    int r= 0;
    int g= map(potValue, 341, 681, 255, 0);
    int b= map(potValue, 341, 681, 0, 255);
    
    analogWrite(redPin, r);
    analogWrite(bluePin, b);
    analogWrite(greenPin, g);
  }
  
  else {
    int r= map(potValue, 682, 1023, 0,255);
    int g=0;
    int b= map(potValue, 682, 1023, 255,0);
    
    analogWrite(redPin, r);
    analogWrite(bluePin, b);
    analogWrite(greenPin, g);
  }
  long blinkInterval = map(potValue, 0, 1023, 1000, 50);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;
    ledState = !ledState;                    
    digitalWrite(ledPin, ledState);
  }

}
  
