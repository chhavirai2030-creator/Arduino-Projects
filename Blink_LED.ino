// C++ code
//

const int red=13;
const int green=8;
const int yellow=7;

unsigned long prev1=0;
unsigned long prev2=0;
unsigned long prev3=0;

bool state1=LOW;
bool state2=LOW;
bool state3=LOW;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop(){
  unsigned long	current=millis();
  
  if(current-prev1 >= 500 && state1==LOW){
    prev1=current;
    state1=!state1;
    digitalWrite(red, state1);
  }
  
  else if(current-prev1 >= 500 && state1==HIGH){
    prev1=current;
    state1=!state1;
    digitalWrite(red,state1);
  }
  
  if(current-prev2 >=1000 && state2==LOW){
    prev2=current;
    state2=!state2;
    digitalWrite(green, state2);
  }
  
  else if(current-prev2 >=1000 && state2==HIGH){
    prev2=current;
    state2=!state2;
    digitalWrite(green, state2);
  }
  
   if(current-prev3 >=1500 && state3==LOW){
    prev3=current;
    state3=!state3;
    digitalWrite(yellow, state3);
  }
  
  if(current-prev3 >= 1500 && state3==HIGH){
    prev3=current;
    state3=!state3;
    digitalWrite(yellow, state3);
  }
  
}
